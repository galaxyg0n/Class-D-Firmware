MAIN_APP = ClassDFirmware

SOURCE_PATH =  src
BUILD_DIR =    build
CUSTOM_INCLUDE = includes

MAIN_HEX_PATH = $(BUILD_DIR)/$(MAIN_APP).hex

# Compiler and other Section
CC = avr-gcc
OBJCOPY = avr-objcopy.exe
AVRDUDE := avrdude

#Options for avr-gcc
CFLAGS = -g -Os -o

#Linking options for avr-gcc
LFLAGS = -Os -mmcu=atmega328p -o

#Options for HEX file generation
HFLAGS = -j .text -j .data -O ihex

#Options for avrdude to burn the hex file
#MMCU model here according to avrdude options
DUDEFLAGS = -c
DUDEFLAGS += arduino 
DUDEFLAGS += -p
DUDEFLAGS += m8  
DUDEFLAGS += -P 
DUDEFLAGS += COM3 
DUDEFLAGS += -b 
DUDEFLAGS += 19200 
DUDEFLAGS += -U flash:w:$(MAIN_HEX_PATH):i

# Sources files needed for building the application 
SRC = ./src/$(MAIN_APP).c
SRC += 

# The headers files needed for building the application
INCLUDE = -I. 
INCLUDE += $(CUSTOM_INCLUDE)/ClassDFirmware.h

# commands Section
burn : Build
	$(AVRDUDE) $(DUDEFLAGS)

build : ./build/$(MAIN_APP).elf
	$(OBJCOPY) $(HFLAGS) $< ./build/$(MAIN_APP).hex
	
./build/$(MAIN_APP).elf: ./build/$(MAIN_APP).o
	$(CC) $(SRC) $(INCLUDE) $(LFLAGS) $@

./build/$(MAIN_APP).o:$(SRC)
	$(CC) $^ $(INCLUDE) $(CFLAGS) $@
	
.PHONY : clean
clean :
	@echo "Cleaning build folder"
	rm $(BUILD_DIR)/$(MAIN_APP).o $(BUILD_DIR)/$(MAIN_APP).hex $(BUILD_DIR)/$(MAIN_APP).elf
	@echo "Build folder clean"
