#include <iostream>
#include <string>
#include <utility>

#include "../UniquePointer.hpp"

class TestObject : public IObject {
   public:
    TestObject(std::string name) : _name(std::move(name)) {
        std::cout << _name << " is alive\n";
    }
    ~TestObject() override { std::cout << _name << " is dead\n"; }

    void touch() override { std::cout << _name << " is touched\n"; }

   private:
    std::string _name;
};

int main() {
    UniquePointer ptr1;
    UniquePointer ptr2(new TestObject("Eccleston"));
    // UniquePointer ptr3(ptr2) ; <- Does not compile !
    ptr1 = new TestObject("Tennant");
    ptr2 = new TestObject("Smith");
    ptr1->touch();
    (*ptr2).touch();
    { UniquePointer ptr4(new TestObject("Whittaker")); }
    ptr1.reset(new TestObject("Capaldi"));
    ptr1.swap(ptr2);
    // ptr1 = ptr2 ; <- Does not compile !
    ptr2.reset();
    return 0;
}
