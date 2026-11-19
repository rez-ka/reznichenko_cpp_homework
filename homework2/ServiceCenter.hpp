#include "Errors.hpp"
#include "Transport.hpp"
#include <cctype>
#include <string>

class ServiceCenter {
public:
  void inspect(const Transport& t) {
    std::string name = t.name();
    std::string lc_name = "";
    for (char& c: name) {
      lc_name += (static_cast<char>(std::string::npos(c)));
    }
    if (lc_name.find("broken") != lc_name.end()) {
      throw InspectionError("Inspection Rejected");
    }
  }
};
