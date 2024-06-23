#include "doctest.h"
#include <iostream>
#include <ostream>
#include <sstream>
#include "kosaraju_linkedList.hpp"
#include "kosaraju_stack.hpp"
#include "kosaraju_matrix.hpp"

TEST_CASE("Testing linked list implimentation")
{
     int vertices = 8;
        linkedList::Graph *graph = linkedList::createGraph(vertices);
        linkedList::addEdge(graph, 1, 2);
        linkedList::addEdge(graph, 2, 3);
        linkedList::addEdge(graph, 3, 4);
        linkedList::addEdge(graph, 4,5);
        linkedList::addEdge(graph, 5, 1);
        linkedList::addEdge(graph, 6, 7);
        linkedList::addEdge(graph, 7, 6);

    SUBCASE("Test number of vertices")
    {
        CHECK(graph->numVertices == 8);
    }

    SUBCASE("Test adjacency lists")
    {
        CHECK(graph->adjLists[0] != nullptr);
        CHECK(graph->adjLists[1] != nullptr);
    }

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    linkedList::kosaraju(graph);

    std::cout.rdbuf(p_cout_streambuf); // restore

 std::string expectedOutput = " 5 4 3 2 1\n 7 6\n 8\n";

    // Check if the output stream was captured correctly
    CHECK(oss.str() == expectedOutput);

    // Free the graph memory
    linkedList::freeGraph(graph);
}
TEST_CASE("Testing stack implimentation")
{
    stack::Graph* graph = stack::createGraph(5);

    stack::addEdge(graph, 1, 2);
    stack::addEdge(graph, 2, 3);
    stack::addEdge(graph, 3, 1);
    stack::addEdge(graph, 3, 4);
    stack::addEdge(graph, 4, 5);

    SUBCASE("Test number of vertices")
    {
        CHECK(graph->numVertices == 5);
    }

    SUBCASE("Test adjacency lists")
    {
        CHECK(graph->adjLists[0] != nullptr);
        CHECK(graph->adjLists[1] != nullptr);
    }

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    stack::kosaraju(graph);

    std::cout.rdbuf(p_cout_streambuf); // restore

    std::string expectedOutput = " 1 3 2\n 4\n 5\n";

    // Check if the output stream was captured correctly
    CHECK(oss.str() == expectedOutput);

    // Free the graph memory
    stack::freeGraph(graph);
}
TEST_CASE("Testing matrix algorithm")
{
    matrix::Graph* graph = matrix::createGraph(5);

    matrix::addEdge(graph, 1, 2);
    matrix::addEdge(graph, 2, 3);
    matrix::addEdge(graph, 3, 1);
    matrix::addEdge(graph, 3, 4);
    matrix::addEdge(graph, 4, 5);

    SUBCASE("Test number of vertices")
    {
        CHECK(graph->numVertices == 5);
    }

 

    std::ostringstream oss;
    std::streambuf* p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());

    matrix::kosaraju(graph);

    std::cout.rdbuf(p_cout_streambuf); // restore

    std::string expectedOutput = " 1 3 2\n 4\n 5\n";

    // Check if the output stream was captured correctly
    CHECK(oss.str() == expectedOutput);

    // Free the graph memory
  //  matrix::freeGraph(graph);
}
