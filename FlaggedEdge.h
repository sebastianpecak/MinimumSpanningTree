#ifndef FLAGGEDEDGE_H
#define FLAGGEDEDGE_H

#include <Edge.h>
#include <Array.h>

///////////////////////////////////////////////
#define FlaggedEdgeArray_GetIndex(array, index) \
	((FlaggedEdge_t*)Array_GetIndex((array), (index)))
	
///////////////////////////////////////////////
#define FlaggedEdgeArray_New(size) \
	Array_New((size), sizeof(FlaggedEdge_t))
	
///////////////////////////////////////////////
#define FlaggedInputEdgeArray_GetIndex(array, index) \
	((FlaggedInputEdge_t*)Array_GetIndex((array), (index)))
	
///////////////////////////////////////////////
#define FlaggedInputEdgeArray_New(size) \
	Array_New((size), sizeof(FlaggedInputEdge_t))
	
///////////////////////////////////////////////
enum _EdgeFlagValues_t {
	FLAG_USED = 1,
	FLAG_EXCLUDED = 2
};

///////////////////////////////////////////////
// Flags field used to detremine multiple Edge states.
typedef unsigned char EdgeFlag_t;

///////////////////////////////////////////////
struct _FlaggedEdge_t {
	EdgeFlag_t Flags;
	OffsetEdge_t Edge;
	
};

///////////////////////////////////////////////
typedef struct _FlaggedEdge_t FlaggedEdge_t;
typedef Array* FlaggedEdgeArray_t;

///////////////////////////////////////////////
struct _FlaggedInputEdge_t {
	EdgeFlag_t Flags;
	InputEdge_t Edge;
};

///////////////////////////////////////////////
typedef struct _FlaggedInputEdge_t FlaggedInputEdge_t;
typedef Array* FlaggedInputEdgeArray_t;

#ifdef __cplusplus
extern "C" {
#endif	// __cplusplus

///////////////////////////////////////////////
void FlaggedEdge_Reset(FlaggedEdge_t*);

///////////////////////////////////////////////
//void FlaggedInputEdge_Reset(FlaggedInputEdge_t*);

#ifdef __cplusplus
}
#endif	// __cplusplus

#endif	// FLAGGEDEDGE_H
