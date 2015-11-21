#include <iostream>
#include <mutex>
#include <thread>

class Singleton {
public:
    static Singleton* getInstance();

private:
    Singleton() {};
};

Singleton* Singleton::getInstance() {
    std::unique_lock<std::mutex> l;

    std::cout << "Instance" << std::endl;

    static Singleton instance;

    return &instance;
}

int main() {
    std::thread t1 (Singleton::getInstance);
    std::thread t2 (Singleton::getInstance);

    t1.join();
    t2.join();
}

