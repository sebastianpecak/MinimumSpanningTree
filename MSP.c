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
	// This array binds initial forest edges with input edges.
	FlaggedInputEdge_t** inputRefsArray = NULL;
	
	// Try to create output array.
	output = FlaggedEdgeArray_New(verticesNo);
	if (output) {
		// Try to create refs array.
		inputRefsArray = (FlaggedInputEdge_t**)malloc(sizeof(FlaggedInputEdge_t*) * verticesNo);
		// Check for error.
		if (inputRefsArray) {
			// Reset output array and refs.
			for (iter = 0; iter < output->ElementsCount; ++iter) {
				FlaggedEdge_Reset(FlaggedEdgeArray_GetIndex(output, iter));
				inputRefsArray[iter] = NULL;
			}
				
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
					inputRefsArray[value->Edge.VerticeA] = value;
					// Set usage flag.
					value->Flags |= FLAG_USED;
				}
				// Value was already set, so compare is new edge is less costly.
				else {
					if (outVal->Edge.Weight > value->Edge.Weight) {
						// Set.
						outVal->Edge.EndPoint = value->Edge.VerticeB;
						outVal->Edge.Weight = value->Edge.Weight;
						// Reset usage flag.
						inputRefsArray[value->Edge.VerticeA]->Flags &= ~FLAG_USED;
						// Set new ref.
						inputRefsArray[value->Edge.VerticeA] = value;
						// Set usage flag.
						value->Flags |= FLAG_USED;
					}
				}
				///////////////////////////////////////////////
				// VERTICE-B.
				outVal = FlaggedEdgeArray_GetIndex(output, value->Edge.VerticeB);
				if (outVal->Edge.EndPoint == EDGE_NOT_SET) {
					outVal->Edge.EndPoint = value->Edge.VerticeA;
					outVal->Edge.Weight = value->Edge.Weight;
					inputRefsArray[value->Edge.VerticeB] = value;
					// Set usage flag.
					value->Flags |= FLAG_USED;
				}
				// Value was already set, so compare is new edge is less costly.
				else {
					if (outVal->Edge.Weight > value->Edge.Weight) {
						// Set.
						outVal->Edge.EndPoint = value->Edge.VerticeA;
						outVal->Edge.Weight = value->Edge.Weight;
						// Reset usage flag.
						inputRefsArray[value->Edge.VerticeB]->Flags &= ~FLAG_USED;
						// Set new ref.
						inputRefsArray[value->Edge.VerticeB] = value;
						// Set usage flag.
						value->Flags |= FLAG_USED;
					}
				}
			}
		}
		else {
			Array_Delete(&output);
			LastError = "MSP_CreateInitialForest() -> Could not create refs array.";
		}
	}
	else
		// Set LastError.
		LastError = "MSP_CreateInitialForest() -> Could not create new Array object.";
	
	// Return output value.
	return output;
}

///////////////////////////////////////////////
size_t MSP_NormalizeForest(FlaggedEdgeArray_t forest) {
	// Number of edges after normalization.
	size_t normalizedEdgesNo = 0;
		
	// Return result.
	return 0;
}
