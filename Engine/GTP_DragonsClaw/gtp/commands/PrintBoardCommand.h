//
// Created by Luke Powell on 1/31/17.
//

#ifndef GTP_DRAGONSCLAW_PRINTBOARDCOMMAND_H
#define GTP_DRAGONSCLAW_PRINTBOARDCOMMAND_H


#include "Command.h"
class PrintBoardCommand : public Command {
public:
    PrintBoardCommand();

    std::string parse(std::vector<std::string> arguments, BoardState &boardState) throw(CommandException*) override;
};


#endif //GTP_DRAGONSCLAW_PRINTBOARDCOMMAND_H
