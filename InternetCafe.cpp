#include "InternetCafe.h"

InternetCafe::InternetCafe()
{
    std::cout << "InternetCafe being constructed\n";
    upstairsLaptop.currentBattery.charge(100.0f);
    downstairsLaptop.currentBattery.charge(100.0f);
    spareBattery.charge(100.0f);
}

InternetCafe::~InternetCafe()
{
    std::cout << "InternetCafe being destructed\n";
}

void InternetCafe::fixDeadUpstairsLaptop(const Laptop::Battery& replacementBattery)
{
    upstairsLaptop.replaceBattery(replacementBattery);
}

void InternetCafe::updateDownstairsLaptopOS(const std::string& newOS)
{
    downstairsLaptop.operatingSystemVersion = newOS;
    std::cout << "update downstairs laptop's OS to " << newOS << "\n";
}
