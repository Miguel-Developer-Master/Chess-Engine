#include "raylib.h"
#include "models/Board.hpp"
#include "LoadBoard.hpp"

#include <array>

void showBoard() {

    Board board;
    std::array<char, 64> squares = board.getSquares();
    std::array<int, 8> rows = {0, 1, 2, 3, 4, 5, 6, 7};
    std::array<int, 8> posY;

    for (int i = 0; i < 8; i++) {
        posY.at(i) = rows.at(i) * 100;
    }


    InitWindow(800, 800, "Chess Engine");
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
                int whiteOrBrown = 0;
                // if even, white
                for (int h = 0; h < 8; h++) {
                    if (whiteOrBrown % 2 == 0) {
                        DrawRectangle(posX.at(h), posY.at(a), 100, 100, WHITE);
                        whiteOrBrown++;
                    } else {
                        DrawRectangle(posX.at(h), posY.at(a), 100, 100, Color{0xB5, 0x88, 0x63, 255});
                        whiteOrBrown++;
                    }
                }
            } else {
                int whiteOrBrown = 0;
                // if odd, white
                for (int h = 0; h < 8; h++) {
                    if (whiteOrBrown % 2 != 0) {
                        DrawRectangle(posX.at(h), posY.at(a), 100, 100, WHITE);
                        whiteOrBrown++;
                    } else {
                        DrawRectangle(posX.at(h), posY.at(a), 100, 100, Color{0xB5, 0x88, 0x63, 255});
                        whiteOrBrown++;
                    }
                }
            }
        }

        EndDrawing();

    }
}

//DrawRectangle(0, 0, 100, 100, Color{0xB5, 0x88, 0x63, 255});
// DrawRectangle(0, 0, 100, 100, WHITE);