objects = image.o bitmaplib.o 

programme: $(objects)
	cc -Wall -std=c99 -o programme $(objects) -lm

image.o : image.c
	cc -Wall -std=c99 -c image.c

bitmaplib.o : bitmaplib.c
	cc -Wall -std=c99 -c bitmaplib.c


clean :
	rm $(objects)
