# BUILD_DIR - каталог, в который будут помещены собранные файлы
BUILD_DIR = build
# TARGET - исполняемый файл
TARGET=$(BUILD_DIR)/temp_prog
# CC - компилятор, используемый для сборки
CC=gcc
# CFLAGS - флаги, которые передаются компилятору
CFLAGS=-Wall -g
# OBJECTS - объектные файлы
OBJECTS=$(BUILD_DIR)/main.o $(BUILD_DIR)/temp_functions.o

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

$(BUILD_DIR)/main.o: main.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c main.c -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/temp_functions.o: temp_functions.c temp_functions.h | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c temp_functions.c -o $(BUILD_DIR)/temp_functions.o

clean:
	rm -rf $(BUILD_DIR)