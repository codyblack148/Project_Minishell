COMPILE_FLAGS = -Wstrict-prototypes -Wshadow -Wpointer-arith -Wcast-qual \
		-Wcast-align -Wwrite-strings -Wnested-externs -Winline \
		-W -Wundef -Wmissing-prototypes -O0 -g
.SUFFIXES: .c .o
LINK_FLAGS =
LIBS = -lm -lc

CC = gcc

all:    codyShell

clean:
	rm -f *~
	rm -f core
	rm -f *.o
	rm -f parse_libs codyShell

%.o: %.c
	$(CC) $(COMPILE_FLAGS) -c $< -o $@

#parse_libs: parse_libs.o
#	$(CC) $(LINK_FLAGS) $(LIBS) -o $@ $^

codyShell: codyShell.o parse_libs.o
	$(CC) $(LINK_FLAGS) $(LIBS) -o $@ $^
