#include "backlight.h"
#include "quantum.h"

// Port D: digital pins of the AVR chipset
#define NUMLOCK_PORT    (1 << 0)  // D0
#define CAPSLOCK_PORT   (1 << 1)  // D1
#define BACKLIGHT_PORT  (1 << 4)  // D4
#define SCROLLLOCK_PORT (1 << 6)  // D6

void led_set_kb(uint8_t usb_led) {
  #ifndef DISABLE_NUMLOCK_LED
    if (usb_led & (1 << USB_LED_NUM_LOCK)) {
      // turn on
      DDRD  |= NUMLOCK_PORT;
      PORTD |= NUMLOCK_PORT;
    } else {
      // turn off
      DDRD  &= ~NUMLOCK_PORT;
      PORTD &= ~NUMLOCK_PORT;
    }
  #else
    DDRD  &= ~NUMLOCK_PORT;
    PORTD &= ~NUMLOCK_PORT;
  #endif

  #ifndef DISABLE_CAPSLOCK_LED
    if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
      DDRD  |= CAPSLOCK_PORT;
      PORTD |= CAPSLOCK_PORT;
    } else {
      DDRD  &= ~CAPSLOCK_PORT;
      PORTD &= ~CAPSLOCK_PORT;
    }
  #else
    DDRD  &= ~CAPSLOCK_PORT;
    PORTD &= ~CAPSLOCK_PORT;
  #endif

  #ifndef DISABLE_SCROLLLOCK_LED
    if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
      DDRD  |= SCROLLLOCK_PORT;
      PORTD |= SCROLLLOCK_PORT;
    } else {
      DDRD  &= ~SCROLLLOCK_PORT;
      PORTD &= ~SCROLLLOCK_PORT;
    }
  #else
    DDRD  &= ~SCROLLLOCK_PORT;
    PORTD &= ~SCROLLLOCK_PORT;
  #endif
}
