#pragma once

#include "baseComponent.h"
#include "baseFactory.h"
#include "../containers/vector.h"
#include "../containers/pair.h"
#include "../containers/string.h"

#define RAL_COMPONENT_SCANTHRU for(i = 0; i < m_components.size(); i++)
#define RAL_FACTORY_SCANTHRU for(i = 0; i < m_factories.size(); i++)
#define RAL_COMPONENT_ISNAME if(*m_components[i].m_name == name)

namespace RAL{

    class FactoryComponentMgr{

    public:
        FactoryComponentMgr();
        ~FactoryComponentMgr();

        template<typename factory> void addFactory();

        void addComponent(BaseComponent* component, const String& name, bool wasInitialized);
        template<typename factory> void createComponent(const String& name);
        void removeComponent(const String& name);

        void createComponents();
        void initComponents();
        void releaseComponents();

        template<typename T> T* get(const String& name);

        void clearFactories();
        void clearComponents();

    private:
        struct Component{

            BaseComponent* m_component;
            String* m_name;
            // flags
            bool m_wasInitialized;
        };

        struct Factory{
//TODO: do some oop magic to make conversions to m_factory pointer possible
            BaseFactory<BaseComponent>* m_factory;
            String* m_productName;
            //flags
            bool m_hadDefaultCreated;
        };

        Vector<Component> m_components;
        Vector<Factory> m_factories;
    };

    template<typename factory>
    void FactoryComponentMgr::addFactory() {

        u64_t i;

        Factory tempFactory{};
        tempFactory.m_factory = mainMemory.alloc<factory>();
        String* productName = mainMemory.alloc<String>(tempFactory.m_factory->productName());

        RAL_FACTORY_SCANTHRU{
            if(*m_factories[i].m_productName == *productName){
                mainMemory.release(tempFactory.m_factory);
                RAL_ASSERT_MSG("%s Factory already created!", productName->c_str())
                return;
            }
        }

        tempFactory.m_productName = productName;
        tempFactory.m_hadDefaultCreated = false;

        m_factories.push_back(tempFactory);
    }

    template<typename factory>
    void FactoryComponentMgr::createComponent(const String& name){

        u64_t i;
        RAL_COMPONENT_SCANTHRU {
            RAL_COMPONENT_ISNAME {
                RAL_ASSERT_MSG("Component %s already created!", name.c_str())
                return;
            }
        }

        Factory tempFactory{};
        tempFactory.m_factory = mainMemory.alloc<factory>();
        String productName = tempFactory.m_factory->productName();
        mainMemory.release(tempFactory.m_factory);

        //will still create if for ex. name = "FileIO" but fileIOFactory hasn't been added yet
        RAL_FACTORY_SCANTHRU{
            if(*m_factories[i].m_productName == name){
                RAL_ASSERT_MSG("Can't create a component of the same name as the default name!")
                return;
            }
        }

        RAL_FACTORY_SCANTHRU{
            if(*m_factories[i].m_productName == productName){
                addComponent(m_factories[i].m_factory->create(), name, false);
                return;
            }
        }
        RAL_ASSERT_MSG("%s factory not found or created!", productName.c_str())
    }

    template<typename T>
    T* FactoryComponentMgr::get(const String &name) {

        u64_t i;
        RAL_COMPONENT_SCANTHRU {
            RAL_COMPONENT_ISNAME {
                break;
            }
        }

        if (i == m_components.size()) {
            RAL_ASSERT_MSG("Object %s not found!", name.c_str())
            return nullptr;
        }

        if(m_components[i].m_wasInitialized){
            return dynamic_cast<T*>(m_components[i].m_component);
        }
        RAL_ASSERT_MSG("Object %s was not initialized!", name.c_str())
        return nullptr;
    }
}
