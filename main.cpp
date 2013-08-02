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
        games = games.getGamesByType("15|10");
        auto months = games.getMonths();
        for(auto &month : months) {
            std::cout << "Stats for " << month << std::endl;
            Games thismonth = games.getGamesByMonth(month);
            Games wonbyme = thismonth.getGamesWonBy("madsravn");
            Games drawGames = thismonth.getDrawGames();
            Games lostbyme = thismonth.getGamesLostBy("madsravn");
            std::cout << "Amount of games: " << thismonth.getSize() << std::endl;
            std::cout << "Won: " << wonbyme.getSize() << std::endl;
            std::cout << "==> As white: " << wonbyme.wonAsWhite().getSize() << std::endl;
            std::cout << "==> As black: " << wonbyme.wonAsBlack().getSize() << std::endl;
            std::cout << "Lost: " << lostbyme.getSize() << std::endl;
            std::cout << "==> As white: " << lostbyme.lostAsWhite().getSize() << std::endl;
            std::cout << "==> As black: " << lostbyme.lostAsBlack().getSize() << std::endl;
            std::cout << "Draw: " << drawGames.getSize() << std::endl; 
            std::cout << "==> As white: " << drawGames.drawAsWhite("madsravn").getSize() << std::endl;
            std::cout << "==> As black: " << drawGames.drawAsBlack("madsravn").getSize() << std::endl << std::endl;

        }
    } else {
        std::cout << "Takes one argument, the file which needs to be parsed." << std::endl; 
    }

    return 0;
}
