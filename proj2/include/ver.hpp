// Everything in this file is used in grading.
// You DO NOT need to write these functions (nor should you).
// This needs to exist so the parts in gtest are aware of this.
// You never even need to call these from your code. 

#include "edge.hpp"
#include <vector>

// returns true iff mst is a MST of g.
bool verifyMST(const std::vector<Edge> & mst, const std::vector< std::vector< unsigned>  > &g);


// verifies that, in this graph, the given journey is valid from the start
// using the given MST.
bool verifyTSPJourney(unsigned n, const std::vector<unsigned> &journey, const std::vector< Edge > & mst, unsigned start);

// Confirms that waste is caluclated correctly. 
bool verifyWaste(const std::vector<Edge> & tree, const std::vector<unsigned> & journey, const std::vector<std::vector<unsigned>> & graph, unsigned waste);
