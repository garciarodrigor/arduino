CPP    := /usr/bin/g++
CC     := /usr/bin/gcc
TARGET := main
OBJS   := $(wildcard *.o)

all: $(TARGET)

$(TARGET): main.cpp
	$(CPP) $< -o $@

clean:
	rm $(TARGET)