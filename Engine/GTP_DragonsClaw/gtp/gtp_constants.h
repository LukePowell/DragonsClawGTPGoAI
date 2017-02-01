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
#ifndef GTP_DRAGONSCLAW_GTP_CONSTANTS_H
#define GTP_DRAGONSCLAW_GTP_CONSTANTS_H

#include <string>

/* Required commands
 * protocol_version
 * name
 * version
 * known_command
 * list_commands
 * quit
 * boardsize
 * clear_board
 * komi
 * play
 * genmove
 */
namespace GTP_CONSTANTS {
    const std::string VERSION = "0.0.1";
    const std::string NAME = "Dragon's Claw Go AI";
    const std::string PROTOCOL_VERSION = "2";
    //Internal code, used if migration is needed on stored data for later versions
    const int VERSION_CODE = 1;


    namespace COMMANDS {
        const std::string NAME_COMMAND = "name";
        const std::string VERSION_COMMAND = "version";
        const std::string PROTOCOL_VERSION_COMMAND = "protocol_version";
        const std::string PLAY_COMMAND = "play";
    }
}
#endif //GTP_DRAGONSCLAW_GTP_CONSTANTS_H
