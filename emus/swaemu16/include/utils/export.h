//
// --------
// SWA
// swaemu16
// 2.0
// --------
//  Stupid Wild Architecture
//  export.h
//
//  https://github.com/reallukee/swa
//

#ifndef SWAEMU16_UTILS_EXPORT_H
#define SWAEMU16_UTILS_EXPORT_H

// #define SWAEMU16_LIB

#ifdef __cplusplus
    #define SWAEMU16_EXTERN extern "C"
#else
    #define SWAEMU16_EXTERN extern
#endif // __cplusplus

#ifdef SWAEMU16_LIB
    #if defined(_WIN32) || defined(_WIN64)
        #define SWAEMU16_DLL __declspec(dllexport)
    #else
        #define SWAEMU16_DLL
    #endif // _WIN32 || _WIN64

    #define SWAEMU16_API SWAEMU16_EXTERN SWAEMU16_DLL
#else
    #if defined(_WIN32) || defined(_WIN64)
        #define SWAEMU16_DLL __declspec(dllimport)
    #else
        #define SWAEMU16_DLL
    #endif // _WIN32 || _WIN64

    #define SWAEMU16_API SWAEMU16_EXTERN SWAEMU16_DLL
#endif // SWAEMU16_LIB

#endif // !SWAEMU16_UTILS_EXPORT_H
