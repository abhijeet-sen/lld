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

class CartDBSaver{
    private:
        ShoppingCart* m_cart;
    public:
        CartDBSaver(ShoppingCart* cart): m_cart(cart){}
        void saveToSQLDB(){
            std::cout<<"saving to SQL DB...\n";
        }
        void saveToMongoDB(){
            std::cout<<"saving to Mongo DB...\n";
        }
        void saveToPostgresDB(){
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

    //for any extension the exixting class needs to be modified
    CartDBSaver* cdb = new CartDBSaver(cart);
    cdb->saveToSQLDB();
    cdb->saveToMongoDB();
    cdb->saveToPostgresDB();
    
    return 0;
}
