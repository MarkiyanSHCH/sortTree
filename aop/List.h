#pragma once
#include<iostream>
using namespace std;

template <typename T>
class list {
private:
    template <typename>
    struct node {
        T data;
        node<T>* next;

        node(T data = T(), node<T>* pNext = nullptr) {
            this->data = data;
            next = pNext;

        }
    };

    int size;
    node<T>* Head;
public:
    list() {
        size = 0;
        Head = nullptr;
    }
    ~list() {
        delAll();
    }


    void push_back(T data) {
        if (Head == nullptr) {
            Head = new node<T>(data);
        }
        else {
            node<T>* current = this->Head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new node<T>(data);
        }
        ++size;
    }

    void pop() {
        node<T>* tmp = this->Head;

        if (tmp->next == nullptr) {
            Head = nullptr;
        }
        else {
            for (int i = 1; i < size - 1; i++) {
                tmp = tmp->next;
            }
            tmp->next = nullptr;
        }
        --size;
    }

    void printAll(){
        node<T>* current = this->Head;
        for (int i = 0; i < size; i++) {
            cout<<current->data<<"  ";
            current = current->next;
        }
        cout << endl;
    }

    int len() {
        return size;
    }


    T& value() {
        node<T>* current = this->Head;
        while (current->next != nullptr) {
            current = current->next;
        }
        return current->data;
    }

    void delAll() {
        while (Head != nullptr)
            pop();
    }

};