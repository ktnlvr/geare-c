#include "../include/engine/app.h"
#include "../include/window/window.h"

void tick() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glViewport(0, 0, 256, 256);

    geare_swap_buffers();
}

void init() { geare_show_window(); }

void kill() { geare_close_window(); }

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
    engine_ptr->callback_table.kill = kill;
    ;

    geare_run();

    return 0;
}
