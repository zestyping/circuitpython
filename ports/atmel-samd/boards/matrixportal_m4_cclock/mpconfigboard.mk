USB_VID = 0x239A
USB_PID = 0x80CA
USB_PRODUCT = "Matrix Portal M4"
USB_MANUFACTURER = "Adafruit Industries LLC"

CHIP_VARIANT = SAMD51J19A
CHIP_FAMILY = samd51

QSPI_FLASH_FILESYSTEM = 1
EXTERNAL_FLASH_DEVICES = "S25FL116K, S25FL216K, GD25Q16C"
LONGINT_IMPL = MPZ

CIRCUITPY_AESIO = 0
CIRCUITPY_ONEWIREIO = 0
CIRCUITPY_PARALLELDISPLAY = 0
CIRCUITPY_SDCARDIO = 0
CIRCUITPY_SHARPDISPLAY = 0
# CIRCUITPY_TRACEBACK = 0
# CIRCUITPY_ZLIB=0

# Include these Python libraries in firmware.
FROZEN_MPY_DIRS += $(TOP)/frozen/Adafruit_CircuitPython_Requests
FROZEN_MPY_DIRS += $(TOP)/frozen/Adafruit_CircuitPython_ESP32SPI
FROZEN_MPY_DIRS += $(TOP)/frozen/Adafruit_CircuitPython_NeoPixel


# Remove more libraries we don't need
# See https://circuitpython.org/board/matrixportal_m4/ for a list of included modules
# See py/circuitpy_defns.mk for their equivalent #defines
CIRCUITPY_AUDIOBUSIO = 0
CIRCUITPY_AUDIOCORE = 0
CIRCUITPY_AUDIOIO = 0
CIRCUITPY_AUDIOMIXER = 0
CIRCUITPY_AUDIOMP3 = 0
# CIRCUITPY_BINASCII = 0  # used by Adafruit_CircuitPython_Hashlib
# CIRCUITPY_BLEIO = 0  # used in main.c
CIRCUITPY_COUNTIO = 0
CIRCUITPY_FLOPPYIO = 0
CIRCUITPY_GETPASS = 0
CIRCUITPY_GIFIO = 0
CIRCUITPY_KEYPAD = 0
CIRCUITPY_MSGPACK = 0
CIRCUITPY_NVM = 0
CIRCUITPY_PS2IO = 0
CIRCUITPY_PULSEIO = 0
CIRCUITPY_RANDOM = 0
CIRCUITPY_SYNTHIO = 0
CIRCUITPY_TOUCHIO = 0
CIRCUITPY_USB_HID = 0
CIRCUITPY_USB_MIDI = 0
CIRCUITPY_VECTORIO = 0

# Add libraries we do want
FROZEN_MPY_DIRS += $(TOP)/frozen/Adafruit_CircuitPython_Bitmap_Font
FROZEN_MPY_DIRS += $(TOP)/frozen/Adafruit_CircuitPython_datetime
FROZEN_MPY_DIRS += $(TOP)/frozen/Adafruit_CircuitPython_Display_Text
FROZEN_MPY_DIRS += $(TOP)/frozen/Adafruit_CircuitPython_DS3231
FROZEN_MPY_DIRS += $(TOP)/frozen/Adafruit_CircuitPython_Hashlib
FROZEN_MPY_DIRS += $(TOP)/frozen/Adafruit_CircuitPython_MatrixPortal
# FROZEN_MPY_DIRS += $(TOP)/frozen/Adafruit_CircuitPython_Register
