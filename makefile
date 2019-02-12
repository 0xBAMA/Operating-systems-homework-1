CC=gcc

MAKE_EXE= -o cpu_percentage

output:
	$(CC) $(MAKE_EXE) cpu_percentage.c

clean:
	rm *.o
