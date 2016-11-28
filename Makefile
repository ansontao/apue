TAR = hello
OBJ = hello.o


$(TAR) : $(OBJ)
	gcc -o $@ $^


%.o: %.c
	gcc $(CFLAGS) -c $<


clean:
	rm $(TAR) $(OBJ)
