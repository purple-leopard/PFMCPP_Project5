#pragma once
#include "Dog.h"
#include "Laptop.h"
#include "WeatherSatellite.h"
#include "InternetCafe.h"
#include "MeteoSpaceNetwork.h"

struct DogWrapper
{
    DogWrapper(Dog* dog);
    ~DogWrapper();

    Dog* dogPtr = nullptr;
};

struct DogCollarWrapper
{
    DogCollarWrapper(Dog::DogCollar* dogCollar);
    ~DogCollarWrapper();

    Dog::DogCollar* dogCollarPtr = nullptr;
};

struct LaptopWrapper
{
    LaptopWrapper(Laptop* laptop);
    ~LaptopWrapper();

    Laptop* laptopPtr = nullptr;
};

struct LaptopBatteryWrapper
{
    LaptopBatteryWrapper(Laptop::Battery* laptopBattery);
    ~LaptopBatteryWrapper();

    Laptop::Battery* laptopBatteryPtr = nullptr;
};

struct WeatherSatelliteWrapper
{
    WeatherSatelliteWrapper(WeatherSatellite* weatherSatellite);
    ~WeatherSatelliteWrapper();

    WeatherSatellite* weatherSatellitePtr = nullptr;
};

struct InternetCafeWrapper
{
    InternetCafeWrapper(InternetCafe* internetCafe);
    ~InternetCafeWrapper();

    InternetCafe* internetCafePtr = nullptr;
};

struct MeteoSpaceNetworkWrapper
{
    MeteoSpaceNetworkWrapper(MeteoSpaceNetwork* meteoSpaceNetwork) : meteoSpaceNetworkPtr(meteoSpaceNetwork) {}

    ~MeteoSpaceNetworkWrapper()
    {
        delete meteoSpaceNetworkPtr;
    }

    MeteoSpaceNetwork* meteoSpaceNetworkPtr = nullptr;
};
