#include "Errors.hpp"
#include <iostream>
#include <string>
#include <vector>

template <typename T, int Cap>
class Registry {
private:
  std::vector<T> log;
public:
  void add(const T& item) {
    if (log.size() >= Cap) {
      throw CustomError("Registry Capacity Exceeded");
    }
    log.push_back(item);
  }
  int size() const { return log.size(); }
  const T& operator[](int idx) const {
    if (idx < 0 || idx >= log.size()) {
      throw CustomError("Invalid Index");
    }
    return log[idx];
  }
};

template <typename T, int Cap>
std::ostream& operator<<(std::ostream& out, const Registry<T, Cap>& log) {
  for (int i = 0; i < log.size(); ++i) {
    out << i + 1 << ": " << log[i] << '\n';
  }
  return out;
}
