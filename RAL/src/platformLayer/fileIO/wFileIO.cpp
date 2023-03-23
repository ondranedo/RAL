#include "wFileIO.h"

#ifdef RAL_WINDOWS

#include <cstdio>
#include "../../core/allocator.h"

namespace RAL {

    WFileIO::WFileIO() {

        openFiles = 0;
        files = reinterpret_cast<RAL_FILE_ENTRY*>(mainMemory.allocn<i8_t>(sizeof(RAL_FILE_ENTRY)));
        RAL_LOG_TRACE("File I/O created");
    }

    WFileIO::~WFileIO() {

        RAL_FILE_SCANTHRU{
            fclose(files[i].y.y);
        }
        mainMemory.release(files);
        RAL_LOG_TRACE("File I/O destroyed");
    }

    void WFileIO::open(const RAL::String& path, const RAL::String& alias, const RAL::String& mode) {

        RAL_FILE_SCANTHRU{
            if(FileIO::stringCompare(path, files[i].x.x)){
                RAL_LOG_ERROR("This path is already open!");
                return;
            }
            RAL_FILE_ISALIAS{
                RAL_LOG_ERROR("This alias is already used!");
                return;
            }
        }
        if(openFiles == _getmaxstdio()){
            RAL_LOG_ERROR("Open file limit reached!");
            return;
        }

        files = reinterpret_cast<RAL_FILE_ENTRY*>(mainMemory.reallocate(files, sizeof(RAL_FILE_ENTRY) * (openFiles + 1)));
        files[openFiles].y.y = fopen(path.c_str(), mode.c_str());
        files[openFiles].x.x = path;
        files[openFiles].x.y = alias;
        files[openFiles].y.x = mode;
        openFiles += 1;
    }

    void WFileIO::close(const RAL::String& alias) {

        i16_t i = findIndex(alias);
        if(i == -1){
            RAL_LOG_ERROR("File alias not found!");
            return;
        }
        fclose(files[i].y.y);

        files[i].x.x = files[openFiles - 1].x.x;
        files[i].x.y = files[openFiles - 1].x.y;
        files[i].y.x = files[openFiles - 1].y.x;
        files[i].y.y = files[openFiles - 1].y.y;

        files = reinterpret_cast<RAL_FILE_ENTRY*>(mainMemory.reallocate(files, sizeof(RAL_FILE_ENTRY) * (openFiles - 1)));
        openFiles -= 1;
    }

    RAL::String WFileIO::readln(const RAL::String& alias){

        char* buf;
        RAL::String buf2 = RAL::String();
        i16_t i = findIndex(alias);
        if(i == -1){
            RAL_LOG_ERROR("File alias not found!");
            return RAL::String();
        }
        if(files[i].y.x.c_str()[1] == 'b'){

        }
        else{
            // change to a better solution than this
            buf = mainMemory.alloc<char>(1024);
            fscanf(files[i].y.y, "%s\n", buf);

            buf2.recreate(buf);
            mainMemory.release(buf);
            return buf2;
        }
    }

    void WFileIO::println(const RAL::String& alias, const RAL::String& string){

        i16_t i = findIndex(alias);
        if(i == -1){
            RAL_LOG_ERROR("File alias not found!");
            return;
        }
        fprintf(files[i].y.y, "%s\n", string.c_str());
    }
    void WFileIO::println(const RAL::String& alias, i64_t num){

        i16_t i = findIndex(alias);
        if(i == -1){
            RAL_LOG_ERROR("File alias not found!");
            return;
        }
        fprintf(files[i].y.y, "%lld", num);
    }
    void WFileIO::println(const RAL::String& alias, f64_t num){

        i16_t i = findIndex(alias);
        if(i == -1){
            RAL_LOG_ERROR("File alias not found!");
            return;
        }
        fprintf(files[i].y.y, "%lf", num);
    }

    void WFileIO::printFileUsage(){

        u32_t maxAliasSize = 0, maxPathSize = 0;
        RAL::String line;

        RAL_FILE_SCANTHRU{

            if(files[i].x.x.size() > maxPathSize)
                maxPathSize = files[i].x.x.size();
            if(files[i].x.y.size() > maxAliasSize)
                maxAliasSize = files[i].x.y.size();
        }

        RAL_FILE_SCANTHRU{

            line.recreate(files[i].x.x);
            while (line.size() < maxPathSize + 1)
                line = line + " ";

            line = line + files[i].x.y;
            while(line.size() < maxPathSize + maxAliasSize + 2)
                line = line + " ";

            line = line + files[i].y.x;
            RAL_LOG_INFO("%s\n", line);
        }
    }

    void WFileIO::maxFile(i16_t count) {

        if(count < openFiles) {
            RAL_LOG_ERROR("Cant decrease the maximum number of open files now! Need to close some prior to decreasing.");
            return;
        }
        RAL_LOG_TRACE("Maximum number of open files changed to %h", count);
        _setmaxstdio(count);
    }
}

#endif