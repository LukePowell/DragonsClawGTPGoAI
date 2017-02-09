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
#include "StringUtilities.h"

std::string & StringUtilities::toupper(std::string &string) {
    for (auto iter = string.begin(); iter < string.end(); ++iter){
        *iter = (char)std::toupper(*iter);
    }
    return string;
}

bool StringUtilities::isNumericalString(const std::string &input){
    for(auto iter = input.begin(); iter < input.end(); ++iter){
        if(*iter < '0' || *iter > '9')
            return false;
    }

    return true;
}

std::vector<std::string> StringUtilities::tokenize(std::string string, int (* comparator)(int)){
    std::vector<std::string> output;
    auto iter = string.begin();
    std::string temp;
    while(iter != string.end()){
        if(!comparator(*iter)){
            temp += *iter;
        }
        else if(!temp.empty()){
            output.push_back(temp);
            temp.clear();
        }
        ++iter;
    }

    if(!temp.empty()){
        output.push_back(temp);
    }

    return output;
}

int StringUtilities::isWhitespace(int ch) {
    return ch == 32 || ch == 9;
}
