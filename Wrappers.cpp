#include "Wrappers.h"
#include "WeatherSatellite.h"
#include "InternetCafe.h"
#include "MeteoSpaceNetwork.h"

DogWrapper::DogWrapper(Dog* dog) : dogPtr(dog) {}

DogWrapper::~DogWrapper()
{
    delete dogPtr;
}

DogCollarWrapper::DogCollarWrapper(Dog::DogCollar* dogCollar) : dogCollarPtr(dogCollar) {}

DogCollarWrapper::~DogCollarWrapper()
{
    delete dogCollarPtr;
}

LaptopWrapper::LaptopWrapper(Laptop* laptop) : laptopPtr(laptop) {}

LaptopWrapper::~LaptopWrapper()
{
    delete laptopPtr;
}

LaptopBatteryWrapper::LaptopBatteryWrapper(Laptop::Battery* laptopBattery) : laptopBatteryPtr(laptopBattery) {}

LaptopBatteryWrapper::~LaptopBatteryWrapper()
{
    delete laptopBatteryPtr;
}

WeatherSatelliteWrapper::WeatherSatelliteWrapper(WeatherSatellite* weatherSatellite) : weatherSatellitePtr(weatherSatellite) {}

WeatherSatelliteWrapper::~WeatherSatelliteWrapper()
{
    delete weatherSatellitePtr;
}

InternetCafeWrapper::InternetCafeWrapper(InternetCafe* internetCafe) : internetCafePtr(internetCafe) {}

InternetCafeWrapper::~InternetCafeWrapper()
{
    delete internetCafePtr;
}

MeteoSpaceNetworkWrapper::MeteoSpaceNetworkWrapper(MeteoSpaceNetwork* meteoSpaceNetwork) : meteoSpaceNetworkPtr(meteoSpaceNetwork) {}

MeteoSpaceNetworkWrapper::~MeteoSpaceNetworkWrapper()
{
    delete meteoSpaceNetworkPtr;
}
