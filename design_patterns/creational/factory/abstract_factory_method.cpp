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

//this is 2nd product of line that facotry can create,
//this makes the factory method to abstract as this is goinf to create family of objects
class garlicBread{
    public:
        virtual void prepare()=0;
};

//related products
class simpleGarlicBread : public garlicBread{
    public:
        void prepare() override {
            std::cout<<"prepare simple garlicBread.\n";
        }
};

class FancyGarlicBread : public garlicBread{
    public:
        void prepare() override {
            std::cout<<"prepare fancy garlicBread.\n";
        }
};

//wheat version
class wheatSimpleGarlicBread : public garlicBread{
    public:
        void prepare() override {
            std::cout<<"prepare wheat simple garlicBread.\n";
        }
};

class wheatFancyGarlicBread : public garlicBread{
    public:
        void prepare() override {
            std::cout<<"prepare wheat fancy garlicBread.\n";
        }
};

//abstract interface
class mealFactory{
    public:
        virtual burger* createBurger(std::string type)=0;
        virtual garlicBread* createGarlicBread(std::string type)=0;
};

class simpleFactory : public mealFactory{
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

        garlicBread* createGarlicBread(std::string type) override {
            if(type=="basic")
                return new simpleGarlicBread();
            else if(type=="fancy")
                return new FancyGarlicBread();
            else{
                std::cout<<"invalid type.\n";
                std::exit(1);
            }
        }
};

class wheatFactory : public mealFactory{
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

        garlicBread* createGarlicBread(std::string type) override {
            if(type=="basic")
                return new wheatSimpleGarlicBread();
            else if(type=="fancy")
                return new wheatFancyGarlicBread();
            else{
                std::cout<<"invalid type.\n";
                std::exit(1);
            }
        }
};

int main(){
    //now we have two factory which creates one item of different types
    //so, based on which factory the object is created it is going to instantioate the object.
    mealFactory* mf = new simpleFactory();

    burger* b = mf->createBurger("basic");
    garlicBread* g = mf->createGarlicBread("fancy");
    b->prepare();
    g->prepare();
    return 0;
}