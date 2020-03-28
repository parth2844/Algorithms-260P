#ifndef __TSP_PROJ2_HPP
#define __TSP_PROJ2_HPP

#include <vector>
#include "edge.hpp"



// Compute the minimum spanning tree of the given graph and return it as a vector of Edge.
// Your function MAY assume that this is a complete graph (as that is part of project specification).
std::vector<Edge> compute_mst(std::vector< std::vector<unsigned> > & graph);

// Returns the cost of the edges in the given vector,
// This does not confirm that it is a MST at all.  
unsigned mstCost(const std::vector<Edge> & vE); 

// Returns a valid TSP journey for the original graph in this MST. 
// Do this by computing a depth-first traversal, from start, of the given MST. 
std::vector<unsigned> computeTSPJourney(const std::vector< Edge > & mst, unsigned start); 

// Cost of journey, with the allowance to take from previous project(s).
// Partners may take from any previous that one or both of them worked on.
// Note graph is unsigned now, not long. 
unsigned costOfJourney(const std::vector<std::vector<unsigned>> & graph, const std::vector<unsigned> & journey);

// Returns the difference between the cost of the given tree and the journey, both within the given graph.
// You may elect to reuse the work for costOfJourney from a previous project that one or both partners in 
// your group wrote or contributed to writing.  If you do so, please include a comment near that function's 
// declaration stating the name of the project partner and which project(s) the code was taken from. 
unsigned waste(const std::vector<Edge> & tree, const std::vector<unsigned> & journey, const std::vector<std::vector<unsigned>> & graph);

void DFS(unsigned v, std::vector<bool> &visited, std::vector<std::vector<unsigned>> adjMatrix, std::vector<unsigned> &journey) ;


#endif 
