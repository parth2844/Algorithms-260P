#ifndef __PROJ_3_HPP
#define __PROJ_3_HPP

#include <vector>

/*
 * given this graph, this computes a TSP journey by using the NNA algorithm from 
 * lecture (shown on February 26).  
 * The given graph is a complete graph;  for all vertices i !=j, graph[i][j] > 0 and represents distance i to j.
 * graph[i][j] will only equal 0 for the case of i=j.
 * Note that unlike project 2, we are not guaranteed a metric space anymore.
*/
std::vector<unsigned> TSP_via_NNA(const std::vector< std::vector<unsigned> > & graph, unsigned start); 

unsigned getMinVertex(const std::vector<unsigned> currentVertex, std::vector<bool> &visited);

std::vector<unsigned> TSP_via_greedyEdge(const std::vector< std::vector<unsigned> > & graph);

/* 
 * Performs an order crossover of j1 and j2 and returns the two children as a vector of size two.
 * If we were going to do the example from lecture on Feb 26, pickStart and pickLen would both be 3.
 *		pickStart means which index (vector zero-based indices) the crossover begins, while
 *		pickLen means how many total vertices are in the length.
 */
std::vector< std::vector<unsigned> > orderCrossover(const std::vector<unsigned> & j1, const std::vector<unsigned> & j2, unsigned pickStart, unsigned pickLen);


/*
 * Performs a mutation of the given journey, as shown in lecture on Feb 26.
 * The journey is going to mutate a total of mutateLength vertices.
 * The first is at journey[mutateStart].
 * The example shown in lecture would have mutateLength of 4 and mutateStart = 2 (for a 0-based vector).
 */
std::vector<unsigned> mutation(const std::vector<unsigned> & journey, unsigned mutateStart, unsigned mutateLength);


/*
 * Forms a new journey in the following fashion:
 	* Construct a union graph of the two journeys, as shown in lecture on Feb 26
 	* Form a path starting at 'start' as follows:
 		* The first numFromUnion edges followed should be done via NNA in the Union Graph.
 			* For these, if there is not a feasible edge, draw from the full graph 
 				instead on a case-by-case basis, returning to the union graph for the next edge as needed.
 		* After numFromUnion edges have been selected, draw the remaining from the original graph.
 		* 		You are guaranteed in my test cases that numFromUnion < j1.size() (i.e., you'll never be told to add more than you can)
 */
std::vector<unsigned> unionGraphReproduce(const std::vector<unsigned> & j1, const std::vector<unsigned> & j2, 
										const std::vector< std::vector<unsigned> > & graph, unsigned start, unsigned numFromUnion);



#endif
