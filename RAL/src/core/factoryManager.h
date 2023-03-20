#pragma once

#include "baseComponent.h"
#include "baseFactory.h"
#include "../containers/vector.h"
#include "../containers/pair.h"
#include "../containers/string.h"

#define stringize(string) #string

#define RAL_COMPONENT_SCANTHRU for(i = 0; i < m_components.size(); i++)
#define RAL_FACTORY_SCANTHRU for(i = 0; i < m_factories.size(); i++)
#define RAL_COMPONENT_ISNAME if(m_components[i].m_name == name)

namespace RAL{

    class FactoryComponentMgr{

    public:
        template<typename factory> void addFactory();

        void addComponent(BaseComponent* component, const String& name);
        template<typename factory> void createComponent(const String& name);
        void removeComponent(const String& name);

        void create();
        void init();
        void release();

        template<typename T> T* get(const String& name);

    private:
        struct Component{

            BaseComponent* m_component;
            String m_name;
            // flags
            bool m_wasInitialized;
        };

        struct Factory{

            BaseFactory<BaseComponent>* m_factory;
            String m_productName;
            //flags
            bool m_hadDefaultCreated;
        };

        Vector<Component> m_components;
        Vector<Factory> m_factories;
    };

    template<typename factory>
    void FactoryComponentMgr::addFactory() {

        String temp2 = stringize(factory);
        struct Factory temp;
        u64_t i;

        RAL_FACTORY_SCANTHRU{
            if(m_factories[i].m_productName == temp2){
                RAL_ASSERT_MSG("Factory %s already created!", temp2.c_str());
            }
        };

        temp.m_productName = temp2;
        temp.m_hadDefaultCreated = false;
        temp.m_factory = mainMemory.alloc<factory>();

        m_factories.push_back(temp);
    }

    template<typename factory> void FactoryComponentMgr::createComponent(const String& name){

        u64_t i;
        RAL_COMPONENT_SCANTHRU
            RAL_COMPONENT_ISNAME
        RAL_ASSERT_MSG("Component %s already created!", name.c_str());

        String temp2 = stringize(factory);

        if(temp2 == name)
        RAL_ASSERT_MSG("Cant create a non-default component with a default name (%s)", name.c_str());

        RAL_FACTORY_SCANTHRU{
            if(m_factories[i].m_productName == temp2){
                struct Component temp;
                temp.m_wasInitialized = false;
                temp.m_name = name;
                temp.m_component = m_factories[i].m_factory->create();
                m_components.push_back(temp);
                return;
            }
        };
        RAL_ASSERT_MSG("Factory %s not found or created!", temp2.c_str());
    }

    template<typename T>
    T* FactoryComponentMgr::get(const String &name) {

        u64_t i;
        RAL_COMPONENT_SCANTHRU
            RAL_COMPONENT_ISNAME
                break;

        if (i == m_components.size()) {
            RAL_ASSERT_MSG("Object %s not found!", name.c_str());
            return nullptr;
        }

        return dynamic_cast<T*>(m_components[i].m_component);
    }
}