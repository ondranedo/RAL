#include "factoryManager.h"
#include "asserts.h"
#include "allocator.h"

namespace RAL {

    FactoryComponentMgr::FactoryComponentMgr() {
        RAL_LOG_TRACE("Component manager running");
    }

    FactoryComponentMgr::~FactoryComponentMgr() {

        clearComponents();
        clearFactories();
        RAL_LOG_TRACE("Component manager destroyed");
    }

    void FactoryComponentMgr::addComponent(BaseComponent *component, const String& name) {

        u64_t i;
        RAL_COMPONENT_SCANTHRU{
            RAL_COMPONENT_ISNAME{
                RAL_ASSERT_MSG("Object %s already created!", name.c_str());
                return;
            }
        }

        Component tempComponent;
        tempComponent.m_component = component;
        tempComponent.m_name = name;
        tempComponent.m_wasInitialized = false;

        m_components.push_back(std::move(tempComponent));
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
            m_components[i].m_component->release();
        }
    }

    //TODO: add a default set of constructor parameters if necessary
    void FactoryComponentMgr::createComponents() {

        u64_t i;

        RAL_FACTORY_SCANTHRU {

            if (!m_factories[i].m_hadDefaultCreated) {

                Component tempComponent;
                tempComponent.m_component = m_factories[i].m_factory->create();
                tempComponent.m_name = m_factories[i].m_productName;
                tempComponent.m_wasInitialized = false;

                m_components.push_back(std::move(tempComponent));
                m_factories[i].m_hadDefaultCreated = true;
            }
        }
    }

    void FactoryComponentMgr::clearComponents() {

        i64_t i;

        releaseComponents();
        RAL_COMPONENT_SCANTHRU{
            if(m_components[i].m_component != nullptr) {
                mainMemory.release(m_components[i].m_component);
                m_components[i].m_component = nullptr;
            }
        }
        m_components.clear();
    }

    void FactoryComponentMgr::clearFactories() {

        i64_t i;

        RAL_FACTORY_SCANTHRU{
            if(m_factories[i].m_factory != nullptr) {
                mainMemory.release(m_factories[i].m_factory);
                m_factories[i].m_factory = nullptr;
            }
        }
        m_factories.clear();
    }
}