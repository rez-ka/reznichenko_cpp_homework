#include "Inventory.hpp"
#include <string>

class Transport : public InventoryItem {
private:
  std::string id_;
  std::string name_;
  int score_;
public:
  Transport(std::string id, std::string name, int score) : id_(id), name_(name), score_(score) {}
  std::string inventoryId() const override { return id_; }
  std::string name() const override { return name_; }
  int score() const { return score_; }
  bool isForNovice() const { return (score_ >= 6); }
};

class CheapBike : public Transport {
public:
  using Transport::Transport;
  std::string describe() const override { 
    return "Cheap Bike >> Id: " + inventoryId() + " >> Name: " + name();
  }
};

class ElectricBike : public Transport, public EnergyConsumer {
private:
  float energy_;
public:
  ElectricBike(std::string id, std::string name, float energy, int score) : Transport(id, name, score), energy_(energy) {}
  std::string describe() const override { 
    return "Electric Bike >> Id: " + inventoryId() + " >> Name: " + name();
  }
float dailyEnergy() const override { return energy_; }
};
