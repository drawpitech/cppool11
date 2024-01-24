/*
** EPITECH PROJECT, 2024
** ppool11
** File description:
** IDirectoryLister
*/

#pragma once

#include <dirent.h>

#include "IDirectoryLister.hpp"

class DirectoryLister : public IDirectoryLister {
   public:
    DirectoryLister();
    DirectoryLister(const std::string &path, bool hidden);
    ~DirectoryLister() override;

    bool open(const std::string &path, bool hidden) override;
    std::string get() override;

   private:
    DIR *_dir = nullptr;
    bool _hidden = false;
};
