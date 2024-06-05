/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */




#include <iostream>
#include "LeakedObjectDetector.h"
/*
 copied UDT 1:
 */
struct Dog
{
    Dog();
    ~Dog();
    float weight;
    float height;
    int ageInYears;
    std::string furColour;
    std::string breed;

    struct DogCollar
    {
        DogCollar();
        ~DogCollar();
        std::string material;
        std::string color;
        std::string dogName;
        float length;
        float width;

        void attachLeash(const std::string& leashType = "standard", const bool isRetractable = false);
        void remove(const bool clipRelease = true);
        bool adjustFit(const float newSize, const float minSize = 10.0f, const float maxSize = 20.0f);
        void jingleBell(const int numJingles);
        void printCollarMaterial() const;

        JUCE_LEAK_DETECTOR(DogCollar)
    };

    void barkAtPostman() const;
    void fetchBall() const;
    bool tryNewCollar(const DogCollar& newCollar);
    void simulateAgeing(const int yearsToAgeBy);
    void printWeight() const;

    DogCollar currentCollar;

    JUCE_LEAK_DETECTOR(Dog)
};

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

Dog::Dog() : weight(1.0f), height(0.5f), ageInYears(1), furColour("brown"), breed("Jack Russel")
{
    std::cout << "Dog being constructed\n";
}

Dog::~Dog()
{
    std::cout << "Dog being destructed\n";
}

Dog::DogCollar::DogCollar() : material("leather"), color("red"), dogName("BUSTER"), length(15.0f), width(0.5f)
{
    std::cout << "DogCollar being constructed\n";
}

Dog::DogCollar::~DogCollar()
{
    std::cout << "DogCollar being destructed\n";
}

void Dog::DogCollar::attachLeash(const std::string& leashType, const bool isRetractable)
{
    std::cout << "leash material: " << material << ", leash type: " << leashType << ", leash retractable: " << isRetractable << "\n";
}

void Dog::DogCollar::remove(const bool clipRelease)
{
    std::cout << (clipRelease ? "clip released\n" : "clip not released\n");
}

bool Dog::DogCollar::adjustFit(const float newSize, const float minSize, const float maxSize) 
{
    if (newSize >= minSize && newSize <= maxSize) 
    {
        length = newSize;
        std::cout << "adjustment successful\n";
        return true;
    }
    std::cout << "adjustment unsuccessful\n";
    return false;
}

void Dog::DogCollar::jingleBell(const int numJingles)
{
    std::cout << "collar bell goes:\n";
    for(int count = 0; count < numJingles; ++count)
    {
        std::cout << "jingle\n";
    }
}

void Dog::DogCollar::printCollarMaterial() const
{
    std::cout << "dog's collar material: " << this->material << "\n";
}

void Dog::barkAtPostman() const
{
    std::cout << furColour << " colour dog is barking at the postman\n";
}

void Dog::fetchBall() const
{
    std::cout << "fetch\n";
}

bool Dog::tryNewCollar(const DogCollar& newCollar) 
{
    if (newCollar.length >= 10.0f && newCollar.length <= 20.0f) 
    {
        currentCollar = newCollar;
        std::cout << "collar fits, replace original collar with new collar\n";
        return true;
    }
    std::cout << "collar doesn't fit, keep original collar\n";
    return false;
}

void Dog::simulateAgeing(const int yearsToAgeBy)
{
    int year = 0;
    while(year < yearsToAgeBy)
    {
        ++year;
        ++ageInYears;
        weight += 1.5f;

        std::cout << "dog is now " << ageInYears << " years old and weighs " << weight << " kg\n";

        if(ageInYears == 9)
        {
            std::cout << "dog is 9 years older now, ending simulation early\n";
            break;
        }
        
    }
}

void Dog::printWeight() const
{
    std::cout << "dog's weight: " << this->weight << " kg" << "\n";
}
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

        bool charge(float chargeToLevel = 100.0f);
        float checkCapacityRemaining(const std::string& fuelGuageAlgorithm = "ModelGauge");
        void limitChargeCurrent(float inputCurrent, float temperatureLimit = 85.8f);
        void drain();
        void printChargeCapacity();

        JUCE_LEAK_DETECTOR(Battery)
    };

    void replaceBattery(Battery newBattery);
    bool launchProgram(const std::string& programName);
    bool invokeCompiler();
    void cycleCharge(Battery battery, int numCycles);
    void printBrand();

    Battery currentBattery;

    JUCE_LEAK_DETECTOR(Laptop)
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

bool Laptop::Battery::charge(float chargeToLevel) 
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

void Laptop::Battery::limitChargeCurrent(float inputCurrent, float temperatureLimit) 
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

void Laptop::Battery::printChargeCapacity()
{
    std::cout << "laptop's battery's charge capacity: " << this->capacity << " mAh\n";
}

void Laptop::replaceBattery(Battery newBattery) 
{
    currentBattery = newBattery;
    std::cout << model <<" battery replaced with type: " << newBattery.type << "\n";
}

bool Laptop::launchProgram(const std::string& programName) 
{
    std::cout << "launching program: " << programName << "\n";
    return true;
}

bool Laptop::invokeCompiler() 
{
    std::cout << "compiler invoked" << "\n";
    return true;
}

void Laptop::cycleCharge(Battery battery, int numCycles)
{
    for(int i = 0; i < numCycles; ++i)
    {
        ++battery.chargeCycles;
        std::cout << "cycling battery charge, cycles are now at: " << battery.chargeCycles << "\n";
    }
}

void Laptop::printBrand()
{
    std::cout << "laptop brand: " << this->brand << "\n";
}
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
    void switchImagingModality();
    int transmitDataToGroundStation();
    float monitorBatteryChargeLevel();
    void normalizeAttitude(double targetAttitude);
    void printOrbitalVelocity();

    JUCE_LEAK_DETECTOR(WeatherSatellite)
};

WeatherSatellite::WeatherSatellite() : attitude(45.7)
{
    std::cout << "WeatherSatellite being constructed\n";
}

WeatherSatellite::~WeatherSatellite()
{
    std::cout << "WeatherSatellite being destructed\n";
}

void WeatherSatellite::switchImagingModality()
{
    std::cout << "satellite attitude is " <<  attitude << " degrees, switching imaging modality from visible to infrared\n";
}

int WeatherSatellite::transmitDataToGroundStation()
{
    int numberOfImagesTransmitted = 500;
    std::cout << "transmitted " << numberOfImagesTransmitted << " images\n";
    return numberOfImagesTransmitted;
}

float WeatherSatellite::monitorBatteryChargeLevel()
{
    float chargeLevel = 75.0f;
    std::cout << "current battery charge level is " << chargeLevel << "%\n";
    return chargeLevel;
}

void WeatherSatellite::normalizeAttitude(double targetAttitude)
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

void WeatherSatellite::printOrbitalVelocity()
{
    std::cout << "sputnik's orbital velocity is: " << this->orbitalVelocity << "*10^3 ms^-1\n";
}
/*
 new UDT 4:
 with 2 member functions
 */
struct InternetCafe
{
    InternetCafe();
    ~InternetCafe();
    Laptop upstairsLaptop;
    Laptop downstairsLaptop;
    Laptop::Battery spareBattery;
    void fixDeadUpstairsLaptop(Laptop::Battery replacementBattery);
    void updateDownstairsLaptopOS(std::string newOS);

    JUCE_LEAK_DETECTOR(InternetCafe)
};

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

void InternetCafe::fixDeadUpstairsLaptop(Laptop::Battery replacementBattery)
{
    upstairsLaptop.replaceBattery(replacementBattery);
}

void InternetCafe::updateDownstairsLaptopOS(std::string newOS)
{
    downstairsLaptop.operatingSystemVersion = newOS;
    std::cout << "update downstairs laptop's OS to " << newOS << "\n";
}
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
    void recalibrateNetworkAntennas(float newFreq);
    void adjustOrbitingNodeVelocity(double targetVelocity);

    JUCE_LEAK_DETECTOR(MeteoSpaceNetwork)
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

void MeteoSpaceNetwork::recalibrateNetworkAntennas(float newFreq)
{
    std::cout << "recalibrating satellite antennas to " << newFreq << " GHz\n";
    geostationarySat.antennaCenterFrequency = newFreq;
    lowOrbitalSat.antennaCenterFrequency = newFreq;
}

void MeteoSpaceNetwork::adjustOrbitingNodeVelocity(double targetVelocity)
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

    WeatherSatellite sputnik;

    sputnik.switchImagingModality();
    sputnik.transmitDataToGroundStation();
    sputnik.monitorBatteryChargeLevel();
    sputnik.normalizeAttitude(48.0);

    InternetCafe cafe3000;

    cafe3000.fixDeadUpstairsLaptop(cafe3000.spareBattery);
    cafe3000.updateDownstairsLaptopOS("Sonoma");

    MeteoSpaceNetwork bigWeather;

    bigWeather.recalibrateNetworkAntennas(2.368f);
    bigWeather.adjustOrbitingNodeVelocity(8.3);

    std::cout << "jack russel's weight: " << dogWrapper.dogPtr->weight << " kg" << "\n";
    dogWrapper.dogPtr->printWeight();
    std::cout << "jack russel's collar material: " << dogWrapper.dogPtr->currentCollar.material << "\n";
    dogWrapper.dogPtr->currentCollar.printCollarMaterial();
    std::cout << "laptop brand: " << laptopWrapper.laptopPtr->brand << "\n";
    laptopWrapper.laptopPtr->printBrand();
    std::cout << "laptop's battery's charge capacity: " << laptopWrapper.laptopPtr->currentBattery.capacity << " mAh\n";
    laptopWrapper.laptopPtr->currentBattery.printChargeCapacity();
    std::cout << "sputnik's orbital velocity is: " << sputnik.orbitalVelocity << "*10^3 ms^-1\n";
    sputnik.printOrbitalVelocity();

    std::cout << "good to go!" << std::endl;
}
