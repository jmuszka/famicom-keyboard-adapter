MCU=atmega32u4
AVR=m32u4
PORT=/dev/ttyACM0
F_CPU=16000000
PROGRAMMER=avr109

all: main.hex

main.hex: main.elf
	avr-objcopy -O ihex -R .eeprom $< $@

main.elf: main.c 
	avr-gcc -mmcu=$(MCU) -DF_CPU=$(F_CPU)UL -Os -Wall -o $@ $<

flash: main.hex 
	avrdude -v -p $(MCU) -c $(PROGRAMMER) -P $(PORT) -U flash:w:$<

clean:
	rm -rf *.elf *.hex
