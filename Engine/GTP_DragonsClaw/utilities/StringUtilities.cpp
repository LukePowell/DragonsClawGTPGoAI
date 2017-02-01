//
// Created by Luke Powell on 1/31/17.
//

#include "StringUtilities.h"

std::string & StringUtilities::toupper(std::string &string) {
    for (auto iter = string.begin(); iter < string.end(); ++iter){
        *iter = (char)std::toupper(*iter);
    }
    return string;
}
