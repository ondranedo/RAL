/////////////////////////////////////////////////////////
// Copyright (C) 2023                                  //
// Ondřej Nedojedlý (https://www.github.com/ondranedo),//
// Matyáš Noska (https://www.github.com/sutiama),      //
// Vojtěch Šokala (https://github.com/Karnatour),      //
// Adam Wiszczor (https://github.com/1nome).           //
//                                                     //
// This file is part of `RAL_PROJECT` project          //
// which is released under `GNU General Public         //
// License v3.0` license.                              //
// See file `LICENSE` for full license details.        //
/////////////////////////////////////////////////////////

#ifndef RAL_PROJECT_FCM_H
#define RAL_PROJECT_FCM_H

#include <core/memoryManager/Overload.h>
#include <core/baseClass/BaseComponent.h>
#include <core/baseClass/BaseFactory.h>
#include <string>
#include <typeindex>

namespace RAL {
    class FCM {
        struct Factory{
            BaseFactory* ptr;
            std::type_index typeIndex;
            std::vector<std::string> products;
            bool defaultCreate :  1;
            template<typename T> explicit Factory(T* ptr);
        };

        struct Component{
            BaseComponent* ptr;
            Factory* motherFactory;
            std::string name;
            // flags
            bool wasInitialized : 1;
            bool wasReleased : 1;
            bool shouldDelete : 1;
        };

    public:
        FCM();
        ~FCM();

        // Adding factory to FCM
        template <typename T> void addFactory();

        // Removing factory and all factories products
        template <typename T> void removeFactory();

        // Adding component to already added factory
        template <typename T> void addComponentToFactory(BaseComponent* component, const std::string& name, bool wasInitialized = false);

        // Adding component without linked factory
        void addComponent(BaseComponent* component, const std::string& name, bool wasInitialized = false, bool shlouldRelease = true, bool shouldDelete = true);

        // Factory have to be created on heap, because it is deleted in FCM
        // Component has to be build using that factory
        template <typename T> void addComponentAndFactory(BaseFactory* factory, T* component, const std::string& name, bool wasInitialized = false);

        // Creating component with custom constructor and adding it to factory
        // T is factory type
        template<typename T, typename... Args> void customComponentCreation(const std::string& name, Args ... args);

        // Removing component through constructor
        void removeComponent(const std::string& name);

        // Creats all components, all factories have to be added
        void createComponents();

        // Calls init on all components
        void initComponents();

        // Calls release on all components
        void releaseComponents();

        // Calls update on all components
        void updateComponents();

        // Clears all components from factory
        template<class T>
        void clearFactoryComponents();

        // Calls delete through specified factory on all components
        void clearComponents();

        // Clears all factories
        void clearFactories();

        // Find component by name and return it
        template<typename T> T* get(const std::string& name);

        [[nodiscard]] size_t getComponentCount() const;
        [[nodiscard]] size_t getFactoriesCount() const;

#ifdef RAL_DEBUG
        void printComponents();
        void printFactories();
#endif
    private:
        void getRidOfComponent(Component& component);
        Factory* findFactoryByTypeIndex(const std::type_index& typeIndex);
        void releaseComponent(Component& component);
        Component* findComponentByName(const std::string& name);
    private:
        std::vector<Factory> m_factories;
        std::vector<Component> m_components;
    };

    template<typename T>
    void FCM::addFactory() {
        Factory factory(new T);
        if(findFactoryByTypeIndex(typeid(T)))
        {
             RAL_LOG_WARNING("Factory %s already exists in FCM", factory.typeIndex.name());
             delete factory.ptr;
             return;
        }
        m_factories.push_back(factory);
        RAL_LOG_DEBUG("Factory %s added to FCM", factory.typeIndex.name());
    }

    template<typename T>
    void FCM::removeFactory() {
        for(size_t i = 0; i < m_factories.size(); i++)
            if(m_factories[i].typeIndex == typeid(T)) {
                // Factory match - deleting all factory components
                clearFactoryComponents<T>();
                // Deleting factory
                delete m_factories[i].ptr;
                m_factories[i].ptr = nullptr;
                m_factories.erase(m_factories.begin() + static_cast<long long>(i));
                return;
            }
        RAL_LOG_WARNING("Factory %s does not exist in FCM", typeid(T).name());
    }

    template<class T>
    void FCM::clearFactoryComponents() {
        Factory* factory = findFactoryByTypeIndex(typeid(T));
        if(!factory) {
            RAL_LOG_WARNING("Factory %s does not exist in FCM", typeid(T).name());
        }

        for(size_t i = 0; i < m_components.size(); i++)
            if(m_components[i].motherFactory->ptr == factory->ptr) {
                releaseComponent(m_components[i]);
                getRidOfComponent(m_components[i]);
            }
    }

    template<typename T>
    void FCM::addComponentToFactory(BaseComponent *component, const std::string &name, bool wasInitialized) {
        if(findComponentByName(name)) {
            RAL_LOG_WARNING("Component %s already exists in FCM", name.c_str());
            return;
        }
        Factory* motherFac = findFactoryByTypeIndex(typeid(T));
        Component newComponent;
        newComponent.ptr = component;
        newComponent.name = name;
        newComponent.wasInitialized = wasInitialized;
        newComponent.wasReleased = false;
        newComponent.motherFactory = motherFac;
        newComponent.shouldDelete = true;
    }

    template<typename T>
    void
    FCM::addComponentAndFactory(BaseFactory *factory, T *component, const std::string &name, bool wasInitialized) {
        //TODO: Implement
    }

    template<typename T, typename... Args>
    void FCM::customComponentCreation(const std::string &name, Args... args) {
        for(auto& factory : m_factories)
        {
            if(factory.typeIndex != typeid(T)) continue;
            if(findComponentByName(name)) {
                RAL_LOG_WARNING("Component %s already exists in FCM", name.c_str());
                return;
            }
            Component newComponent;
            T* typedFactory = dynamic_cast<T*>(factory.ptr);
            BaseComponent* fcomponent = typedFactory->create(args...);
            if(fcomponent == nullptr) {
                RAL_LOG_WARNING("Component %s could not be created, probably maximum factory count reached", name.c_str());
                return;
            }
            newComponent.motherFactory = &factory;
            newComponent.ptr = fcomponent;
            newComponent.name = name;
            newComponent.shouldDelete = true;
            factory.products.push_back(name);
            factory.defaultCreate = false;
            m_components.push_back(newComponent);
            return;
        }
        RAL_LOG_WARNING("Factory %s does not exist in FCM", typeid(T).name());
    }

    template<typename T>
    T *FCM::get(const std::string &name) {
        auto comp = findComponentByName(name);
        if(comp)
            return dynamic_cast<T*>(comp->ptr);
        RAL_LOG_WARNING("Component %s does not exist in FCM", name.c_str());
        return nullptr;
    }

    template<typename T>
    FCM::Factory::Factory(T *ptr) : ptr(ptr), typeIndex(typeid(T)), defaultCreate(true), products() {}
}; // !RAL

#endif //!RAL_PROJECT_FCM_H
