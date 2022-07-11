#include <iostream>
class Rectangle
{
    private:
        int* left= new int[1];
        int* top= new int[1];
        int* width= new int[1];
        int* height= new int[1];
        int* area= new int[1];

    public:
        int ceil(double num)
        {
            int whole = (int)num;
            double fraction  = num - whole;
            if(fraction >= 0.5)
                whole++;
            return whole; 
        }
        Rectangle()
        {
            *(this->left) = 0;
            *(this->top) = 0;
            *(this->width) = 0;
            *(this->height) = 0;
            *(this->area) = 0 * 0;
        }
        Rectangle(int width, int height)
        {
            *(this->left) = 0;
            *(this->top) = 0;            
            *(this->width)=width;
            *(this->height)=height;
            *(this->area) = (*(this->width)) * (*(this->height));
        }
        Rectangle(int left, int top, int width,int height)
        {
            *(this->left) = left;
            *(this->top) = top;
            *(this->width) = width;
            *(this->height) = height;
            *(this->area) = (*(this->width)) * (*(this->height));
        }
        Rectangle(double left, double top, double width,double height)
        {
            *(this->left) = ceil(left);
            *(this->top) = ceil(top);
            *(this->width) = ceil(width);
            *(this->height) = ceil(height);
            *(this->area) = (*(this->width)) * (*(this->height));
        }
        Rectangle (Rectangle *obj)
        {
            *(this->left) = *(obj->left);
            *(this->top) = *(obj->top);
            *(this->width) = *(obj->width);
            *(this->height) = *(obj->height);
            *(this->area) = (*(obj->width)) * (*(obj->height));
        }
        void print()
        {
            std::cout << "LEFT : " << *(this->left) <<"\nTOP : "<< *(this->top) <<"\nWIDTH : "<< *(this->width) <<"\nHEIGHT : "<< *(this->height) 
                        <<"\nAREA : " <<*(this->area)<< "\n\n\n";
        }
        ~Rectangle()
        {
            delete[] left;
            delete[] top;
            delete[] width;
            delete[] height;
            delete[] area;
        }
};
int main()
{

    Rectangle r1(1.4,1.1,5.9,2.9);
    r1.print();

    Rectangle r2(1,2,4,3);
    r2.print();

    Rectangle r3(10,11);
    r3.print();

    Rectangle r4(&r1);
    r4.print();

    return 0;
}