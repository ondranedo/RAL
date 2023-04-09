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


#include "BaseFactory.h"


namespace RAL {
    BaseFactory::BaseFactory()
#ifdef RAL_DEBUG
            :m_maxObjectCount(RAL_BASEFACTORY_DEFAULT_MAXOBJECTCOUNT), m_objectCount(0)
#endif //!RAL_DEBUG
    {}
    BaseFactory::~BaseFactory()
    {
#ifdef RAL_DEBUG
        if(m_objectCount == 0) return;
        // TODO: add conversion from typeid to string
        RAL_LOG_WARNING("%d object%s of %s not destroyed", m_objectCount, m_objectCount > 1 ? "s":"", m_objectCount > 1 ? "were":"was");
#endif //!RAL_DEBUG
    }

    BaseComponent* BaseFactory::createPass(BaseComponent* adr)
    {
#ifdef RAL_DEBUG
        if(m_objectCount >= m_maxObjectCount && m_maxObjectCount != 0)
        {
            // TODO: add conversion from typeid to string
            RAL_LOG_ERROR("Max object count reached[%d] for %s, returning nullptr", m_maxObjectCount, productName().c_str());
            delete adr;
            adr = nullptr;
        };
        if(adr) m_objectCount++;
#endif
        return adr;
    }
    void BaseFactory::destroy(BaseComponent* adr)
    {
        //if(typeid(*adr) != typeid(T))
        //{
        //    // TODO: add conversion from typeid to string
        //    RAL_LOG_WARNING("Object %s can't be destroyed, bc. is not of type %s", typeid(*adr).name(), productName().c_str());
        //    return;
        //x}
        if(!adr)
        {
            RAL_LOG_WARNING("Object is nullptr, can't be destroyed in %s factory", productName().c_str());
            return;
        }
#ifdef RAL_DEBUG
        m_objectCount--;
#endif //!RAL_DEBUG
        delete adr;
    }
    inline void BaseFactory::setMaxObjectCount(const uint32_t new_maxobjectcount)
    {
#ifdef RAL_DEBUG
        m_maxObjectCount = new_maxobjectcount;
#endif //!RAL_DEBUG
    }
    uint32_t  BaseFactory::getMaxObjectCount() const
    {
#ifdef RAL_DEBUG
        return m_maxObjectCount;
#endif //!RAL_DEBUG
    }
    uint32_t BaseFactory::getObjectCount() const {
#ifdef RAL_DEBUG
        return m_objectCount;
#endif //!RAL_DEBUG
    }

} // RAL