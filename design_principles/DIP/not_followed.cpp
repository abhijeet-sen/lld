#include<iostream>

class mongoDB{
    public:
        void saveTOMongoDB(){
            std::cout<<"saving to Mongo DB...\n";
        }
};

class SQLDB{
    public:
        void saveTOMongoDB(){
            std::cout<<"saving to SQL DB...\n";
        }
};

class Application{
    private:
        mongoDB* m;
        SQLDB* s;
    public:
        Application(mongoDB* m,SQLDB* s):m(m),s(s){}
        void saveTOMongoDB(){
            m->saveTOMongoDB();
        }
        void saveTOSQLDB(){
            s->saveTOMongoDB();
        }
};

int main(){
    Application* a =  new Application(new mongoDB(),new SQLDB());

    //high level class directly depend on low level class
    a->saveTOMongoDB();
    a->saveTOSQLDB();
    return 0;
}