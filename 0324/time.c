#include "time.h"
struct timeval {
	long tv_sec;
	long tv_usec;
}

int gettimeofday(struct timeval *tv, NULL);
