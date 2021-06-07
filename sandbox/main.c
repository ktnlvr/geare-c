#include "../include/engine/app.h"

// Nothin', just chillin'
void tick() { ; }

int main() {
    geare_app_desc_t desc = {
        .window_title = "Test Window",
        .height = 256,
        .width = 256,
    };

    geare_engine_create(desc, nullptr);

    geare_engine_t* engine_ptr = geare_engine_instance();
    engine_ptr->callback_table.tick = tick;

    geare_run();

    return 0;
}
