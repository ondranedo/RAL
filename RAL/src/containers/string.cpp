#include "string.h"

#include "../core/logger.h"

// TODO: memory classs
#include <stdlib.h>
#include <string.h>
#include <algorithm>

namespace RAL {
	String::~String()
	{
		clear();
	}

	String::String() :
		m_ptr(nullptr),
		m_size(0l)
	{
	}

	String::String(const char* c_str) :
		m_ptr(nullptr),
		m_size(strlen(c_str))
	{
		// TODO: memory class
		m_ptr = reinterpret_cast<char*>(malloc(m_size + 1));
		memcpy(m_ptr, c_str, m_size + 1);
	}


	String::String(const String& str) :
		m_size(str.size()),
		m_ptr(reinterpret_cast<char*>(str.c_cpy()))
	{
	}

	String::String(String&& str) :
		m_size(str.m_size),
		m_ptr(str.m_ptr)
	{
	}

	const char* String::c_str() const
	{
		return reinterpret_cast<const char*>(m_ptr);
	}

	String String::operator+(const String& str)
	{
		String retstr;
		retstr.recreate(*this);
		retstr.m_size += str.m_size;
		retstr.m_ptr = reinterpret_cast<char*>(realloc(retstr.m_ptr, retstr.m_size + 1));

		// TODO: memory class
		strcat(retstr.m_ptr, str.m_ptr);
		return retstr;
	}

	String String::operator+(const char* msg)
	{
		String retstr;
		retstr.recreate(*this);
		retstr.m_size += strlen(msg);
		retstr.m_ptr = reinterpret_cast<char*>(realloc(retstr.m_ptr, retstr.m_size + 1));

		// TODO: memory class
		strcat(retstr.m_ptr, msg);
		return retstr;
	}

	RAL::String String::operator+(char c)
	{
		String retstr;
		retstr.recreate(*this);
		retstr.m_size++;
		// TODO: memory class
		retstr.m_ptr = reinterpret_cast<char*>(realloc(retstr.m_ptr, retstr.m_size + 1));

		retstr.m_ptr[retstr.m_size-1] = c;
		retstr.m_ptr[retstr.m_size  ] = '\0';
		return retstr;
	}

	RAL::String operator+(const char* msg, const String& str)
	{
		String retstr;
		retstr.recreate(msg);
		retstr.m_size+=str.m_size;

		// TODO: memory class
		retstr.m_ptr = reinterpret_cast<char*>(realloc(retstr.m_ptr, retstr.m_size + 1));
		strcat(retstr.m_ptr, str.m_ptr);
		return retstr;
	}

	char String::operator[](const size_t& index)
	{
		if (index < m_size)
			return m_ptr[index];
		
		RAL_LOG_WARN("Referencing index out of string's scope");
		return '\0';
	}

	u64_t String::size() const
	{
		return m_size;
	}

	void String::flush()
	{
		clear();
	}

	const RAL::String& String::get() const
	{
		return *this;
	}

	void String::toLower()
	{
		strlwr(m_ptr);
	}

	void String::toUpper()
	{
		strupr(m_ptr);
	}

	void String::for_each(void(*function)(char c))
	{
		for (char c : *this)
			function(c);
	}

	char* String::c_cpy() const
	{
		// TODO: memory class
		char* ptr = reinterpret_cast<char*>(malloc(m_size + 1));
		memcpy(ptr, m_ptr, m_size + 1);
		return ptr;
	}

	void String::recreate(String&& str)
	{
		clear();

		m_ptr  = str.m_ptr;
		m_size = str.m_size;
		str.m_ptr = nullptr;
		str.m_size = 0;
	}

	void String::recreate(const String& str)
	{
		clear();

		m_size = str.m_size;

		// TODO: memory class
		m_ptr = reinterpret_cast<char*>(malloc(m_size + 1));
		memcpy(m_ptr, str.m_ptr, m_size + 1);
	}

	void String::recreate(const char* str)
	{
		clear();

		m_size = strlen(str);

		// TODO: memory class
		m_ptr = reinterpret_cast<char*>(malloc(m_size + 1));
		memcpy(m_ptr, str, m_size + 1);
	}

	void String::recreate(char c)
	{
		clear();

		m_size = 1;

		// TODO: memory class
		m_ptr = reinterpret_cast<char*>(malloc(2));
		m_ptr[0] = c;
		m_ptr[1] = '\0';
	}

	String& String::operator=(const String& str)
	{
		recreate((const String&)str);

		return *this;
	}

	String& String::operator=(const char* str)
	{
		recreate((const char*)str);

		return *this;
	}

	String& String::operator=(char c)
	{
		recreate((char)c);

		return *this;
	}

	String& String::operator=(String&& str)
	{
		recreate((String&&)str);

		return *this;
	}

	char* String::begin()
	{
		return m_ptr;
	}

	char* String::end()
	{
		if (m_ptr)
			return &m_ptr[m_size];
		else
			return nullptr;
	}

	void String::clear()
	{
		if (m_ptr)
			// TODO: memory class
			free(m_ptr);
		m_size = 0;
	}
}