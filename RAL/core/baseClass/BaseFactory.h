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

#ifndef RAL_BASEFACTORY_H
#define RAL_BASEFACTORY_H
#include <core/memoryManager/Overload.h>

#include <core/utility/logger.h>

// TODO: Custom data types
#include <cstdint>
#include <typeinfo>
#include <string>
#include <vector>

#define RAL_BASEFACTORY_DEFAULT_MAXOBJECTCOUNT 0 // 0 = unlimited

namespace RAL {
    template<typename T>
    class BaseFactory
    {
    public:
        BaseFactory();
        BaseFactory(uint32_t maxobjectcount)
#ifdef RAL_DEBUG
                :m_maxObjectCount(maxobjectcount), m_objectCount(0) {}
#else
    {}
#endif //!RAL_DEBUG

        virtual ~BaseFactory();

        inline void setMaxObjectCount(uint32_t new_maxobjectcount);
        [[nodiscard]] inline uint32_t getMaxObjectCount() const;

        void destroy(T* adr);

        [[nodiscard]] std::string productName() const;

        [[nodiscard]] virtual T* create() = 0;

    protected:
        [[nodiscard]] T* createPass(T* adr);

    private:
#ifdef RAL_DEBUG
        uint32_t m_maxObjectCount;
        uint32_t m_objectCount;
#endif //!RAL_DEBUG
    };

    template <typename T> BaseFactory<T>::BaseFactory()
#ifdef RAL_DEBUG
            :m_maxObjectCount(RAL_BASEFACTORY_DEFAULT_MAXOBJECTCOUNT), m_objectCount(0)
#endif //!RAL_DEBUG
    {}
    template <typename T> BaseFactory<T>::~BaseFactory()
    {
#ifdef RAL_DEBUG
        if(m_objectCount == 0) return;
        // TODO: add conversion from typeid to string
        RAL_LOG_WARNING("%d object%s of type %s %s not destroyed", m_objectCount, m_objectCount > 1 ? "s":"", productName().c_str(), m_objectCount > 1 ? "were":"was");
#endif //!RAL_DEBUG
    }
    template <typename T>
    T* BaseFactory<T>::createPass(T* adr)
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
    template <typename T> void BaseFactory<T>::destroy(T* adr)
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
    template <typename T> inline void BaseFactory<T>::setMaxObjectCount(const uint32_t new_maxobjectcount)
    {
#ifdef RAL_DEBUG
        m_maxObjectCount = new_maxobjectcount;
#endif //!RAL_DEBUG
    }
    template <typename T> inline uint32_t  BaseFactory<T>::getMaxObjectCount() const
    {
#ifdef RAL_DEBUG
        return m_maxObjectCount;
#endif //!RAL_DEBUG
    }
    template <typename T> std::string BaseFactory<T>::productName() const
    {
        // TODO: add conversion from typeid to string
        return std::string(typeid(T).name());
    }
} // RAL

#endif //!RAL_BASEFACTORY_H
