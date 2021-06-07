#include "../include/engine/app.h"
#include "../include/window/window.h"

/* Nothin', just chillin' */
void tick() { ; }

void init() { geare_show_window(); }

int main() {
    geare_app_desc_t app_desc = {};

    geare_window_desc_t w_desc = {.height = 256,
                                  .width = 256,
                                  .x = 256,
                                  .y = 256,
                                  .window_title = "Test Window"};

    geare_make_window(w_desc);

    geare_engine_create(app_desc, nullptr);

    geare_engine_t* engine_ptr = geare_engine_instance();
    engine_ptr->callback_table.init = init;
    engine_ptr->callback_table.tick = tick;

    geare_run();

    return 0;
}
