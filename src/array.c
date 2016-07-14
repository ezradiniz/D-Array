#include <stdlib.h>
#include <assert.h>
#include "array.h"

static void __array_realloc(array_t *this)
{	
	size_t size = this->capacity + (int)(this->capacity/2);

	void **data = realloc(this->data, sizeof(void *)*size);	

	assert(data != NULL);

	this->data = data;
	this->capacity = size;	
}

array_t *array_new() 
{
	array_t *this;

	this = malloc(sizeof(array_t));
	
	assert(this != NULL);	

	this->data = malloc(INITIAL_CAPACITY*sizeof(void *));
	this->capacity = INITIAL_CAPACITY;
	this->length = 0;	

	return this;
}

void array_set(array_t *this, size_t index,  void *value)
{
	if (this->length == this->capacity)
		__array_realloc(this);
	
	assert(index >= 0 && index <= this->length);
	
	this->data[index] = value;
	this->length++;
}

void *array_get(array_t *this, size_t index)
{
	assert(index >= 0 && index < this->length);
	return this->data[index];
}

void array_delete(array_t *this, size_t index)
{
	assert(index >= 0 && index < this->length);
	
	int i;
	for (i=index; i < this->length-1; i++) 
		this->data[i] = this->data[i+1];
	
	this->length--;
}	

void array_free(array_t *this)
{
	free(this->data);
	free(this);
}

