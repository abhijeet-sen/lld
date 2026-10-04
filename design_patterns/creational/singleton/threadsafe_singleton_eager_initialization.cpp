#include<iostream>

class Singleton{
    private:
    //making static so that it can be initialized without object
    static Singleton* instance;

    Singleton(){
        std::cout<<"object created.\n";
    }
    public:
        //no need to check as there will always be an instance
        static Singleton* getInstance(){
            return instance;
        }
};

//eager initialization which make sure that the instance is alraedy created befmore main is called.
Singleton* Singleton::instance=new Singleton();

int main(){
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    std::cout<<(s1==s2);
    return 0;
}