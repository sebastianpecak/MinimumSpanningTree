#include <Tools.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

///////////////////////////////////////////////
// This function parses single edge and saves result in output.
// Returns non-zero value on error.
// We assume that singleEdge is ASCII encodded.
static int _ParseSingleEdge(const char* singleEdge, InputEdge_t* output, char* highestVertice) {
	size_t stringLen = 0;
	
	// Get singleEdge string length.
	stringLen = strlen(singleEdge);
	if (stringLen > 0) {
		output->VerticeA = (Vertice_t)(*singleEdge - 'a');
		output->VerticeB = (Vertice_t)(*(singleEdge + 2) - 'a');
		output->Weight = (EdgeWeight_t)atoi(singleEdge + 4);
		// Set up highest vertice value.
		if (output->VerticeA > output->VerticeB)
			*highestVertice = (*highestVertice < output->VerticeA ? output->VerticeA : *highestVertice);
		else
			*highestVertice = (*highestVertice < output->VerticeB ? output->VerticeB : *highestVertice);
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
FlaggedInputEdgeArray_t ParseEdgesList(const char* edges, uint32_t* verticesNo) {
	FlaggedInputEdgeArray_t result = NULL;
	// Number of edges.
	size_t edgesNo = 0;
	char* token = NULL;
	char* copyBuffer = NULL;
	size_t edgesLength = 0;
	size_t edgeIter = 0;
	FlaggedInputEdge_t* currentEdge = NULL;
	
	// Reset vertices number.
	*verticesNo = 0;
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
			// Get current edge.
			currentEdge = FlaggedInputEdgeArray_GetIndex(result, edgeIter++);
			// Reset edge flags.
			currentEdge->Flags = (EdgeFlag_t)0;
			_ParseSingleEdge(
				token,
				&currentEdge->Edge,
				verticesNo
			);
			// Get next token.
			token = strtok(NULL, EDGES_SEPARATOR);
		}
		// All is done, free resources.
		free(copyBuffer);
	}
	else
		printf("ParseEdgesList() -> Edges number is 0.");
		
	// Increment vertices number, as we started with 0.
	++(*verticesNo);
	// Return parsed edges.
	return result;
}

///////////////////////////////////////////////
void PrintFlaggedInputEdgeArray(FlaggedInputEdgeArray_t edges) {
	size_t iter;
	FlaggedInputEdge_t* value = NULL;
	
	for (iter = 0; iter < edges->ElementsCount; ++iter) {
		value = FlaggedInputEdgeArray_GetIndex(edges, iter);
		printf(
			"[%d]: (%c - %c).Weight = %d, Flags = %d\n",
			iter,
			value->Edge.VerticeA + 'a',
			value->Edge.VerticeB + 'a',
			value->Edge.Weight,
			value->Flags
		);
	}
	printf("---------------------------------------------------\n");
}

///////////////////////////////////////////////
void PrintFlaggedEdgeArray(FlaggedEdgeArray_t edges) {
	size_t iter;
	FlaggedEdge_t* value = NULL;
	
	for (iter = 0; iter < edges->ElementsCount; ++iter) {
		value = FlaggedEdgeArray_GetIndex(edges, iter);
		printf("(%c - %c).Weight = %d\n", iter + 'a', value->Edge.EndPoint + 'a', value->Edge.Weight);
	}
	printf("---------------------------------------------------\n");
}
