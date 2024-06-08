#include "Wrappers.h"

DogWrapper::DogWrapper(Dog* dog) : dogPtr(dog) {}

DogWrapper::~DogWrapper()
{
    delete dogPtr;
}
