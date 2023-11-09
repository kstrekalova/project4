#include "catch_amalgamated.hpp"
#include "QueueOfStrings.hpp"
#include "HotPotato.hpp"
#include <string>
#include <fstream>  


/*
 * Note how few test cases we have as required here.


 This DOES NOT mean there is very little to do; 
    This DOES mean you are expected to test your code.
    Note that we haven't even provided test cases that *call* 
        every function within QueueOfStrings.
        That would probably be a good first thing for you to write...
 */



namespace{



TEST_CASE("MyFirstEnqueue", "[RequiredQueue]")
{
    QueueOfStrings a;
    a.enqueue("Mike");
    REQUIRE( a.front() == "Mike" );
}

TEST_CASE("Dequeue; size; isEmpty", "[RequiredQueue]")
{
    QueueOfStrings a;
    a.enqueue("Mike");
    REQUIRE( a.size() == 1 );
    REQUIRE( a.isEmpty() == false );
    a.dequeue();
    REQUIRE( a.size() == 0 );
}

TEST_CASE("FrontThrowsWhenNone", "[RequiredQueue]")
{
    QueueOfStrings q;
    REQUIRE_THROWS_AS( q.front(), QueueEmptyException );
}


TEST_CASE("SimpleHotPotato", "[RequiredHotPotato]")
{
    std::ifstream in{"hp_names_1.txt"};
    std::vector<unsigned> numOfPasses{5, 3};
    REQUIRE("Lakshmi" == playHotPotato(in, numOfPasses));
}

TEST_CASE("Copy constructor w/ =", "[RequiredQueue]")
{
    QueueOfStrings a;
    QueueOfStrings b;
    a.enqueue("Mike");
    b = a;
    REQUIRE(b.front() == "Mike");
}
                      
} 

