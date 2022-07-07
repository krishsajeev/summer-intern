#include <iostream>
#include <string>

enum Type { electric=0, petrol, diesel, manpowered }; //Types of class Vehicle.
enum BikeType { motorbike, scooter, moped}; //Types of class Bike.
enum CarType { suv, sedan, hatchback }; //Types of class Car.

const std::string VEHICLES[] = { "electric", "petrol", "diesel", "manpowered" }; //Array that hold the strings of class Vehicle

class Vehicle{
    public:
        Type vehicleType;
        std::string brand;
        std::string model;
        std::string colour;
        float mileage;
        int price;


        Vehicle(Type vehicleType, std::string brand, std::string model, std::string colour, float mileage, int price)
        {
            this->vehicleType = vehicleType;
            this->brand = brand;
            this->model = model;
            this->colour = colour;
            this->mileage = mileage;
            this->price = price;
        }

        virtual int getNumOfWheels() = 0 ;
        virtual void operator << (const Vehicle& v) = 0;
        virtual bool operator < (const Vehicle& v) = 0;
        virtual bool operator > (const Vehicle& v) = 0;

};

//Inherits from Vehicle.
class Bike : public Vehicle{
    public:
        BikeType bikeType;
        float weight;

        Bike( Type vehicleType, BikeType biketype, std::string brand, std::string model, std::string colour, float mileage, int price, float weight)
            : Vehicle( vehicleType, brand, model, colour, mileage, price )
        {
            this->weight = weight;
            this->bikeType = bikeType;
        }

        int getNumOfWheels()
        {
            return 2;
        }

        void operator << (const Vehicle& b)
        {
            std::cout <<"BRAND : "<<brand<<"\nMODEL : "<<model<<"\nVEHICLETYPE : "<<vehicleType<<"\nCOLOUR : "<<colour<<"\nPRICE : "<<price<<"\n\n";
        }

        bool operator < (const Vehicle& b)
        {
            return price < b.price;
        }

        
        bool operator > (const Vehicle& b)
        {            
            return price > b.price;
        }
};

//Inherits from Vehicle.
class Car : public Vehicle{
    public:
        CarType carType;
        int numPersons;
        
        Car( Type vehicleType, CarType carType, std::string brand, std::string model, std::string colour, float mileage, int price, int numPersons )
            : Vehicle( vehicleType, brand, model, colour, mileage, price )
        {
            this->numPersons = numPersons;
            this->carType = carType;
        }

        int getNumOfWheels()
        {
            return 4;
        }

        void operator << (const Vehicle& c)
        {
            std::cout <<"BRAND : "<<brand<<"\nMODEL : "<<model<<"\nVEHICLETYPE : "<<VEHICLES[vehicleType]<<"\nCOLOUR : "<<colour<<"\nPRICE : "<<price<<"\n\n";
        }

        bool operator < (const Vehicle& c)
        {
            return price < c.price;
        }

        
        bool operator > (const Vehicle& c)
        {
            return price > c.price;
        }

};


int main()
{
    //Create some objects.
    Bike tvsScooty ( petrol, scooter, "tvs", "scooty", "red", 20.2, 9, 45 );
    Car fordMustang ( diesel, suv, "ford", "mustang", "blue", 13.1, 999, 4 );
    Bike heroHonda ( petrol, motorbike, "hero", "splendor", "black", 60, 86, 78.4 );

    //call getNumOfWheels function.
    tvsScooty.getNumOfWheels();
    fordMustang.getNumOfWheels();
    heroHonda.getNumOfWheels();

    //Operator overloading for << operator.
    tvsScooty << tvsScooty;
    fordMustang << fordMustang;
    heroHonda << heroHonda;

    //Operator overloading for < and > operator
    std::cout << ( ( heroHonda < fordMustang )? "FORD MUSTANG IS COSTLIER THAN HERO HONDA" : "FORD MUSTANG IS CHEAPER THAN HERO HONDA" ) << "\n";
    std::cout << ( ( tvsScooty < heroHonda )? "HERO HONDA IS COSTLIER THAN TVS SCOOTY" : "HERO HONDA IS CHEAPER THAN TVS SCOOTY" ) << "\n";
    std::cout << ( ( tvsScooty > fordMustang )? "FORD MUSTANG IS CHEAPER THAN TVS SCOOTY" : "FORD MUSTANG IS COSTLIER THAN TVS SCOOTY" ) << "\n";

    return 0;
}