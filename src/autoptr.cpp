#include "autoptr.hpp"
#include <iostream>

template <typename T>
class Autoptr {
  public:
    /* Default constructor */
    Autoptr(T* ptr = nullptr) : m_ptr(ptr) { /*std::cout << "Autoptr constructor called"<< std::endl;*/
    }

    /* Destructor */
    ~Autoptr() {
        /* std::cout << "Autoptr destructor called" << std::endl; */
        delete m_ptr;
    }

    // Copy constructor
    // Do deep copy of a.m_ptr to m_ptr
#if 1
    Autoptr(const Autoptr& a) = delete;
#else
    Autoptr(const Autoptr& a) {
        std::cout << "Autoptr copy constructor" << std::endl;
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
    }
#endif

    // Copy assignment; a = b; Create copy of b into a
    // Do deep copy of a.m_ptr to m_ptr
#if 1
    Autoptr& operator=(const Autoptr& a) = delete;
#else
    Autoptr&
    operator=(const Autoptr& a) {
        std::cout << "Autoptr copy assignment" << std::endl;
        if (&a == this) { // Self-assignment detection
            return *this;
        }
        delete m_ptr;  // Release any resource we're holding
        m_ptr = new T; // Copy the resource
        *m_ptr = *a.m_ptr;

        return *this;
    }
#endif

    // Move constructor
    // Transfer ownership of a.m_ptr to m_ptr
    Autoptr(Autoptr&& a) : m_ptr(a.m_ptr) {
        std::cout << "Autoptr move constructor" << std::endl;
        a.m_ptr = nullptr; // we'll talk more about this line below
    }

    // Move assignment
    // Transfer ownership of a.m_ptr to m_ptr
    Autoptr&
    operator=(Autoptr&& a) {
        std::cout << "Autoptr move assignment" << std::endl;
        if (&a == this) { // Self-assignment detection
            return *this;
        }
        delete m_ptr;      // Release any resource we're holding
        m_ptr = a.m_ptr;   // Transfer ownership of a.m_ptr to m_ptr
        a.m_ptr = nullptr; // we'll talk more about this line below
        return *this;
    }

    // Getter as per refernece
    T&
    operator*() const {
        return *m_ptr;
    }

    // Getter as per pointer
    T*
    operator->() const {
        return m_ptr;
    }

    // Check if null
    bool
    isNull() const {
        return m_ptr == nullptr;
    }

  private:
    T* m_ptr;
};

class MyClass {
  public:
    MyClass() { std::cout << "MyClass constructor called" << std::endl; }

    ~MyClass() { std::cout << "MyClass destructor called" << std::endl; }

    const char*
    getName() {
        return "MyClass name";
    }
};

/* Generate resource class */
Autoptr<MyClass>
generateResource() {
    Autoptr<MyClass> res{new MyClass()};
    return res; // this return value will invoke the copy constructor
}

/* Print resource - call by reference */
void
printResource(Autoptr<MyClass>& p) {
    std::cout << (*p).getName() << std::endl;
}

void
example_autoptr() {
    Autoptr<MyClass> p = generateResource();
    printResource(p);
}