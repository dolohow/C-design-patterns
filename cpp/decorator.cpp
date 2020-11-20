#include <iostream>

class Cake {
public:
  Cake() {}
  virtual uint getCost() { return 100; }
  virtual std::string getDescription() { return "Cake"; }
};

class CakeOptions : public Cake {
  Cake &cake;
  std::string description;
  uint cost;

public:
  CakeOptions(Cake &cake, std::string description, uint cost)
      : cake{cake}, description{description}, cost{cost} {}
  virtual std::string getDescription() {
    return cake.getDescription() + " " + description;
  }
  virtual uint getCost() { return cake.getCost() + cost; }
};

class WhippedCream : public CakeOptions {
public:
  WhippedCream(Cake &cake) : CakeOptions{cake, "WhippedCream", 10} {}
};

class ChocolateGlaze : public CakeOptions {
public:
  ChocolateGlaze(Cake &cake) : CakeOptions{cake, "ChocolateGlaze", 20} {}
};

int main() {
  Cake cake;
  std::cout << cake.getCost() << std::endl;

  WhippedCream cream(cake);
  std::cout << cream.getDescription() << " " << cream.getCost() << std::endl;

  ChocolateGlaze glaze(cream);
  std::cout << glaze.getDescription() << " " << glaze.getCost() << std::endl;
}