//
// Created by Luke Powell on 2/8/17.
//

#include <cstdlib>
#include <iostream>
#include "Engine.h"
#include "../utilities/StringUtilities.h"

const std::string Engine::QUIT = "quit";

Engine::Engine(const CommandParser &commandParser, BoardState &boardState, std::istream &inputStream, std::ostream &outputStream) : inputStream(inputStream), outputStream(outputStream), commandParser(commandParser), boardState(boardState) {
}

int Engine::run() {

    std::string input;
    while(input != QUIT){
        std::getline(inputStream, input);

        auto split = StringUtilities::tokenize(input, &StringUtilities::isWhitespace);

        if(split.empty()){
            continue;
        }

        int commandStartIndex = 0;
        int id = -1;
        if(StringUtilities::isNumericalString(split[commandStartIndex])){
            id = std::atoi(split[commandStartIndex].c_str());
            ++commandStartIndex;
        }

        try{
            std::vector<std::string> arguments(split.begin() + 1, split.end());
            std::string response = commandParser.parseCommand(split[commandStartIndex], arguments, boardState);
            outputStream << "=";
            if(id != -1){
                outputStream << id;
            }
            outputStream << " " << response << "\n\n";
        }catch(const CommandException *commandException){

            outputStream << "?";
            if(id != -1){
                outputStream << id;
            }
            outputStream << " " << commandException->getExceptionText() << "\n\n";
        }
    }

    return 0;
}
