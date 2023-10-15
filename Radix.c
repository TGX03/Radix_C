#include "Radix.h"

void radix(unsigned int* arr, size_t size) {
	struct List zeros = createList(size / 4);
	struct List one = createList(size / 4);
	struct List ten = createList(size / 4);
	struct List eleven = createList(size / 4);
	for (int i = 0; i < 16; ++i) {
		if (i != 0) {
			clear(&zeros);
			clear(&one);
			clear(&ten);
			clear(&eleven);
		}
		for (int j = 0; j < size; ++j) {
			unsigned int current = arr[j];
			unsigned int masked = current >> i * 2;
			masked = masked & 0b11;
			switch (masked) {
				case 0:
					addElement(&zeros, current);
					break;
				case 1:
					addElement(&one, current);
					break;
				case 0b10:
					addElement(&ten, current);
					break;
				case 0b11:
					addElement(&eleven, current);
					break;
			}
		}
		int currentPosition = 0;
		toArray(&zeros, arr);
		currentPosition += zeros.size;
		toArray(&one, arr + currentPosition);
		currentPosition += one.size;
		toArray(&ten, arr + currentPosition);
		currentPosition += ten.size;
		toArray(&eleven, arr + currentPosition);
	}
	deleteArray(&zeros);
	deleteArray(&one);
	deleteArray(&ten);
	deleteArray(&eleven);
}

static void toArray(struct List* source, unsigned int* target) {
	for (int i = 0; i < source->size; ++i) {
		target[i] = source->values[i];
	}
}