#include <iostream>

class Point {
public:
    Point(int x = 0, int y = 0):x{x},y{y} {

        std::cout << "Constructor: " << *this;
    }

    /* Equal operator */
    bool operator == (const Point& other) {
        return x == other.x && y == other.y;
    }

    /* Prefix operator = return reference to us */
    Point& operator ++ () {
        ++x;
        ++y;
        return *this;
    }
    Point& operator -- () {
        --x;
        --y;
        return *this;
    }

    /* Postfix operator = returns copied value */
    Point operator ++ (int) {
        Point tmp{*this};
        ++(*this);
        return tmp;
    }
    Point operator -- (int) {
        Point tmp{*this};
        --(*this);
        return tmp;
    }

    friend std::ostream& operator << (std::ostream& out, const Point& p);
private:
    int x, y;
};


/* Print operator */
std::ostream& operator << (std::ostream& out, const Point& p) {
    out << "X = " << p.x << "; Y = " << p.y << std::endl;
    return out;
}

int
main() {
    Point a(1, 2), b(1, 2);

    std::cout << a;
    std::cout << b;
    if (a == b) {
        std::cout << "a == b" << std::endl;
    } else {
        std::cout << "a != b" << std::endl;
    }
    a++;
    b++;
    std::cout << a;
    std::cout << b;
    return 0;
}
