#include<iostream>
#include <bits/stdc++.h>

int main()
{
    bool inner=false;
    bool outer=false;
    try{
        int num=6000;
        std::cout << "ENTER A NATURAL NUMBER WHICH IS GREATER THAN 1000\n";
        //std::cin >> num;
        if(num<0){
            outer=true;
            throw "NEGATIVE NUMBER EXCEPTION";
        }
        try{
            if(num<1000){
                inner=true;
                throw "SMALL NUMBER EXCEPTION";
            }
        }
        catch(const char* e){
            std::cout << e << std::endl;
            throw;
        }
    }
    catch(const char* e){
        std::cout << e << std::endl;
    }
    if(!outer && !inner){
        std::cout << "NO NOTABLE EXCEPTION !";
    }
}