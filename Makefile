

LIBS= -lSDL -lSDL_image

all: harlantime

harlantime: src/harlantime.cc src/harlantime.h
	g++ -W -Wall -g $(LIBS) src/harlantime.cc -o harlantime