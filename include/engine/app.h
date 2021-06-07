#include <malloc.h>
#include <stdint.h>

#include "../def.h"

// Application descriptor, responsible for all the system-dependent application
// properties e.g. window title
typedef struct geare_app_desc_t {
    const char* window_title;
    uint32_t width, height;
    uint64_t flags;
} geare_app_desc_t;

// Contains all the engine data and information
typedef struct geare_engine_ctx_t {
    geare_app_desc_t desc;
    geare_bool is_running;
} geare_engine_ctx_t;

typedef struct geare_engine_t {
    // A generic pointer to custom user data
    void* data;
    // Engine context
    geare_engine_ctx_t ctx;
} geare_engine_t;

static geare_engine_t* _instance;

#define geare_engine_instance() _instance;

// Constructor for the engine instance
void geare_engine_create(geare_app_desc_t desc) {
    _instance = (geare_engine_t*)malloc(sizeof(geare_engine_t));
    _instance->ctx.desc = desc;
}
