#include <iostream>
#include <string>

enum Type { electric=0, petrol, diesel, manpowered }; //Types of class Vehicle.
enum BikeType { motorbike, scooter, moped}; //Types of class Bike.
enum CarType { suv, sedan, hatchback }; //Types of class Car.

const std::string VEHICLES[] = { "electric", "petrol", "diesel", "manpowered" }; //Array that hold the strings of class Vehicle

class Vehicle{
    private:
        Type vehicleType;
        std::string brand;
        std::string model;
        std::string colour;
        float mileage;
        int price;

    public:
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

        //getter methods
        Type type() const
        {
            return this->vehicleType;
        }
        std::string vehicleBrand() const
        {
            return this->brand;
        }
        std::string vehicleModel() const
        {
            return this->model;
        }
        std::string vehicleColour() const
        {
            return this->colour;
        }
        int vehiclePrice() const
        {
            return this->price;
        }


};

//Inherits from Vehicle.
class Bike : public Vehicle{
    private:    
        BikeType bikeType;
        float weight;

    public:
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

        void operator << (const Vehicle& vehicle)
        {
            std::cout <<"BRAND : "<<vehicle.vehicleBrand()<<"\nMODEL : "<<vehicle.vehicleModel()<<"\nVEHICLETYPE : "<<vehicle.type()<<"\nCOLOUR : "<<vehicle.vehicleColour()<<"\nPRICE : "<<vehicle.vehiclePrice()<<"\n\n";
        }

        bool operator < (const Vehicle& vehicle)
        {
            return vehiclePrice() < vehicle.vehiclePrice();
        }

        
        bool operator > (const Vehicle& vehicle)
        {            
            return vehiclePrice() > vehicle.vehiclePrice();
        }
};

//Inherits from Vehicle.
class Car : public Vehicle{
    private:    
        CarType carType;
        int numPersons;

    public:        
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

        void operator << (const Vehicle& vehicle)
        {
            std::cout <<"BRAND : "<<vehicle.vehicleBrand()<<"\nMODEL : "<<vehicle.vehicleModel()<<"\nVEHICLETYPE : "<<vehicle.type()<<"\nCOLOUR : "<<vehicle.vehicleColour()<<"\nPRICE : "<<vehicle.vehiclePrice()<<"\n\n";
        }

        bool operator < (const Vehicle& vehicle)
        {
            return vehiclePrice() < vehicle.vehiclePrice();
        }

        
        bool operator > (const Vehicle& vehicle)
        {
            return vehiclePrice() < vehicle.vehiclePrice();
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