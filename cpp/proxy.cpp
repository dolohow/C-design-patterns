#include <iostream>

class API {
public:
  int getSecretNumber() { return 5; }
};

class OnlyWhenAuthorized : public API {
  API &api;
  int key;

public:
  OnlyWhenAuthorized(API &api, int key) : api{api}, key{key} {}
  bool hasAccess() {
    if (key == 13)
      return true;
    return false;
  }
  int getSecretNumber() {
    if (hasAccess()) {
      std::cout << "Accessing secret number... ";
      return api.getSecretNumber();
    }
    std::cout << "Access denied ";
    return -1;
  }
};

int main() {

  API api;
  std::cout << "Direct access, result: " << api.getSecretNumber() << std::endl;

  OnlyWhenAuthorized proxy{api, 13};
  std::cout << "Proxy access: " << proxy.getSecretNumber() << std::endl;

  OnlyWhenAuthorized proxy_invalid{api, 7};
  std::cout << "Proxy access: " << proxy_invalid.getSecretNumber() << std::endl;
}