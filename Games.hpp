#ifndef GAMES_HPP_
#define GAMES_HPP_
#include "Game.hpp"
#include <map>
class Games {
    public:
        Games();
        Games(std::vector<Game> games);
        void openFile(std::string tfile);
        size_t getSize();
        Games getGamesWonBy(std::string winner);
        Games getGamesLostBy(std::string loser);
        std::vector<std::string> getMonths();
        void addGame(Game game);
        std::map<std::string, Games> getGamesByMonth();
        Games getGamesByMonth(std::string month);
        Games getDrawGames();
        Games getGamesByType(std::string type);
        Games wonAsBlack();
        Games wonAsWhite();
        Games lostAsWhite();
        Games lostAsBlack();
        Games drawAsWhite(std::string name);
        Games drawAsBlack(std::string name);
    private:
        std::vector<Game> pgames;





};



#endif
