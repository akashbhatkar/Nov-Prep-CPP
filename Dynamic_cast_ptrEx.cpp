#include <iostream>
#include <typeinfo> // For std::bad_cast

#include <iostream>
#include <vector>

class Animal {
public:
    // Must be virtual for dynamic_cast to work
    virtual ~Animal() {} 
    virtual void speak() { std::cout << "Animal sound.\n"; }
};

class Dog : public Animal {
public:
    void speak() override { std::cout << "Woof! Woof!\n"; }
    void train() { std::cout << "Dog is trained to sit.\n"; } // Dog-specific function
};

int main() {
    Animal* a1 = new Dog(); // Actually a Dog
    Animal* a2 = new Animal(); // Just an Animal

    // Case 1: Successful Cast (a1 actually points to a Dog)
    Dog* d1 = dynamic_cast<Dog*>(a1); 
    if (d1) {
        std::cout << "a1 is a Dog: ";
        d1->train(); 
    }

    // Case 2: Failed Cast (a2 only points to an Animal)
    Dog* d2 = dynamic_cast<Dog*>(a2);
    if (!d2) {
        // d2 is nullptr, the conversion failed safely
        std::cout << "a2 is NOT a Dog. Cast failed safely.\n";
    }

    delete a1;
    delete a2;
    return 0;
}
