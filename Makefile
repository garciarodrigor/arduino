#SOURCES   ?= main.cc
LIBRARIES := $(notdir $(wildcard $(CURDIR)/libs/*))
BOARD     ?= nano328

include $(CURDIR)/arduino.mk
