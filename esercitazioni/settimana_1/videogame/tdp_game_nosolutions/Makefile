CCOPTS= -Wall -O3 -std=gnu99
LIBS= -lglut -lGLU -lGL -lm
CC=gcc

OBJS=vec3.o surface.o image.o vehicle.o world.o helpers.o tdp_game.o
.phony: clean 

all: $(OBJS) 
	$(CC) $(CCOPTS) -o tdp_game $^ $(LIBS)

%.o:	%.c
	$(CC) $(CCOPTS) -c -o $@ $^

clean:	
	rm -rf *.o *~ cube main tdp_game
