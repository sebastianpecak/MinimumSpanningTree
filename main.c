#include <Array.h>
#include <stdio.h>
#include <Tools.h>
#include <MSP.h>

///////////////////////////////////////////////
void Test1(void) {
	const char* edges = 
		"a-g-1,"
		"a-i-8,"
		"b-h-11,"
		"b-d-7,"
		"c-d-5,"
		"c-j-12,"
		"d-e-2,"
		"e-i-10,"
		"f-j-3,"
		"f-g-9,"
		"g-h-13,"
		"h-j-6,"
		"i-j-4";
		
	const char* edges2 = 
		"a-b-1,"
		"b-c-2,"
		"c-d-10,"
		"d-e-7,"
		"e-f-8,"
		"a-f-3,"
		"a-g-4,"
		"b-g-6,"
		"c-g-9,"
		"d-g-11,"
		"e-g-12,"
		"f-g-5";
		
	FlaggedInputEdgeArray_t inputArray = NULL;
	FlaggedEdgeArray_t initialForest = NULL;
	uint32_t verticesNo = 0;
	
	// Try to parse given list.
	inputArray = ParseEdgesList(edges, &verticesNo);
	//PrintFlaggedInputEdgeArray(inputArray);
	// Check for success.
	if (inputArray) {
		////////////////////////////////////////////////////////
		initialForest = MSP_CreateInitialForest(inputArray, verticesNo);
		PrintFlaggedInputEdgeArray(inputArray);
		PrintFlaggedEdgeArray(initialForest);
		////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////
	}
	// Error.
	else
		printf("Test1() -> Error when parsing input egdes pairs.");
		
	// Free resources.
	Array_Delete(&inputArray);
	Array_Delete(&initialForest);
}

///////////////////////////////////////////////
int main(int argc, char** argv) {
	Test1();
}