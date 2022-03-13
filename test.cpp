#include "header.h"

class A {
public:
    virtual void func() {
        cout << "a";
    }
};

class B : public A {
public:
    // virtual void func() {
    //     cout << "b";
    // }
};

int main() {
    A a;
    B b;
    b.func();
}