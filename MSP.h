#ifndef MSP_H
#define MSP_H

#include <FlaggedEdge.h>

#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

///////////////////////////////////////////////
// This function create first initial forest from input flagged edges array.
// Used as first step in MSPbySebastianPecak alg.
// Returns new array.
FlaggedEdgeArray_t MSP_CreateInitialForest(const FlaggedInputEdgeArray_t edges, size_t verticesNo);

///////////////////////////////////////////////
// This function gererates unique forest, without duplicated edges.
// Returns new array.
// Parameter is MSP_CreateInitialForest output.
size_t MSP_NormalizeForest(FlaggedEdgeArray_t);

///////////////////////////////////////////////
// This function connects trees in forest with shorest paths.
Array* MSP_MergeForest(const Array* flaggedEdgeInput);

///////////////////////////////////////////////
const char* MSP_GetLastError(void);

#ifdef __cplusplus
}
#endif	// __cplusplus

#endif	// MSP_H
