COPTS = -g -O0 -c -Wall -std=c99
OBS = DoubleLinkedList.o \
	main.o \

all: testprogram

testprogram: $(OBS)
	gcc $(OBS) -o testprogram

DoubleLinkedList.o: DoubleLinkedList.c DoubleLinkedList.h Makefile
	gcc $(COPTS) DoubleLinkedList.c

main.o: main.c Makefile
	gcc $(COPTS) main.c


clean:
	rm -f $(OBS)
	rm -f testprogram