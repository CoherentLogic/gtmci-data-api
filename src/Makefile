CC=gcc
CFLAGS=-Wall -I$(gtm_dist) -fPIC

libgtmdata.so:gtmdata.o
	$(CC) -g -o libgtmdata.so -shared gtmdata.o -L$(gtm_dist) -lgtmshr -Wl,-rpath=$(gtm_dist)

gtmdata.o:gtmdata.c
	$(CC) $(CFLAGS) -g -c gtmdata.c -o gtmdata.o

test:test.o
	$(CC) -g -o test test.o -lgtmdata

test.o:test.c
	$(CC) -g -c test.c -o test.o

clean:
	rm libgtmdata.so
	rm gtmdata.o
	rm gtmdatas.o
	rm test.o
	rm test