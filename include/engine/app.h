#include <stdint.h>

typedef struct geare_app_desc_t {
    const char* window_title;
    uint32_t width, height;
    uint64_t flags;
    uint8_t is_running;
} geare_app_desc_t;

typedef struct geare_engine_ctx {
    geare_app_desc_t desc;
} geare_engine_ctx;
