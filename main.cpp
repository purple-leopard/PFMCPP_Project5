/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via the 'this' keyword and arrow (->) operator and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 Instructions:
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.

 2) Do the following for EVERY std::cout statement in main() that uses the UDT member variables and functions:
    a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
    b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
    c) call that member function AFTER your std::cout statement in main.
    NOTE: if your member functions being called in main() use std::cout statements, you don't need to create duplicates of these functions.  you only need to create member functions for the std::cout statements that exist in main().
        
 3) you should see 2 (almost) identical messages in the program output for each member function you add:
    one for the std::cout line, and one for the member function's output
 
 4) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo();
        ~MyFoo();
        
        void printDetailedMemberInfo();
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };

    MyFoo::MyFoo() { std::cout << "creating MyFoo" << std::endl; }
    MyFoo::~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
	// 2a) the member function whose function body is almost identical to the std::cout statement in main.
    //Remember to NAME FUNCTIONS WHAT THEY DO.
    void MyFoo::printDetailedMemberInfo() //function name contains a verb!!!
    { 
        // 2b) explicitly using 'this' inside this member function.
        std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
    }  
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.printDetailedMemberInfo();
        return 0;
    }
}

/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
*/

#include <iostream>
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

        void attachLeash(const std::string& leashType = "standard", bool isRetractable = false);
        void remove(bool clipRelease = true);
        bool adjustFit(float newSize, float minSize = 10.0f, float maxSize = 20.0f);
        void jingleBell(int numJingles);
        void printCollarMaterial();
    };

    void barkAtPostman();
    void fetchBall();
    bool tryNewCollar(DogCollar newCollar);
    void simulateAgeing(int yearsToAgeBy);
    void printWeight();

    DogCollar currentCollar;
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

void Dog::DogCollar::attachLeash(const std::string& leashType, bool isRetractable)
{
    std::cout << "leash material: " << material << ", leash type: " << leashType << ", leash retractable: " << isRetractable << "\n";
}

void Dog::DogCollar::remove(bool clipRelease)
{
    std::cout << (clipRelease ? "clip released\n" : "clip not released\n");
}

bool Dog::DogCollar::adjustFit(float newSize, float minSize, float maxSize) 
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

void Dog::DogCollar::jingleBell(int numJingles)
{
    std::cout << "collar bell goes:\n";
    for(int count = 0; count < numJingles; ++count)
    {
        std::cout << "jingle\n";
    }
}

void Dog::DogCollar::printCollarMaterial()
{
    std::cout << "dog's collar material: " << this->material << "\n";
}

void Dog::barkAtPostman() 
{
    std::cout << furColour << " colour dog is barking at the postman\n";
}

void Dog::fetchBall()
{
    std::cout << "fetch\n";
}

bool Dog::tryNewCollar(DogCollar newCollar) 
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

void Dog::simulateAgeing(int yearsToAgeBy)
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

void Dog::printWeight()
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
    };

    void replaceBattery(Battery newBattery);
    bool launchProgram(const std::string& programName);
    bool invokeCompiler();
    void cycleCharge(Battery battery, int numCycles);
    void printBrand();

    Battery currentBattery;
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
    Dog jackRussel;
    Dog::DogCollar pinkCollar;
    
    jackRussel.barkAtPostman();
    jackRussel.fetchBall();
    jackRussel.tryNewCollar(pinkCollar);
    jackRussel.simulateAgeing(8);
    jackRussel.currentCollar.attachLeash("gangster", true);
    jackRussel.currentCollar.adjustFit(15, 10.0f, 20.0f);
    jackRussel.currentCollar.jingleBell(4);
    jackRussel.currentCollar.remove(true);

    Laptop laptop;
    Laptop::Battery replacementBattery;

    laptop.replaceBattery(replacementBattery);
    laptop.launchProgram("Logic");
    laptop.invokeCompiler();
    laptop.cycleCharge(laptop.currentBattery, 3);
    laptop.currentBattery.charge(90.0f);
    laptop.currentBattery.drain();
    laptop.currentBattery.checkCapacityRemaining("FastGauge");
    laptop.currentBattery.limitChargeCurrent(2.5f, 90.0f);

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

    std::cout << "jack russel's weight: " << jackRussel.weight << " kg" << "\n";
    jackRussel.printWeight();
    std::cout << "jack russel's collar material: " << jackRussel.currentCollar.material << "\n";
    jackRussel.currentCollar.printCollarMaterial();
    std::cout << "laptop brand: " << laptop.brand << "\n";
    laptop.printBrand();
    std::cout << "laptop's battery's charge capacity: " << laptop.currentBattery.capacity << " mAh\n";
    std::cout << "sputnik's orbital velocity is: " << sputnik.orbitalVelocity << "*10^3 ms^-1\n";

    std::cout << "good to go!" << std::endl;
}
