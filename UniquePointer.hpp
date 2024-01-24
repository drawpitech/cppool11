/*
** EPITECH PROJECT, 2024
** ppool11
** File description:
** IDirectoryLister
*/

#pragma once

#include "IObject.hpp"

class UniquePointer {
   public:
    UniquePointer();
    UniquePointer(IObject *ptr);

    ~UniquePointer();

    void swap(UniquePointer &other) noexcept;
    void reset(IObject *ptr = nullptr) noexcept;

    IObject *operator->() const;
    IObject &operator*() const;
    UniquePointer &operator=(IObject *ptr);

   private:
    IObject *_ptr = nullptr;
};
