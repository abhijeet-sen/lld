#include<iostream>

class account{
    public:
        virtual void deposit(int) = 0;
        virtual void withdraw(int) = 0;
};

class savingsAccount : public account{
    private:
        int m_amount=0;
    public:
        void deposit(int amount) override {
            std::cout<<"deposited "<<amount<<" in savings account.\n";
            m_amount += amount;
        }
        void withdraw(int amount) override {
            if(amount <= m_amount){
                std::cout<<"amount withdrawed "<<amount<<" from savings account.\n";
                m_amount -= amount;
            }
            else{
                std::cout<<"insufficent amount in savings account.\n";
            }
        }
};

class currentAccount : public account{
    private:
        int m_amount=0;
    public:
        void deposit(int amount) override {
            std::cout<<"deposited "<<amount<<" in current account.\n";
            m_amount += amount;
        }
        void withdraw(int amount) override {
            if(amount <= m_amount){
                std::cout<<"amount withdrawed "<<amount<<" from current account.\n";
                m_amount -= amount;
            }
            else{
                std::cout<<"insufficent amount in current account.\n";
            }
        }
};

class fixedDepositAccount : public account{
    private:
        int m_amount=0;
    public:
        void deposit(int amount) override {
            std::cout<<"deposited "<<amount<<" in fixed deposit account.\n";
            m_amount += amount;
        }

        //this violates the LSP
        void withdraw(int amount) override {
            throw std::runtime_error("witdraw is not available for this fixed deposit account.");
        }
};

int main(){
    account* acc = new savingsAccount();
    acc->deposit(100);
    acc->withdraw(50);

    acc = new currentAccount();
    acc->deposit(5500);
    acc->withdraw(570);

    acc = new fixedDepositAccount();
    acc->deposit(5500);
    acc->withdraw(570);

    return 0;
}