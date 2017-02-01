//
// Created by Luke Powell on 1/31/17.
//

#ifndef GTP_DRAGONSCLAW_ECHOCOMMAND_H
#define GTP_DRAGONSCLAW_ECHOCOMMAND_H


#include "Command.h"

class EchoCommand : public Command {
private:
    std::string output;

public:
    EchoCommand(const std::string command, const std::string output);

    std::string parse(std::vector<std::string> arguments, BoardState &boardState) throw(CommandException*) override;
};


#endif //GTP_DRAGONSCLAW_ECHOCOMMAND_H
