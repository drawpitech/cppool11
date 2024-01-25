/*
** EPITECH PROJECT, 2024
** ppool11
** File description:
** SharedPointer
*/

#pragma once

#include <iostream>

#include "IObject.hpp"

class SharedPointer {
   public:
    SharedPointer();
    SharedPointer(IObject *ptr);
    SharedPointer(const SharedPointer &other);

    ~SharedPointer();

    void swap(SharedPointer &other) noexcept;
    void reset(IObject *ptr = nullptr) noexcept;

    IObject *operator->() const;
    IObject &operator*() const;
    SharedPointer &operator=(IObject *ptr);
    SharedPointer &operator=(const SharedPointer &other);

    [[nodiscard]] size_t use_count() const;

   private:
    IObject *_ptr = nullptr;
    std::size_t *_count = nullptr;

    void incrementCount();
    void decrementCount();
};
