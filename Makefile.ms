
CC=gcc
CFLAGS=-c
WARNFLAGS=-Wall
LDFLAGS=-lgsl -lgslcblas -lm
SRCS=derivative.c newton_raphson.c maier_saupe.c
OBJS=$(SRCS:.c=.o)
EXEC=ms

all : $(SRCS) $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(LDFLAGS)

.c.o: $(SRCS)
	$(CC) $(CFLAGS) $< -o $@ -lgsl -lgslcblas -lm


