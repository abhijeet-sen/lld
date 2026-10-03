#include<iostream>
#include<string>

class burger{
    public:
        virtual void prepare()=0;
};

//related products
class simpleBurger : public burger{
    public:
        void prepare() override {
            std::cout<<"prepare simple burger.\n";
        }
};

class FancyBurger : public burger{
    public:
        void prepare() override {
            std::cout<<"prepare fancy burger.\n";
        }
};

//wheat version
class wheatSimpleBurger : public burger{
    public:
        void prepare() override {
            std::cout<<"prepare wheat simple burger.\n";
        }
};

class wheatFancyBurger : public burger{
    public:
        void prepare() override {
            std::cout<<"prepare wheat fancy burger.\n";
        }
};

//abstract interface
class burgerFactory{
    public:
        virtual burger* createBurger(std::string type)=0;
};

class simpleFactory : public burgerFactory{
    public:
        burger* createBurger(std::string type) override {
            if(type=="basic")
                return new simpleBurger();
            else if(type=="fancy")
                return new FancyBurger();
            else{
                std::cout<<"invalid type.\n";
                std::exit(1);
            }
        }
};

class wheatFactory : public burgerFactory{
    public:
        burger* createBurger(std::string type) override {
            if(type=="basic")
                return new wheatSimpleBurger();
            else if(type=="fancy")
                return new wheatFancyBurger();
            else{
                std::cout<<"invalid type.\n";
                std::exit(1);
            }
        }
};

int main(){
    //now we have two factory which creates one item of different types
    //so, based on which factory the object is created it is going to instantioate the object.
    burgerFactory* bf = new wheatFactory();

    burger* b = bf->createBurger("basic");
    b->prepare();
    return 0;
}
