//
// --------
// SWA
// libswa16
// 2.0
// --------
//  Stupid Wild Architecture
//  macros.h
//
//  https://github.com/reallukee/swa
//

#ifndef LIBSWA16_UTILS_MACROS_H
#define LIBSWA16_UTILS_MACROS_H

// #define LIBSWA16_EXPERIMENTAL

#ifdef __cplusplus
    #define LIBSWA16_NAMESPACE_BEGIN namespace libswa16 {
    #define LIBSWA16_NAMESPACE_END   }
#else
    #define LIBSWA16_NAMESPACE_BEGIN
    #define LIBSWA16_NAMESPACE_END
#endif // !__cplusplus

#endif // !LIBSWA16_UTILS_MACROS_H
