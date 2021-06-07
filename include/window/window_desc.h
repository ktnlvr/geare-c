#ifndef __GEARE_WINDOW_DESC__H__
#define __GEARE_WINDOW_DESC__H__

#include <stdint.h>

typedef struct geare_window_desc {
    const char* window_title;
    uint32_t x, y;
    uint32_t height, width;
} geare_window_desc;

#endif