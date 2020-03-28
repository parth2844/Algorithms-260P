#include "proj2.hpp"
#include <queue> // This is where std::priority_queue lives.
#include <stack> // you may want std::stack for your depth-first traversal.
#include <iostream>
#include <limits>
#include <iostream>
#include <utility>
#include <list>


// Your function MAY assume that this is a complete graph (as that is part of project specification).
std::vector<Edge> compute_mst(std::vector< std::vector<unsigned>> & graph)
{
	int V = graph.size();
	std::vector<Edge> mst;
	Edge temp(0,0,UINT_MAX);
	for(int i = 0; i < V-1; i++)
		mst.push_back(temp);
	std::priority_queue< std::pair<unsigned, unsigned>, std::vector <std::pair<unsigned, unsigned>> , std::greater<std::pair<unsigned, unsigned>> > pq; 
  
	std::vector<bool> includedVertex(V, false);
	std::vector<unsigned> edgeWeight(V, UINT_MAX);
	edgeWeight[0] = 0;
	
	//push weight, source onto the priority queue -> we start with 0 as our source/starting vertex
	pq.push(std::make_pair(0,0));
	while(!pq.empty()){
		unsigned start = pq.top().second;
		pq.pop();
		includedVertex[start] = true;
		for(unsigned i = 1; i < V; i++){
			//store the end point of the edge
			unsigned end = i;
			unsigned weight = graph[start][i];
			if(includedVertex[end] == false && weight < edgeWeight[end]){
				edgeWeight[end] = weight;
				pq.push(std::make_pair(weight, end));
				Edge current(start, end, weight);
				mst[end-1] = current;
			}
		}
	}
	return mst;
}


// Returns the cost of the edges in the given vector,
// This does not confirm that it is a MST at all.
unsigned mstCost(const std::vector<Edge> & vE) 
{
	unsigned sum =0;
	for(auto e: vE)
	{
		sum += e.weight;
	}
	return sum;
}

unsigned costOfJourney(const std::vector<std::vector<unsigned>> & graph, const std::vector<unsigned> & journey)
{
	unsigned cost = 0;
	for(auto i=0;i<journey.size()-1;i++){
		cost= cost+graph[journey[i]][journey[i+1]];
	}
	cost+=graph[journey[journey.size()-1]][journey[0]];
	return cost; 
}

unsigned waste(const std::vector<Edge> & tree, const std::vector<unsigned> & journey, const std::vector<std::vector<unsigned>> & graph)
{	
	int tsp_cost=costOfJourney(graph, journey);
	int mst_cost=mstCost(tree);
	//std::cout<<"TSP"<<tsp_cost<<"MST"<<mst_cost<<std::endl;
	return tsp_cost-mst_cost; // stub, incorrect answer. 
}


void DFS(unsigned v, std::vector<bool> &visited, std::vector<std::vector<unsigned>> adjMatrix, std::vector<unsigned> &journey) 
{ 
    // Mark the current node as visited and 
    // print it 
    visited[v] = true; 
    journey.push_back(v);

    // Recur for all the vertices adjacent 
  	std:: vector<unsigned>::iterator i;
    for (i = adjMatrix[v].begin(); i < adjMatrix[v].end(); i++) 
       if (!visited[*i]) 
            DFS(*i, visited, adjMatrix, journey);
            
           
}

std::vector<unsigned> computeTSPJourney(const std::vector< Edge > & mst, unsigned start)
{
	std::vector<unsigned> journey;
	int V= mst.size()+1;
	std::vector<bool> visited(V,false);
	std::vector<std::vector<unsigned>> adjMatrix(V);
	//std::cout<<"Adjacency size"<<adjMatrix.size()<<std::endl;
	for(unsigned i = 0; i <mst.size(); i++){
		int start = mst[i].pt1, end = mst[i].pt2;
		adjMatrix[start].push_back(end);
		adjMatrix[end].push_back(end);
	}
	//unsigned start = 0;

	DFS(0, visited, adjMatrix, journey);

	return journey; 
}
