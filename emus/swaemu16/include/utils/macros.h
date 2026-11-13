//
// --------
// SWA
// swaemu16
// 2.0
// --------
//  Stupid Wild Architecture
//  macros.h
//
//  https://github.com/reallukee/swa
//

#ifndef SWAEMU16_UTILS_MACROS_H
#define SWAEMU16_UTILS_MACROS_H

// #define SWAEMU16_EXPERIMENTAL

#ifdef __cplusplus
    #define SWAEMU16_NAMESPACE_BEGIN namespace swaemu16 {
    #define SWAEMU16_NAMESPACE_END   }
#else
    #define SWAEMU16_NAMESPACE_BEGIN
    #define SWAEMU16_NAMESPACE_END
#endif // !__cplusplus

#endif // !SWAEMU16_UTILS_MACROS_H
