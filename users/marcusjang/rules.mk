MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = yes
#COMMAND_ENABLE = no
ifneq ($(MCU), atmega32a)
	NKRO_ENABLE = yes
endif

SRC += marcus.c