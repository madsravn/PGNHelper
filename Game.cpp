#include "Game.hpp"


Game::Game() {
    enums = {"Event", "Site", "Date", "White", "Black", "Result", "WhiteElo", "BlackElo", "TimeControl", "Termination"};
    list = {"","","","","","","","","",""};
};

void
Game::parse(std::string line) {
    std::istringstream str(line);
    if(line.at(0) == '[') {
        char a;
        str >> a;
        std::string event;
        str >> event;
        std::cout << event << std::endl;
        int index = std::find(enums.begin(),enums.end(), event) - enums.begin();
        std::cout << index << std::endl;
        if(index < enums.size()) {
            str >> std::ws;
            str >> a;
            std::string name;
            // Change to a more stringstream friendly way
            std::getline(str,name);
            std::string::size_type end = name.find_first_of("\"");
            name = name.substr(0,end);
        }
    }
}
