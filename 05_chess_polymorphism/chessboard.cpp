#include <iostream>
#include <sstream>
#include <memory>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

class ChessBoard {
public:
  enum class Color { WHITE,
                     BLACK };

  class Piece {
  public:
    Piece(Color color) : color(color) {}
    virtual ~Piece() {}

    Color color;
    std::string color_string() const {
      if (color == Color::WHITE)
        return "white";
      else
        return "black";
    }

    /// Return color and type of the chess piece
    /// Note: This serves as visuall representation, too!
    virtual std::string type() const = 0;

    /// Returns true if the given chess piece move is valid
    virtual bool valid_move(int from_x, int from_y, int to_x, int to_y) const = 0;

    virtual std::string to_string() const = 0;

    static bool within_bounds(int x, int y) {
      return x >= 0 && x < 8 && y >= 0 && y < 8;
    }
  };

  class King : public Piece {
  public:
    King(Color color) : Piece(color) {}

    std::string type() const override {
      return (color == Color::WHITE ? "white" : "black") + std::string(" king");
    }

    std::string to_string() const override {
      // Yes, it could be done with text like this:
      // return (color == Color::WHITE ? "white" : "black") + " king";
      // But since there are unicode characters for all chess pieces
      // and the terminal *I* use does support unicode,
      // I choose to display the pieces in a prettier way
      // ...never mind, I'll conform to your desires
      return (color == Color::WHITE) ? "♔" : "♚";
    }

    /// A king moves 1 step in any direction
    // This does not (and can not) handle castling
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      if (!within_bounds(to_x, to_y))
        return false;
      return to_x <= from_x + 1 && to_x >= from_y - 1
          && to_y <= from_y + 1 && to_y >= from_y - 1
          && !(to_x == from_x && to_y == from_y);
    }
  };

  class Knight : public Piece {
  public:
    Knight(Color color) : Piece(color) {}

    std::string type() const override {
      return (color == Color::WHITE ? "white" : "black") + std::string(" knight");
    }

    std::string to_string() const override {
      return (color == Color::WHITE) ? "♘" : "♞";
    }

    /// A knight moves 2 steps in one direction and 1 step in the other
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      if (!within_bounds(to_x, to_y))
        return false;
      return (abs(from_x - to_x) == 2 && abs(from_y - to_y) == 1)
          || (abs(from_x - to_x) == 1 && abs(from_y - to_y) == 2);
    }
  };

  class Rook : public Piece {
  public:
    Rook(Color color) : Piece(color) {}

    std::string type() const override {
      return (color == Color::WHITE ? "white" : "black") + std::string(" rook");
    }

    std::string to_string() const override {
      return (color == Color::WHITE) ? "♖" : "♜";
    }

    /// A rook moves horizontally or vertically
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      if (!within_bounds(to_x, to_y))
        return false;
      return from_x == to_x || from_y == to_y; // movement along *one* axis
    }
  };

  class Bishop : public Piece {
  public:
    Bishop(Color color) : Piece(color) {}

    std::string type() const override {
      return (color == Color::WHITE ? "white" : "black") + std::string(" bishop");
    }

    std::string to_string() const override {
      return (color == Color::WHITE) ? "♗" : "♝";
    }

    /// A bishop moves diagonally
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      if (!within_bounds(to_x, to_y))
        return false;
      return abs( to_x - from_x ) == abs( from_y - to_y );
    }
  };

  class Queen : public Piece {
  public:
    Queen(Color color) : Piece(color) {}

    std::string type() const override {
      return (color == Color::WHITE ? "white" : "black") + std::string(" queen");
    }

    std::string to_string() const override {
      return (color == Color::WHITE) ? "♕" : "♛";
    }

    /// A queen moves like a rook and a bishop combined
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      if (!within_bounds(to_x, to_y))
        return false;
      return (from_x == to_x || from_y == to_y) || (abs( to_x - from_x ) == abs( from_y - to_y )); // eight-directional straight-line movement
    }
  };

  class Pawn : public Piece {
  public:
    Pawn(Color color) : Piece(color) {}

    std::string type() const override {
      return (color == Color::WHITE ? "white" : "black") + std::string(" pawn");
    }

    std::string to_string() const override {
      return (color == Color::WHITE) ? "♙" : "♟";
    }

    /// A pawn moves 1 step forward, or 2 if it is in its starting position
    // This does *not* handle special/normal behaviour for taking out another piece,
    // due to the severe limitation of not *knowing* the state of the board.
    bool valid_move(int from_x, int from_y, int to_x, int to_y) const override {
      if (!within_bounds(to_x, to_y))
        return false;
      return from_x == to_x && (abs(to_y - from_y) == 1
          || (abs(to_y - from_y) == 2 && (color == Color::WHITE ? from_y == 1 : from_y == 6)));
    }
  };

  ChessBoard() {
    // Initialize the squares stored in 8 columns and 8 rows:
    squares.resize(8);
    for (auto &square_column : squares)
      square_column.resize(8);
  }

  /// 8x8 squares occupied by 1 or 0 chess pieces
  vector<vector<unique_ptr<Piece>>> squares;

  /// Move a chess piece if it is a valid move.
  /// Does not test for check or checkmate.
  bool move_piece(const std::string &from, const std::string &to) {
    int from_x = from[0] - 'a';
    int from_y = stoi(string() + from[1]) - 1;
    int to_x = to[0] - 'a';
    int to_y = stoi(string() + to[1]) - 1;

    auto &piece_from = squares[from_x][from_y];
    if (piece_from) {
      if (piece_from->valid_move(from_x, from_y, to_x, to_y)) {
        cout << piece_from->type() << " is moving from " << from << " to " << to << endl;
        auto &piece_to = squares[to_x][to_y];
        if (piece_to) {
          if (piece_from->color != piece_to->color) {
            cout << piece_to->type() << " is being removed from " << to << endl;
            if (auto king = dynamic_cast<King *>(piece_to.get()))
              cout << king->color_string() << " lost the game" << endl;
          } else {
            // piece in the from square has the same color as the piece in the to square
            cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
            return false;
          }
        }
        piece_to = move(piece_from);
        return true;
      } else {
        cout << "can not move " << piece_from->type() << " from " << from << " to " << to << endl;
        return false;
      }
    } else {
      cout << "no piece at " << from << endl;
      return false;
    }
  }

  std::string to_string() const {
    std::ostringstream os;

    // Print column letters
    os << " ";
    for (int i = 0; i < 8; i++) 
      os << " " << (char)('a' + i);
    os << endl;

    for (int i = 7; i >= 0; i--) {
      os << (i+1); // so, the inner index is the y axis
      for (int j = 0; j < 8; j++)
        os << " " << (squares[j][i] ? squares[j][i]->to_string() : "_");
      os << endl;
    }

    return os.str();
  }
};

int main() {
  ChessBoard board;

  board.squares[4][0] = make_unique<ChessBoard::King>(ChessBoard::Color::WHITE);
  board.squares[1][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);
  board.squares[6][0] = make_unique<ChessBoard::Knight>(ChessBoard::Color::WHITE);

  board.squares[4][7] = make_unique<ChessBoard::King>(ChessBoard::Color::BLACK);
  board.squares[1][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);
  board.squares[6][7] = make_unique<ChessBoard::Knight>(ChessBoard::Color::BLACK);

  ChessBoard other_board;

  other_board.squares[4][2] = make_unique<ChessBoard::Queen>(ChessBoard::Color::WHITE);
  other_board.squares[2][5] = make_unique<ChessBoard::Bishop>(ChessBoard::Color::WHITE);
  other_board.squares[3][1] = make_unique<ChessBoard::Pawn>(ChessBoard::Color::WHITE);
  other_board.squares[4][1] = make_unique<ChessBoard::Pawn>(ChessBoard::Color::WHITE);

  other_board.squares[7][7] = make_unique<ChessBoard::Rook>(ChessBoard::Color::BLACK);

  cout << board.to_string();

  cout << "Invalid moves:" << endl;
  board.move_piece("e3", "e2");
  board.move_piece("e1", "e3");
  board.move_piece("b1", "b2");
  cout << endl;

  cout << "Another board:" << endl;
  cout << other_board.to_string();
  cout << endl;

  cout << "More invalid moves:" << endl;
  other_board.move_piece("e3", "f5"); // queen outside axis
  other_board.move_piece("c6", "f5"); // bishop outside axis
  other_board.move_piece("h8", "a1"); // rook outside axis
  other_board.move_piece("e2", "e6"); // pawn 4 forward
  cout << endl;

  cout << "Some valid moves:" << endl;
  other_board.move_piece("e3", "g5");
  other_board.move_piece("c6", "a4");
  other_board.move_piece("h8", "h1");
  other_board.move_piece("d2", "d4");
  other_board.move_piece("e2", "e3");
  cout << endl;

  cout << "State of this other board:" << endl;
  cout << other_board.to_string();
  cout << endl;

  cout << "A simulated game:" << endl;

  // the moves that were here before
  vector<pair<string, string>> moves = {
    {"e1", "e2"},
    {"g8", "h6"},
    {"b1", "c3"},
    {"h6", "g8"},
    {"c3", "d5"},
    {"g8", "h6"},
    {"d5", "f6"},
    {"h6", "g8"},
    {"f6", "e8"}
  };

  cout << endl;
  cout << board.to_string();
  cout << endl;

  // Decomposition time!
  for (auto [a,b] : moves) {
    board.move_piece(a, b);
    cout << endl;
    cout << board.to_string();
    cout << endl;
  }
}

// vim:softtabstop=2:shiftwidth=2
