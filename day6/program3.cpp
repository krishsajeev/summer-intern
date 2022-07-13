#include <bits/stdc++.h>
#include<iostream>

class StudentException : public std::exception
{
    const char *message;
    std::string param;

    public:
        StudentException(const char *message, std::string param) 
            : message(message), param(param) {

        }

        const char* what() const throw()
        {
            std::cout << "\nStudentException [ " << param << " ]\n";
            return message;
        }
};

class Student{
    private:
        static Student* ptr;

        bool flag=false;
        int rollno;
        std::string name;
        int age;
        std::string course;
        std::unordered_set <std::string> courses{"DSA", "CPP", "JAVA", "NETWORKS", "DBMS"};

        std::string toUpperCase(std::string str){
            for(int i=0;i<str.length();i++){
                if(str[i]>=97 && str[i]<=122){
                    str[i]=(char)((int)str[i]-32);
                }
            }
            return str;
        }

        Student(int rollno,std::string name,int age,std::string course){

            try{
                course=toUpperCase(course);

                if(!(age >= 15 && age <= 21)) {
                    throw StudentException("\nAgeNotValidException", "Age is not in the range");
                }
                for(int i = 0; i < name.length(); i++){
                    if(((int)name[i] < 65 || (int)name[i] > 90) && ((int)name[i] < 97 || (int)name[i] > 122))
                    throw StudentException("\nNameNotValidException", "Name is not in correct format");
                }
                if(courses.find(course) == courses.end()){
                    throw StudentException("\nInvalidCourseException", "Course does not exist");
                }
            }
            catch(const std::exception &e){
                std::cout << e.what();
            }

            this->rollno = rollno;
            this->age = age;
            this->name = name;
            this->course = course;

        }
    public:
        static Student* getObject(int rollno, std::string name, int age, std::string course)
        {
            if(!ptr)
                ptr= new Student(rollno, name, age, course);

            return ptr;
        }

        //Getter methods
        int studentRollno()
        {
            return this->rollno;
        }
        std::string studentName()
        {
            return ptr->name;
        }
        int studentAge()
        {
            return this->age;
        }
        std::string studentCourse()
        {
            return ptr->course;
        }

};

Student *Student::ptr = 0;

int main()
{
    Student* stud1 = stud1->getObject(123, "SAJEEV", 20, "CPP");
    
    std::cout << stud1->studentRollno() << stud1->studentName() << stud1->studentAge() << stud1->studentCourse() << std::endl ;

    
    Student* stud2 = stud2->getObject(123, "KRISHNA", 100, "CPP");
    std::cout << stud2->studentRollno() << stud2->studentName() << stud2->studentAge() << stud2->studentCourse() ;

}