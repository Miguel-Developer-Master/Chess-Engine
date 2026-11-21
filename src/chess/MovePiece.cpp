#include "raylib.h"

#include "MovePiece.hpp"

#include "models/Pieces.hpp"
#include "models/Board.hpp"
#include "models/Position.hpp"

#include <vector>

bool canMove(int mousePressedRow, char mousePressedColumn, int mouseUnpressedRow, char mouseUnpressedColumn,
    Pieces willTakePiece, Pieces willBeTakePiece, Board& board) {
    int willTakePieceTeam = board.getTeam(willTakePiece);
    bool run = false;
    std::vector<Position> positions = board.getMoves(mousePressedRow, mousePressedColumn, willTakePiece, willTakePieceTeam);
    for (Position& position : positions) {
        if (position.row == mouseUnpressedRow && position.column == mouseUnpressedColumn) {
            run = true;
            break;
        }
    }

    return run;
}

void movePiece(int mousePressedRow, char mousePressedColumn, int mouseUnpressedRow,
    char mouseUnpressedColumn, Pieces pressedPiece, Pieces unpressedPiece, Board& board) {

    bool move = canMove(mousePressedRow, mousePressedColumn, mouseUnpressedRow,
        mouseUnpressedColumn, pressedPiece, unpressedPiece, board);
    if (move) {
        board.setPiece(mousePressedRow, mousePressedColumn, mouseUnpressedRow,
        mouseUnpressedColumn, pressedPiece);
    }

}