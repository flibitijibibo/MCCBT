# Makefile for MCCBT
# Written by Ethan "flibitijibibo" Lee

# System information
UNAME = $(shell uname)
ARCH = $(shell uname -m)

# Detect cross targets
WINDOWS_TARGET=0
APPLE_TARGET=0
ifeq ($(OS), Windows_NT) # cygwin/msys2
        WINDOWS_TARGET=1
endif
ifneq (,$(findstring w64-mingw32,$(CC))) # mingw-w64 on Linux
        WINDOWS_TARGET=1
endif
ifeq ($(UNAME), Darwin)
        APPLE_TARGET=1
endif
ifneq (,$(findstring apple-darwin,$(CC))) # osxcross on Linux
        APPLE_TARGET=1
endif

# Compiler
ifeq ($(WINDOWS_TARGET),1)
        TARGET = .exe
        CFLAGS += -static-libgcc
else ifeq ($(APPLE_TARGET),1)
        CFLAGS += -mmacosx-version-min=10.9
endif

# Targets

all: clean
	$(CC) $(CFLAGS) -o mccbt$(TARGET) mccbt.c `sdl2-config --cflags --libs` -Wall -pedantic

clean:
	rm -f mccbt$(TARGET)
