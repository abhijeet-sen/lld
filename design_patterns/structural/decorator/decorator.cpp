#include<iostream>
#include<string>

class character{
    public:
        virtual std::string getAbilities() const = 0;
};

class characterDecorator : public character{
    public:
        character* c;
        characterDecorator(character* c):c(c){}
};

class mario : public character{
    public:
        std::string getAbilities() const override {
            return "Mario ";
        }
};

class heightUpDecorator : public characterDecorator{
    public:
        heightUpDecorator(character* c):characterDecorator(c){}
        std::string getAbilities() const override{
            return c->getAbilities() + "height powerup ";
        }
};

class starDecorator : public characterDecorator{
    public:
        starDecorator(character* c):characterDecorator(c){}
        std::string getAbilities() const override{
            return c->getAbilities() + "star powerup";
        }
};

int main(){
    character* mario_c = new mario();
    std::cout<<mario_c->getAbilities()<<"\n";

    mario_c = new heightUpDecorator(mario_c);
    std::cout<<mario_c->getAbilities()<<"\n";

    mario_c = new starDecorator(mario_c);
    std::cout<<mario_c->getAbilities()<<"\n";

    return 0;
    
}