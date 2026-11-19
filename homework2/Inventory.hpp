#include <iostream>
#include <string>

class InventoryItem {
public:
  virtual ~InventoryItem() = default;
  virtual std::string inventoryId() const = 0;
  virtual std::string name() const = 0;
  virtual std::string describe() const = 0;
};

class EnergyConusmer {
public:
  virtual ~EnergyConsumer() = default;
  virtual float dailyEnergy() const = 0;
};

inline std::ostream& operator<<(std::ostream& out, const InventoryItem& item) {
  out << item.InventoryId() << ' ' << item.name();
  return out;
}

inline bool operator<(const InventoryItem& a, const InventoryItem& b) {
  return (a.inventoryId() < b.inventoryId());
}

inline bool operator<=(const InventoryItem& a, const InventoryItem& b) {
  return (a.inventoryId() <= b.inventoryId());
}

inline bool operator==(const InventoryItem& a, const InventoryItem& b) {
  return (a.inventoryId() == b.inventoryId());
}

inline bool operator!=(const InventoryItem& a, const InventoryItem& b) {
  return (a.inventoryId() != b.inventoryId());
}
