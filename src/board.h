#pragma once
#include <vector>

#include <cell.h>

enum class GameState { Playing, Won, Lost };
enum class MoveResult { Valid, Invalid, Flagged, AlreadyOpen };

class Board {
  public:
    Board(int rows, int cols, int bombs);
    MoveResult flagCell(int row, int col);
    const Cell &getCell(int row, int col) const;
    MoveResult processMove(int row, int col);
    bool checkMove(int row, int col);
    MoveResult handleFirstClick(int row, int col);
    GameState getGameState() const;
    int getFlagCount() const;
    int getBombCount() const;

  private:
    std::vector<std::vector<Cell>> m_grid;
    int m_bombs;
    int m_rows;
    int m_cols;
    int m_bombsFlagged;
    GameState m_gameState = GameState::Playing;
    void updateGameState();
    void calculateValue(int row, int col);
    void floodFill(int row, int col);
    bool isNeighbor(int r1, int c1, int r2, int c2);
};