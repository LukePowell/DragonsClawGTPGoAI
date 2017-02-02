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

#include <sstream>
#include <iomanip>
#include "boardstate.h"

std::string BoardState::getASCIIRepresentation() const {
    std::stringstream outputstream;
    //Header, the current size of the board
    outputstream << gameBoardCurrent.getSize() << " x " <<  gameBoardCurrent.getSize() << std::endl;
    //Header for the column above
    outputstream << "   ";
    for(int i = 0; i < gameBoardCurrent.getSize(); ++i){
        char header = static_cast<char>('A' + i);
        if(header >= 'I'){
            header++;
        }

        outputstream << " " << header << " ";
    }

    outputstream << std::endl;

    for(int y = 0; y < gameBoardCurrent.getSize(); ++y){
        outputstream << std::setw(2) << (gameBoardCurrent.getSize() - y) << " ";
        for(int x = 0; x < gameBoardCurrent.getSize(); ++x){
            char output;
            switch(gameBoardCurrent.getPieceAt(x, y)){
                case 1:
                    output = 'B';
                    break;
                case 2:
                    output = 'W';
                    break;
                default:
                    output = '|';
            }
            outputstream << "-" << output << "-";
        }
        outputstream << std::endl;
    }
    return outputstream.str();
}

bool BoardState::makeMove(int playerId, int column, int row) {
    if(playerId != PlayerState::BLACK_ID && playerId != PlayerState::WHITE_ID){
        return false;
    }

    if( column < 0 || column >= gameBoardCurrent.getSize() ||  row < 0 || row >= gameBoardCurrent.getSize()){
        return  false;
    }

    gameBoardCurrent.play(playerId, column, row);

    return true;
}

bool BoardState::resize(int size) {
    if(size < 1 || size > 25){
        return false;
    }

    gameBoardCurrent.setSize(size);

    return true;
}

void BoardState::clear() {
//    whitePlayerState.reset();
//    blackPlayerState.reset();
    gameBoardCurrent.clear();
}

std::vector<MoveVertex> BoardState::getValidMoveVertices() {
    return gameBoardCurrent.getValidMoves();
}
