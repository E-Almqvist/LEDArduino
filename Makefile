ARDUINO_DIR = /usr/share/arduino
ARDUINO_PORT = /dev/ttyACM*

ARDUINO_PLATFORM_LIB_PATH = /usr/share/arduino/hardware/archlinux-arduino/avr/libraries
ARDUINO_VAR_PATH = /usr/share/arduino/hardware/archlinux-arduino/avr/variants
ARDUINO_CORE_PATH = /usr/share/arduino/hardware/archlinux-arduino/avr/cores/arduino

USER_LIB_PATH = /home/elal/Projects/LEDArduino/libraries
BOARDS_TXT = /usr/share/arduino/hardware/archlinux-arduino/avr/boards.txt
BOARD_TAG = uno

include /usr/share/arduino/Arduino.mk
