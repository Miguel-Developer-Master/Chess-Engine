#include "raylib.h"

#include "DrawPiece.hpp"
#include "models/Board.hpp"
#include "LoadBoard.hpp"
#include "MovePiece.hpp"

#include <array>
#include <format>
#include <string>
#include <map>

int getMouseColumn(int mouseX) {
    int mouseColumn;

    if (mouseX > 700) {
        mouseColumn = 7;
    } else if (mouseX > 600) {
        mouseColumn = 6;
    } else if (mouseX > 500) {
        mouseColumn = 5;
    } else if (mouseX > 400) {
        mouseColumn = 4;
    } else if (mouseX > 300) {
        mouseColumn = 3;
    } else if (mouseX > 200) {
        mouseColumn = 2;
    } else if (mouseX > 100) {
        mouseColumn = 1;
    } else {
        mouseColumn = 0;
    }

    return mouseColumn;
}

int getMouseRow(int mouseY) {
    int mouseRow;

    if (mouseY > 700) {
        mouseRow = 7;
    } else if (mouseY > 600) {
        mouseRow = 6;
    } else if (mouseY > 500) {
        mouseRow = 5;
    } else if (mouseY > 400) {
        mouseRow = 4;
    } else if (mouseY > 300) {
        mouseRow = 3;
    } else if (mouseY > 200) {
        mouseRow = 2;
    } else if (mouseY > 100) {
        mouseRow = 1;
    } else {
        mouseRow = 0;
    }

    return mouseRow;
}

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

    SetTargetFPS(180);

//dictionary.at(getMouseColumn(mouseX))
//int mousePressedRow = getMouseRow(mouseY);
    bool isDragging = false;
    int mouseX = -1;
    char mousePressedColumn;
    int mouseY = -1;
    int mousePressedRow;
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
                        drawPiece(posX.at(columns), posY.at(a), dictionary.at(columns),
                            row, board, textures, false);
                        columns++;
                    } else {
                        DrawRectangle(posX.at(columns), posY.at(a), 100, 100, Color{0xB5, 0x88, 0x63, 255});
                        drawPiece(posX.at(columns), posY.at(a), dictionary.at(columns),
                            row, board, textures, false);
                        columns++;
                    }
                }
            } else {
                int columns = 0;
                // if odd, white
                while (columns < 8) {
                    if (columns % 2 != 0) {
                        DrawRectangle(posX.at(columns), posY.at(a), 100, 100, WHITE);
                        drawPiece(posX.at(columns), posY.at(a), dictionary.at(columns),
                            row, board, textures, false);
                        columns++;
                    } else {
                        DrawRectangle(posX.at(columns), posY.at(a), 100, 100, Color{0xB5, 0x88, 0x63, 255});
                        drawPiece(posX.at(columns), posY.at(a), dictionary.at(columns),
                            row, board, textures, false);
                        columns++;
                    }
                }
            }
        }


        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            isDragging = true;
            mouseX = GetMouseX();
            mouseY = GetMouseY();
            mousePressedColumn = dictionary.at(getMouseColumn(mouseX));
            mousePressedRow = getMouseRow(mouseY);
        }

        if (isDragging && IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
            int movingMouseX = GetMouseX();
            int movingMouseY = GetMouseY();
            drawPiece(movingMouseX - 50, movingMouseY - 50, mousePressedColumn, mousePressedRow,
                board, textures, true);
        }

        if (isDragging && IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {

            int mouseX2 = GetMouseX();
            char mouseUnpressedColumn = dictionary.at(getMouseColumn(mouseX2));
            int mouseY2 = GetMouseY();
            int mouseUnpressedRow = getMouseRow(mouseY2);
            Pieces pressedPiece = board.getSquare(mousePressedRow, mousePressedColumn);
            Pieces unpressedPiece = board.getSquare(mouseUnpressedRow, mouseUnpressedColumn);

            if (!((mouseUnpressedColumn == mousePressedColumn && mouseUnpressedRow == mousePressedRow))) {

                movePiece(mousePressedRow, mousePressedColumn, mouseUnpressedRow,
                    mouseUnpressedColumn, pressedPiece, unpressedPiece, board);

            }


            isDragging = false;
        }

        EndDrawing();
    }

    for (int j = 1; j < 13; j++) {
        UnloadTexture(textures.at(j));
    }
    CloseWindow();
}