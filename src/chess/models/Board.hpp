#pragma once

#include "Pieces.hpp"
#include "Position.hpp"

#include <array>
#include <map>
#include <vector>

class Board {
private:
    std::array<Pieces, 64> squares;
    int turn = 0;
    // 0 = White, 1 = Black
    std::map<int, char> dictionary = {
        {0, 'a'},
        {1, 'b'},
        {2, 'c'},
        {3, 'd'},
        {4, 'e'},
        {5, 'f'},
        {6, 'g'},
        {7, 'h'},
    };

    void getVerticalOrHorizontalMoves(int direction, int qtd, int row, char column, std::vector<Position>& positions, int team) const{
        int dr, dc;
        switch (direction) {
            case 0: dr = 1; dc = 0; break;
            case 1: dr = 0; dc = 1; break;
            case 2: dr = -1; dc = 0; break;
            case 3: dr = 0; dc = -1; break;
        }

        int a = row;
        int b = column - 'a';
        bool run = true;

        for (int i = 0; i < qtd; i++) {
            if (!run) {
                break;
            }
            a += dr;
            b += dc;
            if (!(a < 8 && b < 8 && a >= 0 && b >= 0)) {
                break;
            }
            if (getTeam(getSquare(a, dictionary.at(b))) == team) {
                break;
            }
            positions.push_back(Position(a, dictionary.at(b)));
            if (getSquare(a, dictionary.at(b)) != Pieces::Empty) {
                run = false;
            }
        }
    }

    void getDiagonalMoves(int direction, int qtd, int row, char column, std::vector<Position>& positions, int team) const {
        int dr, dc;

        switch (direction) {
            case 0: dr = 1; dc = -1; break;
            case 1: dr = 1; dc = 1; break;
            case 2: dr = -1; dc = 1; break;
            case 3: dr = -1; dc = -1; break;
        }

        int a = row;
        int b = column - 'a';
        bool run = true;
        for (int i = 0; i < qtd; i++) {
            if (!run) {
                break;
            }
            a += dr;
            b += dc;

            if (!(a < 8 && b < 8 && a >= 0 && b >= 0)) {
                break;
            }
            if (getTeam(getSquare(a, dictionary.at(b))) == team) {
                break;
            }
            positions.push_back(Position(a, dictionary.at(b)));
            if (getSquare(a, dictionary.at(b)) != Pieces::Empty) {
                run = false;
            }
        }
    }

    void getKnightMoves(int row, char column, std::vector<Position>& positions, int team) const {
        int b = column - 'a';
        if (row + 2 < 8 && b + 1 < 8 && getTeam(getSquare(row + 2, dictionary.at(b + 1))) != team) positions.push_back(Position(row + 2, dictionary.at(b + 1)));
        if (row + 2 < 8 && b - 1 >= 0 && getTeam(getSquare(row + 2, dictionary.at(b - 1))) != team) positions.push_back(Position(row + 2, dictionary.at(b - 1)));
        if (row - 2  >= 0 && b + 1 < 8 && getTeam(getSquare(row - 2, dictionary.at(b + 1))) != team) positions.push_back(Position(row - 2, dictionary.at(b + 1)));
        if (row - 2  >= 0 && b - 1 >= 0 && getTeam(getSquare(row - 2, dictionary.at(b - 1))) != team) positions.push_back(Position(row - 2, dictionary.at(b - 1)));
        if (row + 1 < 8 && b + 2 < 8 && getTeam(getSquare(row + 1, dictionary.at(b + 2))) != team) positions.push_back(Position(row + 1, dictionary.at(b + 2)));
        if (row + 1 < 8 && b - 2 >= 0 && getTeam(getSquare(row + 1, dictionary.at(b - 2))) != team) positions.push_back(Position(row + 1, dictionary.at(b - 2)));
        if (row - 1 >= 0 && b + 2 < 8 && getTeam(getSquare(row - 1, dictionary.at(b + 2))) != team) positions.push_back(Position(row - 1, dictionary.at(b + 2)));
        if (row - 1 >= 0 && b - 2 >= 0 && getTeam(getSquare(row - 1, dictionary.at(b - 2))) != team) positions.push_back(Position(row - 1, dictionary.at(b - 2)));
    }
// if (row  && b && getTeam(getSquare()) != team)
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

        //putting knights
        squares.at(1) = Pieces::BlackKnight;
        squares.at(6) = Pieces::BlackKnight;
        squares.at(57) = Pieces::WhiteKnight;
        squares.at(62) = Pieces::WhiteKnight;

        //putting bishops
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

    int getTeam(Pieces piece) const {
    /*
     * 0 = white
     * 1 = black
     * 2 = empty
     */
        int team;
        if (piece == Pieces::BlackPawn || piece == Pieces::BlackRook || piece == Pieces::BlackBishop ||
            piece == Pieces::BlackKnight || piece == Pieces::BlackKing || piece == Pieces::BlackQueen) {
            team = 1;
        } else if (piece == Pieces::Empty) {
            team = 2;
        } else {
            team = 0;
        }
        return team;
    }

    std::array<Pieces, 64> getSquares() const {
        return squares;
    }

    int getTurn() const {
        return turn;
    }

    void changeTurn() {
        turn = 1 - turn;
    }

    std::vector<Position> getMoves(int row, char column, Pieces piece, int team) const {
        std::vector<Position> positions;

        if (piece == Pieces::BlackPawn && row == 1) {
            if (getSquare(row + 1, column) == Pieces::Empty && getSquare(row + 2, column) == Pieces::Empty) {
                positions.push_back(Position(row + 2, column));
            }
        } else if (piece == Pieces::WhitePawn && row == 6) {
            if (getSquare(row - 1, column) == Pieces::Empty && getSquare(row - 2, column) == Pieces::Empty) {
                positions.push_back(Position(row - 2, column));
            }
        }

        if (piece == Pieces::BlackPawn) {
            if (row + 1 < 8) {
                if (getSquare(row + 1, column) == Pieces::Empty) {
                    getVerticalOrHorizontalMoves(0, 1, row, column, positions, team);
                }
            }

            if (row + 1 < 8 && (column - 'a') - 1 >= 0) {
                if (getSquare(row + 1, dictionary.at((column - 'a') - 1)) != Pieces::Empty && getTeam(getSquare(row + 1, dictionary.at((column - 'a') - 1))) != team) {
                    getDiagonalMoves(0, 1, row, column, positions, team);
                }
            }

            if (row + 1 < 8 && (column - 'a') + 1 < 8) {
                if (getSquare(row + 1, dictionary.at((column - 'a') + 1)) != Pieces::Empty && getTeam(getSquare(row + 1, dictionary.at((column - 'a') + 1))) != team) {
                    getDiagonalMoves(1, 1, row, column, positions, team);
                }
            }

        } else if (piece == Pieces::WhitePawn) {
            if (row - 1 >= 0) {
                if (getSquare(row - 1, column) == Pieces::Empty) {
                    getVerticalOrHorizontalMoves(2, 1, row, column, positions, team);
                }
            }

            if (row - 1 >= 0 && column - 'a' - 1 >= 0) {
                if (getSquare(row - 1, dictionary.at((column - 'a') - 1)) != Pieces::Empty && getTeam(getSquare(row - 1, dictionary.at((column - 'a') - 1))) != team) {
                    getDiagonalMoves(3, 1, row, column, positions, team);
                }
            }

            if (row - 1 >= 0 && column - 'a' + 1 < 8) {
                if (getSquare(row - 1, dictionary.at((column - 'a') + 1)) != Pieces::Empty && getTeam(getSquare(row - 1, dictionary.at((column - 'a') + 1))) != team) {
                    getDiagonalMoves(2, 1, row, column, positions, team);
                }
            }
        } else if (piece == Pieces::BlackRook || piece == Pieces::WhiteRook) {
            for (int i = 0; i < 4; i++) {
                getVerticalOrHorizontalMoves(i, 10, row, column, positions, team);
            }
        } else if (piece == Pieces::BlackBishop || piece == Pieces::WhiteBishop) {
            for (int i = 0; i < 4; i++) {
                getDiagonalMoves(i, 10, row, column, positions, team);
            }
        } else if (piece == Pieces::BlackQueen || piece == Pieces::WhiteQueen) {
            for (int i = 0; i < 4; i++) {
                getDiagonalMoves(i, 10, row, column, positions, team);
                getVerticalOrHorizontalMoves(i, 10, row, column, positions, team);
            }
        } else if (piece == Pieces::BlackKing || piece == Pieces::WhiteKing) {
            for (int i = 0; i < 4; i++) {
                getDiagonalMoves(i, 1, row, column, positions, team);
                getVerticalOrHorizontalMoves(i, 1, row, column, positions, team);
            }
        } else if (piece == Pieces::BlackKnight || piece == Pieces::WhiteKnight) {
            getKnightMoves(row, column, positions, team);
        }

        return positions;
    }

    Pieces getSquare(int row, char column) const {
        int index = row * 8 + (column - 'a');

        return squares.at(index);
    }


    void setPiece(int oldRow, char oldColumn, int row, char column, Pieces piece) {
        int oldIndex = oldRow * 8 + (oldColumn - 'a');
        int index = row * 8 + (column - 'a');

        int team = getTeam(piece);
        int gotTurn = getTurn();
        if ((gotTurn == 0 && team == 0) || (gotTurn == 1 && team == 1)) {
            squares.at(oldIndex) = Pieces::Empty;
            squares.at(index) = piece;
            changeTurn();
        }
    }
};