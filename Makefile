CC=clang
CFLAGS=-Werror=vla -std=c11
DEPS=
OBJ=battleships.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

battleships: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
	
clean:
	rm *.o
