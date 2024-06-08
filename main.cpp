/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */







#include <iostream>
#include "LeakedObjectDetector.h"
#include "Dog.h"
#include "Laptop.h"
#include "WeatherSatellite.h"
#include "InternetCafe.h"

struct DogWrapper
{
    DogWrapper(Dog* dog) : dogPtr(dog) {}

    ~DogWrapper()
    {
        delete dogPtr;
    }

    Dog* dogPtr = nullptr;
};

struct DogCollarWrapper
{
    DogCollarWrapper(Dog::DogCollar* dogCollar) : dogCollarPtr(dogCollar) {}

    ~DogCollarWrapper()
    {
        delete dogCollarPtr;
    }

    Dog::DogCollar* dogCollarPtr = nullptr;
};

struct LaptopWrapper
{
    LaptopWrapper(Laptop* laptop) : laptopPtr(laptop) {}

    ~LaptopWrapper()
    {
        delete laptopPtr;
    }

    Laptop* laptopPtr = nullptr;
};

struct LaptopBatteryWrapper
{
    LaptopBatteryWrapper(Laptop::Battery* laptopBattery) : laptopBatteryPtr(laptopBattery) {}

    ~LaptopBatteryWrapper()
    {
        delete laptopBatteryPtr;
    }

    Laptop::Battery* laptopBatteryPtr = nullptr;
};

struct WeatherSatelliteWrapper
{
    WeatherSatelliteWrapper(WeatherSatellite* weatherSatellite) : weatherSatellitePtr(weatherSatellite) {}

    ~WeatherSatelliteWrapper()
    {
        delete weatherSatellitePtr;
    }

    WeatherSatellite* weatherSatellitePtr = nullptr;
};

struct InternetCafeWrapper
{
    InternetCafeWrapper(InternetCafe* internetCafe) : internetCafePtr(internetCafe) {}

    ~InternetCafeWrapper()
    {
        delete internetCafePtr;
    }

    InternetCafe* internetCafePtr = nullptr;
};

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

struct MeteoSpaceNetworkWrapper
{
    MeteoSpaceNetworkWrapper(MeteoSpaceNetwork* meteoSpaceNetwork) : meteoSpaceNetworkPtr(meteoSpaceNetwork) {}

    ~MeteoSpaceNetworkWrapper()
    {
        delete meteoSpaceNetworkPtr;
    }

    MeteoSpaceNetwork* meteoSpaceNetworkPtr = nullptr;
};

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

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    DogWrapper dogWrapper(new Dog);
    DogCollarWrapper dogCollarWrapper(new Dog::DogCollar);
    
    dogWrapper.dogPtr->barkAtPostman();
    dogWrapper.dogPtr->fetchBall();
    dogWrapper.dogPtr->tryNewCollar(*dogCollarWrapper.dogCollarPtr);
    dogWrapper.dogPtr->simulateAgeing(8);
    dogWrapper.dogPtr->currentCollar.attachLeash("gangster", true);
    dogWrapper.dogPtr->currentCollar.adjustFit(15, 10.0f, 20.0f);
    dogWrapper.dogPtr->currentCollar.jingleBell(4);
    dogWrapper.dogPtr->currentCollar.remove(true);

    LaptopWrapper laptopWrapper(new Laptop);
    LaptopBatteryWrapper laptopBatteryWrapper(new Laptop::Battery);

    laptopWrapper.laptopPtr->replaceBattery(*laptopBatteryWrapper.laptopBatteryPtr);
    laptopWrapper.laptopPtr->launchProgram("Logic");
    laptopWrapper.laptopPtr->invokeCompiler();
    laptopWrapper.laptopPtr->cycleCharge(laptopWrapper.laptopPtr->currentBattery, 3);
    laptopWrapper.laptopPtr->currentBattery.charge(90.0f);
    laptopWrapper.laptopPtr->currentBattery.drain();
    laptopWrapper.laptopPtr->currentBattery.checkCapacityRemaining("FastGauge");
    laptopWrapper.laptopPtr->currentBattery.limitChargeCurrent(2.5f, 90.0f);

    WeatherSatelliteWrapper weatherSatteliteWrapper(new WeatherSatellite);

    weatherSatteliteWrapper.weatherSatellitePtr->switchImagingModality();
    weatherSatteliteWrapper.weatherSatellitePtr->transmitDataToGroundStation();
    weatherSatteliteWrapper.weatherSatellitePtr->monitorBatteryChargeLevel();
    weatherSatteliteWrapper.weatherSatellitePtr->normalizeAttitude(48.0);

    InternetCafeWrapper internetCafeWrapper(new InternetCafe);

    internetCafeWrapper.internetCafePtr->fixDeadUpstairsLaptop(internetCafeWrapper.internetCafePtr->spareBattery);
    internetCafeWrapper.internetCafePtr->updateDownstairsLaptopOS("Sonoma");

    MeteoSpaceNetworkWrapper meteoSpaceNetworkWrapper(new MeteoSpaceNetwork);

    meteoSpaceNetworkWrapper.meteoSpaceNetworkPtr->recalibrateNetworkAntennas(2.368f);
    meteoSpaceNetworkWrapper.meteoSpaceNetworkPtr->adjustOrbitingNodeVelocity(8.3);

    std::cout << "jack russel's weight: " << dogWrapper.dogPtr->weight << " kg" << "\n";
    dogWrapper.dogPtr->printWeight();
    std::cout << "jack russel's collar material: " << dogWrapper.dogPtr->currentCollar.material << "\n";
    dogWrapper.dogPtr->currentCollar.printCollarMaterial();
    std::cout << "laptop brand: " << laptopWrapper.laptopPtr->brand << "\n";
    laptopWrapper.laptopPtr->printBrand();
    std::cout << "laptop's battery's charge capacity: " << laptopWrapper.laptopPtr->currentBattery.capacity << " mAh\n";
    laptopWrapper.laptopPtr->currentBattery.printChargeCapacity();
    std::cout << "sputnik's orbital velocity is: " << weatherSatteliteWrapper.weatherSatellitePtr->orbitalVelocity << "*10^3 ms^-1\n";
    weatherSatteliteWrapper.weatherSatellitePtr->printOrbitalVelocity();

    std::cout << "good to go!" << std::endl;
}
