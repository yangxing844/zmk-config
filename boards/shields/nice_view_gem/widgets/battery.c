#include <zephyr/kernel.h>
#include "battery.h"
#include "../assets/custom_fonts.h"

LV_IMG_DECLARE(bolt);
LV_IMG_DECLARE(l_battery_100);
LV_IMG_DECLARE(l_battery_90);
LV_IMG_DECLARE(l_battery_75);
LV_IMG_DECLARE(l_battery_50);
LV_IMG_DECLARE(l_battery_25);
LV_IMG_DECLARE(l_battery_10);


static void draw_level(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_image_dsc_t img_dsc_l;
    lv_draw_image_dsc_init(&img_dsc_l);

    uint8_t level = state->battery;
    if (level > 90) {
        canvas_draw_img(canvas, 8, 10, &l_battery_100, &img_dsc_l);
    } else if (level > 75) {
        canvas_draw_img(canvas, 8, 10, &l_battery_90, &img_dsc_l);
    } else if (level > 50) {
        canvas_draw_img(canvas, 8, 10, &l_battery_75, &img_dsc_l);
    } else if (level > 25) {
        canvas_draw_img(canvas, 8, 10, &l_battery_50, &img_dsc_l);
    } else if (level > 10) {
        canvas_draw_img(canvas, 8, 10, &l_battery_25, &img_dsc_l);
    } else if (level > 1) {
        canvas_draw_img(canvas, 8, 10, &l_battery_10, &img_dsc_l);
    }

}

void draw_battery_status(lv_obj_t *canvas, const struct status_state *state) {
    draw_level(canvas, state);
}