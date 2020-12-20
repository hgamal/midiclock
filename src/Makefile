#
# MCU Code Makefile by Haroldo Gamal
#

# default HFUSE: avrdude -c usbasp -pm16 -v -B16 -U lfuse:w:0x99:m
# default LFUSE: avrdude -c usbasp -pm16 -v -B16 -U lfuse:w:0xe1:m

MCU=atmega32u4
TARGET=midiclock.hex

BUILD_DIR = build

CCOPTS=-Os -D__AVR__ -DF_CPU=16000000UL -mmcu=$(MCU) -ffunction-sections -fdata-sections -I ../u8glib/csrc -I ../u8glib/cppsrc -I ../u8glib/nonarduino
CPPOPTS=-fno-threadsafe-statics -fno-exceptions 
#CCOPTS=-Os -DF_CPU=16000000UL -mmcu=$(MCU) -DXDEBUG -I ../u8glib/csrc -I ../u8glib/cppsrc -I ../u8glib/nonarduino
#CCOPTS=-Os -DF_CPU=8000000UL -mmcu=$(MCU) -DXDEBUG -I../u8g2/csrc/
# PGMOPT=-D -B8 -v -pm32u4 -cavr109 -P/dev/ttyACM0 -b57600
PGMPORT=/dev/ttyACM0
PGMOPT=-D -v -patmega32u4 -cavr109 -P${PGMPORT} -b57600

# U8glib path to c source files
U8GPATH:=$(abspath ../u8glib/csrc/)
U8GFONTPATH:=$(abspath ../u8glib/fntsrc)
U8GCPPPATH:=$(abspath ../u8glib/cppsrc/)
#U8GNARDUINOPATH:=$(abspath ../u8glib/nonarduino)

# U8G Source files
U8GCSRCS:=$(wildcard $(U8GPATH)/*.c) $(wildcard $(U8GFONTPATH)/*.c) $(wildcard $(U8GCPPPATH)/*.c) 
U8GCPPSRCS:=$(wildcard $(U8GCPPPATH)/*.cpp)
U8GOBJS:= $(addprefix $(BUILD_DIR)/, $(notdir $(U8GCSRCS:.c=.o))) $(addprefix $(BUILD_DIR)/, $(notdir $(U8GCPPSRCS:.cpp=.o)))

vpath %.cpp $(U8GCPPPATH):$(U8GNARDUINOPATH)
vpath %.c $(U8GPATH):$(U8GFONTPATH)
vpath %.h $(U8GPATH):$(U8GFONTPATH)
vpath %.o $(BUILD_DIR)

all: $(BUILD_DIR) $(TARGET)  $(BUILD_DIR)/libu8g.a

SOURCES = arduino_io.cpp timer0.cpp uart.cpp debounce.cpp micro_panel.cpp midi_clock.cpp midi_state.cpp squeue.cpp main.cpp 

OBJS = $(addprefix $(BUILD_DIR)/, $(SOURCES:.cpp=.o))

ELF = $(basename $(TARGET)).elf

$(BUILD_DIR)/%.o: %.c
	avr-gcc ${CCOPTS} -o $@ -c $<

$(BUILD_DIR)/%.o: %.cpp
	avr-g++ ${CCOPTS} ${CPPOPTS} -o $@ -c $<

$(TARGET):	$(ELF) $(BUILD_DIR)
	avr-objcopy -O ihex -R .eeprom $(ELF) $(TARGET)

#avr-objcopy" -O ihex -j .eeprom --set-section-flags=.eeprom=alloc,load --no-change-warnings --change-section-lma .eeprom=0  "/tmp/arduino_build_699981/midiclock.ino.elf" "/tmp/arduino_build_699981/midiclock.ino.eep"
#avr-objcopy" -O ihex -R .eeprom  "/tmp/arduino_build_699981/midiclock.ino.elf" "/tmp/arduino_build_699981/midiclock.ino.hex"

$(ELF):	${OBJS} $(BUILD_DIR)/libu8g.a
	avr-gcc ${CCOPTS} -L${BUILD_DIR} -fuse-linker-plugin  -Wl,--gc-sections -Wl,-Map,$(basename $@).map -o $@ ${OBJS} -lu8g
	avr-size --mcu=atmega32u4 $(ELF)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/libu8g.a: $(U8GOBJS)
	$(AR) -r $@ $(U8GOBJS)

status:
	avrdude ${PGMOPT}

program: $(TARGET)
	stty -F ${PGMPORT} 1200
	avrdude ${PGMOPT} -U flash:w:$(TARGET):i
	stty -F ${PGMPORT} 1200

pgmread:
	avrdude ${PGMOPT} -U flash:r:read.hex:i

clean:
	-rm *.map  ${OBJS} $(ELF) ${TARGET}
	-rm -fR .dep $(BUILD_DIR) $(U8GOBJS)

dfu: $(TARGET)
	-dfu-programmer $(MCU) erase --force
	dfu-programmer $(MCU) flash $(TARGET)
	-dfu-programmer $(MCU) launch
