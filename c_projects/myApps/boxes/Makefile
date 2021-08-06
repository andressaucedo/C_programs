CC = gcc
TARGET = boxes
CFLAGS=\
	-Wall\
	-Wextra\
	-lraylib -lm -lpthread -ldl

LDFLAGS=-std=c99 -Wall -Iexternal -DPLATFORM_DESKTOP

OBJECTS=\
	boxes.o

.PHONY: clean

all: $(TARGET)

$(TARGET):  $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(CFLAGS)

clean:
	rm -f $(TARGET) $(OBJECTS)
