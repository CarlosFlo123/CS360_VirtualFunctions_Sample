#include <string>
#include <iostream>
#include "Customer.h"
#include "Manager.h"
#include <array>
using namespace std;

class FormA {
protected:
    string a;
public:

    FormA(string a1) : a(a1) {
    }

    virtual void display() {
        cout << a << " display()" << endl;
    }

    void show() {
        cout << a << " show()" << endl;
    }
};

class FormB : public FormA {
protected:
    string b;
public:

    FormB(string a1, string b1) : FormA(a1), b(b1) {
    }

    virtual void display() {
        FormA::display();
        cout << b << " display()" << endl;
    }

    void show() {
        FormA::show();
        cout << b << " show()" << endl;
    }
};

class FormC : public FormB {
protected:
    string c;
public:

    FormC(string a1, string b1, string c1) : FormB(a1, b1), c(c1) {
    }

    virtual void display() {
        FormB::display();
        cout << c << " display()" << endl;
    }

    void show() {
        FormB::show();
        cout << c << " show()" << endl;
    }
};

void printList(const array<FormA*, 3>& ary) {
    for (auto p : ary) {
        p->display();
        cout << endl;
    }
}

void printList2(const array<FormA*, 3>& ary) {
    for (auto p : ary) {
        p->show();
        cout << endl;
    }
}

int main() {
    FormA a("A");
    FormB b("AB", "B");
    FormC c("AC", "BC", "C");
    array<FormA*, 3> ary;
    ary[0] = &a;
    ary[1] = &b;
    ary[2] = &c;
    printList(ary);
    cout << "==================" << endl;
    printList2(ary);
    return 0;
}
