#include "Parser.hpp"
#include <fstream>

Parser::Parser() {

}

void
Parser::parse(std::string tfile) {
    std::ifstream file;
    std::string line;
    Game game;
    bool STRtags = false;
    file.open(tfile);
    if(file.is_open()) {
        while(file.good()) {
            std::getline(file,line);
            //std::cout << line << std::endl;
            if(line.length() > 0) {
                if(STRtags == false && line.at(0) == '[') {
                    STRtags = true;
                    pgames.push_back(game);
                    game = Game();
                }
                if(STRtags == true && line.at(0) != '[') {
                    STRtags = false;
                }
                game.parse(line);
            }
        }
        file.close();
        pgames.push_back(game);
    }
    pgames.erase(pgames.begin());
}

std::vector<Game>
Parser::games() {
    return pgames;
}
