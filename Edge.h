#ifndef EDGE_H
#define EDGE_H

///////////////////////////////////////////////
#define EDGE_NOT_SET 0

///////////////////////////////////////////////
// This is type for vertices.
// Here vertices are just natural numbers.
typedef unsigned int Vertice_t;

///////////////////////////////////////////////
// Particual edge weigth type.
// Used in alg to decide which way in graph is less costly to go.
typedef int EdgeWeight_t;

///////////////////////////////////////////////
// Offset egde is used when storing edges in array with constant offset.
struct _OffsetEdge_t {
	Vertice_t EndPoint;
	// This edge wieght.
	EdgeWeight_t  Weight;
};

///////////////////////////////////////////////
typedef struct _OffsetEdge_t OffsetEdge_t;

///////////////////////////////////////////////
struct _InputEdge_t {
	Vertice_t VerticeA;
	Vertice_t VerticeB;
	// This edge wieght.
	EdgeWeight_t  Weight;
};

///////////////////////////////////////////////
typedef struct _InputEdge_t InputEdge_t;

#endif	// EDGE_H
