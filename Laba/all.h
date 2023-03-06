#ifndef LABA_ALL_H
#define LABA_ALL_H
#include <cstdio>
#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <windows.h>
#include <iostream>
struct Node {
    int number;
    Node* next;
};

Node* createList(int& length);

void showList(Node* originList);

void cleanList(Node* originList);

void addElement(Node* originList, int& length);

Node* getElementByIndex(Node* originList, int index);

long validation();

long validationWithArgument(int min, int max);

Node* reverseList(Node* originList, int& length);

void deleteElementByIndex(Node* originList, int& length);

#endif //LABA_ALL_H
