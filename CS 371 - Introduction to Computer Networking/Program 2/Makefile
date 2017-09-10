CC = gcc
CFLAGS = -Wall -g -w
INCLUDES = -I.
LIBS = -lpthread -ldl
SRCS = Program2.c
OBJS = Program2.o
EXE = Program2

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o *~ $(EXE)
