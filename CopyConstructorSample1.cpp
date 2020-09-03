#include <iostream>

using namespace std;

class Line {

public:
    int getLength(void);
    void setLength(int nl);
    Line(int len);             // simple constructor
    Line(const Line& obj);  // copy constructor
    ~Line();                     // destructor

private:
    int* ptr;
};

// Member functions definitions including constructor
Line::Line(int len) {
    cout << "Normal constructor allocating ptr" << endl;

    // allocate memory for the pointer;
    ptr = new int;
    *ptr = len;
}

Line::Line(const Line& obj) {
    cout << "Copy constructor allocating ptr." << endl;
    ptr = new int;
    *ptr = *obj.ptr; // copy the value
}

Line::~Line(void) {
    cout << "Freeing memory!" << endl;
    delete ptr;
}

int Line::getLength(void) {
    return *ptr;
}

void Line::setLength(int nl) {
    *ptr = nl;
}

void display(Line obj) {
    cout << "Length of line : " << obj.getLength() << endl;
}

// Main function for the program
int main() {
    Line line(10);

    Line line2 = line;  // call copy constructor..
    line2.setLength(20);  // one copy points to 10. The other points to 20.
    display(line);  // call copy const.
    display(line2);  // call copy const.

    // copy const. is called 3 times.
    // 2 copies in this scope, 2 copies in display functions. Thus destructor is called 4 times. 
    return 0;
}