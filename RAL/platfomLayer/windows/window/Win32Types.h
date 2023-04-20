#ifndef RAL_PROJECT_WIN32TYPES_H
#define RAL_PROJECT_WIN32TYPES_H

#include <core/utility/Types.h>
#include <Windows.h>
#include <Winuser.h>


namespace RAL
{
    namespace Win32
    {
        [[nodiscard]] Types::Codes TranslateToRalTypes(WPARAM wParam);
    }
}


#endif //RAL_PROJECT_WIN32TYPES_H
