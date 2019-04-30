INCLUDE_DIRS = 
LIB_DIRS = 
CC = g++

CDEFS=
CFLAGS= -O0 -g $(INCLUDE_DIRS) $(CDEFS)
LIBS=

BLACKJACK_DRIVER= blackjacktest
CARD_DRIVER= cardtest

HFILES= blackjack.hpp Deck.hpp Card.hpp randGen.hpp
BLACKJACK_CFILES= blackjack.cc blackjacktest.cc
CARD_CFILES= cardtest.cc Card.cc Deck.cc Random.cc 

BLACKJACK_OBJS= ${BLACKJACK_CFILES:.cc=.o}
CARD_OBJS= ${CARD_CFILES:.cc=.O}

all:	${BLACKJACK_DRIVER} ${CARD_DRIVER}

clean:
	-rm -f *.o *.NEW *~
	-rm -f ${BLACKJACK_DRIVER} ${CARD_DRIVER} ${DERIVED} ${GARBAGE}

${BLACKJACK_DRIVER}: ${BLACKJACK_OBJS}
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $(BLACKJACK_OBJS) $(LIBS)

${CARD_DRIVER}: ${CARD_OBJS}
	$(CC) $(LDFLAGS) $(CFLAGS) -o $@ $(CARD_OBJS) $(LIBS)

depend:

blackjacktest.o: blackjacktest.cc
	$(CC) $(LDFLAGS) $(CFLAGS) -c $<

blackjack.o: blackjack.cc
	$(CC) $(LDFLAGS) $(CFLAGS) -c $<

Deck.o: Deck.cc
	$(CC) $(LDFLAGS) $(CFLAGS) -c $<

cardtest.o: cardtest.cc
	$(CC) $(LDFLAGS) $(CFLAGS) -c $<

Card.o: Card.cc
	$(CC) $(LDFLAGS) $(CFLAGS) -c $<

Random.o: Random.cc
	$(CC) $(LDFLAGS) $(FLAGS) -c $<


