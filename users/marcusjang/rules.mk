MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
NO_USB_STARTUP_CHECK = yes

#COMMAND_ENABLE = no

ifneq ($(MCU), atmega32a)
	NKRO_ENABLE = yes
endif

SRC += marcusjang.c