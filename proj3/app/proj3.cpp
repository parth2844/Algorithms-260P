#include "proj3.hpp"
#include <vector>
#include <queue> // std::priority_queue lives here. 
#include <iostream>
#include <set>
#include "../include/edge.hpp"

std::vector<unsigned> TSP_via_NNA(const std::vector< std::vector<unsigned> > & graph, unsigned start)
{
	std::vector<unsigned> journey;
	std::vector<bool> visited(graph.size(),false);
	//Set starting vertex 0 to true
	visited[0]=true;
	journey.push_back(0);
	for(int i=1;i<visited.size();i++){
		unsigned current=0;
		//Get min distance vertex from current vertex
		unsigned v=getMinVertex(graph[current],visited);
		visited[v]=true;
		journey.push_back(v);
		current=v;
	}
	return journey;
}

unsigned getMinVertex(const std::vector<unsigned> currentVertex, std::vector<bool> &visited){
	int min=__INT_MAX__, index= -1;
	for(int i=0;i<currentVertex.size();i++){
		if(visited[i]==false){
			if(min>currentVertex[i]){
				min=currentVertex[i];
				index=i;
			}
		}
	}
	return index;
}


std::vector<unsigned> TSP_via_greedyEdge(const std::vector< std::vector<unsigned> > & graph)
{
	std::vector<unsigned> journey;
	return journey; 
}



std::vector< std::vector<unsigned> > orderCrossover(const std::vector<unsigned> & j1, const std::vector<unsigned> & j2, 
														unsigned pickStart, unsigned pickLen)
{
	std::vector< std::vector<unsigned> > children; // (2, std::vector<unsigned>());

	// I found it easier to start with the child of the right size
	// and use indexing to place the right elements.
	// Feel free to do something different.
	std::vector<unsigned> oneChild(j1.size());	
	std::vector<unsigned> otherChild(j2.size());
	
	unsigned len= j1.size();
	std:: set<int> s1,s2;
	for(unsigned i=pickStart;i<pickStart+pickLen;i++){
		s1.insert(j1[i]);
		s2.insert(j2[i]);
	}
	std:: vector<unsigned> temp1,temp2;
	unsigned itr=0;
	for(unsigned i2=pickStart;itr<len;i2++){
		if(s1.count(j2[i2%len])==0)
			temp1.push_back(j2[i2%len]);
		if(s2.count(j1[i2%len])==0)
			temp2.push_back(j1[i2%len]);
		itr++;
	}
	unsigned j=0;
	for(unsigned i=0;i<oneChild.size();i++){
		if(i<pickStart || i>=pickStart+pickLen){
			oneChild[i]=temp1[j];
			otherChild[i]=temp2[j];
			j++;
		}
		else{
			oneChild[i]=j1[i];
			otherChild[i]=j2[i];
		}
	}
	
	// Hint to make debugging and writing easier: 
	//		the procedure for one child and the other child is the same
	//		with a minor change.
	children.push_back( oneChild );
	children.push_back( otherChild );


	return children;
}



std::vector<unsigned> mutation(const std::vector<unsigned> & journey, unsigned mutateStart, unsigned mutateLength)
{
	// This starts with result as a copy of the initial journey.
	// As always, feel free to start differently (as long as your result is correct)
	std::vector<unsigned> result;
	int i=0;
	while(i<mutateStart){
		result.push_back(journey[i]);
		i++;
	}
	i+=mutateLength-1;
	while(i>=mutateStart){
		result.push_back(journey[i]);
		i--;
	}
	i=mutateStart+mutateLength;
	while(i<journey.size()){
		result.push_back(journey[i]);
		i++;
	}
	return result; 
}



std::vector<unsigned> unionGraphReproduce(const std::vector<unsigned> & j1, const std::vector<unsigned> & j2, 
										const std::vector< std::vector<unsigned> > & graph, unsigned start, unsigned numFromUnion)
{

	std::vector< unsigned> journey;

	return journey; 
}


