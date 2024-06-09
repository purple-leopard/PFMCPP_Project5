#include <iostream>
#include "Laptop.h"

Laptop::Laptop() : model("Macbook")
{
    std::cout << "Laptop being constructed\n";
}

Laptop::~Laptop()
{
    std::cout << "Laptop being destructed\n";
}

Laptop::Battery::Battery() : capacity(1000.0f)
{
    std::cout << "Battery being constructed\n";
}

Laptop::Battery::~Battery()
{
    std::cout << "Battery being destructed\n";
}

bool Laptop::Battery::charge(const float chargeToLevel) 
{
    float chargeLevel = 75.0f;
    std::cout << "battery charging to level: " << chargeToLevel << "%\n";
    return chargeLevel >= chargeToLevel;
}

float Laptop::Battery::checkCapacityRemaining(const std::string& fuelGuageAlgorithm) 
{
    float capacityRemaining = 1000.0f;
    std::cout << "checking battery capacity remaining out of max capacity " << capacity << " mAh, using " << fuelGuageAlgorithm << "\n";
    return capacityRemaining;
}

void Laptop::Battery::limitChargeCurrent(float inputCurrent, const float temperatureLimit) 
{
    float temperature = 38.0f;
    if (inputCurrent > maxChargeCurrent || temperature > temperatureLimit) 
    {
        inputCurrent = maxChargeCurrent;
        std::cout << "charge current limited to " << maxChargeCurrent << "\n";
    }
}

void Laptop::Battery::drain()
{
    while (capacity > 200.0f)
    {
        capacity -= 200.0f;
        std::cout << "battery capacity now at " << capacity << " mAh\n";
    }
    std::cout << "battery low, please recharge\n";
}

void Laptop::Battery::printChargeCapacity() const
{
    std::cout << "laptop's battery's charge capacity: " << this->capacity << " mAh\n";
}

void Laptop::replaceBattery(const Battery& newBattery) 
{
    currentBattery = newBattery;
    std::cout << model <<" battery replaced with type: " << newBattery.type << "\n";
}

bool Laptop::launchProgram(const std::string& programName) 
{
    std::cout << "launching program: " << programName << "\n";
    return true;
}

bool Laptop::invokeCompiler() const
{
    std::cout << "compiler invoked" << "\n";
    return true;
}

void Laptop::cycleCharge(Battery& battery, const int numCycles)
{
    for(int i = 0; i < numCycles; ++i)
    {
        ++battery.chargeCycles;
        std::cout << "cycling battery charge, cycles are now at: " << battery.chargeCycles << "\n";
    }
}

void Laptop::printBrand() const
{
    std::cout << "laptop brand: " << this->brand << "\n";
}
