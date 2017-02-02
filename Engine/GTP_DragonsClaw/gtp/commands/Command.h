/*
 * Copyright 2017 Luke Powell
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
 * documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
 * Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
 * OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
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
