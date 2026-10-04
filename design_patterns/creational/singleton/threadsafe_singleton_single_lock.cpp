#include<iostream>
#include<mutex>

class Singleton{
    private:
    //making static so that it can be initialized without object
    static Singleton* instance;
    static std::mutex mtx;

    Singleton(){
        std::cout<<"object created.\n";
    }
    public:
        //client can se this static method ot get the instance of object
        static Singleton* getInstance(){
            //using mutex in critical section
            std::lock_guard<std::mutex> lock(mtx);
            if(instance==nullptr)
                instance = new Singleton();
            return instance;
        }
};

//need to initialize static member
Singleton* Singleton::instance=nullptr;
std::mutex Singleton::mtx;

int main(){
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    std::cout<<(s1==s2);
    return 0;
}