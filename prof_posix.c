#include <assert.h>
#include <unistd.h>
#include <time.h>

double Prof_get_time(void)
{
    struct timespec tp = {0};
    int ret = clock_gettime(CLOCK_MONOTONIC, &tp);
    assert(ret == 0);
    return tp.tv_sec + tp.tv_nsec*1e-9;
}
