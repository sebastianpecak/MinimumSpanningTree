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
Array* MSP_CreateInitialForest(const FlaggedInputEdgeArray_t edges, size_t verticesNo) {
	Array* output = NULL;
	size_t iter;
	FlaggedInputEdge_t* value = NULL;
	FlaggedEdge_t* outVal = NULL;
	
	// Try to create output array.
	output = FlaggedEdgeArray_New(verticesNo);
	if (output) {
		// Reset output array.
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
