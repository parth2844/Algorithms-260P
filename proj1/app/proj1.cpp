#include "proj1.hpp"
#include <iostream> // for debug purposes, see project description for a suggestion.
#include <limits> // for UINT_MAX
#include <math.h>
/*
// Solve TSP exactly, using dynamic programming.
// The grading script will use this exact function signature, so do not change it!
// The graph is given as an adjacency matrix, HOWEVER, no edges have a cost of '0'.
// The value graph[i][j] tells you the cost of an edge from i TO j.  This graph is directed.
// 		However, if graph[i][j]==0, this means there is no edge from i to j, instead of having one of that cost.
*/
bool check(unsigned i, unsigned currNode,const std::vector<std::vector<long>> & graph, unsigned target,const std::vector<std::vector<long>> &opt,long min){
	if((i & ((unsigned)pow(2,(currNode-1)))) != 0) {
		if(graph[currNode][target] != 0 && opt[i-pow(2,(currNode-1))][currNode] != LONG_MAX) {
			if(graph[currNode][target] + opt[i-pow(2,(currNode-1))][currNode] < min){
				return true;
			}
		}
	}
	return false;
}

void get_tsp(const std::vector<std::vector<long>> & graph, unsigned n, std::vector<std::vector<long>> &opt, std::vector<std::vector<long>> &parent, unsigned subset){

	for(unsigned i=0;i<subset ;i++) {
		// Base case intialization for i=0
		if(i==0){
			for(int index=1;index<n;index++) {
				if(graph[0][index]!=0) {
					opt[0][index] = graph[0][index];
					parent[0][index] = 0;
				}
			}
		}
		else{
			//get the minimum cost to reach the target via  currNode
			for(unsigned target= 1 ; target< n ;target++) {
				long min = LONG_MAX;
				unsigned predecessor = 0;
				if((i & ((unsigned)pow(2,(target-1)))) == 0) {
					for(unsigned currNode=1;currNode<n;currNode++) {
						if(check(i,currNode,graph,target,opt,min)) //check if the currNode is in the subset and if there is an edge that connects currNode to target 
						{
							min = opt[i-pow(2,(currNode-1))][currNode] + graph[currNode][target];//get minimum value
							predecessor = currNode;
						}
					}
				}
				//storing the value in opt matrix for memoization
				opt[i][target] = min;
				parent[i][target] = predecessor;
			}
		}
	}
	
}


std:: vector<unsigned> get_tsp_path(const std::vector<std::vector<long>> & graph, unsigned subset,std::vector<std::vector<long>> opt, std::vector<std::vector<long>> &parent){
	long total= __LONG_MAX__;
	unsigned currPar;
	long visited = 0;
	std::vector<unsigned> journey;

	for(unsigned i=1;i<graph.size();i++) {
		if(graph[i][0]!=0) {
			if(total>opt[subset - pow(2,(i-1))][i] + graph[i][0]) {
				total = opt[subset - pow(2,(i-1))][i] + graph[i][0];
				currPar = i;
			}
		}
	}

	//If total=Max value that means the path does not exist hence return empty vector 
	if(total==__LONG_MAX__) {
		return journey;
	} 
	// If a valid path exists return path
	
	while(currPar!= 0) {
		journey.push_back(currPar);
		visited = visited + pow(2,(currPar-1));
		currPar = parent[subset-visited][currPar];
	}

	journey.push_back(0);
	reverse(journey.begin(),journey.end());
	
	return journey;
	
}
std::vector<unsigned> tsp_dynamic_program(const std::vector<std::vector<long>> & graph, unsigned n)
{
	
	unsigned subset = pow(2,(n-1)) - 1;
	std::vector<std::vector<long>>opt(subset, std::vector<long> (n,__LONG_MAX__));
	std::vector<std::vector<long>> parent(subset, std::vector<long> (n));
	
	get_tsp(graph, n, opt,parent,subset);	// Function to fill the values in opt matrix

	return get_tsp_path(graph,subset, opt,parent); // Returning the result path
}


// Returns the cost of the journey described here.
long costOfJourney(const std::vector<std::vector<long>> & graph, const std::vector<unsigned> & journey)
{
	long cost=0;
	// Adding the cost to travel to each node in journey vector
	for(auto i=0;i<journey.size()-1;i++){
		cost= cost+graph[journey[i]][journey[i+1]];
	}
	cost+=graph[journey[journey.size()-1]][journey[0]];
	return cost;  
}

