#include <malloc.h>
#include <stdint.h>

#include "../def.h"

// Application descriptor, responsible for all the system-dependent application
// properties e.g. window title
typedef struct geare_app_desc_t {
} geare_app_desc_t;

// Contains all the engine data and information
typedef struct geare_engine_ctx_t {
    geare_app_desc_t desc;
    geare_bool is_running;
} geare_engine_ctx_t;

// Contains callbacks to all the app stages
typedef struct geare_app_callback_table_t {
    void (*init)();
    void (*tick)();
    void (*kill)();
} geare_app_callback_table_t;

typedef struct geare_engine_t {
    // A generic pointer to custom user data
    void* data;
    // Engine context
    geare_engine_ctx_t ctx;
    // Callbacks
    geare_app_callback_table_t callback_table;
} geare_engine_t;

static geare_engine_t* _instance;

#define geare_engine_instance() _instance;

// Constructor for the engine instance
void geare_engine_create(geare_app_desc_t desc, void* data) {
    _instance = (geare_engine_t*)malloc(sizeof(geare_engine_t));
    _instance->ctx.desc = desc;
    _instance->data = data;
    _instance->ctx.is_running = False;
}

void geare_run() {
    geare_app_callback_table_t table = _instance->callback_table;
    _instance->ctx.is_running = True;

    if (table.init) table.init();

    while (_instance->ctx.is_running) {
        table.tick();
    }

    if (table.kill) table.kill();
}