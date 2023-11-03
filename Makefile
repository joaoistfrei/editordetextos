all:
	gcc -c comandoseditor.c  -I . -o comandoseditor.o
	gcc main.c comandoseditor.o -I . -lm -o main.exe

run:
	./main.exe