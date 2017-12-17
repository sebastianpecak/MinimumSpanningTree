#include <Array.h>
#include <stdlib.h>

///////////////////////////////////////////////
Array* Array_New(size_t arraySize, size_t elementSize) {
	Array* output = NULL;
	
	// Validate arguments.
	if (arraySize > 0 && elementSize > 0) {
		output = (Array*)malloc(sizeof(Array));
		// Check if we successfully allocated memory for Array object.
		if (output) {
			// Allocate data buffer.
			output->Data = malloc(elementSize * arraySize);
			// Check for error.
			if (output->Data) {
				// Setup array values.
				output->ElementsCount = arraySize;
				output->ElementSize = elementSize;
			}
			else {
				// Error occured while creating data buffer.
				// Free resources.
				free(output);
				output = NULL;
			}
		}
	}
	
	// Return output value.
	return output;
}

///////////////////////////////////////////////
void Array_Delete(Array** array) {
	if (array && *array) {
		// Free resources.
		free((*array)->Data);
		free(*array);
		// Reset pointer.
		*array = NULL;
	}
}

///////////////////////////////////////////////
void* Array_GetIndex(const Array* array, size_t index) {
	return ((char*)(array->Data)) + (array->ElementSize * index);
}

///////////////////////////////////////////////
/*void Array_Test(void) {
	Array* array = NULL;
	int* value = NULL;
	int i;
	
	array = Array_New(10, sizeof(int));
	if (array) {
		
		for (i = 0; i < array->ElementsCount; ++i) {
			value = Array_GetNthElement(array, i);
			*value = i * 2;
		}
		
		for (i = 0; i < array->ElementsCount; ++i) {
			value = Array_GetNthElement(array, i);
			printf("Array[%0d]: %d\n", i, *value);
		}
		
		Array_Delete(&array);
		
	}
	else
		printf("Could not create array object.\n");
}*/
