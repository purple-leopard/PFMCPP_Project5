#pragma once
#include "LeakedObjectDetector.h"

/*
 copied UDT 2:
 */
struct Laptop
{
    Laptop();
    ~Laptop();
    std::string brand = "Apple";
    std::string model;
    std::string operatingSystemVersion = "Snow Leopard";
    int memoryCapacity = 16;
    int numberOfProcessorCores = 4;
    
    struct Battery
    {
        Battery();
        ~Battery();
        std::string type = "Li-ion";
        float capacity;
        int chargeCycles = 1000;
        float maxChargeCurrent = 2.0f;
        float voltage = 18.0f;

        bool charge(const float chargeToLevel = 100.0f);
        float checkCapacityRemaining(const std::string& fuelGuageAlgorithm = "ModelGauge");
        void limitChargeCurrent(float inputCurrent, const float temperatureLimit = 85.8f);
        void drain();
        void printChargeCapacity() const;

        JUCE_LEAK_DETECTOR(Battery)
    };

    void replaceBattery(const Battery& newBattery);
    bool launchProgram(const std::string& programName);
    bool invokeCompiler() const;
    void cycleCharge(Battery& battery, const int numCycles);
    void printBrand() const;

    Battery currentBattery;

    JUCE_LEAK_DETECTOR(Laptop)
};
