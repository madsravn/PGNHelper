#ifndef GAME_HPP_
#define GAME_HPP_
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
class Game {
public:
    Game();
    void parse(std::string line);
private:
    std::vector<std::string> list;
    std::vector<std::string> enums;
    std::vector<std::string> moves;


};

#endif
