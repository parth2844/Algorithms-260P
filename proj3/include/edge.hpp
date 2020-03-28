/*
DO NOT MODIFY THIS FILE (or create another class called 'Edge').

Edge struct with < and == operators defined.  == means weight the same AND endpts match, but endpts in either order.

This is for the interface of Edge. 

If you want a different comparison operator (e.g., you want to call std::sort), 
you will need to create your own comparator.  How to do that in C++ is something 
you are allowed to look up online, or ask for help for on Piazza, or ask your 
professor to help you out. 
*/

#ifndef __GRAPH_EDGE_H
#define __GRAPH_EDGE_H

struct Edge{
	unsigned pt1, pt2;
	unsigned weight;
	Edge(unsigned u, unsigned v, unsigned wt) : pt1(u), pt2(v), weight(wt){}

	// This might look bad to you, but std::priority_queue uses a max heap.
	// So by defining the < as a greater-than (on weight), we get the effect
	// of a min heap.
	// This is not the most principled way to solve this problem, by the way.
	bool operator<(const Edge & e) const{
		return weight > e.weight;
	}

	// I consider two edges to be the same if they have the same endpoints
	// and the weights are the same.  This works for simple graphs, which
	// will be sufficient for this assignment. 
	bool operator==(const Edge & e){
		return weight == e.weight && ((pt1 == e.pt1 && pt2 == e.pt2) ||(pt2 == e.pt1 && pt1 == e.pt2));
	}
};


#endif 
