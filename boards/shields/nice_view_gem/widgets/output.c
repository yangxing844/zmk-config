#include <zephyr/kernel.h>
#include "output.h"
#include "../assets/custom_fonts.h"

LV_IMG_DECLARE(bt_no_signal);
LV_IMG_DECLARE(bt_unbonded);
LV_IMG_DECLARE(bt);
LV_IMG_DECLARE(usb);

#if !IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
static void draw_usb_connected(lv_obj_t *canvas) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_8, LV_TEXT_ALIGN_LEFT);
    canvas_draw_text(canvas, 12, 140, SCREEN_WIDTH-8, &label_dsc, "USB");
}
#endif

static void draw_ble_disconnected(lv_obj_t *canvas) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_8, LV_TEXT_ALIGN_LEFT);
    canvas_draw_text(canvas, 12, 140, SCREEN_WIDTH-8, &label_dsc, "NULL");
}

static void draw_ble_connected(lv_obj_t *canvas) {
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &quinquefive_8, LV_TEXT_ALIGN_LEFT);
    canvas_draw_text(canvas, 12, 140, SCREEN_WIDTH-8, &label_dsc, "BLE");
}

void draw_output_status(lv_obj_t *canvas, const struct status_state *state) {
    switch (state->selected_endpoint.transport) {
        case ZMK_TRANSPORT_USB:
            draw_usb_connected(canvas);
            break;
        case ZMK_TRANSPORT_BLE:
            draw_ble_connected(canvas);
            break;
        default:
            draw_ble_disconnected(canvas);
            break;
    }

    /*
    lv_draw_label_dsc_t label_dsc;
    init_label_dsc(&label_dsc, LVGL_FOREGROUND, &lcd_phone, LV_TEXT_ALIGN_LEFT);
    canvas_draw_text(canvas, 0, 1, 25, &label_dsc, "SIG");

    lv_draw_rect_dsc_t rect_white_dsc;
    init_rect_dsc(&rect_white_dsc, LVGL_FOREGROUND);
    canvas_draw_rect(canvas, 43, 0, 24, 15, &rect_white_dsc);

#if !IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
    switch (state->selected_endpoint.transport) {
    case ZMK_TRANSPORT_USB:
        draw_usb_connected(canvas);
        break;

    case ZMK_TRANSPORT_BLE:
        if (state->active_profile_bonded) {
            if (state->active_profile_connected) {
                draw_ble_connected(canvas);
            } else {
                draw_ble_disconnected(canvas);
            }
        } else {
            draw_ble_unbonded(canvas);
        }
        break;
    }
#else
    if (state->connected) {
        draw_ble_connected(canvas);
    } else {
        draw_ble_disconnected(canvas);
    }
#endif
*/
}