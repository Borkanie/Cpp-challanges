#include "../Headers/Position.hpp"
#include <stdexcept>

Position::Position::Position(int line, int number)
{
    if(line<0){
        throw std::invalid_argument(" Line must be positive. ");
    }
    if( number>line+1){
        throw std::invalid_argument(" Number must smaller than Line+1. ");
    }
    Value=1;
    Line=line;
    Number=number;
}
