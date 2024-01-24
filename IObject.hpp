/*
** EPITECH PROJECT, 2024
** ppool11
** File description:
** IObject
*/

#pragma once

class IObject {
   public:
    virtual ~IObject() = default;

    virtual void touch() = 0;
};
