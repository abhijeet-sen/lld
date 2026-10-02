#include<iostream>

class shape2D{
    public:
        virtual void area()=0;
};

class shape3D{
    public:
        virtual void area()=0;
        virtual void volume()=0;
};

class square : public shape2D{
    private:
        int side;
    public:
        square(int side):side(side){}
        void area() override {
            std::cout<<"area is:"<<side*side<<std::endl;
        }
};

class cube : public shape3D{
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
    shape3D* s = new cube(10);

    s->area();
    s->volume();

    shape2D* s2 = new square(10);
    s2->area();
    // now volume method doesn't exist
    // s2->volume();

    return 0;
}
