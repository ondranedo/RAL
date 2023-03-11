#pragma once

// constants for open modes
#define TXT_READ "r"
#define TXT_WRITE "w"
#define TXT_APPEND "a"
#define TXT_READ_WRITE "r+"
#define BIN_READ "rb"
#define BIN_WRITE "wb"
#define BIN_APPEND "ab"
#define BIN_READ_WRITE "rb+"

/* TODO: 
*		use String once it has been documented
*		refactor to Memory once platformLayer is complete
*		potentially more overrides for println
*/

namespace RAL {

	class fileIO{
	public:
		fileIO();
		~fileIO();

		void open(const i8_t* path, const i8_t* alias, const i8_t* mode);
		void close(const i8_t* alias);

		void println(const i8_t* string);
		void println(i32_t num);
		void println(f32_t num);

		i8_t* readln();

		void printFileUsage();
		
		void maxFile(u16_t count);

	private:

		u16_t openFiles;
	};
}