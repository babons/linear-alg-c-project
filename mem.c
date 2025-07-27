#include <stdio.h>
#define MAXBUFSIZE 8192
#define MAXENTRIES 128

char buf[MAXBUFSIZE];
char* hist[MAXENTRIES];
char *ap = buf;
int histp = 0;

void *alloc(size_t n) {
	if (ap + n > buf + MAXBUFSIZE) {
		printf("oops: buffer full, please clear\n");
		return NULL;
	} else {
		if (histp >= MAXENTRIES) {
			printf("oops: hit max entries, please clear\n");
			return NULL;
		}
		hist[histp++] = ap;
		ap+=n;
		return hist[histp - 1];
	}
}

void rmlast() {
	if (histp > 0) {
		ap = hist[histp--];
		hist[histp] = NULL;
	} else {
		printf("oops: enter something\n");
	}
}

void clear() {
	while (histp != 0) {
		hist[--histp] = NULL;
	}
	ap = buf;
}
