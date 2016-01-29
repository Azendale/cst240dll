COPTS = -g -O0 -c
OBS = DoubleLinkedList.o \
	main.o \

all: testprogram

testprogram: $(OBS)
	gcc $(OBS) -o testprogram

DoubleLinkedList.o: DoubleLinkedList.c DoubleLinkedList.h
	gcc $(COPTS) DoubleLinkedList.c

main.o: main.c
	gcc $(COPTS) main.c


clean:
	rm -f $(OBS)
	rm -f testprogram