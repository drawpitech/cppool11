/*
** EPITECH PROJECT, 2024
** ppool11
** File description:
** IDirectoryLister
*/

#include "SharedPointer.hpp"

#include <utility>

SharedPointer::SharedPointer() { incrementCount(); }
SharedPointer::SharedPointer(IObject *ptr) : _ptr(ptr) { incrementCount(); }
SharedPointer::SharedPointer(const SharedPointer &other)
    : _count(other._count) {
    incrementCount();
}

SharedPointer::~SharedPointer() { decrementCount(); }

void SharedPointer::swap(SharedPointer &other) noexcept {
    std::swap(_ptr, other._ptr);
    std::swap(_count, other._count);
}
void SharedPointer::reset(IObject *ptr) noexcept {
    decrementCount();
    if (ptr != nullptr) {
        incrementCount();
        _ptr = ptr;
    }
}

size_t SharedPointer::use_count() const { return (_count != nullptr) ? *_count : 0; }

IObject *SharedPointer::operator->() const { return _ptr; }
IObject &SharedPointer::operator*() const { return *_ptr; }
SharedPointer &SharedPointer::operator=(IObject *ptr) {
    decrementCount();
    incrementCount();
    _ptr = ptr;
    return *this;
}
SharedPointer &SharedPointer::operator=(const SharedPointer &other) {
    decrementCount();
    _count = other._count;
    _ptr = other._ptr;
    incrementCount();
    return *this;
}

void SharedPointer::incrementCount() {
    if (_count == nullptr)
        _count = new size_t(1);
    else
        *_count += 1;
}
void SharedPointer::decrementCount() {
    if (_count == nullptr)
        return;
    *_count -= 1;
    if (*_count == 0) {
        delete _ptr;
        delete _count;
    }
    _count = nullptr;
    _ptr = nullptr;
}
