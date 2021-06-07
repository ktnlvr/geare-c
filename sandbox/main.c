#include "../include/engine/app.h"
#include "../include/window/os/window_xlib.h"

static geare_window_state_xlib window_state;

/* Nothin', just chillin' */
void tick() { ; }

void init() {
    geare_create_window_xlib(&window_state);
    geare_show_window_xlib(&window_state);
}

int main() {
    geare_app_desc_t desc = {
        .window_title = "Test Window",
        .height = 256,
        .width = 256,
    };

    geare_engine_create(desc, nullptr);

    geare_engine_t* engine_ptr = geare_engine_instance();
    engine_ptr->callback_table.init = init;
    engine_ptr->callback_table.tick = tick;

    geare_run();

    return 0;
}
