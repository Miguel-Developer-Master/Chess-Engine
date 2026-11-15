#include "raylib.h"

#include "DrawPiece.hpp"

#include <format>
#include <iostream>

#include "models/Pieces.hpp"
#include "models/Board.hpp"

#include <string_view>

void drawPiece(int posX, int posY, char column, int row, Board& board, const std::array<Texture2D, 13>& textures) {

    Pieces piece = board.getSquare(row, column);

    if (!(piece == Pieces::Empty)) {
        size_t index = static_cast<size_t>(piece);
        Texture2D texture = textures.at(index);

        DrawTexturePro(
            texture,
            Rectangle{0, 0, (float)texture.width, (float)texture.height},
            Rectangle{(float)posX, (float)posY, 100, 100},
            Vector2(0, 0),
            0,
            WHITE
        );
    }
}
