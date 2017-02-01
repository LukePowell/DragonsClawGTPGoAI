//
// Created by Luke Powell on 1/31/17.
//

#include "NameCommand.h"
#include "../gtp_constants.h"

std::string NameCommand::parse(std::vector<std::string> arguments, BoardState &boardState) throw(CommandException*) {
    return GTP_CONSTANTS::NAME;
}

NameCommand::NameCommand() : Command(GTP_CONSTANTS::COMMANDS::NAME_COMMAND) {
}
