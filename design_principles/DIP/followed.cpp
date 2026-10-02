#include<iostream>

class DBInterface{
    public:
        virtual void saveToDB()=0;
};

class mongoDB : public DBInterface{
    public:
        void saveToDB() override {
            std::cout<<"saving to Mongo DB...\n";
        }
};

class SQLDB : public DBInterface{
    public:
        void saveToDB() override {
            std::cout<<"saving to SQL DB...\n";
        }
};

class Application{
    private:
        DBInterface* DB; 
    public:
        Application(DBInterface* DB):DB(DB){}
        void saveToDB(){
            DB->saveToDB();
        }
};

int main(){
    //now application is only dependent on interface
    Application* a =  new Application(new mongoDB());
    a->saveToDB();

    a = new Application(new SQLDB());
    a->saveToDB();

    return 0;
}