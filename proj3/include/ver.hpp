#include <vector>

// You do not need to, nor should you, modify anything in this file. 
// There is pre-included code that will use this to grade.


bool ver_TSP_via_NNA(const std::vector< std::vector<unsigned> > & graph, unsigned start, const std::vector<unsigned> & journey); 


bool ver_TSP_via_greedyEdge(const std::vector< std::vector<unsigned> > & graph, const std::vector<unsigned> & journey);

bool ver_isAnOrderCrossover(const std::vector<unsigned> & p1, const std::vector<unsigned> & p2, unsigned pickStart, unsigned pickLen, 
							const std::vector<unsigned> & res);

bool ver_mutation(const std::vector<unsigned> & journey, unsigned mutateStart, unsigned mutateLength, const std::vector<unsigned> & result);


bool ver_unionGraphReproduce(const std::vector<unsigned> & j1, const std::vector<unsigned> & j2, 
										const std::vector< std::vector<unsigned> > & graph, unsigned start, unsigned numFromUnion, 
										const std::vector<unsigned> & journey);
