//
// Created by Luke Powell on 1/31/17.
//
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
                    output = ' ';
            }
            outputstream << " " << output << " ";
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
