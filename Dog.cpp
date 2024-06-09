#include <iostream>
#include "Dog.h"

Dog::Dog() : weight(1.0f), height(0.5f), ageInYears(1), furColour("brown"), breed("Jack Russel")
{
    std::cout << "Dog being constructed\n";
}

Dog::~Dog()
{
    std::cout << "Dog being destructed\n";
}

Dog::DogCollar::DogCollar() : material("leather"), color("red"), dogName("BUSTER"), length(15.0f), width(0.5f)
{
    std::cout << "DogCollar being constructed\n";
}

Dog::DogCollar::~DogCollar()
{
    std::cout << "DogCollar being destructed\n";
}

void Dog::DogCollar::attachLeash(const std::string& leashType, const bool isRetractable)
{
    std::cout << "leash material: " << material << ", leash type: " << leashType << ", leash retractable: " << isRetractable << "\n";
}

void Dog::DogCollar::remove(const bool clipRelease)
{
    std::cout << (clipRelease ? "clip released\n" : "clip not released\n");
}

bool Dog::DogCollar::adjustFit(const float newSize, const float minSize, const float maxSize) 
{
    if (newSize >= minSize && newSize <= maxSize) 
    {
        length = newSize;
        std::cout << "adjustment successful\n";
        return true;
    }
    std::cout << "adjustment unsuccessful\n";
    return false;
}

void Dog::DogCollar::jingleBell(const int numJingles)
{
    std::cout << "collar bell goes:\n";
    for(int count = 0; count < numJingles; ++count)
    {
        std::cout << "jingle\n";
    }
}

void Dog::DogCollar::printCollarMaterial() const
{
    std::cout << "dog's collar material: " << this->material << "\n";
}

void Dog::barkAtPostman() const
{
    std::cout << furColour << " colour dog is barking at the postman\n";
}

void Dog::fetchBall() const
{
    std::cout << "fetch\n";
}

bool Dog::tryNewCollar(const DogCollar& newCollar) 
{
    if (newCollar.length >= 10.0f && newCollar.length <= 20.0f) 
    {
        currentCollar = newCollar;
        std::cout << "collar fits, replace original collar with new collar\n";
        return true;
    }
    std::cout << "collar doesn't fit, keep original collar\n";
    return false;
}

void Dog::simulateAgeing(const int yearsToAgeBy)
{
    int year = 0;
    while(year < yearsToAgeBy)
    {
        ++year;
        ++ageInYears;
        weight += 1.5f;

        std::cout << "dog is now " << ageInYears << " years old and weighs " << weight << " kg\n";

        if(ageInYears == 9)
        {
            std::cout << "dog is 9 years older now, ending simulation early\n";
            break;
        }
        
    }
}

void Dog::printWeight() const
{
    std::cout << "dog's weight: " << this->weight << " kg" << "\n";
}
