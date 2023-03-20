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

        //TODO: change factoryName to productName
        struct Factory{

            BaseFactory<BaseComponent>* m_factory;
            String m_factoryName;
            //flags
            bool m_hadDefaultCreated;
        };

        Vector<Component> m_components;
        Vector<Factory> m_factories;
    };

    template<typename factory>
    void FactoryComponentMgr::addFactory() {

        String factoryName = stringize(factory);
        auto* tempFactory = mainMemory.alloc<struct Factory>();
        u64_t i;

        RAL_FACTORY_SCANTHRU{
            if(m_factories[i].m_factoryName == factoryName){
                RAL_ASSERT_MSG("Factory %s already created!", factoryName.c_str());
                return;
            }
        }

        tempFactory->m_factoryName = factoryName;
        tempFactory->m_hadDefaultCreated = false;
        tempFactory->m_factory = mainMemory.alloc<factory>();

        m_factories.push_back(*tempFactory);
        mainMemory.release(tempFactory);
    }

    template<typename factory>
    void FactoryComponentMgr::createComponent(const String& name){

        u64_t i;
        RAL_COMPONENT_SCANTHRU {
            RAL_COMPONENT_ISNAME {
                RAL_ASSERT_MSG("Component %s already created!", name.c_str());
                return;
            }
        }

        String factoryName = stringize(factory);

        if(factoryName == name){
            RAL_ASSERT_MSG("Cant create a component of a same name as a factory (for some reason)");
            return;
        }

        RAL_FACTORY_SCANTHRU{
            if(m_factories[i].m_factoryName == factoryName){
                auto* tempComponent = mainMemory.alloc<struct Component>();
                tempComponent->m_wasInitialized = false;
                tempComponent->m_name = name;
                tempComponent->m_component = m_factories[i].m_factory->create();
                m_components.push_back(*tempComponent);
                mainMemory.release(tempComponent);
                return;
            }
        };
        RAL_ASSERT_MSG("Factory %s not found or created!", factoryName.c_str());
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
            RAL_ASSERT_MSG("Object %s not found!", name.c_str());
            return nullptr;
        }

        return dynamic_cast<T*>(m_components[i].m_component);
    }
}