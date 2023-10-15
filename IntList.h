struct List {
	size_t size;
	size_t space;
	unsigned int* values;
};

void addElement(struct List* arr, unsigned int value);
void clear(struct List* arr);
struct List createList(size_t capacity);
void resizeArray(struct List* arr, size_t newCapacity);
void deleteArray(struct List* arr);