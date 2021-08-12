CC = gcc
TARGET = weekly


CFLAGS = \
	-Wall\
	-Wextra\

OBJECTS = weekly.o
.PHONY: clean
all: $(TARGET)

$(TARGET):	$(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(CFLAGS)

clean:
	rm -f $(TARGET) $(OBJECTS)
