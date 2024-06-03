
#include <iostream>
#include <vector>

// Напишите программу, которая с использованием стека магазинного типа преобразует постфиксальное выражение в инфиксальное
// 59*8746+*213*+*+*.
#include <stdexcept>

template <class Item>
class STACK {
private:
    std::vector<Item> stack; // контейнер для хранения элементов
    int maxSize; // максимальное количество элементов в стеке

public:
    // Конструктор, инициализирующий стек с максимальным размером
    STACK(int size) : maxSize(size) {}

    // Метод проверки, пуст ли стек
    int empty() const {
        return stack.empty();
    }

    // Метод добавления элемента в стек
    void push(Item item) {
        if (stack.size() == maxSize) {
            throw std::overflow_error("Stack overflow");
        }
        stack.push_back(item);
    }

    // Метод удаления и возврата последнего добавленного элемента из стека
    Item pop() {
        if (empty()) {
            throw std::underflow_error("Stack underflow");
        }
        Item item = stack.back();
        stack.pop_back();
        return item;
    }
};

void example4_18() {
    int N = 17;
    STACK<int> stack(N);
    char* a = new char[N];
    a[0] = '5';
    a[1] = '9';
    a[2] = 'm';
    a[3] = '8';
    a[4] = '7';
    a[5] = '4';
    a[6] = '6';
    a[7] = 'a';
    a[8] = 'm';
    a[9] = '2';
    a[10] = '1';
    a[11] = '3';
    a[12] = 'm';
    a[13] = 'a';
    a[14] = 'm';
    a[15] = 'a';
    a[16] = 'm';
    for (int i = 0; i < N; ++i) {
        if (a[i] == 'a') {
            stack.push(stack.pop() + stack.pop());
        }
        if (a[i] == 'm') {
            stack.push(stack.pop() * stack.pop());
        }
        if (a[i] >= '0' && a[i] <= '9') {
            int val = a[i] - '0';
            stack.push(val);
        }
    }
    std::cout << stack.pop();
}

int main()
{
    example4_18();
}


