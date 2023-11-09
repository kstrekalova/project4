#include "HotPotato.hpp"
#include "QueueOfStrings.hpp"

#include <istream>  
#include <iostream>
#include <vector>

// You may want to #include others that we have talked about

/*
Parameters: 
    &in is a stream for a file, which contains 1+ names of people/players on separate lines
    numOfPasses contains the number of times the potato should be passed in each round
Return: "[Player x] burned their hands on the potato and had to sit out."
*/
std::string playHotPotato(std::istream &in, const std::vector<unsigned> & numOfPasses)
{
    // Create a new QueueOfStrings for all the players
    QueueOfStrings players;

    // In QueueOfStrings terms, player's names are stored as Node values
    std::string name;
    in >> name;
    while( name.length() > 0 )
    {
        players.enqueue( name );
        in >> name;
    }

    // Do not proceed if no players were added or vector is empty.
    if ( players.isEmpty() ) { 
        std::cout << "No players' names in file";
        exit(0);
    }
    if ( numOfPasses.empty() ) {
        std::cout << "No passes in vector";
        exit(0);
    }
    
    // Play the game until one player remains, looping through numOfPasses 
    // as many times as necessary.
    unsigned numPasses;
    
        // Failed attempts to resolve problem w size of players vs 1:
        // error: line 43: 3107002 Segmentation fault      (core dumped)... 
    // while ( players.size() > 1 ) {  //bad
    // while ( static_cast<int>(players.size()) > 1 ) { //bad
    //size_t players_length = (size_t) players.size();  //bad
    
    while ( players.size() > 1 ) {

        // Pass through entire numOfPasses vector (unless players.size() reaches 1)
        for ( unsigned i = 0; i < numOfPasses.size(); i++ ) {

            // if after any # of passes, there's one player left, return name
            if ( players.size() == 1 ) { return players.front(); }

            numPasses = numOfPasses[i];
            
            // enqueue/dequeue front of vector #=numPasses times
            for ( unsigned j = 0; j < numPasses; j++ ) {
                players.enqueue( players.front() );
                players.dequeue();
            }

            // dequeue front of vector: that player is holding the potato
            players.dequeue();
        }
    }
    
    return players.front();
}
