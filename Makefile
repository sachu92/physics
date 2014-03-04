
CC=gcc
CFLAGS=-c
WARNFLAGS=-Wall
LDFLAGS=-lm
SRCS=q_newton_cotes.c q_test.c 
OBJS=$(SRCS:.c=.o)
EXEC=q_test

all : $(SRCS) $(OBJS)
	$(CC) -o $(EXEC) $(OBJS) $(LDFLAGS)

.c.o: $(SRCS)
	$(CC) $(CFLAGS) $< -o $@ 


clean: 
	rm -rf *.o
	rm -rf *.dat
	rm -rf $(EXEC)
