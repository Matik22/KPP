#pragma once
#include <iostream>

class IContainable {
public:
    virtual void printInfo() = 0;
    virtual bool isLessThan(const IContainable& other) const = 0;
    virtual ~IContainable() = default;
};