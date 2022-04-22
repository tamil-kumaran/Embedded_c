#Main application file name
 embedded_c = sensor
#Main hex file path in windows format
MAIN_HEX_PATH = C:\Users\TAMILKUMARAN\Documentation\project\sensor\$(embedded_c).hex

# Compiler and other Section
CC = avr-gcc
OBJCOPY = avr-objcopy.exe
AVRDUDE := avrdude

#Options for avr-gcc
CFLAGS = -g -Os -o

#Linking options for avr-gcc
LFLAGS = -Os -mmcu=atmega8 -o

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
SRC = $(embedded_c).c
SRC += 

# The headers files needed for building the application
INCLUDE = -I. 
INCLUDE += #add user defined application

# commands Section
Burn : Build
	$(AVRDUDE) $(DUDEFLAGS)

Build : $(embedded_c).elf
	$(OBJCOPY) $(HFLAGS) $< $(embedded_c).hex
	
$(embedded_c).elf: $(embedded_c).o
	$(CC) $(SRC) $(INCLUDE) $(LFLAGS) $@
	
$(embedded_c).o:$(SRC)
	$(CC) $^ $(INCLUDE) $(CFLAGS) $@
