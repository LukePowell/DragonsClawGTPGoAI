//
// Created by Luke Powell on 1/31/17.
//

#include "Command.h"

const std::string &Command::getCommand() const {
    return command;
}

Command::Command(const std::string command) {
    this->command = command;
}

CommandException::CommandException(std::string exceptionText) {
    this->exceptionText = exceptionText;
}

CommandException * CommandException::generateUnsupportedOperation() {
    return  new CommandException("unsupported operation");
}

const std::string &CommandException::getExceptionText() const {
    return exceptionText;
}

CommandException *CommandException::generateSyntaxError() {
    return new CommandException("syntax_error");
}
