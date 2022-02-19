#ifndef CONFIG_USER_H

#define CONFIG_USER_H

#define PERMISSIVE_HOLD
#undef IGNORE_MOD_TAP_INTERRUPT	

#define QMK_KEYS_PER_SCAN 6
#define USB_POLLING_INTERVAL_MS 1

#undef MOUSEKEY_DELAY
#undef MOUSEKEY_INTERVAL
#undef MOUSEKEY_MAX_SPEED
#undef MOUSEKEY_TIME_TO_MAX
#undef MOUSEKEY_WHEEL_DELAY
#undef MOUSEKEY_WHEEL_INTERVAL
#undef MOUSEKEY_WHEEL_MAX_SPEED
#undef MOUSEKEY_WHEEL_TIME_TO_MAX

#define MOUSEKEY_DELAY              50
#define MOUSEKEY_INTERVAL           16
#define MOUSEKEY_MAX_SPEED          4
#define MOUSEKEY_TIME_TO_MAX        50
#define MOUSEKEY_WHEEL_DELAY		50
#define MOUSEKEY_WHEEL_INTERVAL		48
#define MOUSEKEY_WHEEL_MAX_SPEED    16
#define MOUSEKEY_WHEEL_TIME_TO_MAX  50

#undef RGBLIGHT_ANIMATIONS
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_STATIC_GRADIENT

#endif
