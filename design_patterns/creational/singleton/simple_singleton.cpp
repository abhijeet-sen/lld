#include<iostream>

class Singleton{
    private:
    //making static so that it can be initialized without object
    static Singleton* instance;
    Singleton(){
        std::cout<<"object created.\n";
    }
    public:
        //client can se this static method ot get the instance of object
        static Singleton* getInstance(){
            if(instance==nullptr)
                instance = new Singleton();
            return instance;
        }
};

//need to initialize static member
Singleton* Singleton::instance=nullptr;

int main(){
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    std::cout<<(s1==s2);
    return 0;
}