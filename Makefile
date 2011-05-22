all: main

main: main.o framebuffer.o

%.o: %.c
	$(CROSS_COMPILE)$(CC) -c $^ -o $@
