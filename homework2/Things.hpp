#include "Inventory.hpp"
#include <string>

class Helmet : public InventoryItem {
private:
  std::string id_;
  std::string name_;
public:
  Helmet(std::string id, std::string name) : id_(id), name_(name) {}
  std::string inventoryId() const override { return id_; }
  std::string name() const override { return name_; }
  std::string describe() const override {
    return "Helmet >> Id: " + inventoryId() + " >> Name: " + name();
  }
};
