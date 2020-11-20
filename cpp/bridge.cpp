#include <iostream>
#include <vector>

class Transport {
public:
    virtual void send(std::string person, std::string message) = 0;
    virtual ~Transport() {}
};

class UDP : public Transport {
public:
   void send(std::string person, std::string message) {
       std::cout << "Sending message through UDP: " << message << " to person: " << person << std::endl;
   }
};

class TCP : public Transport {
public:
   void send(std::string person, std::string message) {
       std::cout << "Sending message through TCP: " << message << " to person: " << person << std::endl;
   }
};

class Notifier {
    Transport& transport;
public:
    Notifier(Transport& message) : transport{message} {}
    void notify(const std::vector<std::string>& people) {
        for (auto& i : people) {
            transport.send(i, "Theres a fire in a server room");
        }
    }
};

int main() {
    TCP tcp;
    UDP udp;
    std::vector<std::string> people{"Adam", "Ewa", "Peter"};
    
    Notifier notifierTCP(tcp);
    notifierTCP.notify(people);
    
    Notifier notifierUDP(udp);
    notifierUDP.notify(people);
}
