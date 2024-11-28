compile:
	mkdir -p output
	gcc src/backtracking.c src/main.c src/mapa.c src/menu.c src/pilha.c src/utilites.c -o output/exe.out

run:
	./output/exe

all: compile run