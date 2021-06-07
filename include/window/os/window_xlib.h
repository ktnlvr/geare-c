#include <X11/Xlib.h>

typedef struct geare_window_state_xlib {
    Display* display;
    Screen* screen;
    Window rootWindow, window;
} geare_window_state_xlib;

void geare_create_window_xlib(geare_window_state_xlib* target) {
    target->display = XOpenDisplay(NULL);
    target->screen = DefaultScreenOfDisplay(target->display);
    target->rootWindow = DefaultRootWindow(target->display);
    target->window =
        XCreateWindow(target->display, target->rootWindow, 0, 0, 256, 256, 0, 0,
                      CopyFromParent, CopyFromParent, 0, NULL);
}

void geare_show_window_xlib(geare_window_state_xlib* target) {
    XMapWindow(target->display, target->window);
    XFlush(target->display);
}

void geare_close_window_xlib(geare_window_state_xlib* target) {
    XDestroyWindow(target->display, target->window);
    XCloseDisplay(target->display);
}
