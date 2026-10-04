#ifndef _PROF_LINUX_H
#define _PROF_LINUX_H

#include <stdint.h>
#include <x86intrin.h>

typedef int64_t Prof_Int64;

static 
#ifdef __cplusplus
inline
#endif

void Prof_get_timestamp(Prof_Int64 *result) {
    __rdtscp((unsigned int*)result);
}

#endif // _PROF_LINUX_H
