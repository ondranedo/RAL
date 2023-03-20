#include "factoryManager.h"
#include "asserts.h"
#include "allocator.h"

namespace RAL {

    void FactoryComponentMgr::addComponent(BaseComponent *component, const String &name) {

        u64_t i;
        RAL_COMPONENT_SCANTHRU{
            RAL_COMPONENT_ISNAME{
                RAL_ASSERT_MSG("Object %s already created!", name.c_str());
                return;
            }
        }

        auto* tempComponent = mainMemory.alloc<struct Component>();
        tempComponent->m_component = component;
        tempComponent->m_name = name;
        tempComponent->m_wasInitialized = true;

        m_components.push_back(*tempComponent);
        mainMemory.release(tempComponent);
    }

    void FactoryComponentMgr::removeComponent(const String &name) {

        u64_t i;
        RAL_COMPONENT_SCANTHRU{
            RAL_COMPONENT_ISNAME{
                break;
            }
        }

        if (i == m_components.size()) {
            RAL_ASSERT_MSG("Object %s not found!", name.c_str());
            return;
        }

        m_components[i].m_component->release();

        m_components[i] = m_components[m_components.size() - 1];
        m_components.pop_back();
    }

    void FactoryComponentMgr::initComponents() {

        u64_t i;
        RAL_COMPONENT_SCANTHRU {

            if (!m_components[i].m_wasInitialized) {
                m_components[i].m_component->init();
                m_components[i].m_wasInitialized = true;
            }
        }
    }

    void FactoryComponentMgr::releaseComponents() {

        u64_t i;
        RAL_COMPONENT_SCANTHRU {

            if (m_components[i].m_wasInitialized) {
                m_components[i].m_component->release();
                m_components[i].m_wasInitialized = false;
            }
        }
    }

    void FactoryComponentMgr::createComponents() {

        auto* tempComponent = mainMemory.alloc<struct Component>();
        u64_t i;

        RAL_FACTORY_SCANTHRU {

            if (!m_factories[i].m_hadDefaultCreated) {

                tempComponent->m_component = m_factories[i].m_factory->create();
                tempComponent->m_name = m_factories[i].m_factoryName;
                tempComponent->m_wasInitialized = false;

                m_components.push_back(*tempComponent);
                m_factories[i].m_hadDefaultCreated = true;
            }
        }
        mainMemory.release(tempComponent);
    }
}