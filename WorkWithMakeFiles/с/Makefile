.PHONY: clean
%.o : %.c

main: main.o init.o base.o task.o
	gcc -o main main.o init.o base.o task.o

main.o: main.c
	gcc -c main.c

task.o: task.c task.h
	gcc -c task.c

base.o: base.c base.h
	gcc -c base.c

init.o: init.c init.h
	gcc -c init.c

clean:
	rm -rvf *.o result