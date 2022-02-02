/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define EE_HANDS
#define SPLIT_USB_DETECT

#undef USE_I2C
#undef SSD1306OLED

#define USE_SERIAL_PD2

#define PERMISSIVE_HOLD
#undef IGNORE_MOD_TAP_INTERRUPT	

#define OLED_FONT_H "keyboards/crkbd/keymaps/marcus_nus/glcdfont.c"

#define TAPPING_TERM    200
#define TAPPING_TOGGLE  2

#define QMK_KEYS_PER_SCAN 12

#define MOUSEKEY_DELAY              50
#define MOUSEKEY_INTERVAL           15
#define MOUSEKEY_MAX_SPEED          4
#define MOUSEKEY_TIME_TO_MAX        50
#define MOUSEKEY_WHEEL_MAX_SPEED    1
#define MOUSEKEY_WHEEL_TIME_TO_MAX  50