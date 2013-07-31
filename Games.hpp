#ifndef GAMES_HPP_
#define GAMES_HPP_
#include "Game.hpp"
class Games {
    public:
        Games();
        Games(std::vector<Game> games);
        void openFile(std::string tfile);
        size_t getSize();
        Games getGamesWonBy(std::string winner);
    private:
        std::vector<Game> pgames;





};



#endif
