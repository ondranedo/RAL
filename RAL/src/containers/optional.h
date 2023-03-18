#pragma once

#include <utility>
#include "../core/asserts.h"

template<typename T>
struct Optional{
    Optional():m_hasValue(false){}
    Optional(const T& val):m_hasValue(true), m_value(val){}
    Optional(T&& val):m_hasValue(true), m_value(std::move(val)){}

    const T& value() const {
        RAL_ASSERT(m_value, "RAL::Optional<T> can't access value");
        return m_value;
    }

    const T& value_or(const T& val) const {
        if(m_value) return m_value;
        return val;
    }

    T& value_or(T&& val){
        if(m_value) return m_value;
        return val;
    }

    Optional<T>& operator= (const T& val){
        this->m_value = val;
        this->m_hasValue = true;
        return *this;
    }

private:
    T m_value;
    bool m_hasValue;
};