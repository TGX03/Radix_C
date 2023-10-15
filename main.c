#include <stdio.h>
#include "Radix.h"

const size_t size = 10;

int main() {
	unsigned int values[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	radix(&values, size);
	for (int i = 0; i < size; ++i) {
		printf(" %d;", values[i]);
	}
}