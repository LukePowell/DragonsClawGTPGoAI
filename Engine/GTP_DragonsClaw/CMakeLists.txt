cmake_minimum_required(VERSION 3.6)
project(GTP_DragonsClaw)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp gtp/gtp_constants.h gamelogic/boardstate.h gamelogic/PlayerState.cpp gamelogic/PlayerState.h gamelogic/Board.cpp gamelogic/Board.h gtp/commands/Commands.cpp gtp/commands/Commands.h gtp/commands/Command.cpp gtp/commands/Command.h gtp/commands/NameCommand.cpp gtp/commands/NameCommand.h gtp/commands/EchoCommand.cpp gtp/commands/EchoCommand.h gtp/commands/PrintBoardCommand.cpp gtp/commands/PrintBoardCommand.h gamelogic/boardstate.cpp gtp/commands/PlayCommand.cpp gtp/commands/PlayCommand.h utilities/StringUtilities.cpp utilities/StringUtilities.h)
add_executable(GTP_DragonsClaw ${SOURCE_FILES})