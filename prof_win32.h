#ifndef Prof_INC_PROF_WIN32_H
#define Prof_INC_PROF_WIN32_H

#include <stdint.h>
typedef int64_t Prof_Int64;

#ifndef _MSC_VER
#include <x86intrin.h>
#endif

#ifdef __cplusplus
  inline
#elif _MSC_VER >= 1200
  __forceinline
#else
  static
#endif
      void Prof_get_timestamp(Prof_Int64 *result)
      {
#ifdef _MSC_VER
         __asm {
            rdtsc;
            mov    ebx, result
            mov    [ebx], eax
            mov    [ebx+4], edx
         }
#else
        *result = __rdtsc();
#endif

      }

#endif
