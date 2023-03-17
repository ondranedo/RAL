#include "factoryManager.h"
#include "asserts.h"

namespace RAL{

    BaseComponent* FactoryMgr::get(const String& name) {

        i16_t i = findIndex(name);
        if(i == -1){
            RAL_ASSERT("Object %s not found!", name.c_str());
        }

        return m_components[i].x;
    }

    void FactoryMgr::addComponent(BaseComponent *component, const String& name) {

        i16_t i = findIndex(name);
        if(i == -1){
            RAL_ASSERT("Object %s already created!", name.c_str());
        }

        Pair<BaseComponent*, String> temp = {component, name};

        m_components.push_back(temp);
        m_flags.push_back(0);
    }

    //TODO: finish
    void FactoryMgr::removeComponent(const String &name) {

        i16_t i = findIndex(name);
        if(i == -1){
            RAL_ASSERT("Object %s not found!", name.c_str());
        }

        m_components[i].x->release();

        m_flags[i] = m_flags.pop_back();

        m_components[i] = m_components.pop_back();
    }

    void FactoryMgr::init(){

        RAL_COMPONENT_SCANTHRU{

            if(!(m_flags[i] & RAL_WAS_INITIALIZED)) {
                m_components[i].x->init();
                m_flags[i] |= RAL_WAS_INITIALIZED;
            }
        }
    }

    void FactoryMgr::release() {

        RAL_COMPONENT_SCANTHRU{

            if(m_flags[i] & RAL_WAS_INITIALIZED){
                m_components[i].x->release();
                m_flags[i] &= ~RAL_WAS_INITIALIZED;
            }
        }
    }

    //TODO: find a way to convert class name to string
    void FactoryMgr::create() {

        Pair<BaseComponent*, String> temp;

        RAL_FACTORY_SCANTHRU{

            if(m_flags[i] & RAL_DEFAULT_CREATED){

                temp = {m_factories[i].create(), "placeholderNotFinalThisWontWork"};
                m_flags[i] |= RAL_DEFAULT_CREATED;

                m_components.push_back(temp);
                m_flags.push_back(0);
            }
        }
    }

    bool FactoryMgr::stringCompare(const RAL::String& a, const RAL::String& b) {

        /* three levels of nesting is fine ~1nome */
        if(a.size() == b.size()){
            for(u32_t i = 0; i < a.size(); i++){
                if(a.c_str()[i] != b.c_str()[i])
                    return false;
            }
            return true;
        }
        return false;
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