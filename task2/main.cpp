#include <iostream>

using Func = bool (*)(int& b);

struct Command {
  const char* name;
  Func foo;
};

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

bool Deposit(int& b) {
  int k;
  std::cin >> k;
  if (k <= 0) {
    return false;
  }
  b += k;
  return true;
}

bool Withdraw(int& b) {
  int k;
  std::cin >> k;
  if (k <= 0 || k > b) {
    return false;
  }
  b -= k;
  return true;
}

bool Balance(int& b) {
  std::cout << b << '\n';
  return true;
}

bool Reset(int& b) {
  b = 0;
  return true;
}

bool Inc(int& b) {
  ++b;
  return true;
}

int main() {
  int b = 0;
  const int c_ = 5;
  Command commands[c_] = {{"deposit", Deposit}, {"withdraw", Withdraw}, {"balance", Balance}, {"reset", Reset}, {"inc", Inc}};
  
  char cur_cmd[100];
  while (std::cin >> cur_cmd) {
    if (CheckStrings(cur_cmd, "stop")) {
        break;
    }
    bool flag_found = false;
    for (int i = 0; i < c_; ++i) {
      if (CheckStrings(commands[i].name, cur_cmd)) {
        flag_found = true;
        if (commands[i].foo(b) == false) {
          std::cout << "error" << '\n';
        }
        break;
      }
    }
    if (flag_found == false) {
      std::cout << "error" << '\n';
    }
  }
  return 0;
}
