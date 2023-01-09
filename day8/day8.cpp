#include<iostream>
#include<map>

class Landline
 {
 public:
     std::string STDCode;
     std::string number;
     float amount;
     Landline(std::string number, std::string STDCode)
     {
         amount = 0;
         this->STDCode = STDCode;
         this->number = number;
     }
     void setAmount(float amount)
     {
         this->amount = amount;
     }
 };

 class Mobile
 {
 public:
     std::string number;
     float amount;
     Mobile(std::string number)
     {
         amount = 0;
         this->number = number;
     }
     void setAmount(float amount)
     {
         this->amount = amount;
     }
 };

 template <typename T>
 class BillPayment{
     public:
         std::map<std::string, T*> connections;
         void addConnection(std::string number)
         {
             Mobile m(number);
             connections[number] = &m;
             std::cout << "NEW CONNECTION CREATED\n" << number;
         }
         void addConnection(std::string STDCode, std::string number)
         {
             Landline l(STDCode, number);
             connections[STDCode + number] = &l;
             std::cout << "NEW CONNECTION CREATED\n" << number;
         }
         void payBill(std::string number)
         {
             connections[number]->setAmount(0);
             std::cout << "BILL PAID FOR NUMBER\n" << number;
         }
         void updateBill(std::string number, int amount)
         {
             connections[number]->setAmount(amount);
             std::cout << "BILL UPDATED FOR NUMBER " << number << "AMOUNT " << amount;
         }
 };

 int main()
 {
     BillPayment<Mobile> mobilePayment;
     BillPayment<Landline> landlinePayment;

     while(1){
         int mode;
         std::cout << "ENTER YOUR MODE \n 1 --- MOBILE \n 2 --- LANDLINE \n";
         std::cin >> mode;            

         int option;
         std::cout << "ENTER YOUR OPTION\n 1 --- CREATE CONNECTION\n 2 --- PAY BILL\n 3 --- UPDATE BILL\n\n";
         std::cin >> option;

         std::string num;
         std::cout << "ENTER THE NUMBER\n";
         std::cin >> num;

         if(mode == 1){
             switch (option)
             {
             case 1:
                 mobilePayment.addConnection(num);
                 break;
             case 2:
             {
                 mobilePayment.payBill(num);
                 break;
             }
             case 3:
             {
                 int amount;
                 std::cout << "ENTER THE AMOUNT\n";
                 std::cin >> amount;
                 mobilePayment.updateBill(num, amount);
                 break;
             }
             }
         }
         else{
             std::string code;
             std::cout << "ENTER THE STD CODE\n";
             std::cin >> code;

             switch (option)
             {
             case 1:
                 landlinePayment.addConnection(num, code);
                 break;
             case 2:
             {
                 landlinePayment.payBill(num);
                 break;
             }
             case 3:
             {
                 int amount;
                 std::cout << "ENTER THE AMOUNT\n";
                 std::cin >> amount;
                 landlinePayment.updateBill(num, amount);
                 break;
             }
             }
         }
     }
 }
