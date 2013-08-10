#ifndef GAMES_HPP_
#define GAMES_HPP_
#include "Game.hpp"
#include <map>
class Games {
    public:
        Games();
        Games(std::vector<Game> games);
        void openFile(const std::string& tfile);
        size_t getSize() const { return pgames.size(); };
        Games getGamesWonBy(const std::string& winner);
        Games getGamesLostBy(const std::string& loser);
        std::vector<std::string> getMonths();
        void addGame(Game game);
        std::map<std::string, Games> getGamesByMonth();
        Games getGamesByMonth(const std::string& month);
        Games getDrawGames();
        Games getGamesByType(const std::string& type);
        Games wonAsBlack();
        Games wonAsWhite();
        Games lostAsWhite();
        Games lostAsBlack();
        Games drawAsWhite(const std::string& name);
        Games drawAsBlack(const std::string& name);
    private:
        std::vector<Game> pgames;
};

#endif
