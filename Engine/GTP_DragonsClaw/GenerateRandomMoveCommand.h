//
// Created by Luke Powell on 2/1/17.
//

#ifndef GTP_DRAGONSCLAW_GENERATERANDOMMOVECOMMAND_H
#define GTP_DRAGONSCLAW_GENERATERANDOMMOVECOMMAND_H


#include "gtp/commands/Command.h"

class GenerateRandomMoveCommand : public Command {
public:
    GenerateRandomMoveCommand();

    std::string parse(std::vector<std::string> arguments, BoardState &boardState) throw(CommandException *) override;
};


#endif //GTP_DRAGONSCLAW_GENERATERANDOMMOVECOMMAND_H
