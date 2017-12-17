#ifndef TOOLS_H
#define TOOLS_H

#include <FlaggedEdge.h>

#define EDGE_VALUE_SEPARATOR "-"
#define EDGES_SEPARATOR ","

#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

///////////////////////////////////////////////
// This function accepts string formatted like this:
// "a-b-10,a-d-12,..."
// Veritces are letters from a-z.
// Returns valid pointer to Array of edges (on success).
FlaggedInputEdgeArray_t ParseEdgesList(const char* egdes);

///////////////////////////////////////////////
void PrintFlaggedInputEdgeArray(FlaggedInputEdgeArray_t);

#ifdef __cplusplus
}
#endif	// __cplusplus

#endif	// TOOLS_H
