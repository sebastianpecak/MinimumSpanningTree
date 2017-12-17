#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>

///////////////////////////////////////////////
struct _Array {
	size_t ElementSize;
	size_t ElementsCount;
	void* Data;
};

///////////////////////////////////////////////
typedef struct _Array Array;

#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

	///////////////////////////////////////////////
	// This function creates new array of given elements.
	Array* Array_New(size_t arraySize, size_t elementSize);

	///////////////////////////////////////////////
	// This function frees all resources allocated for given array.
	void Array_Delete(Array** array);

	///////////////////////////////////////////////
	// This function returns n-th element pointer from array.
	// Preconditions: 
	// 1) Array pointer must be valid, otherwise undefined behaviour.
	// 2) index must be valid, otherwise undefined behaviour.
	void* Array_GetIndex(const Array* array, size_t index);

#ifdef __cplusplus
}
#endif	// __cplusplus

#endif	// ARRAY_H
