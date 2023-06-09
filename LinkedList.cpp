#include "LinkedList.h"
#include <iostream>

LinkedList::LinkedList() : head(nullptr) {}

LinkedList::~LinkedList() {
    clear();
}

void LinkedList::addToStart(int value) { //принимает значение элемента
        Node* newNode = new Node(value); //создаем временную переменную
        newNode->data = value; // указатель дата к нему присваиваем значение дата
        newNode->next = head; //и следовательно передаем в том узле ссылку на первый элемент
        head = newNode;
    }


void LinkedList::addToEnd(int value) {
        Node* newNode = new Node(value);
        newNode->data = value; //передаем ей значение дата  и ссылку на след элемент пустую!, так как последний элемент
        newNode->next = nullptr;

    if (head == nullptr) { // если голова пустая
        head = newNode; // просто присваиваем хед нашу переменную
        return;
    }

    Node* current = head; //временная переменная
    while (current->next != nullptr) { //пока мы не долли до конца списка
        current = current->next; //двигаемся по списку
    }

    current->next = newNode; // добавляем элемент в конец списка


}





void LinkedList::addAtPosition(int data, int position) {
    Node* newNode = new Node(data);  // временная переменная
    newNode->data = data;
    newNode->next = nullptr;

    if (position == 0) { // если это 0ой элемент, то в нашей временной переменной мы вкладываем ссылку на голову, и голова теперь по значению равна нашей переменной
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    for (int i = 0; i < position - 1 && current != nullptr; i++) { //проверка , корректный ли у нас указан узел в current и не вышел ли индекс за рамки нашего списка
        current = current->next;// если все хорошо, то current ссылается на следующий элемент
    }

    if (current == nullptr) { // если он пустой , то позиция не входит на список
        std::cout << "Position out of range" << std::endl;
        return;
    }

    newNode->next = current->next; // здесь мы как раз добавляем этот элемент
    current->next = newNode;
}



void LinkedList::removeByValue(int value) {
    if (head == nullptr) {
        std::cout << "List is empty!" << std::endl;
        return;
    }
    Node* current = head; // у current значение голова

    if (value == 0) {
        head = head->next; // перемещаем голову на след элемент
        delete current; // удаляем, то что запрашивалось
        return;
    }

    for (int i = 0; current != nullptr && i < value - 1; i++) { // проверка на то что мы не дошли до конца  и на то, что позиция не выходит за список
        current = current->next; //переходим к следующему узлу списка
    }

    if (current == nullptr || current->next == nullptr) {
        return;
    }

    Node* temp = current->next;
    current->next = current->next->next;
    delete temp;
}

void LinkedList::removeByPosition(int position) {
    if (position <= 0) {
        std::cout << "Invalid position!" << std::endl;
        return;
    }

    if (head == nullptr) {
        std::cout << "List is empty!" << std::endl;
        return;
    }

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* previous = nullptr;
    Node* current = head;
    int currentPosition = 1;

    while (current != nullptr && currentPosition < position) {
        previous = current;
        current = current->next;
        currentPosition++;
    }

    if (current == nullptr) {
        std::cout << "Invalid position!" << std::endl;
        return;
    }

    previous->next = current->next;
    delete current;
}



int LinkedList::searchByValue(int value, Node** node) {
    *node = head;

    // Итерируемся по списку, пока не найдем элемент или не достигнем конца списка
    while (*node != nullptr) {
        if ((*node)->data == value) {
            return 1;
        }

        *node = (*node)->next;
    }
}

int LinkedList::searchByPosition(int pos) {
    if (pos <= 0) {
        return -1;
    }
    Node* current = head;
    int currentPosition = 1;
    while (current != nullptr && currentPosition < pos) {
        current = current->next;
        currentPosition++;
    }

    if (current == nullptr) {
        return -1;
    }

    return current->data;
}

void LinkedList::print() {
    Node* current = head; //присваиваем временной переменной значение головы
    while (current != nullptr) { //пока этоот элемент существует
        std::cout << current->data << " ";
        current = current->next; // идем к следующему элементу
    }
    std::cout << std::endl;
}


void LinkedList::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
}

bool LinkedList::isEmpty() {
    return head == nullptr;
}