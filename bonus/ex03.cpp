#include "../List.hpp"
#include <iostream>

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

void touch(IObject* object) {
    if (object != nullptr)
        object->touch();
}

int main(void) {
    try {
        List list;
        list.pushBack(new TestObject("Kermit"));
        list.pushBack(new TestObject("Miss Piggy"));
        list.pushFront(nullptr);
        list.front() = new TestObject("Fozzie");
        list.pushBack(nullptr);
        list.forEach(touch);
        list.clear();
        list.popBack();
        list.pushFront(new TestObject("Gonzo"));
    } catch (const List ::InvalidOperationException& e) {
        std ::cout << "Invalid operation on a list" << std ::endl;
    }
    return 0;
}
