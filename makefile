compile:
	gcc src/main.c src/mapa.c -o output/exe 

run:
	./output/exe

all: compile run