#include "stack.h"
#include <iostream>
using namespace std;

void CreateStack(Stack &S) {
    S.top = -1;
}

void Push(Stack &S, int x) {
    if (S.top == MAX - 1) {
        cout << "Stack penuh!" << endl;
    } else {
        S.top++;
        S.info[S.top] = x;
    }
}

void pop(Stack &S, int &x) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        x = S.info[S.top];
        S.top--;
    }
}

void printInfo(Stack S) {
    if (S.top == -1) {
        cout << "Stack kosong!" << endl;
    } else {
        cout << "[TOP] ";
        for (int i = S.top; i >= 0; i--) {
            cout << S.info[i] << " ";
        }
        cout << endl;
    }
}

void balikStack(Stack &S) {
    int i = 0;
    int j = S.top;
    while (i < j) {
        int tmp = S.info[i];
        S.info[i] = S.info[j];
        S.info[j] = tmp;
        i++; j--;
    }
}
