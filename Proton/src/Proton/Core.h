#pragma once

#ifdef PN_PLATFORM_WINDOWS
    #ifdef PN_BUILD_DLL
        #define PROTON_API __declspec(dllexport)
    #else
        #define PROTON_API __declspec(dllimport)
    #endif
#else
    #define PROTON_API
#endif
