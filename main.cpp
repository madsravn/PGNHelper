#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Game.hpp"
int main(int argc, const char **argv) {
    bool STRtags = false; 
    std::string line;
    std::vector<Game> games;
    Game game;
    if(argc > 1) {
        // Open argument as file
        std::ifstream file;
        file.open(std::string(argv[1]));
        if(file.is_open()) {
            while(file.good()) {
                std::getline(file,line);
                std::cout << line << std::endl;
                if(line.length() > 0) {
                    if(STRtags == false && line.at(0) == '[') {
                        STRtags = true;
                        games.push_back(game);
                        game = Game();
                    }
                    if(STRtags == true && line.at(0) != '[') {
                        STRtags = false;
                    }
                    game.parse(line);
                }
            }
            file.close();
            games.push_back(game);
        }
    games.erase(games.begin());
    std::cout << games.size() << " games were parsed." << std::endl;
    } else {
        std::cout << "Takes one argument, the file which needs to be parsed." << std::endl; 
    }

    return 0;
}
