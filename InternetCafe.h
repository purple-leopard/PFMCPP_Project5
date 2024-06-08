#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"
#include "Laptop.h"

/*
 new UDT 4:
 with 2 member functions
 */
struct InternetCafe
{
    InternetCafe();
    ~InternetCafe();
    Laptop upstairsLaptop;
    Laptop downstairsLaptop;
    Laptop::Battery spareBattery;
    void fixDeadUpstairsLaptop(const Laptop::Battery& replacementBattery);
    void updateDownstairsLaptopOS(const std::string& newOS);

    JUCE_LEAK_DETECTOR(InternetCafe)
};
