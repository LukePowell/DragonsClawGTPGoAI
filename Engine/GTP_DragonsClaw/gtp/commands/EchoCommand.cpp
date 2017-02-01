//
// Created by Luke Powell on 1/31/17.
//

#include "EchoCommand.h"

EchoCommand::EchoCommand(const std::string command, const std::string output) : Command(command){
    this->output = output;
}

std::string EchoCommand::parse(std::vector<std::string> arguments, BoardState &boardState) throw(CommandException*) {
    return output;
}
