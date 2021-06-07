#include "../include/engine/app.h"

int main() {
    geare_app_desc_t desc = {
        .window_title = "Test Window",
        .height = 256,
        .width = 256,
    };

    geare_engine_create(desc);

    geare_engine_t* engine_ptr = geare_engine_instance();

    return 0;
}
