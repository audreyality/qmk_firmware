UF2_DEVICE_TYPE_ID = 0x35446147
UF2CONV_ARGS = --device-type $(UF2_DEVICE_TYPE_ID)

SRC += lib/common.c lib/mux.c lib/audreyality/audreyality.c

ANALOG_DRIVER_REQUIRED = yes
