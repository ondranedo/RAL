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
#define RAL_BASEFACTORY_CREATE(T) dynamic_cast<T*>(this->createPass(dynamic_cast<BaseComponent*>(new T)))
#define RAL_BASEFACTORY_CREATE_ADR(T, adr) dynamic_cast<T*>(this->createPass(dynamic_cast<BaseComponent*>(adr)))

namespace RAL {
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
        [[nodiscard]] uint32_t getMaxObjectCount() const;
        [[nodiscard]] uint32_t getObjectCount() const;

        [[nodiscard]] virtual std::string productName() const = 0;
        [[nodiscard]] virtual BaseComponent* create() = 0;
        void destroy(BaseComponent* adr);


    protected:
        [[nodiscard]] BaseComponent* createPass(BaseComponent* adr);

    private:
#ifdef RAL_DEBUG
        uint32_t m_maxObjectCount;
        uint32_t m_objectCount;
#endif //!RAL_DEBUG
    };
} // RAL

#endif //!RAL_BASEFACTORY_H
