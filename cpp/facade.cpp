#include <iostream>

class AirConditioning {
public:
    void ACOn() {
        std::cout << "AC is running; ";
    }
    void ACOff() {
        std::cout << "AC is off; ";
    }
};

class Blind {
public:
    void close() {
        std::cout << "Closing blinds; ";
    }
    void reveal() {
        std::cout << "Revealing blinds; ";
    }
};

class TV {
public:
    void TVOn() {
        std::cout << "TV on; ";
    }
    void TVOff() {
        std::cout << "TV off; ";
    }
};

class HouseManager {
    AirConditioning airConditioning;
    Blind blind;
    TV tv;
public:
    void saveEnergy() {
        airConditioning.ACOff();
        tv.TVOff();
    };
    void goOut() {
        airConditioning.ACOff();
        tv.TVOff();
        blind.close();
    }
    void comeHome() {
        airConditioning.ACOn();
        tv.TVOn();
        blind.reveal();
    }
};


int main() {
    HouseManager houseManager;
    std::cout << "Save energy: ";
    houseManager.saveEnergy();
    std::cout << std::endl;
    
    std::cout << "Go out: ";
    houseManager.goOut();
    std::cout << std::endl;
    
    std::cout << "Come home: ";
    houseManager.comeHome();
    std::cout << std::endl;
}
