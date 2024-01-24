/*
** EPITECH PROJECT, 2024
** ppool11
** File description:
** IDirectoryLister
*/

#pragma once

#include <dirent.h>

#include "IDirectoryLister.hpp"

class SafeDirectoryLister : public IDirectoryLister {
   public:
    SafeDirectoryLister();
    SafeDirectoryLister(const std::string &path, bool hidden);
    ~SafeDirectoryLister() override;

    bool open(const std::string &path, bool hidden) override;
    std::string get() override;

   private:
    DIR *_dir = nullptr;
    bool _hidden = false;
};
