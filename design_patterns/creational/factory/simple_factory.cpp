#include<iostream>
#include<string>

class burger{
    public:
        virtual void prepare()=0;
};

class simpleBurger : public burger{
    public:
        void prepare() override {
            std::cout<<"prepare simple burger.\n";
        }
};

class wheatFancyBurger : public burger{
    public:
        void prepare() override {
            std::cout<<"prepare wheat fancy burger.\n";
        }
};

class burgerFactory{
    public:
        burger* createBurger(std::string type){
            if(type=="basic")
                return new simpleBurger();
            else if(type=="fancy")
                return new wheatFancyBurger();
            else{
                std::cout<<"invalid type.\n";
                std::exit(1);
            }
        }
};

int main(){
    burgerFactory* bf = new burgerFactory();

    burger* b = bf->createBurger("basic");
    b->prepare();
    return 0;
}
