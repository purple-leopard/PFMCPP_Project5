#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

/*
 copied UDT 1:
 */
struct Dog
{
    Dog();
    ~Dog();
    float weight;
    float height;
    int ageInYears;
    std::string furColour;
    std::string breed;

    struct DogCollar
    {
        DogCollar();
        ~DogCollar();
        std::string material;
        std::string color;
        std::string dogName;
        float length;
        float width;

        void attachLeash(const std::string& leashType = "standard", const bool isRetractable = false);
        void remove(const bool clipRelease = true);
        bool adjustFit(const float newSize, const float minSize = 10.0f, const float maxSize = 20.0f);
        void jingleBell(const int numJingles);
        void printCollarMaterial() const;

        JUCE_LEAK_DETECTOR(DogCollar)
    };

    void barkAtPostman() const;
    void fetchBall() const;
    bool tryNewCollar(const DogCollar& newCollar);
    void simulateAgeing(const int yearsToAgeBy);
    void printWeight() const;

    DogCollar currentCollar;

    JUCE_LEAK_DETECTOR(Dog)
};
