//
// Created by Luke Powell on 1/31/17.
//

#ifndef GTP_DRAGONSCLAW_PLAYCOMMAND_H
#define GTP_DRAGONSCLAW_PLAYCOMMAND_H


#include "Command.h"

class PlayCommand : public Command {
private:
public:
    PlayCommand();
    std::string parse(std::vector<std::string> arguments, BoardState &boardState) throw(CommandException*) override;
};


#endif //GTP_DRAGONSCLAW_PLAYCOMMAND_H
