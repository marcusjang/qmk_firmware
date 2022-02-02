/* Copyright 2019 Danny Nguyen <danny@keeb.io>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public Licens
e * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "marcus.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_MUTE,      KC_PGUP, KC_MPLY,   \
        C(S(KC_TAB)), KC_TAB,  C(KC_TAB), \
        LOWER,        KC_PGDN, RAISE      \
    ),
    [_LOWER] = LAYOUT(
        _______, _______, KC_STOP, \
        KC_MPRV, KC_MPLY, KC_MNXT, \
        _______, _______, _______ \
    ),
    [_RAISE] = LAYOUT(
        KC_BTN1, KC_MS_U, KC_BTN2, \
        KC_MS_L, KC_MS_D, KC_MS_R, \
        _______, KC_BTN3, _______ \
    ),
    [_ADJUST] = LAYOUT(
        RESET,   A(KC_F4), _______, \
        BL_TOGG, BL_STEP,  BL_BRTG, \
        _______, _______,  _______ \
    ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_WH_D);
        } else {
            tap_code(KC_WH_U);
        }
    }
}
