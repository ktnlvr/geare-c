
#include <GLES3/gl3.h>

#include "../include/engine/app.h"
#include "../include/window/window.h"

unsigned int buffer;

void init() {
    geare_show_window();

    float positions[6] = {-.5, -.5, 0, .5, .5, -.5};

    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), &positions,
                 GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void tick() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);

    geare_swap_buffers();
}

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
