#include <stdio.h>
#include "mem.h"
#define MAXBUFSIZE 8192
#define MAXENTRIES 128

char buf[MAXBUFSIZE];
struct Entry hist[MAXENTRIES];
char *ap = buf;
int histp = 0;

void *alloc(size_t n, enum EntryType type) {
	if (ap + n > buf + MAXBUFSIZE) {
		printf("oops: buffer full, please clear\n");
		return NULL;
	}
	if (histp >= MAXENTRIES) {
		printf("oops: hit max entries, please clear\n");
		return NULL;
	}

	hist[histp].ptr = ap;
	hist[histp].type = type;
	histp++;

	ap += n;
	return hist[histp - 1].ptr;
}

enum EntryType get_last_type(void) {
	if (histp > 0) {
		return hist[histp - 1].type;
	}
	return -1;
}

void *get_last_ptr(void) {
	if (histp > 0) {
		return hist[histp -1].ptr;
	}
	return NULL;
}
void rmlast() {
	if (histp > 0) {
		ap = hist[--histp].ptr;
	} else {
		printf("oops: enter something\n");
	}
}

void clear() {
	while (histp != 0) {
		hist[--histp].ptr = NULL;
		hist[histp].type = -1;
	}
	ap = buf;
}
