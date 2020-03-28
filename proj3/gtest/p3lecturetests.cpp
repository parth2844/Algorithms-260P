#include <vector>
#include <gtest/gtest.h>
#include "proj3.hpp"
#include "../include/ver.hpp"

/*
 * As always, remember:

 		Be sure to add additional test cases to test your code.
 		This is a starting point, not a conclusion.
 */


namespace{

TEST(LectureTests, NNA1)
{
	std::vector< std::vector<unsigned> > graph = {
		{ 0, 4, 5, 2},
		{ 4, 0, 1, 3},
		{ 5, 1, 0, 6},
		{ 2, 3, 6, 0}
	};
	std::vector<unsigned> j = TSP_via_NNA(graph, 0);
	EXPECT_TRUE(ver_TSP_via_NNA( graph, 0, j ) );
}

/*
TEST(LectureTests, GEA1)
{
	std::vector< std::vector<unsigned> > graph = {
		{ 0, 4, 5, 2},
		{ 4, 0, 1, 3},
		{ 5, 1, 0, 6},
		{ 2, 3, 6, 0}
	};
	std::vector<unsigned> j = TSP_via_greedyEdge(graph);
	EXPECT_TRUE(ver_TSP_via_greedyEdge( graph, j ) );
}
*/
TEST(LectureTests, LectureOrderCrossover)
{
	std::vector<unsigned> p1 = {2, 1, 3, 9, 5, 4, 8, 7, 6};
	std::vector<unsigned> p2 = {5, 3, 2, 6, 8, 9, 7, 1, 4};
	auto r = orderCrossover(p1, p2, 3,3);

	bool c1is = ver_isAnOrderCrossover(p1, p2, 3, 3, r[0] ) or ver_isAnOrderCrossover(p2, p1, 3, 3, r[0] );
	bool c2is = ver_isAnOrderCrossover(p1, p2, 3, 3, r[1] ) or ver_isAnOrderCrossover(p2, p1, 3, 3, r[1] );
	bool differ = (r[0] != r[1]);
	EXPECT_TRUE(c1is and c2is and differ);
}

TEST(LectureTests, LectureMutation)
{
	std::vector<unsigned> in = {4, 2, 1, 5, 3, 7, 6, 8};
	std::vector<unsigned> out = mutation(in, 2, 4);

	EXPECT_TRUE( ver_mutation(in, 2, 4, out) );
}


/*
TEST(LectureTests, LectureUnionGraphTest)
{
	std::vector<unsigned> j1 = {0, 1, 2, 3, 4, 5};
	std::vector<unsigned> j2 = {0, 2, 1, 3, 5, 4};
	std::vector< std::vector<unsigned> > graph = {
		// graph from lecture, with extra edges added higher fictitiously.
		{0, 1, 8, 9, 2, 7}, 
		{1, 0, 4, 6, 10, 11},
		{8, 4, 0, 5, 13, 12}, 
		{9, 6, 5, 0, 2, 4}, 
		{2, 10, 13, 2, 0, 3}, 
		{7, 11, 12, 4, 3, 0}
	};
	std::vector<unsigned> result = unionGraphReproduce(j1, j2, graph, 0, 5);
	EXPECT_TRUE( ver_unionGraphReproduce(j1, j2, graph, 0, 5, result) );

}

TEST(ExtraCases, ExtraOrderCrossover)
{
	std::vector<unsigned> p1 = { 14, 20, 16, 19, 15, 12, 9, 10, 11, 4, 1, 8, 3, 18, 17, 2, 6, 13, 5, 7};
	std::vector<unsigned> p2 =  { 8, 3, 9, 14, 7, 11, 20, 12, 2, 4, 5, 17, 10, 16, 18, 6, 13, 19, 1, 15};

	auto r = orderCrossover(p1, p2, 5, 7);

	bool c1is = ver_isAnOrderCrossover(p1, p2, 5, 7, r[0] ) or ver_isAnOrderCrossover(p2, p1, 5, 7, r[0] );
	bool c2is = ver_isAnOrderCrossover(p1, p2, 5, 7, r[1] ) or ver_isAnOrderCrossover(p2, p1, 5, 7, r[1] );
	bool differ = (r[0] != r[1]);
	EXPECT_TRUE(c1is and c2is and differ);
}

*/


}