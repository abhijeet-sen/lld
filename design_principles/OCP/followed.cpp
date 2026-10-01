#include <iostream>
#include <string>
#include <vector>

class Product {
private:
    std::string name;
    int price;

public:
    Product(std::string name, int price) : name(name), price(price) {}

    std::string getName() { return name; }

    int getPrice() { return price; }
};

class ShoppingCart {
private:
    std::vector<Product *> m_products;

public:
    void addProduct(Product *p) { m_products.push_back(p); }

    void displayProducts() {
        std::cout << "Products in cart:\n";
        for (Product *p : m_products) {
            std::cout << p->getName() << " ";
        }
    }

    void calculatePrice() {
        int sumPrice = 0;
        for (Product *p : m_products) {
            sumPrice += p->getPrice();
        }
        std::cout<<"total price is:"<<sumPrice<<std::endl;
    }
};

class CartBillPrinter{
    private:
        ShoppingCart* m_cart;
    public:
        CartBillPrinter(ShoppingCart* cart): m_cart(cart){}
        void printBill(){
            std::cout<<"Printing bill...\n";
        }
};

class CartDB{
    public:
    virtual void saveToDB() = 0;
};

class SQLSaver:public CartDB{
    private:
        ShoppingCart* m_cart;
    public:
        SQLSaver(ShoppingCart* cart): m_cart(cart){}
        void saveToDB() override {
            std::cout<<"saving to SQL DB...\n";
        }
};

class MongoSaver:public CartDB{
    private:
        ShoppingCart* m_cart;
    public:
        MongoSaver(ShoppingCart* cart): m_cart(cart){}
        void saveToDB() override {
            std::cout<<"saving to Mongo DB...\n";
        }
};
        
class PostgresSaver:public CartDB{
    private:
        ShoppingCart* m_cart;
    public:
        PostgresSaver(ShoppingCart* cart): m_cart(cart){}
        void saveToDB() override {
            std::cout<<"saving to Postgres DB...\n";
        }
};

int main() {
    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("a", 10));
    cart->addProduct(new Product("b", 405));
    cart->displayProducts();
    cart->calculatePrice();

    CartBillPrinter* cb = new CartBillPrinter(cart);
    cb->printBill();

    //cdb object can be used.
    // for extension only new class needs to be created from abstract class.
    CartDB* cdb = new SQLSaver(cart);
    cdb->saveToDB();

    cdb = new MongoSaver(cart);
    cdb->saveToDB();
    
    cdb = new PostgresSaver(cart);
    cdb->saveToDB();

    return 0;
}
