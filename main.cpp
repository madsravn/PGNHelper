#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Game.hpp"
#include "Parser.hpp"
#include "Games.hpp"
int main(int argc, const char **argv) {
    bool STRtags = false; 
    std::string line;
    //Parser parser;
    if(argc > 1) {
        // Open argument as file
        //parser.parse(std::string(argv[1]));
    
        //games = parser.games();
        Games games;
        games.openFile(std::string(argv[1]));
        std::cout << games.getSize() << " games were parsed." << std::endl;
        Games madswon = games.getGamesWonBy("madsravn");
        std::cout << "Madsravn won " << madswon.getSize() << " of those games" << std::endl;
    } else {
        std::cout << "Takes one argument, the file which needs to be parsed." << std::endl; 
    }

    return 0;
}
