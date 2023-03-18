#include "factoryManager.h"
#include "asserts.h"

namespace RAL{

    BaseComponent* FactoryMgr::get(const String& name) {

        i16_t i = findIndex(name);
        if(i == -1){
            RAL_ASSERT("Object %s not found!", name.c_str());
        }

        return m_components[i].m_component;
    }

    void FactoryMgr::addComponent(BaseComponent *component, const String& name) {

        i16_t i = findIndex(name);
        if(i == -1){
            RAL_ASSERT("Object %s already created!", name.c_str());
        }

        struct Component temp;
        temp.m_component = component;
        temp.m_name = name;
        temp.m_wasInitialized = false;

        m_components.push_back(temp);
    }

    void FactoryMgr::removeComponent(const String &name) {

        i16_t i = findIndex(name);
        if(i == -1){
            RAL_ASSERT("Object %s not found!", name.c_str());
        }

        m_components[i].m_component->release();

        m_components[i] = m_components[m_components.size() - 1];
        m_components.pop_back();
    }

    void FactoryMgr::init(){

        RAL_COMPONENT_SCANTHRU{

            if(!m_components[i].m_wasInitialized) {
                m_components[i].m_component->init();
                m_components[i].m_wasInitialized = true;
            }
        }
    }

    void FactoryMgr::release() {

        RAL_COMPONENT_SCANTHRU{

            if(m_components[i].m_wasInitialized){
                m_components[i].m_component->release();
                m_components[i].m_wasInitialized = false;
            }
        }
    }

    //TODO: find a way to convert class name to string
    void FactoryMgr::create() {

        struct Component temp;

        RAL_FACTORY_SCANTHRU{

            if(!m_factories[i].m_hadDefaultCreated){

                temp.m_component = m_factories[i].m_factory->create();
                temp.m_name = "ClassName";
                temp.m_wasInitialized = false;

                m_components.push_back(temp);
            }
        }
    }

    i16_t FactoryMgr::findIndex(const String& name){

        RAL_COMPONENT_SCANTHRU{
            RAL_COMPONENT_ISNAME{
                return i;
            }
        }
        return -1;
    }
}