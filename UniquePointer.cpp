/*
** EPITECH PROJECT, 2024
** ppool11
** File description:
** IDirectoryLister
*/

#include "UniquePointer.hpp"

#include <utility>

UniquePointer::UniquePointer() = default;
UniquePointer::UniquePointer(IObject *ptr) : _ptr(ptr) {}

UniquePointer::~UniquePointer() { delete _ptr; }

void UniquePointer::swap(UniquePointer &other) noexcept {
    std::swap(_ptr, other._ptr);
}
void UniquePointer::reset(IObject *ptr) noexcept {
    delete _ptr;
    _ptr = ptr;
}

IObject *UniquePointer::operator->() const { return _ptr; }
IObject &UniquePointer::operator*() const { return *_ptr; }
UniquePointer &UniquePointer::operator=(IObject *ptr) {
    delete _ptr;
    _ptr = ptr;
    return *this;
}
