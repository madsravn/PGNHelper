#ifndef PARSER_HPP_
#define PARSER_HPP_
#include "Game.hpp"
class Parser {
    public:
        Parser();
        void parse(std::string tfile);
        std::vector<Game> games();
    private:
        std::vector<Game> pgames;

};
#endif
