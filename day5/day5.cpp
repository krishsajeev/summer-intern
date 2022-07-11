#include<iostream>

namespace math{
    class Obj{ //Class inside namespace
        int num1;
        int num2;
        Obj(int num1, int num2){
            this->num1 = num1;
            this->num2 = num2;
        }
    };
    namespace equations{ //Nested namespace
        int add(int num1, int num2) //Math equations
        {
            return num1+num2;
        }
        int subtract(int num1, int num2)
        {
            return num1-num2;
        }
        inline namespace ns{ //Inline namespace
            void description()
            {
                std::cout << "THIS NAMESPACE CONTAINS MATH FUNCTIONS AND EQUATIONS\n";
            }
        }
    }
}



class MyObj{
    public:
        int num1;
        int num2;
        MyObj(int num1, int num2){
            this->num1 = num1;
            this->num2 = num2;
        }
        int add(int num1,int num2){
            using namespace math::equations; //Import it in separate class
            std::cout << "ADDED " << add(num1, num2);
        }
        int sub(int num1,int num2){
            using namespace math::equations;
            std::cout << "SUBTRACTED " << subtract(num1, num2);            
        }
};



int main()
{
    namespace eqn = math::equations; //Namespace aliases

    std::cout << "ADDED " << eqn::add(1, 2) << std::endl;
    std::cout << "SUBTRACTED " << eqn::subtract(2, 1) << std::endl;
    eqn::description();

    return 0;
}