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
#include "MoveVertex.h"

MoveVertex::MoveVertex() : row(0), column(0) {
}

MoveVertex::MoveVertex(int row, int column) : row(row), column(column) {
}

std::string MoveVertex::getResponseVector(int row, int column) {
    std::stringstream output;
    output << MoveVertex::columnToLetter(column);
    output << row;
    return output.str();
}

char MoveVertex::columnToLetter(int column) {
    char output = static_cast<char>(column + 'A');
    if(output >= 'I'){
        output++;
    }
    return output;
}

std::string MoveVertex::getResponseVertex(const MoveVertex &moveVertex) {
    return getResponseVector(19 - moveVertex.row, moveVertex.column);
}

std::string MoveVertex::getResponseVertex() const {
    return getResponseVertex(*this);
}

int MoveVertex::getRow() const {
    return row;
}

int MoveVertex::getColumn() const {
    return column;
}
