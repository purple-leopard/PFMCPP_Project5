#include <iostream>
#include "MeteoSpaceNetwork.h"

MeteoSpaceNetwork::MeteoSpaceNetwork()
{
    std::cout << "MeteoSpaceNetwork being constructed\n";
    geostationarySat.normalizeAttitude(50.1);
    lowOrbitalSat.normalizeAttitude(49.3);
}

MeteoSpaceNetwork::~MeteoSpaceNetwork()
{
    std::cout << "MeteoSpaceNetwork being destructed\n";
}

void MeteoSpaceNetwork::recalibrateNetworkAntennas(const float newFreq)
{
    std::cout << "recalibrating satellite antennas to " << newFreq << " GHz\n";
    geostationarySat.antennaCenterFrequency = newFreq;
    lowOrbitalSat.antennaCenterFrequency = newFreq;
}

void MeteoSpaceNetwork::adjustOrbitingNodeVelocity(const double targetVelocity)
{
    std::cout << "adjusting orbital velocity of orbiting satellite to " << targetVelocity << "*10^3 ms^-1\n";
    lowOrbitalSat.orbitalVelocity = targetVelocity;
}
