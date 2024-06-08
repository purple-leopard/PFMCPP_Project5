#pragma once
#include <iostream>
#include "LeakedObjectDetector.h"

/*
 copied UDT 3:
 */
struct WeatherSatellite
{
    WeatherSatellite();
    ~WeatherSatellite();
    int numberOfSolarPanels = 8;
    std::string radiationHardeningType = "Standard";
    double attitude;
    double orbitalVelocity = 7.8;
    float antennaCenterFrequency = 2.4f;
    void switchImagingModality() const;
    int transmitDataToGroundStation() const;
    float monitorBatteryChargeLevel() const;
    void normalizeAttitude(const double targetAttitude);
    void printOrbitalVelocity() const;

    JUCE_LEAK_DETECTOR(WeatherSatellite)
};
