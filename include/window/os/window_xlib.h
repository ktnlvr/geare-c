#include "../../platform.h"
#include "../window_desc.h"

#ifdef GEARE_USE_LINUX

#ifndef __GEARE_WINDOW_OS_XLIB__H__
#define __GEARE_WINDOW_OS_XLIB__H__

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glx.h>
#include <X11/X.h>
#include <X11/Xlib.h>

#ifndef X_PROTOCOL
#error Your linux machine does not support Xlib, which geare did not expect to happen
#endif

typedef struct geare_window_state__xlib {
    Display* display;
    Screen* screen;
    Window rootWindow, window;
    Colormap cmap;
    XVisualInfo* vi;
    GLint* att;
    XSetWindowAttributes swa;
    GLXContext glc;
} geare_window_state__xlib;

void geare_make_window__xlib(geare_window_state__xlib* target,
                             geare_window_desc_t desc) {
    target->display = XOpenDisplay(NULL);
    target->screen = DefaultScreenOfDisplay(target->display);
    target->rootWindow = DefaultRootWindow(target->display);

    static GLint att[] = {GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None};
    target->att = att;

    /* TODO: detect the actual screen number if it's not too much trouble */
    target->vi = glXChooseVisual(target->display, 0, target->att);

    target->cmap = XCreateColormap(target->display, target->rootWindow,
                                   target->vi->visual, AllocNone);

    target->swa.colormap = target->cmap;
    target->swa.event_mask = ExposureMask | KeyPressMask;

    target->window = XCreateWindow(
        target->display, target->rootWindow, desc.x, desc.y, desc.width,
        desc.height, 0, target->vi->depth, InputOutput, target->vi->visual,
        CWColormap | CWEventMask, &target->swa);

    target->glc = glXCreateContext(target->display, target->vi, NULL, GL_TRUE);
    glXMakeCurrent(target->display, target->window, target->glc);
    glEnable(GL_DEPTH_TEST);

    XStoreName(target->display, target->window, (char*)desc.window_title);
}

void geare_show_window__xlib(geare_window_state__xlib* target) {
    XMapWindow(target->display, target->window);
    XFlush(target->display);
}

void geare_close_window__xlib(geare_window_state__xlib* target) {
    glXMakeCurrent(target->display, None, NULL);
    glXDestroyContext(target->display, target->glc);
    XDestroyWindow(target->display, target->window);
    XCloseDisplay(target->display);
}

#endif

#endif
