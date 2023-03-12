#include "factoryManager.h"

namespace RAL{

    BaseComponent* FactoryMgr::get(const String& name) {

        return m_components[findIndex(name)].x;
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