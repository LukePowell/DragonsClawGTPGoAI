//
// Created by Luke Powell on 1/31/17.
//

#ifndef GTP_DRAGONSCLAW_NAMECOMMAND_H
#define GTP_DRAGONSCLAW_NAMECOMMAND_H


#include "Command.h"

class NameCommand : public Command{
public:
    NameCommand();
    std::string parse(std::vector<std::string> arguments, BoardState &boardState) throw(CommandException*) override;
};


#endif //GTP_DRAGONSCLAW_NAMECOMMAND_H