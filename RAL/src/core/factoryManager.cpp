#include "factoryManager.h"
#include "asserts.h"
#include "allocator.h"

namespace RAL {

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

    BaseComponent* FactoryComponentMgr::operator[](const String &name) {

        u64_t i;
        RAL_COMPONENT_SCANTHRU
            RAL_COMPONENT_ISNAME
                break;

        if (i == m_components.size()) {
            RAL_ASSERT_MSG("Object %s not found!", name.c_str());
        }

        return m_components[i].m_component;
    }

    void FactoryComponentMgr::addComponent(BaseComponent *component, const String &name) {

        u64_t i;
        RAL_COMPONENT_SCANTHRU
            RAL_COMPONENT_ISNAME
                RAL_ASSERT_MSG("Object %s already created!", name.c_str());

        struct Component temp;
        temp.m_component = component;
        temp.m_name = name;
        temp.m_wasInitialized = true;

        m_components.push_back(temp);
    }

    void FactoryComponentMgr::removeComponent(const String &name) {

        u64_t i;
        RAL_COMPONENT_SCANTHRU
            RAL_COMPONENT_ISNAME
                break;

        if (i == m_components.size()) {
            RAL_ASSERT_MSG("Object %s not found!", name.c_str());
        }

        m_components[i].m_component->release();

        m_components[i] = m_components[m_components.size() - 1];
        m_components.pop_back();
    }

    void FactoryComponentMgr::init() {

        u64_t i;
        RAL_COMPONENT_SCANTHRU {

            if (!m_components[i].m_wasInitialized) {
                m_components[i].m_component->init();
                m_components[i].m_wasInitialized = true;
            }
        }
    }

    void FactoryComponentMgr::release() {

        u64_t i;
        RAL_COMPONENT_SCANTHRU {

            if (m_components[i].m_wasInitialized) {
                m_components[i].m_component->release();
                m_components[i].m_wasInitialized = false;
            }
        }
    }

    void FactoryComponentMgr::create() {

        struct Component temp;
        u64_t i;

        RAL_FACTORY_SCANTHRU {

            if (!m_factories[i].m_hadDefaultCreated) {

                temp.m_component = m_factories[i].m_factory->create();
                temp.m_name = m_factories[i].m_productName;
                temp.m_wasInitialized = false;

                m_components.push_back(temp);
                m_factories[i].m_hadDefaultCreated = true;
            }
        }
    }
}