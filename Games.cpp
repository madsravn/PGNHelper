#include "Games.hpp"
#include "Parser.hpp"
#include <algorithm>
Games::Games() {

}

Games::Games(std::vector<Game> games) {
    pgames = games;
}

void
Games::openFile(const std::string& tfile) {
    Parser parser;
    parser.parse(tfile);
    pgames = parser.games();
}

Games
Games::getGamesWonBy(const std::string& winner) {
    std::vector<Game> games;
    for(Game &game : pgames) {
        if(game.getWinner().find(winner) == 0) {
            games.push_back(game);
        }
    }
    return games;
}

Games
Games::getGamesLostBy(const std::string& loser) {
    std::vector<Game> games;
    for(auto &game : pgames) {
        if(game.getLoser().find(loser) == 0) {
            games.push_back(game);
        }
    }
    return games;
}

std::vector<std::string>
Games::getMonths() {
    std::vector<std::string> months;
    for(Game &game : pgames) {
        std::string month = game.getMonth();
        auto index = std::find(months.begin(), months.end(), month);
        if(index == months.end()) {
            months.push_back(month);
        }
    }
    std::sort(months.begin(), months.end());
    return months;
}

Games
Games::getGamesByMonth(const std::string& month) {
    std::vector<Game> games;
    for(auto &game : pgames) {
        if(game.getMonth() == month) {
            games.push_back(game);
        }
    }
    Games rgames(games);
    return rgames;
}

void
Games::addGame(Game game) {
    pgames.push_back(game);
}

std::map<std::string, Games>
Games::getGamesByMonth() {
    std::map<std::string, Games> games;
    for(auto &game : pgames) {
        auto it = games.find(game.getMonth());
        if(it != games.end()) {
            games.at(game.getMonth()).addGame(game);
        } else {
            Games gamestemp;
            gamestemp.addGame(game);
            std::string month = game.getMonth();
            games.insert(std::make_pair(month, gamestemp));
            //games[month] = gamestemp;
        }
    }
    return games;
}

Games
Games::getDrawGames() {
    std::vector<Game> games;
    for(auto &game : pgames) {
        if(game.getDraw() == true) {
            games.push_back(game);
        }
    }
    Games rgames(games);
    return rgames;
}

Games
Games::getGamesByType(const std::string& type) {
    std::vector<Game> games;
    for(auto &game : pgames) {
        if(game.getType() == type) {
            games.push_back(game);
        }
    }
    Games rgames(games);
    return rgames;
}

Games
Games::wonAsBlack() {
    std::vector<Game> games;
    for(auto &game : pgames) {
        if(game.getResult() == "0-1") {
            games.push_back(game);
        }
    }
    Games rgames(games);
    return rgames;
}

Games
Games::wonAsWhite() {
    std::vector<Game> games;
    for(auto &game : pgames) {
        if(game.getResult() == "1-0") {
            games.push_back(game);
        }
    }
    Games rgames(games);
    return rgames;
}

Games
Games::lostAsBlack() {
    return wonAsWhite();
}

Games
Games::lostAsWhite() {
    return wonAsBlack();
}

Games
Games::drawAsWhite(const std::string& name) {
    std::vector<Game> games;
    for(auto &game : pgames) {
        if(game.getWhite().find(name) == 0  && game.getResult() == "½-½") {
            games.push_back(game);
        }
    }
    return games;
}

Games
Games::drawAsBlack(const std::string& name) {
    std::vector<Game> games;
    for(auto &game : pgames) {
        if(game.getBlack().find(name) == 0 && game.getResult() == "½-½") {
            games.push_back(game);
            }
    }
    return games;
}
