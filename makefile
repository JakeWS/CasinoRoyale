CC = g++

CFLAGS= -std=c++11 -O0 -g $(INCLUDE_DIRS) $(CDEFS)


PRODUCT=cardTest

HFILES= Card.h Deck.h randGen.h
CFILES= cardTest.cc Card.cc Deck.cc Random.cc

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