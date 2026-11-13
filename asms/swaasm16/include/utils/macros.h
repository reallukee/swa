//
// --------
// SWA
// swaasm16
// 2.0
// --------
//  Stupid Wild Architecture
//  macros.h
//
//  https://github.com/reallukee/swa
//

#ifndef SWAASM16_UTILS_MACROS_H
#define SWAASM16_UTILS_MACROS_H

// #define SWAASM16_EXPERIMENTAL

#ifdef __cplusplus
    #define SWAASM16_NAMESPACE_BEGIN namespace swaasm16 {
    #define SWAASM16_NAMESPACE_END   }
#else
    #define SWAASM16_NAMESPACE_BEGIN
    #define SWAASM16_NAMESPACE_END
#endif // !__cplusplus

#endif // !SWAASM16_UTILS_MACROS_H
