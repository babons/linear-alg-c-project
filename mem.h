#ifndef MEM_H
#define MEM_H

#include <stddef.h>

enum EntryType { ENTRY_VECTOR, ENTRY_MATRIX };

struct Entry {
	void *ptr;
	enum EntryType type;
};

void *alloc(size_t n, enum EntryType type);
void rmlast();
void clear();

enum EntryType get_last_type(void);
void *get_last_ptr(void);

#endif
