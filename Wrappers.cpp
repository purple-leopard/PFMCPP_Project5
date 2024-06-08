#include "Wrappers.h"

DogWrapper::DogWrapper(Dog* dog) : dogPtr(dog) {}

DogWrapper::~DogWrapper()
{
    delete dogPtr;
}

DogCollarWrapper::DogCollarWrapper(Dog::DogCollar* dogCollar) : dogCollarPtr(dogCollar) {}

DogCollarWrapper::~DogCollarWrapper()
{
    delete dogCollarPtr;
}
