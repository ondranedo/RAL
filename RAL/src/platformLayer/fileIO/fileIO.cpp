#include "fileIO.h"
#include <utility>

#define RAL_FILE_SCANTHRU for(i16_t i = 0; i < openFiles; i++)
#define RAL_FILE_ISALIAS if(fileIO::stringCompare(alias, files[i].x.y))

namespace RAL {

	fileIO::fileIO() {

        openFiles = 0;
        files = reinterpret_cast<RAL_FILE_ENTRY*>(malloc(sizeof(RAL_FILE_ENTRY)));
		RAL_LOG_TRACE("File I/O created");
	}

	fileIO::~fileIO() {

        RAL_FILE_SCANTHRU{
            fclose(files[i].y.y);
        }
        free(files);
		RAL_LOG_TRACE("File I/O destroyed");
	}

	void fileIO::open(RAL::String path, RAL::String alias, RAL::String mode) {

        RAL_FILE_SCANTHRU{
            if(fileIO::stringCompare(path, files[i].x.x)){
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

        files = reinterpret_cast<RAL_FILE_ENTRY*>(realloc(files, sizeof(RAL_FILE_ENTRY) * (openFiles + 1)));
		files[openFiles].y.y = fopen(path.c_str(), mode.c_str());
        files[openFiles].x.x = path;
        files[openFiles].x.y = alias;
        files[openFiles].y.x = mode;
        openFiles += 1;
	}

    void fileIO::close(RAL::String alias) {

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

        files = reinterpret_cast<RAL_FILE_ENTRY*>(realloc(files, sizeof(RAL_FILE_ENTRY) * (openFiles - 1)));
        openFiles -= 1;
    }

    bool fileIO::stringCompare(RAL::String a, RAL::String b) {

        /* three levels of nesting is fine ~1nome */
        if(a.size() == b.size()){
            for(u32_t i = 0; i < a.size(); i++){
                if(a.c_str()[i] != b.c_str()[i])
                    return false;
            }
            return true;
        }
        return false;
    }

    i16_t fileIO::findIndex(RAL::String alias){

        RAL_FILE_SCANTHRU{
            RAL_FILE_ISALIAS{
                return i;
            }
        }
        return -1;
    }

    RAL::String fileIO::readln(RAL::String alias){

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
            buf = reinterpret_cast<char*>(malloc(1024));
            fscanf(files[i].y.y, "%s\n", buf);

            buf2.recreate(buf);
            free(buf);
            return buf2;
        }
    }

    void fileIO::println(RAL::String alias, RAL::String string){

        i16_t i = findIndex(alias);
        if(i == -1){
            RAL_LOG_ERROR("File alias not found!");
            return;
        }
        fprintf(files[i].y.y, "%s\n", string.c_str());
    }
    void fileIO::println(RAL::String alias, i64_t num){

        i16_t i = findIndex(alias);
        if(i == -1){
            RAL_LOG_ERROR("File alias not found!");
            return;
        }
        fprintf(files[i].y.y, "%lld", num);
    }
    void fileIO::println(RAL::String alias, f64_t num){

        i16_t i = findIndex(alias);
        if(i == -1){
            RAL_LOG_ERROR("File alias not found!");
            return;
        }
        fprintf(files[i].y.y, "%lf", num);
    }

    void fileIO::printFileUsage(){

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

	void fileIO::maxFile(i16_t count) {

        if(count < openFiles) {
            RAL_LOG_ERROR("Cant decrease the maximum number of open files now! Need to close some prior to decreasing.");
            return;
        }
        RAL_LOG_TRACE("Maximum number of open files changed to %h", count);
		_setmaxstdio(count);
	}
}
