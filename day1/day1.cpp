#include <iostream>
#include <string>

using namespace std;


enum Type { electric,petrol,diesel,manpowered };    //vehicle types
enum BikeType { motorbike,scooter,moped};   //types of bikes
enum CarType { suv,sedan,hatchback };   //types of cars

class Vehicle{      //vehicle class
    public:
        Type vehicleType;
        string brand;
        string model;
        string colour;
        float mileage;
        int price;


        Vehicle(Type vehicleType,string brand,string model,string colour,float mileage,int price){  //constructor
            this->vehicleType=vehicleType;
            this->brand=brand;
            this->model=model;
            this->colour=colour;
            this->mileage=mileage;
            this->price=price;
        }

        virtual int getNumOfWheels() = 0 ;
        virtual void operator << (const Vehicle& v) = 0;
        virtual bool operator < (const Vehicle& v) = 0;
        virtual bool operator > (const Vehicle& v) = 0;

};

class Bike : public Vehicle{
    public:
        BikeType bikeType;
        float weight;

        //call parentclass constructor
        Bike(Type vehicleType,BikeType biketype,string brand,string model,string colour,float mileage,int price,float weight) : Vehicle(vehicleType,brand,model,colour,mileage,price) {
            //initialise the weight and biketype
            this->weight=weight;
            this->bikeType=bikeType;
        }

        //implementation of virtual method
        int getNumOfWheels(){
            return 2;
        }

        void operator << (const Vehicle& b){
            cout<<"BRAND : "<<brand<<"\nMODEL : "<<model<<"\nVEHICLETYPE : "<<vehicleType<<"\nCOLOUR : "<<colour<<"\nPRICE : "<<price<<"\n\n";
        }

        bool operator < (const Vehicle& b){
            return (price<b.price);
        }

        
        bool operator > (const Vehicle& b){            
            return (price>b.price);
        }
};


class Car : public Vehicle{
    public:
        CarType carType;
        int numPersons;
        
        //call parentcalss constructor
        Car(Type vehicleType,CarType carType,string brand,string model,string colour,float mileage,int price,int numPersons) : Vehicle(vehicleType,brand,model,colour,mileage,price) {
            //initialise the numPersons and carType
            this->numPersons=numPersons;
            this->carType=carType;
        }

        //implementation of virtual method
        int getNumOfWheels(){
            return 4;
        }

        void operator << (const Vehicle& c){
            cout<<"BRAND : "<<brand<<"\nMODEL : "<<model<<"\nVEHICLETYPE : "<<vehicleType<<"\nCOLOUR : "<<colour<<"\nPRICE : "<<price<<"\n\n";
        }

        bool operator < (const Vehicle& c){
            return (price<c.price);
        }

        
        bool operator > (const Vehicle& c){
            return (price>c.price);
        }

};


int main(){
    //create some objects
    Bike tvsScooty(petrol,scooter,"tvs","scooty","red",20.2,9,45);
    Car fordMustang(diesel,suv,"ford","mustang","blue",13.1,999,4);
    Bike heroHonda(petrol,motorbike,"hero","splendor","black",60,86,78.4);

    //print number of wheels
    tvsScooty.getNumOfWheels();
    fordMustang.getNumOfWheels();
    heroHonda.getNumOfWheels();

    //overloaded <<
    tvsScooty<<tvsScooty;
    fordMustang<<fordMustang;
    heroHonda<<heroHonda;

    //overloaded < and >
    cout<< ( (heroHonda<fordMustang)? "FORD MUSTANG IS COSTLIER THAN HERO HONDA" : "FORD MUSTANG IS CHEAPER THAN HERO HONDA" ) << "\n";
    cout<< ( (tvsScooty<heroHonda)? "HERO HONDA IS COSTLIER THAN TVS SCOOTY" : "HERO HONDA IS CHEAPER THAN TVS SCOOTY" ) << "\n";
    cout<< ( (tvsScooty<fordMustang)? "FORD MUSTANG IS COSTLIER THAN TVS SCOOTY" : "FORD MUSTANG IS CHEAPER THAN TVS SCOOTY" ) << "\n";

    return 0;
}