#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Game.hpp"
#include "Parser.hpp"
int main(int argc, const char **argv) {
    bool STRtags = false; 
    std::string line;
    std::vector<Game> games;
    Parser parser;
    if(argc > 1) {
        // Open argument as file
        parser.parse(std::string(argv[1]));
    
        games = parser.games();
        std::cout << games.size() << " games were parsed." << std::endl;
    } else {
        std::cout << "Takes one argument, the file which needs to be parsed." << std::endl; 
    }

    return 0;
}
