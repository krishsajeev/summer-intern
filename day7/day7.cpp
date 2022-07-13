#include<iostream>
#include <cstdio>
#include<functional>
#include<vector>
#include<map>

class Sensor{
    public:
        virtual float getData() = 0;

        virtual void increase(float del) = 0;
        virtual void decrease(float del) = 0;

        virtual void onConnect() = 0;
        virtual void onDisconnect() = 0;

        virtual void setListener(const std::function<void(float)>& fun) = 0;
        virtual void onChange() = 0;
        
        virtual bool available() = 0;
};
class Actuator{
    public:
        virtual void setData(bool action) = 0;
        virtual void onConnect() = 0;
        virtual void onDisconnect() = 0;
        virtual bool getStatus() = 0;
        virtual bool available() = 0;
};

class Fan : public Actuator{
    private:
        bool state = false;
        bool isConnected = false;
    public:
        void setData(bool action)
        {
            state=action;
        }
        void onConnect()
        {
            isConnected = true;
        }
        void onDisconnect()
        {
            isConnected = false;
        }
        bool getStatus()
        {
            return state;
        }
        bool available()
        {
            return isConnected;
        }
};

class Light : public Actuator{
    private:
        bool state = false;
        bool isConnected = false;
    public:
        void setData(bool action)
        {
            state=action;
        }
        void onConnect()
        {
            isConnected = true;
        }
        void onDisconnect()
        {
            isConnected = false;
        }
        bool getStatus()
        {
            return state;
        }
        bool available()
        {
            return isConnected;
        }
};

class Door : public Actuator{
    private:
        bool state = false;
        bool isConnected = false;
    public:
        void setData(bool action)
        {
            state=action;
        }
        void onConnect()
        {
            isConnected = true;
        }
        void onDisconnect()
        {
            isConnected = false;
        }
        bool getStatus()
        {
            return state;
        }
        bool available()
        {
            return isConnected;
        }
};

class TemperatureSensor : public Sensor{
    private:
        float temperature=0;
        bool isConnected = false;
        std::vector<std::function<void(float)>> subscribers;
    public:
        void increase(float delta)
        {
            temperature += delta;
            onChange();
        }
        void decrease(float delta)
        {
            temperature -= delta;
            onChange();
        }
        float getData()
        {
            return temperature;
        }

        void setListener(const std::function<void(float)>& fun)
        {
            subscribers.push_back(fun);
            onChange();
        }
        void onChange()
        {
            for(int i=0; i<subscribers.size(); i++){
                subscribers[i](this->temperature);
            }
        }

        void onConnect()
        {
            isConnected = true;
        }
        void onDisconnect()
        {
            isConnected = false;
        }
        bool available()
        {
            return isConnected;
        }
};

class MotionSensor : public Sensor{
    private:
        float motion=0;
        bool isConnected = false;
        std::vector<std::function<void(float)>> subscribers;
    public:
        void increase(float delta)
        {
            motion += delta;
            onChange();
        }
        void decrease(float delta)
        {
            motion -= delta;
            onChange();
        }
        float getData()
        {
            return motion;
        }

        void setListener(const std::function<void(float)>& fun)
        {
            subscribers.push_back(fun);
            onChange();
        }
        void onChange()
        {
            for(int i=0; i<subscribers.size(); i++){
                subscribers[i](this->motion);
            }
        }

        void onConnect()
        {
            isConnected = true;
        }
        void onDisconnect()
        {
            isConnected = false;
        }
        bool available()
        {
            return isConnected;
        }
};

class WaterLevelSensor : public Sensor{
    private:
        float waterLevel=0;
        bool isConnected = false;
        std::vector<std::function<void(float)>> subscribers;
    public:
        void increase(float delta)
        {
            waterLevel += delta;
            onChange();
        }
        void decrease(float delta)
        {
            waterLevel -= delta;
            onChange();
        }
        float getData()
        {
            return waterLevel;
        }

        void setListener(const std::function<void(float)>& fun)
        {
            subscribers.push_back(fun);
            onChange();
        }
        void onChange()
        {
            for(int i=0; i<subscribers.size(); i++){
                subscribers[i](this->waterLevel);
            }
        }

        void onConnect()
        {
            isConnected = true;
        }
        void onDisconnect()
        {
            isConnected = false;
        }
        bool available()
        {
            return isConnected;
        }
};

class GasSensor : public Sensor{
    private:
        float gasLevel=0;
        bool isConnected = false;
        std::vector<std::function<void(float)>> subscribers;
    public:
        void increase(float delta)
        {
            gasLevel += delta;
            onChange();
        }
        void decrease(float delta)
        {
            gasLevel -= delta;
            onChange();
        }
        float getData()
        {
            return gasLevel;
        }

        void setListener(const std::function<void(float)>& fun)
        {
            if(!isConnected)
                return;
            subscribers.push_back(fun);
            onChange();
        }
        void onChange()
        {
            for(int i=0; i<subscribers.size(); i++){
                subscribers[i](this->gasLevel);
            }
        }
        void onConnect()
        {
            isConnected = true;
        }
        void onDisconnect()
        {
            isConnected = false;
        }
        bool available()
        {
            return isConnected;
        }
};

bool compare(float data1, int mode, float data2)
{
    switch (mode)
    {
    case 62:
        return data1 > data2;
        break;
    case 60:
        return data1 < data2;
        break;
    case 61:
        return data1 == data2;
        break;
    }
}

void banner(){
    std::string str1 = "1. SIMULATE INPUT\n2. DEVICE AUTOMATION\n3. DEVICE STATUS\n--------\n";
    std::string str2 = "KEY CODES\n1. Increase Value\n2. Decrease Value\n3. Connect Device\n4. Disconnect Device\n\n--------\n";
    std::cout << str1;
    std::cout << str2;
}

int main()
{

    TemperatureSensor temp;
    GasSensor gas;
    WaterLevelSensor water;
    MotionSensor motion;
    Fan fan;
    Door door;
    Light light;

    std::map<std::string, Sensor*> sensors;
    sensors = {
                {"TEMPERATURE", &temp},
                {"GAS", &gas},
                {"WATERLEVEL", &water},
                {"MOTION", &motion}
              };

    std::map<std::string, Actuator*> actuators;
    actuators = {
                  {"FAN", &fan},
                  {"DOOR", &door},
                  {"LIGHT", &light}
                };


    banner();
    while(1){
        std::cout << "\n\n\n-----------\n\nENTER THE OPTION\n";
        int option;
        std::cin >> option;
        if(option == 1) { //Simulate input
            std::string name;
            std::cout << "ENTER THE DEVICE NAME\n";
            std::cin >> name;

            int key;
            std::cout << "ENTER KEY CODE\n";
            std::cin >> key;
            switch(key){
                case 1:
                {
                    int val;
                    std::cout << "ENTER THE VALUE\n";
                    std::cin >> val;
                    sensors[name]->increase(val);

                    break;
                }
                case 2:
                {
                    int val;
                    std::cout << "ENTER THE VALUE\n";
                    std::cin >> val;
                    sensors[name]->decrease(val);

                    break;
                }
                case 3:
                {
                    if(sensors.find(name) != sensors.end())
                        sensors[name]->onConnect();

                    if(actuators.find(name) != actuators.end())
                        actuators[name]->onConnect();

                    break;
                }
                case 4:
                {
                    if(sensors.find(name) != sensors.end())
                        sensors[name]->onDisconnect();

                    if(actuators.find(name) != actuators.end())
                        actuators[name]->onDisconnect();

                    break;
                }
            }
        }
        else if(option == 2){ //Device Automation
            std::string sensorName;
            char ch;
            float val;
            std::string actuatorName;
            int action;
            std::cout << "ENTER COMMAND STRICTLY ACCORDING TO THE SYNTAX \n";

            std::cout << "IF: ";
            std::cin >> sensorName;
            std::cout << " ";
            std::cin >> ch;
            std::cout << " ";
            std::cin >> val;
            std::cout << "\nTHEN: ";
            std::cin >> actuatorName;
            std::cout << " ";
            std::cin >> action;

            std::cout << std::endl;
            Actuator* a = actuators[actuatorName];

            sensors[sensorName]->setListener([val, ch, a, action](int reading)->void{
                if(a->available() && compare(reading, (int)ch, val)){
                    a->setData(action);
                }
            });

        }
        else{
                std::cout << "DEVICES    ----    STATUS" << std::endl;
                for(auto m: sensors){
                    if(m.second->available())
                        std::cout << m.first << ": " << m.second->getData() << std::endl;
                }
                for(auto m: actuators){
                    if(m.second->available())
                        std::cout << m.first << ": " << m.second->getStatus() << std::endl;
                }
        }
    }

    return 0;
}