//
// Created by Luke Powell on 1/31/17.
//

#ifndef GTP_DRAGONSCLAW_COMMAND_H
#define GTP_DRAGONSCLAW_COMMAND_H


#include <string>
#include <vector>
#include "../../gamelogic/boardstate.h"

class CommandException{
private:
    std::string exceptionText;
public:
    CommandException(std::string exceptionText);

    const std::string &getExceptionText() const;

    static CommandException * generateUnsupportedOperation();

    static CommandException *generateSyntaxError();
};

class Command {
private:
    std::string command;
protected:
    Command(const std::string command);

public:
    virtual std::string parse(std::vector<std::string> arguments, BoardState &boardState) throw(CommandException*) = 0;
    const std::string &getCommand() const;
};


#endif //GTP_DRAGONSCLAW_COMMAND_H
