IDIR =../include
CC=gcc
CFLAGS = -I$(IDIR) -lm
LDFLAGS = 
PACKAGE = 

LIBS=

_DEPS = bloomfilter.h hash.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = bloomfilter.o hash.o main.o
OBJ = $(patsubst %,%,$(_OBJ))

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) 

bloom: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f *.o *~ core $(INCDIR)/*~ bloom