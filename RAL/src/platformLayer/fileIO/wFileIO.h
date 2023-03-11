#pragma once

#include "fileIO.h"

// constants for open modes
#define TXT_READ "r"
#define TXT_WRITE "w"
#define TXT_APPEND "a"
#define TXT_READ_WRITE "r+"
#define BIN_READ "rb"
#define BIN_WRITE "wb"
#define BIN_APPEND "ab"
#define BIN_READ_WRITE "rb+"

/*		refactor to Memory once platformLayer is complete
 *		potentially more overrides for println
 *		something to not repeat code when doing so^^^
 *		refactor to whatever fileIO["text"] is
 *		switch to safer functions like fscanf_s if recommended
 *		wiki
*/

#ifdef RAL_WINDOWS

namespace RAL {

    class WFileIO: public FileIO{
    public:
        WFileIO();
        ~WFileIO();

        void open(RAL::String path, RAL::String alias, RAL::String mode);
        void close(RAL::String alias);

        void println(RAL::String alias, RAL::String string);
        void println(RAL::String alias, i64_t num);
        void println(RAL::String alias, f64_t num);

        RAL::String readln(RAL::String alias);

        void printFileUsage();

        void maxFile(i16_t count);
    };
}

#endif
