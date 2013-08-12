BOARD       ?= nano328
SOURCES     ?= main.cc

LIBRARYPATH := $(dir $(CURDIR))/libs
LIBRARIES   ?= $(notdir $(wildcard $(LIBRARYPATH)/*))

include $(dir $(CURDIR))/arduino.mk

Stepper Led:
	$(MAKE) SOURCES=$@.cc TARGET=$@


%.upload: $*
	$(MAKE) upload SOURCES=$*.cc TARGET=$*