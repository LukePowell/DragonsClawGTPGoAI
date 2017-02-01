//
// Created by Luke Powell on 1/31/17.
//

#include "PrintBoardCommand.h"

PrintBoardCommand::PrintBoardCommand() : Command("print_board"){
}

std::string PrintBoardCommand::parse(std::vector<std::string> arguments, BoardState &boardState) throw(CommandException*) {
    return boardState.getASCIIRepresentation();
}

