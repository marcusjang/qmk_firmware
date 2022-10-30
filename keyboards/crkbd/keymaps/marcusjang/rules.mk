BOOTLOADER      = qmk-dfu
USER_NAME      := none
MOUSEKEY_ENABLE = yes
#NKRO_ENABLE     = yes
RGBLIGHT_ENABLE = yes    # Enable WS2812 RGB underlight.
OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306
LTO_ENABLE      = yes

CONSOLE_ENABLE = no
COMMAND_ENABLE = no
#MOUSEKEY_ENABLE = no
EXTRAKEY_ENABLE = no



# If you want to change the display of OLED, you need to change here
#SRC +=  ./lib/glcdfont.c \
#        ./lib/rgb_state_reader.c \
#        ./lib/layer_state_reader.c \
#        ./lib/logo_reader.c \
#        ./lib/keylogger.c \
        # ./lib/mode_icon_reader.c \
        # ./lib/host_led_state_reader.c \
        # ./lib/timelogger.c \
