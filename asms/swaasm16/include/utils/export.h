//
// --------
// SWA
// swaasm16
// 2.0
// --------
//  Stupid Wild Architecture
//  export.h
//
//  https://github.com/reallukee/swa
//

#ifndef SWAASM16_UTILS_EXPORT_H
#define SWAASM16_UTILS_EXPORT_H

// #define SWAASM16_LIB

#ifdef __cplusplus
    #define SWAASM16_EXTERN extern "C"
#else
    #define SWAASM16_EXTERN extern
#endif // __cplusplus

#ifdef SWAASM16_LIB
    #if defined(_WIN32) || defined(_WIN64)
        #define SWAASM16_DLL __declspec(dllexport)
    #else
        #define SWAASM16_DLL
    #endif // _WIN32 || _WIN64

    #define SWAASM16_API SWAASM16_EXTERN SWAASM16_DLL
#else
    #if defined(_WIN32) || defined(_WIN64)
        #define SWAASM16_DLL __declspec(dllimport)
    #else
        #define SWAASM16_DLL
    #endif // _WIN32 || _WIN64

    #define SWAASM16_API SWAASM16_EXTERN SWAASM16_DLL
#endif // SWAASM16_LIB

#endif // !SWAASM16_UTILS_EXPORT_H
