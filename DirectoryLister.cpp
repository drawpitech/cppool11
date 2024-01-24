/*
** EPITECH PROJECT, 2024
** ppool11
** File description:
** IDirectoryLister
*/

#include "DirectoryLister.hpp"

#include <sys/types.h>

DirectoryLister::DirectoryLister() = default;

DirectoryLister::DirectoryLister(const std::string &path, bool hidden) {
    open(path, hidden);
}

DirectoryLister::~DirectoryLister() {
    if (_dir != nullptr)
        closedir(_dir);
}

bool DirectoryLister::open(const std::string &path, bool hidden) {
    if (_dir != nullptr)
        closedir(_dir);
    _hidden = hidden;
    _dir = opendir(path.c_str());
    if (_dir != nullptr)
        return true;
    perror("DirectoryLister");
    return false;
}

std::string DirectoryLister::get() {
    if (_dir == nullptr)
        return "";
    struct dirent *ent = readdir(_dir);
    if (ent == nullptr || (char *)ent->d_name == nullptr)
        return "";
    if (ent->d_name[0] == '.' && !_hidden)
        return get();
    return (char *)ent->d_name;
}
