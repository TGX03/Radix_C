#include <stdlib.h>
#include "IntList.h"

void addElement(struct List* arr, unsigned int value) {
	if (arr->size == arr->space) {
		resizeArray(arr, arr->space * 2);
	}
	arr->values[arr->size] = value;
	arr->size++;
}

void clear(struct List* arr) {
	for (int i = 0; i < arr->size; ++i) {
		arr->values[i] = 0;
	}
	arr->size = 0;
}

struct List createList(size_t capacity) {
	unsigned int* data = (int *) calloc(capacity, sizeof(unsigned int));
	struct List result;
	result.size = 0;
	result.space = capacity;
	result.values = data;
	return result;
}

void resizeArray(struct List* arr, size_t newCapacity) {
	arr->values = realloc(arr->values, newCapacity * sizeof(unsigned int));
	arr->space = newCapacity;
	if (newCapacity < arr->size) {
		arr->size = newCapacity;
	}
}

void deleteArray(struct List* arr) {
	free(arr->values);
	arr->size = -1;
	arr->space = -1;
}