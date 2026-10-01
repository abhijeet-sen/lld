#include<iostream>

class nonWithdrawableAccount{
    public:
        virtual void deposit(int) = 0;
};

class withdrawableAccount : public nonWithdrawableAccount{
    public:
        virtual void withdraw(int) = 0;
};

class savingsAccount : public withdrawableAccount{
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

class currentAccount : public withdrawableAccount{
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

class fixedDepositAccount : public nonWithdrawableAccount{
    private:
        int m_amount=0;
    public:
        void deposit(int amount) override {
            std::cout<<"deposited "<<amount<<" in fixed deposit account.\n";
            m_amount += amount;
        }
};

int main(){
    withdrawableAccount* acc = new savingsAccount();
    acc->deposit(100);
    acc->withdraw(50);

    acc = new currentAccount();
    acc->deposit(5500);
    acc->withdraw(570);

    nonWithdrawableAccount* nonWAcc = new fixedDepositAccount();
    nonWAcc->deposit(5500);
    // does not have this function
    //nonWAcc->withdraw(570);

    return 0;
}