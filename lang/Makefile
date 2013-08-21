BOARD       ?= nano328
SOURCES     ?= $(wildcard *.cpp)
TARGET      ?= main

LIBRARYPATH := $(dir $(CURDIR))/libs
LIBRARIES   ?= $(notdir $(wildcard $(LIBRARYPATH)/*))

include $(dir $(CURDIR))/arduino.mk
