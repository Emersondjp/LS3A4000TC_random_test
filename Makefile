#
#  Makefile to build hello.c
#

CC=g++
CFLAGS=-O1 -g -Wno-write_strings
#CFLAGS+=-DDEBUG
OBJS=str2num.o gs_memory_class.o gs_memory_test.o
LDFLAGS=-g

all:	${OBJS}
	${CC} ${LDFLAGS} ${OBJS} -o gs_memory_test

.c.o:
	${CC} ${CFLAGS} -c $< -o $@

.cpp.o:
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f *.o gs_memory_test
