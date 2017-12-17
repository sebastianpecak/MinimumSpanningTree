#include <MSP.h>
#include <stdlib.h>

///////////////////////////////////////////////
static const char* LastError = "";

///////////////////////////////////////////////
inline const char* MSP_GetLastError(void) {
	const char* output = LastError;
	
	// Reset last error.
	LastError = "";
	return output;
}

///////////////////////////////////////////////
FlaggedEdgeArray_t MSP_CreateInitialForest(const FlaggedInputEdgeArray_t edges, size_t verticesNo) {
	FlaggedEdgeArray_t output = NULL;
	size_t iter;
	FlaggedInputEdge_t* value = NULL;
	FlaggedEdge_t* outVal = NULL;
	
	// Try to create output array.
	output = FlaggedEdgeArray_New(verticesNo);
	if (output) {
		// Reset output array.
		for (iter = 0; iter < edges->ElementsCount; ++iter)
			FlaggedEdge_Reset(FlaggedEdgeArray_GetIndex(output, iter));
			
		// For each input edge.
		for (iter = 0; iter < edges->ElementsCount; ++iter) {
			// Get element from input array.
			value = FlaggedInputEdgeArray_GetIndex(edges, iter);
			///////////////////////////////////////////////
			// VERTICE-A.
			outVal = FlaggedEdgeArray_GetIndex(output, value->Edge.VerticeA);
			// If output edge has no shortest value yet, set.
			if (outVal->Edge.EndPoint == EDGE_NOT_SET) {
				outVal->Edge.EndPoint = value->Edge.VerticeB;
				outVal->Edge.Weight = value->Edge.Weight;
			}
			// Value was already set, so compare is new edge is less costly.
			else {
				if (outVal->Edge.Weight > value->Edge.Weight) {
					// Set.
					outVal->Edge.EndPoint = value->Edge.VerticeB;
					outVal->Edge.Weight = value->Edge.Weight;
				}
			}
			///////////////////////////////////////////////
			// VERTICE-B.
			outVal = FlaggedEdgeArray_GetIndex(output, value->Edge.VerticeB);
			if (outVal->Edge.EndPoint == EDGE_NOT_SET) {
				outVal->Edge.EndPoint = value->Edge.VerticeA;
				outVal->Edge.Weight = value->Edge.Weight;
			}
			// Value was already set, so compare is new edge is less costly.
			else {
				if (outVal->Edge.Weight > value->Edge.Weight) {
					// Set.
					outVal->Edge.EndPoint = value->Edge.VerticeA;
					outVal->Edge.Weight = value->Edge.Weight;
				}
			}
		}
	}
	else
		// Set LastError.
		LastError = "Could not create new Array object.";
	
	// Return output value.
	return output;
}

///////////////////////////////////////////////
FlaggedEdgeArray_t MSP_NormalizeForest(const FlaggedEdgeArray_t forest) {
	FlaggedEdgeArray_t output = NULL;
	size_t iter = 0;
	// Number of edges after normalization.
	size_t normalizedEdgesNo = 0;
	FlaggedEdge_t* currentEdge = NULL;
	FlaggedEdge_t* outputElement = NULL;
	
	// Create output.
	output = FlaggedEdgeArray_New(forest->ElementsCount);
	if (output) {
		// Reset output array.
		for (iter = 0; iter < forest->ElementsCount; ++iter)
			FlaggedEdge_Reset(FlaggedEdgeArray_GetIndex(output, iter));
			
		// Do for each forest's edge.
		for (iter = 0; iter < forest->ElementsCount; ++iter) {
			// Check this edge flag, if it was not processed yet.
			currentEdge = FlaggedEdgeArray_GetIndex(forest, iter);
			// Get output element.
			outputElement = FlaggedEdgeArray_GetIndex(output, normalizedEdgesNo++);
			// Copy current edge to output.
			
		}
	}
	else
		printf("MSP_NormalizeForest() -> Could not create output array object.");
		
	// Return result.
	return output;
}
