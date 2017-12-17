#include <Array.h>
#include <stdio.h>
#include <Tools.h>

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
	FlaggedInputEdgeArray_t inputArray = NULL;
	
	// Try to parse given list.
	inputArray = ParseEdgesList(edges);
	PrintFlaggedInputEdgeArray(inputArray);
	// Check for success.
	if (inputArray) {
		////////
	}
	// Error.
	else
		printf("Test1() -> Error when parsing input egdes pairs.");
}

///////////////////////////////////////////////
int main(int argc, char** argv) {
	Test1();
}