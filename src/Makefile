CC=gcc
CFLAGS=-Wall -I$(gtm_dist) -fPIC

libgtmdata.so:gtmdata.o
	$(CC) -o libgtmdata.so -shared gtmdata.o -L$(gtm_dist) -lgtmshr -Wl,-rpath=$(gtm_dist)

gtmdata.o:gtmdata.c
	$(CC) $(CFLAGS) -c gtmdata.c -o gtmdata.o