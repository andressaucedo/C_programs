CC = gcc
TARGET = friends

OBJECTS = friends.o

CFLAGS =\
	-Wall\
	-Wextra\

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(CFLAGS)

clean:
	rm -f $(TARGET) $(OBJECTS)
