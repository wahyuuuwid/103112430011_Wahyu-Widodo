#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

const int MAX = 20;

struct Stack {
    int info[MAX];
    int top;
};

void CreateStack(Stack &S);
void Push(Stack &S, int x);
void pop(Stack &S, int &x);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, int x);

#endif
