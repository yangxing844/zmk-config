#include <zephyr/kernel.h>
#include "battery_peripheral.h"
#include "../assets/custom_fonts.h"

LV_IMG_DECLARE(bolt);
LV_IMG_DECLARE(r_battery_100);
LV_IMG_DECLARE(r_battery_90);
LV_IMG_DECLARE(r_battery_75);
LV_IMG_DECLARE(r_battery_50);
LV_IMG_DECLARE(r_battery_25);
LV_IMG_DECLARE(r_battery_10);


static void draw_level_peripheral(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_image_dsc_t img_dsc_r;
    lv_draw_image_dsc_init(&img_dsc_r);

    uint8_t level = state->battery_p;
    if (level > 90) {
        canvas_draw_img(canvas, 80, 10, &r_battery_100, &img_dsc_r);
    } else if (level > 75) {
        canvas_draw_img(canvas, 80, 10, &r_battery_90, &img_dsc_r);
    } else if (level > 50) {
        canvas_draw_img(canvas, 80, 10, &r_battery_75, &img_dsc_r);
    } else if (level > 25) {
        canvas_draw_img(canvas, 80, 10, &r_battery_50, &img_dsc_r);
    } else if (level > 10) {
        canvas_draw_img(canvas, 80, 10, &r_battery_25, &img_dsc_r);
    } else if (level > 1) {
        canvas_draw_img(canvas, 80, 10, &r_battery_10, &img_dsc_r);
    }
}

void draw_battery_peripheral_status(lv_obj_t *canvas, const struct status_state *state) {
    draw_level_peripheral(canvas, state);
}
