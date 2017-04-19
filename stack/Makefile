TAR = math
OBJ = math.o stack.o

TAR2 = intopost
OBJ2 = intopost.o stack.o

$(TAR2) : $(OBJ2)
	gcc -o $@ $^

$(TAR) : $(OBJ) 
	gcc -o $@ $^


%.o: %.c *.h
	gcc $(CFLAGS) -c $< -std=c99


clean:
	rm $(TAR) $(OBJ)
