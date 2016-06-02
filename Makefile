INCLUDES = -I src/
dirs = ./bin ./obj
main_obj = ./obj/main.o ./obj/bstree.o 

all: ./bin/main

./bin/main: $(dirs) $(main_obj)
	gcc $(main_obj) -Wall -o ./bin/main -lm

$(dirs):
	mkdir obj
	mkdir bin

./obj/main.o: ./src/main.c
	gcc -c ./src/main.c -Wall -o ./obj/main.o $(INCLUDES)

./obj/bstree.o: ./src/bstree.c
	gcc -c ./src/bstree.c -Wall -o ./obj/bstree.o $(INCLUDES)

.PHONY: clean
clean:
	rm -rf bin/ obj/