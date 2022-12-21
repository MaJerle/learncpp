#include <iostream>
#include "postfix_prefix_class.hpp"

class Point {
  public:
    Point(int x = 0, int y = 0) : x{x}, y{y} { std::cout << "Constructor: " << *this; }

    /* Check if equal */
    bool
    operator==(const Point& other) {
        return x == other.x && y == other.y;
    }

    /* Check if not equal */
    bool
    operator!=(const Point& other) {
        return operator==(other);
    }

    /* Prefix operator = return reference to us */
    Point&
    operator++() {
        ++x;
        ++y;
        return *this;
    }

    /* Prefix decrease with reference return */
    Point&
    operator--() {
        --x;
        --y;
        return *this;
    }

    /* Postfix operator = returns copied value */
    Point
    operator++(int) {
        Point tmp{*this};
        ++(*this);
        return tmp;
    }

    /* Postfix operator = returns copied value */
    Point
    operator--(int) {
        Point tmp{*this};
        --(*this);
        return tmp;
    }

    /* Print function for the class */
    friend std::ostream& operator<<(std::ostream& out, const Point& p);

  private:
    int x, y;
};

/* Print operator */
std::ostream&
operator<<(std::ostream& out, const Point& p) {
    out << "X = " << p.x << "; Y = " << p.y << std::endl;
    return out;
}

void
example_postfix_prefix_class() {
    Point a(1, 2), b(1, 2);

    std::cout << a;
    std::cout << b;

    /* == operator check */
    std::cout << "Check if equal" << std::endl;
    if (a == b) {
        std::cout << "a == b" << std::endl;
    } else {
        std::cout << "a != b" << std::endl;
    }

    /* != operator check */
    std::cout << "Check if not equal" << std::endl;
    if (a != b) {
        std::cout << "a != b" << std::endl;
    } else {
        std::cout << "a == b" << std::endl;
    }

    /* Postfix */
    a++;
    b++;

    /* Prefix */
    ++a;
    ++b;
    std::cout << a;
    std::cout << b;
}
