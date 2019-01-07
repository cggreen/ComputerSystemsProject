CC = gcc

CFLAGS = -O2 -Wall -I $(CSAPP_INC) -I ..

CSAPP_SRC = ../../../src
CSAPP_INC = ../../../include
LDLIBS = -lpthread
PROGS = echo.o\
	dd2hex\
	hostinfo\
	hostinfo-ntop\
	echoclient\
	fileReaderClass\
	rio\
	echoserveri\
	tiny/tiny\
	netpfragments.o\

all:  $(CSAPP_SRC)/csapp.c $(CSAPP_SRC)/csapp.o weatherTry

$(CSAPP_SRC)/csapp.c:
	$(CSAPP_SRC)/csapp.c

$(CSAPP_SRC)/csapp.o: $(CSAPP_SRC)/csapp.c $(CSAPP_INC)/csapp.h

weatherTry: weatherTry.c $(CSAPP_SRC)/csapp.c 
	$(CC) $(CFLAGS) -o weatherTry weatherTry.c $(CSAPP_SRC)/csapp.c -lpthread 

clean:
	rm -f weatherTry *~
