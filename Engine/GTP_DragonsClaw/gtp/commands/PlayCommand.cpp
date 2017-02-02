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
#include "PlayCommand.h"
#include "../gtp_constants.h"
#include "../../utilities/StringUtilities.h"

std::string PlayCommand::parse(std::vector<std::string> arguments, BoardState &boardState) throw(CommandException*) {
    if(arguments.empty() || arguments.size() < 2){
        throw new CommandException("syntax_error");
    }

    int playerId = PlayerState::getPlayerIdFromString(StringUtilities::toupper(arguments[0]));

    if(playerId == -1){
        throw new CommandException("syntax_error");
    }

    StringUtilities::toupper(arguments[1]);

    if(arguments[1] == "PASS"){
        //boardState.pass(playerid);
    }else if(arguments[1] == "RESIGN"){
        //boardState.resign(playerId);
    }else{
        int column = arguments[1][0] < 'I' ? arguments[1][0] - 'A' : arguments[1][0] - 'A' - 1;
        int row = 19 - std::atoi(arguments[1].substr(1,2).c_str());
        if(!boardState.makeMove(playerId, column, row)){
            return "illegal move";
        }
    }
    return "";
}

PlayCommand::PlayCommand() : Command(GTP_CONSTANTS::COMMANDS::PLAY_COMMAND) {
}
