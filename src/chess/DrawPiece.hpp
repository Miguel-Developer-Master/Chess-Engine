#pragma once

#include "models/Board.hpp"

void drawPiece(int posX, int posY, char column, int row, Board& board, const std::array<Texture2D, 13>& textures, const bool& transparent);
