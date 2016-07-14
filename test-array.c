#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main(int argc, char *argv[])
{
	array_t *items;
	
	items = array_new();
	
	array_set(items, 0, "1");
	array_set(items, 1, "2");
	array_set(items, 2, "3");
	array_set(items, 3, "4");
	array_set(items, 4, "5");
	
	array_delete(items, 0);	
	
	printf("[0] = %s\n", (char *)array_get(items, 0));
	printf("[1] = %s\n", (char *)array_get(items, 1));
	printf("[2] = %s\n", (char *)array_get(items, 2));
	printf("[3] = %s\n", (char *)array_get(items, 3));
	
	printf("length = %d\n", (int)items->length);
	
	array_free(items);

	//printf("length = %d\n", (int)items->length);
	
	return 0;
}
