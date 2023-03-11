#pragma once

#include "types.h"

namespace RAL
{
    template<typename T>
    class BaseFactory
    {
    public:
        BaseFactory()
        {
            m_maxObjectCount = 0;
            m_objectCount = 0;
        }
        virtual ~BaseFactory()
        {

        }

        virtual T* create() = 0;

        virtual void setMaxObjectCount(u32_t new_maxobjectcount)
        {
            m_maxObjectCount = new_maxobjectcount;
        }
        virtual u32_t getMaxObjectCount()
        {
            return m_maxObjectCount;
        }

    protected:

        u32_t m_maxObjectCount;
        u32_t m_objectCount;
    };
}


