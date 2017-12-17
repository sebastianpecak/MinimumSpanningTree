#include <FlaggedEdge.h>

///////////////////////////////////////////////
void FlaggedEdge_Reset(FlaggedEdge_t* edge) {
	edge->Edge.EndPoint = EDGE_NOT_SET;
	edge->Edge.Weight = 0;
	edge->Flags = 0;
}
