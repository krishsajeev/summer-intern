#include <bits/stdc++.h>

class MyException : public std::exception
{
    const char *message;
    std::string param;

    public:
        MyException(const char *message, std::string param) 
            : message(message), param(param) {

        }

        const char* what() const throw()
        {
            std::cout << "\nMyException [ " << param << " ]\n";
            return message;
        }
};

int main()
{
    try
    {
        int a, b;
        std::cout << "Enter two elements - ";
        std::cin >> a >> b;
        if (b == 0) {
            throw MyException("\nInvalid division", "Division by zero");
        }
        std::cout << "\nDivision result - " << (a / b) << "\n\n";

        char* p = new (std::nothrow) char [9999999999999999];

        if (!p) {
            throw MyException("\nArray index is invalid", "Index out of range");
        }
        else {
            std::cout << "Succeeded!\n";
            delete[] p;
        }

        std::string str;
        std::cout << "Enter a number - ";
        std::cin >> str;
        int num = stoi(str);
        std::cout << "Number - " << num << "\n";

        std::string s2;
        std::cout << "Enter a string - ";
        std::cin >> s2;
        int sLen = s2.length(), sIndex;
        std::cout << "Enter an index to access the string - ";
        std::cin >> sIndex;
        if (sIndex < 0 or sIndex >= sLen){
            throw MyException("\nString index is invalid", "Index out of range");
        }
        std::cout << "String value - " << s2[sIndex] << "\n";

        int arrLen;
        std::cout << "Enter the size for array - ";
        std::cin >> arrLen;
        int arr[arrLen];
        std::cout << "Enter an array of integers - ";
        for (int i = 0; i < arrLen; i++){
            std::cin >> arr[i];
        }
        int arrIndex;
        std::cout << "Enter an index to access the array - ";
        std::cin >> arrIndex;
        if (arrIndex < 0 or arrIndex >= arrLen){
            throw MyException("\nArray index is invalid", "Index out of range");
        }
        std::cout << "Array value - " << arr[arrIndex] << "\n";

        int n;
        std::cout << "Enter a number greater than 0 - ";
        std::cin >> n;
        if (n < 0){
            throw "You have entered a negative number !";
        }
        std::cout << "The number entered is " << n;
    }
    catch (const std::exception &e)
    {
        std::cout << "\n" << e.what() << "\n";
    }
    catch (...)
    {
        std::cout << "\nException occurred\n";
    }

    std::cout << "\nException Handling Accomplished\n\n";

    return 0;
}