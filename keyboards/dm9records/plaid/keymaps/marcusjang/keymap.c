#include QMK_KEYBOARD_H
#include "quantum.h"
#include "marcus.h"

#define NO_NKRO_SUPPORT
#include "keymap_4x12_grid.h"

void matrix_scan_user(void) {
    uint8_t layer = biton32(layer_state);
    /*
      DDRC  &= ~(1 << 5);
      DDRC  &= ~(1 << 4);
      PORTC &= ~(1 << 5);
      PORTC &= ~(1 << 4);

    if (layer == _LOWER) {
      // turn on
      DDRC  |= (1 << 5);
      PORTC |= (1 << 5);
    } else if (layer == _RAISE) {
      // turn on
      DDRC  |= (1 << 4);
      PORTC |= (1 << 4);
    } else if (layer == _ADJUST) {
      // turn on
      DDRC  |= (1 << 5);
      DDRC  |= (1 << 4);
      PORTC |= (1 << 5);
      PORTC |= (1 << 4);
    }
    */

    if (layer == _ADJUST) {
      // turn on
      DDRC  |= (1 << 5);
      PORTC |= (1 << 5);
    
    } else {
      // turn off
      DDRC  &= ~(1 << 5);
      PORTC &= ~(1 << 5);

    }
}