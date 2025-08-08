CC=gcc
FLAGS=-W -Wall -g

EXEC=nn
OBJS=src/matrix.o src/main.o
DEPS=src/matrix.h

all: $(EXEC)

# simplified rule that makes all object files from their header and source
%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c  -o $@ $<

# rule to make the final executable from the created object files
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC) 

# clean out the object files and the final executable
.PHONY: clean
clean:
	rm $(EXEC) src/*.o
