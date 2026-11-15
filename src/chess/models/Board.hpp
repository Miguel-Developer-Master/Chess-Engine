#pragma once

#include "Pieces.hpp"
#include <array>

class Board {
private:
    std::array<Pieces, 64> squares;
public:

    Board() {
        squares.fill(Pieces::Empty);

        //putting black pawns
        for (int a = 8; a <= 15; a++) {
            squares.at(a) = Pieces::BlackPawn;
        }

        //putting white pawns
        for (int b = 48; b <= 55; b++) {
            squares.at(b) = Pieces::WhitePawn;
        }

        //putting rooks
        squares.at(0) = Pieces::BlackRook;
        squares.at(7) = Pieces::BlackRook;
        squares.at(56) = Pieces::WhiteRook;
        squares.at(63) = Pieces::WhiteRook;

        //putting bishops
        squares.at(1) = Pieces::BlackKnight;
        squares.at(6) = Pieces::BlackKnight;
        squares.at(57) = Pieces::WhiteKnight;
        squares.at(62) = Pieces::WhiteKnight;

        //putting knights
        squares.at(2) = Pieces::BlackBishop;
        squares.at(5) = Pieces::BlackBishop;
        squares.at(58) = Pieces::WhiteBishop;
        squares.at(61) = Pieces::WhiteBishop;

        //putting queens and kings
        squares.at(4) = Pieces::BlackKing;
        squares.at(3) = Pieces::BlackQueen;
        squares.at(59) = Pieces::WhiteQueen;
        squares.at(60) = Pieces::WhiteKing;
    }

    std::array<Pieces, 64> getSquares() {
        return squares;
    }

    Pieces getSquare(int row, char column) const {
        int index = row * 8 + (column - 'a');

        return squares.at(index);
    }
};