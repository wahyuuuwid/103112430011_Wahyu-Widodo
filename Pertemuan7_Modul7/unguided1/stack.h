#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX = 20; // kapasitas array stack

struct Stack {
    int info[MAX];
    int top;
};

void CreateStack(Stack &S);
void Push(Stack &S, int x);
void pop(Stack &S, int &x);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
