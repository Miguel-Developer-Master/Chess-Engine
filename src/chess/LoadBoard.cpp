#include "raylib.h"

#include "DrawPiece.hpp"
#include "models/Board.hpp"
#include "LoadBoard.hpp"

#include <array>
#include <format>
#include <string>
#include <map>

void showBoard() {

    Board board;
    std::array<Pieces, 64> squares = board.getSquares();
    std::array<int, 8> rows = {0, 1, 2, 3, 4, 5, 6, 7};
    std::array<int, 8> posY;
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

    for (int i = 0; i < 8; i++) {
        posY.at(i) = rows.at(i) * 100;
    }



    InitWindow(800, 800, "Chess Engine");

    std::array<Texture2D, 13> textures;
    for (int i = 1; i < 13; i++) {
        std::string path = std::format("../src/chess/images/{}.png", pieceNames.at(i));
        textures.at(i) = LoadTexture(path.c_str());
    }

    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        BeginDrawing();

        for (int a = 0; a < rows.size(); a++) {

            int row = rows.at(a);

            std::array<int, 8> posX;

            for (int j = 0; j < 8; j++) {
                if (j == 0) {
                    posX.at(j) = 0;
                    continue;
                }
                posX.at(j) = posY.at(j - 1) + 100;
            }

            if (row % 2 == 0) {
                int columns = 0;
                // if even, white

                while (columns < 8) {
                    if (columns % 2 == 0) {
                        DrawRectangle(posX.at(columns), posY.at(a), 100, 100, WHITE);
                        drawPiece(posX.at(columns), posY.at(a), dictionary.at(columns), row, board, textures);
                        columns++;
                    } else {
                        DrawRectangle(posX.at(columns), posY.at(a), 100, 100, Color{0xB5, 0x88, 0x63, 255});
                        drawPiece(posX.at(columns), posY.at(a), dictionary.at(columns), row, board, textures);
                        columns++;
                    }
                }
            } else {
                int columns = 0;
                // if odd, white
                while (columns < 8) {
                    if (columns % 2 != 0) {
                        DrawRectangle(posX.at(columns), posY.at(a), 100, 100, WHITE);
                        drawPiece(posX.at(columns), posY.at(a), dictionary.at(columns), row, board, textures);
                        columns++;
                    } else {
                        DrawRectangle(posX.at(columns), posY.at(a), 100, 100, Color{0xB5, 0x88, 0x63, 255});
                        drawPiece(posX.at(columns), posY.at(a), dictionary.at(columns), row, board, textures);
                        columns++;
                    }
                }
            }
        }

        EndDrawing();

    }

    for (int j = 1; j < 13; j++) {
        UnloadTexture(textures.at(j));
    }
    CloseWindow();
}