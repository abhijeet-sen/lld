#include<iostream>

class shape{
    public:
        virtual void area()=0;
        virtual void volume()=0;
};

class square : public shape{
    private:
        int side;
    public:
        square(int side):side(side){}
        void area() override {
            std::cout<<"area is:"<<side*side<<std::endl;
        }
        void volume() override {
            throw std::logic_error("square doesn't have volume");
        }
};

class cube : public shape{
    private:
        int side;
    public:
        cube(int side):side(side){}
        void area() override {
            std::cout<<"area is:"<<side*side<<std::endl;
        }
        void volume() override {
            std::cout<<"volume is:"<<side*side*side<<std::endl;
        }
};

int main(){
    shape* s = new cube(10);

    s->area();
    s->volume();

    s = new square(10);
    s->area();
    //throws error
    s->volume();

    return 0;
}