//
// Created by Luke Powell on 1/31/17.
//

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
