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
        ~WFileIO() override;

        void open(RAL::String path, RAL::String alias, RAL::String mode) override;
        void close(RAL::String alias) override;

        void println(RAL::String alias, RAL::String string) override;
        void println(RAL::String alias, i64_t num) override;
        void println(RAL::String alias, f64_t num) override;

        RAL::String readln(RAL::String alias) override;

        void printFileUsage() override;

        void maxFile(i16_t count) override;
    };
}

#endif
