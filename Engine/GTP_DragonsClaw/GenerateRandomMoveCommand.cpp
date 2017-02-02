//
// Created by Luke Powell on 2/1/17.
//

#include "GenerateRandomMoveCommand.h"
#include "gtp/gtp_constants.h"
#include "utilities/StringUtilities.h"

/**
 * Takes the form of genmove color , returns a move vertex, pass or resign
 */
std::string GenerateRandomMoveCommand::parse(std::vector<std::string> arguments, BoardState &boardState) throw(CommandException *){
    //TODO: This is just silly
    auto validMoves = boardState.getValidMoveVertices();
    if(validMoves.empty()){
        return "pass";
    }
    std::random_shuffle(validMoves.begin(), validMoves.end());
    boardState.makeMove(PlayerState::getPlayerIdFromString(StringUtilities::toupper(arguments[0])), validMoves[0].getColumn(), validMoves[0].getRow());
    return validMoves[0].getResponseVertex();
}

GenerateRandomMoveCommand::GenerateRandomMoveCommand() : Command(GTP_CONSTANTS::COMMANDS::GEN_MOVE_COMMAND){

}
