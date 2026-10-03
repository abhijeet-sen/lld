#include<iostream>

//interfaces for the different group of stratergies
class walkable{
    public:
        virtual void walk()=0;
};

class flyable{
    public:
        virtual void fly()=0;
};

class takable{
    public:
        virtual void talk()=0;
};

//walking stratergies
class normalWalkStratergy : public walkable{
    public:
        void walk() override {
            std::cout<<"normal walk...\n";
        }
};

class noWalkStratergy : public walkable{
    public:
        void walk() override {
            std::cout<<"cannot walk...\n";
        }
};

class moonWalkStratergy : public walkable{
    public:
        void walk() override {
            std::cout<<"moon walk...hehe\n";
        }
};

//talking stratergies
class normalTalkStratergy: public takable{
    public:
        void talk() override{
            std::cout<<"noraml talk...\n";
        }
};

class noTalkStratergy: public takable{
    public:
        void talk() override{
            std::cout<<"cannot talk...\n";
        }
};

//flying stratergy
class normalFlystratergy : public flyable{
    public:
        void fly() override {
            std::cout<<"normal flying...\n";
        }
};

class noFlystratergy : public flyable{
    public:
        void fly() override {
            std::cout<<"cannot flying...\n";
        }
};

class heheFlystratergy : public flyable{
    public:
        void fly() override {
            std::cout<<"hehe flying...\n";
        }
};

class Robot{
    private:
        walkable* w;
        flyable* f;
        takable* t;
    public:
        Robot(walkable* w,flyable* f, takable* t)
            :w(w),f(f),t(t){}

        void walk(){
            w->walk();
        }
        void fly(){
            f->fly();
        }
        void talk(){
            t->talk();
        }
        //common part of all robot which doesn't change
        virtual void projection()=0;
};

class crawlerRobot : public Robot{
    private:
        walkable* w;
        flyable* f;
        takable* t;
    public:
        //pass the stratergy to Robot class
        crawlerRobot(walkable* w,flyable* f, takable* t)
            :Robot(w,f,t){}

        void projection() override{
            std::cout<<"Projecton of crawler robot...\n";
        }
};

class flyerRobot : public Robot{
    private:
        walkable* w;
        flyable* f;
        takable* t;
    public:
        //pass the stratergy to Robot class
        flyerRobot(walkable* w,flyable* f, takable* t)
            :Robot(w,f,t){}

        void projection() override{
            std::cout<<"Projecton of flyer robot...\n";
        }
};

int main(){
    Robot* r1 = new crawlerRobot(new moonWalkStratergy(),new noFlystratergy(),new noTalkStratergy());

    r1->fly();
    r1->talk();
    r1->walk();
    r1->projection();

    Robot* r2 = new flyerRobot(new normalWalkStratergy(),new normalFlystratergy(),new noTalkStratergy());

    r2->fly();
    r2->talk();
    r2->walk();
    r2->projection();

    return 0;
}