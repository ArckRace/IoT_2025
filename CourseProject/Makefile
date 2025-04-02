# TARGET - исполняемый файл
TARGET=temp_prog
# CC - компилятор, используемый для сборки
CC=gcc
# CFLAGS - флаги, которые передаются компилятору
CFLAGS=-Wall -g
# OBJECTS - объектные файлы
OBJECTS=main.o temp_functions.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

temp_functions.o: temp_functions.c temp_functions.h
	$(CC) $(CFLAGS) -c temp_functions.c -o temp_functions.o

clean:
	rm -rf $(OBJECTS) $(TARGET)