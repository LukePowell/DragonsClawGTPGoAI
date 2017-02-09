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
#include <iostream>
#include <vector>
#include <map>
#include "gamelogic/boardstate.h"
#include "gtp/gtp_constants.h"
#include "gtp/commands/Commands.h"
#include "gtp/commands/EchoCommand.h"
#include "gtp/commands/PrintBoardCommand.h"
#include "gtp/commands/PlayCommand.h"
#include "gtp/commands/ListCommandsCommand.h"
#include "gtp/commands/BoardSizeCommand.h"
#include "gtp/commands/ClearBoardCommand.h"
#include "GenerateRandomMoveCommand.h"
#include "gamelogic/Engine.h"



void setupCommandParser(CommandParser &commandParser){
    commandParser.addCommand(new EchoCommand(GTP_CONSTANTS::COMMANDS::NAME_COMMAND, GTP_CONSTANTS::NAME));
    commandParser.addCommand(new EchoCommand(GTP_CONSTANTS::COMMANDS::PROTOCOL_VERSION_COMMAND, GTP_CONSTANTS::PROTOCOL_VERSION));
    commandParser.addCommand(new EchoCommand(GTP_CONSTANTS::COMMANDS::VERSION_COMMAND, GTP_CONSTANTS::VERSION));
    commandParser.addCommand(new EchoCommand("quit", ""));
    commandParser.addCommand(new PlayCommand());
    commandParser.addCommand(new ListCommandsCommand(commandParser));
    commandParser.addCommand(new BoardSizeCommand());
    commandParser.addCommand(new ClearBoardCommand());
    commandParser.addCommand(new PrintBoardCommand());
    commandParser.addCommand(new GenerateRandomMoveCommand());
}

int main() {
    BoardState boardState;
    CommandParser commandParser;
    setupCommandParser(commandParser);
    Engine engine(commandParser, boardState, std::cin, std::cout);
    return engine.run();
}