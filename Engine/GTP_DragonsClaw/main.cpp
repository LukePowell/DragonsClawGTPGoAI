/*
 * Copyright 2017 Luke Powell
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
 * OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include <iostream>
#include <vector>
#include <map>
#include "gamelogic/boardstate.h"
#include "gtp/gtp_constants.h"
#include "gtp/commands/Commands.h"
#include "gtp/commands/EchoCommand.h"
#include "gtp/commands/PrintBoardCommand.h"
#include "gtp/commands/PlayCommand.h"
#include "gtp/commands/ListCommandsCommand.h"
#include "gtp/commands/BoardSizeCommand.h"
#include "gtp/commands/ClearBoardCommand.h"
#include "GenerateRandomMoveCommand.h"

bool isNumericalString(const std::string &input){
    for(auto iter = input.begin(); iter < input.end(); ++iter){
        if(*iter < '0' || *iter > '9')
            return false;
    }

    return true;
}

std::vector<std::string> tokenize(std::string string, int (* comparator)(int)){
    std::vector<std::string> output;
    auto iter = string.begin();
    std::string temp;
    while(iter != string.end()){
        if(!comparator(*iter)){
            temp += *iter;
        }
        else if(!temp.empty()){
            output.push_back(temp);
            temp.clear();
        }
        ++iter;
    }

    if(!temp.empty()){
        output.push_back(temp);
    }

    return output;
}


std::map<std::string, std::string (*)(std::vector<std::string>::iterator, std::vector<std::string>::iterator, BoardState *) > commands;

void setupCommandParser(CommandParser &commandParser){
    commandParser.addCommand(new EchoCommand(GTP_CONSTANTS::COMMANDS::NAME_COMMAND, GTP_CONSTANTS::NAME));
    commandParser.addCommand(new EchoCommand(GTP_CONSTANTS::COMMANDS::PROTOCOL_VERSION_COMMAND, GTP_CONSTANTS::PROTOCOL_VERSION));
    commandParser.addCommand(new EchoCommand(GTP_CONSTANTS::COMMANDS::VERSION_COMMAND, GTP_CONSTANTS::VERSION));
    commandParser.addCommand(new EchoCommand("quit", ""));
    commandParser.addCommand(new PlayCommand());
    commandParser.addCommand(new ListCommandsCommand(commandParser));
    commandParser.addCommand(new BoardSizeCommand());
    commandParser.addCommand(new ClearBoardCommand());
    commandParser.addCommand(new PrintBoardCommand());
    commandParser.addCommand(new GenerateRandomMoveCommand());
}

int isWhitespace(int ch){
    return ch == 32 || ch == 9;
}

int main() {
    BoardState boardState;
    CommandParser commandParser;
    setupCommandParser(commandParser);

    std::string input;
    while(input != "quit"){
        std::getline(std::cin, input);

        auto split = tokenize(input, &isWhitespace);

        if(split.empty()){
            continue;
        }

        int commandStartIndex = 0;
        int id = -1;
        if(isNumericalString(split[commandStartIndex])){
            id = std::atoi(split[commandStartIndex].c_str());
            ++commandStartIndex;
        }


        try{
            std::vector<std::string> arguments(split.begin() + 1, split.end());
            std::string response = commandParser.parseCommand(split[commandStartIndex], arguments, boardState);
            std::cout << "=";
            if(id != -1){
                std::cout << id;
            }
            std::cout << " " << response << "\n\n";
        }catch(const CommandException *commandException){

            std::cout << "?";
            if(id != -1){
                std::cout << id;
            }
            std::cout << " " << commandException->getExceptionText() << "\n\n";
        }
    }
    return 0;
}