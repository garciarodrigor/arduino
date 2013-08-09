SOURCES   ?= main.cc
LIBRARIES ?= $(notdir $(wildcard $(dir $(CURDIR)/libs/*)))
BOARD     ?= nano328

include $(dir $(CURDIR))/arduino.mk

Stepper:
	$(MAKE) SOURCES=$@.cc

Led:
	$(MAKE) SOURCES=$@.cc TARGET=$@
