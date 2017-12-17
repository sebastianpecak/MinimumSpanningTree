#include <Tools.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

///////////////////////////////////////////////
// This function parses single edge and saves result in output.
// Returns non-zero value on error.
// We assume that singleEdge is ASCII encodded.
static int _ParseSingleEdge(const char* singleEdge, InputEdge_t* output) {
	size_t stringLen = 0;
	int tmp = 0;
	
	// Get singleEdge string length.
	stringLen = strlen(singleEdge);
	if (stringLen > 0) {
		output->VerticeA = (Vertice_t)(*singleEdge - 'a');
		output->VerticeB = (Vertice_t)(*(singleEdge + 2) - 'a');
		output->Weight = (EdgeWeight_t)atoi(singleEdge + 4);
		//tmp = (*singleEdge - 'a');
		//output->VerticeA = (Vertice_t)tmp;
		//tmp = *(singleEdge + 2) - 'a';
		//output->VerticeB = (Vertice_t)tmp;
		//const char* sss = singleEdge + 4;
		//output->Weight = (EdgeWeight_t)atoi(singleEdge + 4);
		// Copy value.
		// No safety switches. TODO.
		//copyBuffer = (char*)malloc(stringLen + 1);
		//strcpy(copyBuffer, singleEdge);
		// Tokenize string.
		//token = strchr(copyBuffer, *(EDGE_VALUE_SEPARATOR));
		/*while (token) {
			// Move to next character.
			++token;
			// This list is easly extensible.
			switch (valueIter++) {
				// Edge source vertice.
			case 0:
				output->VerticeA = (Vertice_t)((*token) - 'a');
				break;
				// Edge endpoint verice.
			case 1:
				output->VerticeB = (Vertice_t)((*token) - 'a');
				break;
				// Edge weight, treated as signed integer value.
			case 2:
				output->Weight = (EdgeWeight_t)atoi(token);
				//valueIter = 0;
				break;
			}
			// Get next token.
			token = strtok(NULL, EDGE_VALUE_SEPARATOR);
		}*/
		// Free resources.
		//free(copyBuffer);
	}
	else
		printf("_ParseSingleEdge() -> Value length is 0.");
		
	return 0;
}

///////////////////////////////////////////////
static size_t _CountEdgesInString(const char* edgesString, size_t* outputLen) {
	size_t result = 0;
	size_t iter;
	size_t stringLen;
	
	// Get string length.
	stringLen = strlen(edgesString);
	for (iter = 0; iter < stringLen; ++iter) {
		if(edgesString[iter] == *(EDGES_SEPARATOR))
			++result;
	}
	// If we have valid outputLen pointer, store edgesString length.
	if (outputLen)
		*outputLen = stringLen;
	// Return counted edges. +1 is for last edge.
	return result + 1;
}

///////////////////////////////////////////////
FlaggedInputEdgeArray_t ParseEdgesList(const char* edges) {
	FlaggedInputEdgeArray_t result = NULL;
	// Number of edges.
	size_t edgesNo = 0;
	char* token = NULL;
	char* copyBuffer = NULL;
	size_t edgesLength = 0;
	size_t edgeIter = 0;
	
	edgesNo = _CountEdgesInString(edges, &edgesLength);
	if (edgesNo > 0) {
		// Create output array.
		result = FlaggedInputEdgeArray_New(edgesNo);
		// Allocate buffer for edges copy.
		copyBuffer = (char*)malloc(edgesLength + 1);
		strcpy(copyBuffer, edges);
		// Tokenize string.
		token = strtok(copyBuffer, EDGES_SEPARATOR);
		while (token) {
			_ParseSingleEdge(
				token,
				&FlaggedInputEdgeArray_GetIndex(result, edgeIter++)->Edge
			);
			// Get next token.
			token = strtok(NULL, EDGES_SEPARATOR);
		}
		// All is done, free resources.
		free(copyBuffer);
	}
	else
		printf("ParseEdgesList() -> Edges number is 0.");
	// Return parsed edges.
	return result;
}

///////////////////////////////////////////////
void PrintFlaggedInputEdgeArray(FlaggedInputEdgeArray_t edges) {
	size_t iter;
	FlaggedInputEdge_t* value = NULL;
	
	for (iter = 0; iter < edges->ElementsCount; ++iter) {
		value = FlaggedInputEdgeArray_GetIndex(edges, iter);
		printf("[%d]: (%d - %d).Weight = %d\n", iter, value->Edge.VerticeA, value->Edge.VerticeB, value->Edge.Weight);
	}
}
