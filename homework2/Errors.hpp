#include <exception>
#include <string>

class CustomError : public std::exception {
private:
  std::string message_;
public:
  explicit CustomError(std::string message) : message_(message) {}
  const char* what() const noexcept override {
    return message_.c_str();
  }
};

class InspectionError : public CustomError {
public:
  using CustomError::CustomError;
};

class ParsingError : public CustomError {
public:
  using CustomError::CustomError;
};
