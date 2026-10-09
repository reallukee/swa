//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  export.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_UTILS_EXPORT_H
#define LIBSWA16_UTILS_EXPORT_H

// #define LIBSWA16_LIB

#ifdef __cplusplus
    #define LIBSWA16_EXTERN extern "C"
#else
    #define LIBSWA16_EXTERN extern
#endif // __cplusplus

#ifdef LIBSWA16_LIB
    #if defined(_WIN32) || defined(_WIN64)
        #define LIBSWA16_DLL __declspec(dllexport)
    #else
        #define LIBSWA16_DLL
    #endif // _WIN32 || _WIN64

    #define LIBSWA16_API LIBSWA16_EXTERN LIBSWA16_DLL
#else
    #if defined(_WIN32) || defined(_WIN64)
        #define LIBSWA16_DLL __declspec(dllimport)
    #else
        #define LIBSWA16_DLL
    #endif // _WIN32 || _WIN64

    #define LIBSWA16_API LIBSWA16_EXTERN LIBSWA16_DLL
#endif // LIBSWA16_LIB

#endif // !LIBSWA16_UTILS_EXPORT_H
