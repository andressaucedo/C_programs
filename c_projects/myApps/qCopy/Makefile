CC = gcc
TARGET = qcopy
CFLAGS = \
	-Wall\
	-Wextra\

OBJECTS = qcopy.o
.PHONY = clean

all: $(TARGET)

$(TARGET):	$(OBJECTS)
	$(CC) -o $(TARGET) $(OBJECTS) $(CFLAGS)

clean:
	rm -f $(TARGET) $(OBJECTS)
