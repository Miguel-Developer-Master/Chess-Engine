#pragma once

#include "models/Pieces.hpp"
#include "models/Board.hpp"

void movePiece(int mousePressedRow, char mousePressedColumn, int mouseUnpressedRow,
    char mouseUnpressedColumn, Pieces pressedPiece, Pieces unpressedPiece, Board& board);
//NEVER EVER TAKE OUT THE F*&#ING REFERENCE FROM BOARD
//By miguel: after 30 minutes searching for the error