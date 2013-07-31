#include "Games.hpp"
#include "Parser.hpp"

Games::Games() {

}

Games::Games(std::vector<Game> games) {
    pgames = games;
}

void
Games::openFile(std::string tfile) {
    Parser parser;
    parser.parse(tfile);
    pgames = parser.games();
}

size_t
Games::getSize() {
    return pgames.size();
}

Games
Games::getGamesWonBy(std::string winner) {
    std::vector<Game> games;
    for(Game &game : pgames) {
        if(game.getWinner().find(winner) == 0) {
            games.push_back(game);
        }
    }
    return games;
}
