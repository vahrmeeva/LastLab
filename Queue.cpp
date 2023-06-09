#include <iostream>
#include "Queue.h"

void Queue::enqueue(int value) {
    list.addToEnd(value);
}

int Queue::dequeue() {
    if (isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return 0;
    }

    int frontValue = list.searchByPosition(1);
    list.removeByPosition(1);
    return frontValue;
}

int Queue::front() {
    if (isEmpty()) {
        std::cout << "Queue is empty!" << std::endl;
        return 0;
    }

    return list.searchByPosition(1);
}

bool Queue::isEmpty() {
    return list.isEmpty();
}
