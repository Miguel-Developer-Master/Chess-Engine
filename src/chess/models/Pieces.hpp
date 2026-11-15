#pragma once

#include <array>
#include <string_view>

enum class Pieces {
    Empty,

    WhitePawn,
    WhiteRook,
    WhiteBishop,
    WhiteKnight,
    WhiteQueen,
    WhiteKing,

    BlackPawn,
    BlackRook,
    BlackBishop,
    BlackKnight,
    BlackQueen,
    BlackKing
};

inline constexpr std::array<std::string_view, 13> pieceNames = {
    "Empty",
    "WhitePawn",
    "WhiteRook",
    "WhiteBishop",
    "WhiteKnight",
    "WhiteQueen",
    "WhiteKing",
    "BlackPawn",
    "BlackRook",
    "BlackBishop",
    "BlackKnight",
    "BlackQueen",
    "BlackKing"
};