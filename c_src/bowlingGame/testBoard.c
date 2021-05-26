#include "board.h"

int main(void) 
{

    setScore(5, 1, 9);
    setScore(5, 2, 0);
    setScore(10, 1, 9);

    setFrameScore(1, 9);
    setFrameScore(5, 98);
    setFrameScore(10, 300);
    printBoard();

    return 0;
}