#pragma once
#include "../pch.h"
#include <ctype.h>
namespace RAL {
	class String {
		char* m_ptr;
		u64_t m_size;

	public:
		~String();
		String();
		String(const char* c_str);
		String(const String& str);
		String(String&& str);

		// getters
		u64_t size() const;
		const String& get() const;

		// Supporting functions
		void toLower();
		void toUpper();
		void for_each(void(*function)(char c));

		// Memory functions
		void flush();
		void recreate(String&& str);
		void recreate(const String& str);
		void recreate(const char* c_str);
		void recreate(char c);

		// for C sup. functions
		char* c_cpy() const;
		const char* c_str() const;

		String operator+(const String& str);
		String operator+(const char* msg);
		String operator+(char c);
		friend 	String operator+(const char* msg, const String& str);
		char operator[](const size_t& index);
		String& operator=(const String& str);
		String& operator=(String&& str);
		String& operator=(const char* str);
		String& operator=(char c);
		// Iterators
		char* begin();
		char* end();

	private:
		void clear();
	};
}