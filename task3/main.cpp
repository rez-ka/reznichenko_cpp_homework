#include <iostream>

bool IsInBounds(int x, int y) {
  return (x >= 0 && x <= 9 && y >= 0 && y <= 4);
}

bool CheckStrings(const char* s, const char* t) {
  int i = 0;
  while (s[i] != '\0' && t[i] != '\0') {
    if (s[i] != t[i]) {
      return false;
    }
    ++i;
  }
  if (s[i] == '\0' && t[i] == '\0')  {
    return true;
  }
  return false;
}

void Clear(char board[5][10]) {
  for (int y = 0; y < 5; ++y) {
    for (int x = 0; x < 10; ++x) {
      board[y][x] = ' ';
    }
  }
}

bool Put(char board[5][10], int x, int y, char c) {
  if (IsInBounds(x, y)) {
    board[y][x] = c;
    return true;
  }
  return false;
}

bool Text(char board[5][10], int x, int y, const char* s) {
  int n = 0;
  while (s[n] != '\0') {
    ++n;
  }
  for (int i = 0; i < n; ++i) {
    if (IsInBounds(x + i, y) == false) {
      return false;
    }
  }
  for (int i = 0; i < n; ++i) {
    board[y][x + i] = s[i];
  }
  return true;
}

void Print(char board[5][10]) {
  for (int y = 0; y < 5; ++y) {
    for (int x = 0; x < 10; ++x) {
      std::cout << board[y][x];
    }
    std::cout << '\n';
  }
}

int main() {
  char board[5][10];
  Clear(board);

  char cur_cmd[100];
  while (std::cin >> cur_cmd) {
    if (CheckStrings(cur_cmd, "quit")) {
      break;
    } else if (CheckStrings(cur_cmd, "clear")) {
      Clear(board);
    } else if (CheckStrings(cur_cmd, "put")) {
      int x, y;
      char c;
      std::cin >> x >> y >> c;
      if (Put(board, x, y, c) == false) {
        std::cout << "error" << '\n';
      }
    } else if (CheckStrings(cur_cmd, "text")) {
      int x, y;
      char s[100];
      std::cin >> x >> y >> s;
      if (Text(board, x, y, s) == false) {
        std::cout << "error" << '\n';
      }
    } else if (CheckStrings(cur_cmd, "print")) {
      Print(board);
    }
    else {
      std::cout << "error" << '\n';
    }
  }
  return 0;
}
