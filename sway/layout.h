#ifndef _SWAY_LAYOUT_H
#define _SWAY_LAYOUT_H

#include <wlc/wlc.h>
#include "list.h"

struct sway_container {
    wlc_handle handle;

    enum {
        C_ROOT,
        C_OUTPUT,
        C_WORKSPACE,
        C_CONTAINER,
        C_VIEW
    } type;

    enum {
        L_NONE,
        L_HORIZ,
        L_VERT,
        L_STACKED,
        L_TABBED,
        L_FLOATING
    } layout;

    // Not including borders or margins
    int width, height;

    char *name;

    list_t *children;

    struct sway_container *parent;
    struct sway_container *focused;
};

typedef struct sway_container swayc_t;

extern swayc_t root_container;

void init_layout();
void add_output(wlc_handle output);
void destroy_output(wlc_handle output);
void destroy_view(swayc_t *view);
void add_view(wlc_handle view);
void focus_view(swayc_t *view);

swayc_t *get_swayc_for_handle(wlc_handle handle, swayc_t *parent);

#endif
