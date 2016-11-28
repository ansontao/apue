TAR = testchangeable
OBJ = testchangeable.o


$(TAR) : $(OBJ)
	gcc -o $@ $^


%.o: %.c
	gcc $(CFLAGS) -c $< -std=c99


clean:
	rm $(TAR) $(OBJ)
