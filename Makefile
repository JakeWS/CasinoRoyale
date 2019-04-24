CC = g++

CFLAGS= -std=c++11 -O2 -g $(INCLUDE_DIRS) $(CDEFS)


PRODUCT=CasinoApp

HFILES= 
CFILES= main.cc

SRCS= ${HFILES} ${CFILES}
OBJS= ${CFILES:.c=.o}

all:	${PRODUCT}

clean:
	-rm -f *.o *.NEW *~
	-rm -f ${PRODUCT} ${DERIVED} ${GARBAGE}

${PRODUCT}:	${OBJS}
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $(OBJS) $(LIBS)

depend:

.c.o:
	$(CC) $(CFLAGS) -c $<