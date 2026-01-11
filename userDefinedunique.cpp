#include <iostream>

template <typename T>
class MyUniquePtr {
private:
    T* ptr = nullptr; // The actual raw pointer

public:
    // 1. Constructor
    explicit MyUniquePtr(T* p = nullptr) : ptr(p) {}

    // 2. Destructor (The "RAII" part)
    ~MyUniquePtr() {
        delete ptr;
        std::cout << "Memory Deleted\n";
    }

    // 3. Disable Copying (No two pointers can own the same memory)
    MyUniquePtr(const MyUniquePtr&) = delete;
    MyUniquePtr& operator=(const MyUniquePtr&) = delete;

    // 4. Enable Moving (Transfer ownership)
    MyUniquePtr(MyUniquePtr&& other) noexcept {
        ptr = other.ptr;     // Take the pointer
        other.ptr = nullptr; // Leave the old one empty
    }

    MyUniquePtr& operator=(MyUniquePtr&& other) noexcept {
        if (this != &other) {
            delete ptr;          // Delete existing resource
            ptr = other.ptr;     // Take the new one
            other.ptr = nullptr; // Nullify source
        }
        return *this;
    }

    // 5. Overload dereference operators
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }

    T* get() const { return ptr; }
};

int main() {
    {
        MyUniquePtr<int> p1(new int(50));
        std::cout << "Value: " << *p1 << std::endl;

        // MyUniquePtr<int> p2 = p1; // This would cause a Compile Error (Good!)
        
        MyUniquePtr<int> p2 = std::move(p1); // Ownership transferred
        if (p1.get() == nullptr) {
            std::cout << "p1 is now empty.\n";
        }
    } // p2 goes out of scope here, memory is automatically deleted
    
    return 0;
}
