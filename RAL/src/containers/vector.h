#pragma once
#include "../pch.h"
#include <utility>

namespace RAL {
    template<typename T>
    class Vector{
        const u32_t m_allocScale = 2;
        u32_t m_maxCount;
        u32_t m_count;
        T* m_first;

    public:
        ~Vector();
        Vector();
        Vector(const Vector& other);
        Vector(Vector&& other) noexcept;

        template<typename... Args>
        Vector(const T& arg, Args... args);

        template<typename... Args>
        Vector(T&& arg, Args... args) noexcept;

        Vector(const T& arg);
        Vector(T&& arg) noexcept;

        void push_back(const T& val);
        void push_back(T&& val) noexcept;
        template<typename... Args>
        void push_back(const T& val, Args... args);
        template<typename... Args>
        void push_back(T&& val, Args... args) noexcept;

        T pop_back();
        Vector<T> pop_nback(const size_t& count);
        void clear();

        [[nodiscrad]] u32_t size() const {
            return m_count;
        }

        [[nodiscard]] u32_t capacity() const {
            return m_maxCount;
        }

        [[nodiscard]] const T* c_cpy() const;
        void for_each(void(*function)(const T& val)) const;

        Vector<T>& operator=(const Vector<T>& other);
        Vector<T>& operator=(Vector<T>&& other);
        T& operator[](const size_t& val);
        const T& operator[](const size_t& val) const;


        [[nodiscard]] T * begin() const;
        [[nodiscard]] T * end() const;

        [[nodiscard]] const T * cbegin() const;
        [[nodiscard]] const T * cend() const;

    private:
        void realloc();
        void dealloc();
    };

    template<typename T>
    Vector<T> Vector<T>::pop_nback(const size_t& count) {
        Vector<T> retvec, tmp;
        for(size_t i = 0; i < count; i++)
            tmp.push_back(pop_back());
        // rotate
        for(auto& v:tmp)
            retvec.push_back(tmp.pop_back());

        return retvec;
    }

    template<typename T>
    T &Vector<T>::operator[](const size_t &val) {
        if(val < m_count)
            return m_first[val];
        // TODO: Asserts
        return m_first[m_count-1];
    }

    template<typename T>
    const T &Vector<T>::operator[](const size_t &val) const {
        if(val < m_count)
            return m_first[val];
        // TODO: Asserts
        return m_first[m_count-1];
    }

    template<typename T>
    const T *Vector<T>::cbegin() const {
        return begin();
    }

    template<typename T>
    const T *Vector<T>::cend() const {
        return end();
    }

    template<typename T>
    T Vector<T>::pop_back() {
        if(!m_first || !m_count) return 0; // TODO: Assert + Error
        T val = m_first[m_count-1];
        if(--m_count <= m_maxCount/m_allocScale)
            this->dealloc();
        return val;
    }

    template<typename T>
    void Vector<T>::clear() {
        m_maxCount = 0;
        m_count = 0;
        if(m_first)
            // TODO: memory class
            std::free(m_first);
        m_first = nullptr;
    }

    template<typename T>
    Vector<T> &Vector<T>::operator=(Vector<T> &&other) {
        this->m_count = other.m_count;
        this->m_maxCount = other.m_maxCount;
        this->m_first = other.m_first;
        other.m_first = nullptr;
        other.m_maxCount = 0;
        other.m_count = 0;
    }

    template<typename T>
    Vector<T> &Vector<T>::operator=(const Vector<T> &other) {
        this->m_count = other.m_count;
        this->m_maxCount = other.m_maxCount;
        this->m_first = other.c_cpy();
    }

    template<typename T>
    T * Vector<T>::begin() const {
        return m_first;
    }

    template<typename T>
    T * Vector<T>::end() const {
        return &m_first[m_count];
    }

    template<typename T>
    void Vector<T>::for_each(void (*function)(const T & val)) const {
        for(const auto& val : *this){
            function(val);
        }
    }

    template<typename T>
    template<typename... Args>
    void Vector<T>::push_back(T &&val, Args... args) noexcept {
        push_back(std::move(val));
        push_back(args...);
    }

    template<typename T>
    void Vector<T>::push_back(T &&val) noexcept {
        if(!m_first)
        {
            m_maxCount = 1;
            // TODO: memory class
            m_first = static_cast<T*>(std::malloc(m_maxCount*sizeof(T)));
        }
        if(m_count == m_maxCount)
            this->realloc();
        m_first[m_count++] = std::move(val);
    }

    template<typename T>
    Vector<T>::Vector(T &&arg) noexcept:
    m_maxCount(0), m_count(0), m_first(nullptr){
        push_back(std::move(arg));
    }

    template<typename T>
    template<typename... Args>
    Vector<T>::Vector(T &&arg, Args... args) noexcept :
    m_maxCount(0), m_count(0), m_first(nullptr){
        push_back(std::move(arg), args...);
    }

    template<typename T>
    Vector<T>::~Vector() {
        if(m_first)
            // TODO: memory class
            std::free(m_first);
    }


    template<typename T>
    template<typename... Args>
    void Vector<T>::push_back(const T &val, Args... args) {
        push_back(val);
        push_back(args...);
    }

    template<typename T>
    void Vector<T>::push_back(const T &val) {
        if(!m_first)
        {
            m_maxCount = 1;
            // TODO: memory class
            m_first = static_cast<T*>(std::malloc(m_maxCount*sizeof(T)));
        }
        if(m_count == m_maxCount)
            this->realloc();
        m_first[m_count++] = val;
    }

    template<typename T>
    void Vector<T>::realloc() {
        if(m_maxCount == 0) m_maxCount++;
        else  m_maxCount *= m_allocScale;
        // TODO: memory class
        T* tmp = static_cast<T*>(std::malloc(m_maxCount*sizeof(T)));
        std::memcpy(tmp, m_first, m_count*sizeof(T));
        // TODO: memory class
        std::free(m_first);
        m_first = tmp;
    }


    template<typename T>
    void Vector<T>::dealloc() {
        if(m_count == 0){
            if(m_first) std::free(m_first);
            m_first = nullptr;
            m_maxCount = 0;
            return;
        }
        m_maxCount /= m_allocScale;
        // TODO: memory class
        T* tmp = static_cast<T*>(std::malloc(m_maxCount*sizeof(T)));
        std::memcpy(tmp, m_first, m_count*sizeof(T));
        // TODO: memory class
        std::free(m_first);
        m_first = tmp;
    }

    template<typename T>
    const T *Vector<T>::c_cpy() const {
        // TODO: memory class
        T* ret = reinterpret_cast<T*>(std::malloc(m_maxCount * sizeof(T)));
        std::memcpy(ret, m_first,m_maxCount * sizeof(T));
        return ret;
    }

    template<typename T>
    Vector<T>::Vector():
    m_maxCount(0), m_count(0), m_first(nullptr)
    {}

    template<typename T>
    Vector<T>::Vector(const Vector &other):
    m_maxCount(other.m_maxCount), m_count(other.m_count), m_first(other.c_cpy())
    {}

    template<typename T>
    Vector<T>::Vector(Vector &&other) noexcept:
    m_maxCount(other.m_maxCount), m_count(other.m_count), m_first(other.m_first) {
        other.m_first = nullptr;
        other.m_count = 0;
        other.m_maxCount = 0;
    }

    template<typename T>
    template<typename... Args>
    Vector<T>::Vector(const T &arg, Args... args):
    m_maxCount(0), m_count(0), m_first(nullptr){
        push_back(arg, args...);
    }

    template<typename T>
    Vector<T>::Vector(const T &arg):
    m_maxCount(0), m_count(0), m_first(nullptr) {
        push_back(arg);
    }
}