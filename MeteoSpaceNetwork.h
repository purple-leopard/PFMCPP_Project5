#pragma once
#include "LeakedObjectDetector.h"
#include "WeatherSatellite.h"

/*
 new UDT 5:
 with 2 member functions
 */
struct MeteoSpaceNetwork
{
    MeteoSpaceNetwork();
    ~MeteoSpaceNetwork();
    WeatherSatellite geostationarySat;
    WeatherSatellite lowOrbitalSat;
    void recalibrateNetworkAntennas(const float newFreq);
    void adjustOrbitingNodeVelocity(const double targetVelocity);

    JUCE_LEAK_DETECTOR(MeteoSpaceNetwork)
};
