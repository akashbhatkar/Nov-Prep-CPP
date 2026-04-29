#include <iostream>

template <typename T>
class myShared {
private:
    T* ptr;
    int* ref_count; // Shared across all instances

    void release() {
        if (ref_count) {
            (*ref_count)--;
            if (*ref_count == 0) {
                delete ptr;
                delete ref_count;
                std::cout << "Resource and Reference Count Deleted\n";
            }
        }
    }

public:
    // Constructor
    explicit myShared(T* p = nullptr) : ptr(p) {
        if (ptr) {
            ref_count = new int(1);
        } else {
            ref_count = nullptr;
        }
    }

    // Destructor
    ~myShared() {
        release();
    }

    // Copy Constructor: Increments count
    myShared(const myShared& other) {
        ptr = other.ptr;
        ref_count = other.ref_count;
        if (ref_count) {
            (*ref_count)++;
        }
    }

    // Copy Assignment Operator
    myShared& operator=(const myShared& other) {
        if (this != &other) {
            release(); // Clean up current resource
            
            ptr = other.ptr;
            ref_count = other.ref_count;
            if (ref_count) {
                (*ref_count)++;
            }
        }
        return *this;
    }

    // Move Semantics (optional but good practice)
    myShared(myShared&& other) noexcept : ptr(other.ptr), ref_count(other.ref_count) {
        other.ptr = nullptr;
        other.ref_count = nullptr;
    }

    // Accessors
    T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    int use_count() const { return (ref_count) ? *ref_count : 0; }
};

int main() {
    myShared<int> s1(new int(100));
    cout << "s1 count: " << s1.use_count() << endl;

    {
        myShared<int> s2 = s1; // Copying
        cout << "After s2 created - s1 count: " << s1.use_count() << endl;
        cout << "Value via s2: " << *s2 << endl;
    } // s2 goes out of scope

    cout << "After s2 destroyed - s1 count: " << s1.use_count() << endl;

    return 0;
}
