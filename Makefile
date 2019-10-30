# Macros
CC = gcc
CFLAGS = -Wall -Wextra -pedantic
APP = wc

# Options
all: $(APP)

run: $(APP)
	./$(APP)

clean:
	rm $(APP).o $(APP)
clear:
	rm $(APP).o $(APP)

# Binary
$(APP): $(APP).o
	$(CC) $(CFLAGS) $^ -o $@

# Object file
$(APP).o: $(APP).c
	$(CC) $(CFLAGS) -c $< -o $@
