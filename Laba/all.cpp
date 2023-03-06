#include "all.h"

Node *createList(int &length) {
    Node *current, *next = nullptr;
    for (int i = length; i > 0; --i) {
        current = new Node;
        current->number = i;
        current->next = next;
        next = current;
    }
    return current;
}

void showList(Node *originList) {
    Node *element = originList;
    while (element != nullptr) {
        printf("%d ", element->number);
        element = element->next;
    }
    printf("\n");
}

void cleanList(Node *originList) {
    Node *element;
    Node *current = originList;
    Node *nextForDelete;
    while (current->next != nullptr) {
        element = current;
        nextForDelete = element->next;
        delete element;
        current = nextForDelete;
    }
}

void addElement(Node *originList, int &length) {
    int index = validationWithArgument(0, length);
    Node *elementByIndex = getElementByIndex(originList, index);
    Node *newElement = new Node;
    newElement->number = validation();
    newElement->next = elementByIndex->next;
    elementByIndex->next = newElement;
    length++;
}

void deleteElementByIndex(Node *originList, int &length) {
    int index = validationWithArgument(0, length);
    Node *elementByIndex = getElementByIndex(originList, index - 1);
    Node *elementForDelete = elementByIndex->next;
    elementByIndex->next = elementForDelete->next;
    delete elementForDelete;
    length--;
}

Node *getElementByIndex(Node *originList, int index) {
    Node *current = originList;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}

Node *reverseList(Node *originList, int &length) {
    Node *allElements[length];
    Node *current = originList;
    for (int i = 0; i < length; i++) {
        allElements[i] = current;
        current = current->next;
    }
    for (int i = length - 1; i >= 0; i--) {
        if (i != 0) allElements[i]->next = allElements[i - 1];
        else allElements[i]->next = nullptr;
    }
    return allElements[length - 1];
}

bool checkOverflow(double d) {
    return d >= -2147483648 && d <= 2147483647;
}

long validation() {
    bool validationFlag = false;
    double result;
    while (!validationFlag) {
        if (scanf("%lf", &result)) {
            if (!checkOverflow(result)) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
                printf("Неправильный ввод! Число вышло за границу дозволенного! Попробуйте снова!\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
            } else validationFlag = true;
        } else {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            printf("Неправильный ввод! Попробуйте снова!\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
        }
        fflush(stdin);
    }
    return (long) result;
}


long validationWithArgument(int min, int max) {
    long result;
    do {
        result = validation();
        if (result > max || result < min) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
            printf("Неверный ввод! Значение должно быть от %d до %d\n", min,
                   max);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
        }
    } while (result > max || result < min);
    return result;
}


