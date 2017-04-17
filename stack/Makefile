TAR = math
OBJ = math.o 


$(TAR) : $(OBJ)
	gcc -o $@ $^


%.o: %.c *.h
	gcc $(CFLAGS) -c $< -std=c99


clean:
	rm $(TAR) $(OBJ)
