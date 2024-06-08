#include "WeatherSatellite.h"

WeatherSatellite::WeatherSatellite() : attitude(45.7)
{
    std::cout << "WeatherSatellite being constructed\n";
}

WeatherSatellite::~WeatherSatellite()
{
    std::cout << "WeatherSatellite being destructed\n";
}

void WeatherSatellite::switchImagingModality() const
{
    std::cout << "satellite attitude is " <<  attitude << " degrees, switching imaging modality from visible to infrared\n";
}

int WeatherSatellite::transmitDataToGroundStation() const
{
    int numberOfImagesTransmitted = 500;
    std::cout << "transmitted " << numberOfImagesTransmitted << " images\n";
    return numberOfImagesTransmitted;
}

float WeatherSatellite::monitorBatteryChargeLevel() const
{
    float chargeLevel = 75.0f;
    std::cout << "current battery charge level is " << chargeLevel << "%\n";
    return chargeLevel;
}

void WeatherSatellite::normalizeAttitude(const double targetAttitude)
{
    std::cout << "starting attitude normalization from " << attitude << " degrees to " << targetAttitude << " degrees\n";
    while(attitude < targetAttitude)
    {
        attitude += 0.5;
        std::cout << "adjusting, current attitude: " << attitude << " degrees\n";
        if(attitude >= targetAttitude)
        {
            std::cout << "target attitude achieved\n";
            break; 
        }
    }
}

void WeatherSatellite::printOrbitalVelocity() const
{
    std::cout << "sputnik's orbital velocity is: " << this->orbitalVelocity << "*10^3 ms^-1\n";
}
