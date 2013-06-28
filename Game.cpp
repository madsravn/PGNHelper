#include "Game.hpp"


Game::Game() {
    enums = {"Event", "Site", "Date", "White", "Black", "Result", "WhiteElo", "BlackElo", "TimeControl", "Termination"};
    list = {"","","","","","","","","",""};
};

//TODO: Make decent. Currently doesn't work with commented PGN files (maybe more)
void
Game::parse(std::string line) {
    std::istringstream str(line);
    // Is it a STRtag? 
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
    } else {

        // It's chess notation or an "empty" line. Do something with it later.
        std::string move;
        while(str >> move) {
            if(move.find(".") != std::string::npos) {
                moves.push_back(move.substr(move.find(".")));
            } else {
                moves.push_back(move);
            }
        }
        
    }
}
