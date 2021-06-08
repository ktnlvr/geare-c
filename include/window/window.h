#ifndef __GEARE_WINDOW__H__
#define __GEARE_WINDOW__H__

#include "../platform.h"
#include "./window_desc.h"

void geare_make_window(geare_window_desc_t);
void geare_show_window();
void geare_close_window();
void geare_window_swap_buffers();

#ifdef GEARE_USE_LINUX
#include "./os/window_xlib.h"

static geare_window_state__xlib _geare_xlib_state;

void geare_make_window(geare_window_desc_t w) {
    geare_make_window__xlib(&_geare_xlib_state, w);
    return;
}

void geare_show_window() {
    geare_show_window__xlib(&_geare_xlib_state);
    return;
}

void geare_close_window() {
    geare_close_window__xlib(&_geare_xlib_state);
    return;
}

void geare_swap_buffers() {
    glXSwapBuffers(_geare_xlib_state.display, _geare_xlib_state.window);
}

#endif

#endif
