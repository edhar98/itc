#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int element_type;
typedef unsigned int size_type;

struct array_t
{
	element_type* start;
	size_type size;
};

typedef struct array_t array;

array* array_create(size_type n, element_type default_value)
{
	array* a = (array*)malloc(sizeof(array));
	a->size = n;
	a->start = (element_type*)malloc(n * sizeof(element_type));
	for (size_type i = 0; i < a->size; ++i)  {
		a->start[i] = default_value;
	}
	return a;
}

array* array_empty_create()
{
	array* a = (array*)malloc(sizeof(array));
	a->size = 0;
	a->start = NULL;
    return a;
}

void array_destroy(array* a)
{
    if (a->start != NULL) {
        free(a->start);
    }
	free(a);
}

void array_insert(array* a, size_type index, element_type value)
{
	assert(index >= 0);
	assert(index <= a->size);
	a->size = a->size + 1;
	element_type* tmp = (element_type*)malloc(a->size * sizeof(element_type));
	for (size_type i = 0; i < index; ++i) {
		tmp[i] = a->start[i];
	}
	tmp[index] = value;
	for (size_type i = index + 1; i < a->size; ++i) {
		tmp[i] = a->start[i - 1];
	}
    if (a->start != NULL) {
        free(a->start);
    }
	a->start = tmp;
}

void array_modify(array* a, size_type index, element_type value)
{
	assert(index >= 0);
	assert(index <= a->size);
	a->start[index] = value;
}
	
void array_remove(array* a, element_type index){
	assert(index >= 0);
	assert(index <= a->size);
	a->size = a->size - 1;
	element_type* tmp = (element_type*)malloc(a->size * sizeof(element_type));
	for (size_type i = 0; i < index; ++i) {
		tmp[i] = a->start[i];
	}
	for (size_type i = index; i < a->size; ++i) {
		tmp[i] = a->start[i + 1];
	}
	free(a->start);
	a->start = tmp;
}

size_type array_size(array* a)
{
	return a->size;
}

int array_is_empty(array* a)
{
    assert(a->size >= 0);
	return a->size == 0;
}

element_type array_access(array* a, size_type index)
{
	assert(index >= 0);
	assert(index < a->size);
	assert(a->start != NULL);
	return a->start[index];
}

int main()
{
	array* a = array_create(4, 0);
	assert(array_size(a) == 4);
	assert(! array_is_empty(a));
	for (element_type i = 0; i < 4; ++i){
		assert(array_access(a, i) == 0);
	}
	array_insert(a, array_size(a), 8);
	array_insert(a, array_size(a), 9);
	assert(array_size(a) == 6);
	assert(array_access(a, 0) == 0);
	assert(array_access(a, 1) == 0);
	assert(array_access(a, 2) == 0);
	assert(array_access(a, 3) == 0);
	assert(array_access(a, 4) == 8);
	assert(array_access(a, 5) == 9);
	array_insert(a, 0, 5);
	assert(array_size(a) == 7);
	assert(array_access(a, 0) == 5);
	assert(array_access(a, 1) == 0);
	assert(array_access(a, 2) == 0);
	assert(array_access(a, 3) == 0);
	assert(array_access(a, 4) == 0);
	assert(array_access(a, 5) == 8);
	assert(array_access(a, 6) == 9);
	array_remove(a, 5);
	array_modify(a,1,13);	
	for (size_type i = 0; i < a->size; ++i)  {
		printf("a[%d] = %d\n", i, array_access(a, i));
	}
	array_destroy(a);
	array* b = array_empty_create();
	assert(array_size(b) == 0);
	assert(array_is_empty(b));
	array_destroy(b);
	return 0;

}
