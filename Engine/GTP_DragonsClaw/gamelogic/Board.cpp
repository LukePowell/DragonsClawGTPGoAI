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
#include <cstring>
#include "Board.h"

Board::Board() {
    size = Board::DEFAULT_SIZE;
    setupBoard();
}

void Board::setupBoard() {
    deleteBoard();

    board = new int*[size];
    for(int i = 0; i < size; ++i){
        board[i] = new int[size];
        std::memset(board[i], 0, sizeof(int) * size);
    }
}

Board::~Board() {
    deleteBoard();
}

void Board::deleteBoard() {
    if(board != nullptr){
        for(int i = 0; i < size; ++i){
            delete [] board[i];
        }

        delete[] board;
    }
}

void Board::setSize(int newSize) {
    this->size = newSize;
    setupBoard();
}

void Board::clear() {
    for(int y = 0; y < 0; ++y){
        for(int x = 0; x < 0; ++x){
            getPieceAt(x, y) = 0;
        }
    }
}

int &Board::getPieceAt(int x, int y) {
    return board[y][x];
}

int Board::getSize() const {
    return size;
}

const int &Board::getPieceAt(int x, int y) const {
    return board[y][x];
}

void Board::play(int playerId, int column, int row) {
    getPieceAt(column, row) = playerId;
}
