#include "Game.hpp"


Game::Game() {
    enums = {"Event", "Site", "Date", "White", "Black", "Result", "WhiteElo", "BlackElo", "TimeControl", "Termination"};
    list = {"","","","","","","","","",""};
};


int
Game::indexOf(std::string str) {
    int resultIndex = std::find(enums.begin(),enums.end(), str) - enums.begin();
    if(resultIndex < enums.size()) {
        return resultIndex;
    }
    return -1;
}


std::string
Game::getType() {
    int index = indexOf("TimeControl");
    if(index < 0) {
        std::cout << "ERROR" << std::endl;
        return "";
    }
    return list.at(index);
}

std::string
Game::getResult() {
    int index = indexOf("Result");
    return list.at(index);
}

std::string
Game::getBlack() {
    int index = indexOf("Black");
    return list.at(index);
}

std::string
Game::getWhite() {
    int index = indexOf("White");
    return list.at(index);
}

bool
Game::getDraw() {
    int index = indexOf("Result");
    if(list.at(index) == "½-½") {
        return true;
    }
    return false;
}


std::string
Game::getMonth() {
    std::string date = list.at(2);
    if(date == "") {
        return "";
    }
    std::string month = date.substr(0,date.find_last_of("."));
    return month;
}


std::string
Game::getWinner() {
    int resultIndex = std::find(enums.begin(),enums.end(), "Result") - enums.begin();
    std::string result = list.at(resultIndex);
    if(result == "0-1") {
        int blackResult = std::find(enums.begin(),enums.end(), "Black") - enums.begin(); 
        return list.at(blackResult);
    }
    if(result == "1-0") {
        int whiteResult = std::find(enums.begin(),enums.end(), "White") - enums.begin();
        return list.at(whiteResult);
    }
    // Either there's an error or the game was draw
    return "";

}

const std::string
Game::getLoser() const {
    int resultIndex = std::find(enums.begin(), enums.end(), "Result") - enums.begin();
    std::string result = list.at(resultIndex);
    if(result == "0-1") {
        int whiteResult = std::find(enums.begin(), enums.end(), "White") - enums.begin();
        return list.at(whiteResult);
    }
    if(result == "1-0") {
        int blackResult = std::find(enums.begin(), enums.end(), "Black") - enums.begin();
        return list.at(blackResult);
    }
    // Either there's an error or the game was draw

    return "";
}

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
        //std::cout << event << std::endl;
        int index = std::find(enums.begin(),enums.end(), event) - enums.begin();
        //std::cout << index << std::endl;
        if(index < enums.size()) {
            str >> std::ws;
            str >> a;
            std::string name;
            // Change to a more stringstream friendly way
            std::getline(str,name);
            std::string::size_type end = name.find_first_of("\"");
            name = name.substr(0,end);
            //std::cout << name << std::endl << std::endl;
            list.at(index) = name;
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
