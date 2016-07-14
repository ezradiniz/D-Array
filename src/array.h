#ifndef ARRAY_H
#define ARRAY_H

typedef struct array array_t;
struct array {
	void **data;
	size_t capacity;
	size_t length;
};

array_t *array_new();

void array_set(array_t *this, size_t index, void *value);
void *array_get(array_t *this, size_t index);
void array_delete(array_t *this, size_t index);
void array_free(array_t *this);

#define INITIAL_CAPACITY 50

/*#define array_for_each(item, array) \
	int i = 0; \
	item = array->data[0]; \
	for (i = 0; i<array->length-1; item = array->data[i], i++) \
*/		 

#endif
