#include "../../platform.h"
#include "../window_desc.h"

#ifdef GEARE_USE_LINUX

#ifndef __GEARE_WINDOW_OS_XLIB__H__
#define __GEARE_WINDOW_OS_XLIB__H__

#include <X11/Xlib.h>

#ifndef X_PROTOCOL
#error Your linux machine does not support Xlib, which geare did not expect to happen
#endif

typedef struct geare_window_state__xlib {
    Display* display;
    Screen* screen;
    Window rootWindow, window;
} geare_window_state__xlib;

void geare_make_window__xlib(geare_window_state__xlib* target,
                             geare_window_desc desc) {
    target->display = XOpenDisplay(NULL);
    target->screen = DefaultScreenOfDisplay(target->display);
    target->rootWindow = DefaultRootWindow(target->display);
    target->window =
        XCreateWindow(target->display, target->rootWindow, 0, 0, 256, 256, 0, 0,
                      CopyFromParent, CopyFromParent, 0, NULL);
}

void geare_show_window__xlib(geare_window_state__xlib* target) {
    XMapWindow(target->display, target->window);
    XFlush(target->display);
}

void geare_close_window__xlib(geare_window_state__xlib* target) {
    XDestroyWindow(target->display, target->window);
    XCloseDisplay(target->display);
}

#endif

#endif
