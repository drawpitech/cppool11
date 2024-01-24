/*
** EPITECH PROJECT, 2024
** ppool11
** File description:
** IObject
*/

#pragma once

#include <iostream>

class IObject {
   public:
    virtual ~IObject() = default;

    virtual void touch() = 0;
};

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
