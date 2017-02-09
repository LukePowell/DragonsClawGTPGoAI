//
// Created by Luke Powell on 2/8/17.
//

#ifndef GTP_DRAGONSCLAW_ENGINE_H
#define GTP_DRAGONSCLAW_ENGINE_H


#include "../gtp/commands/Commands.h"

class Engine {
public:
    Engine(const CommandParser &commandParser, BoardState &boardState, std::istream &inputStream, std::ostream &outputStream);
    int run();

private:
    static const std::string QUIT;
    std::istream &inputStream;
    std::ostream &outputStream;
    const CommandParser &commandParser;
    BoardState &boardState;
};


#endif //GTP_DRAGONSCLAW_ENGINE_H
