#pragma once

#include <array>

class Board {
private:
    std::array<char, 64> squares;
public:

    Board() {
        squares.fill('.');
    }

    std::array<char, 64> getSquares() {
        return squares;
    }

    char getSquare(int row, char column) const {
        int index = (8 - row) * 8 + (column - 'a');

        return squares.at(index);
    }
};