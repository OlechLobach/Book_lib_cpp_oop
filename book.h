#ifndef BOOK_H
#define BOOK_H

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <functional>
#include <ctime>


using namespace std;


class PrintClient {
public:
    string name;
    int priority;
    PrintClient* next;

    PrintClient(string n, int p) : name(n), priority(p), next(nullptr) {}
};


class PrintStatistics {
public:
    struct PrintRecord {
        string clientName;
        time_t printTime;
        PrintRecord* next;
    };

    PrintRecord* printQueue;

    PrintStatistics() : printQueue(nullptr) {}

    void AddPrintRecord(string clientName) {
        PrintRecord* record = new PrintRecord{ clientName, time(nullptr), nullptr };
        if (!printQueue) {
            printQueue = record;
        }
        else {
            PrintRecord* current = printQueue;
            while (current->next) {
                current = current->next;
            }
            current->next = record;
        }
    }

    void PrintStatisticsInfo() const {
        cout << "Printing Statistics:\n";
        PrintRecord* current = printQueue;
        while (current) {
            cout << "Client: " << current->clientName << ", Print Time: " << ctime(&current->printTime);
            current = current->next;
        }
    }
};

// Клас для імітації черги друку принтера
class PrinterQueue {
private:
    PrintClient* front;
    PrintClient* rear;

public:
    PrinterQueue() : front(nullptr), rear(nullptr) {}

    void AddClient(PrintClient* client) {
        if (!front) {
            front = rear = client;
        }
        else {
            rear->next = client;
            rear = client;
        }
    }

    PrintClient* GetNextClient() {
        if (front) {
            PrintClient* nextClient = front;
            front = front->next;
            if (!front) {
                rear = nullptr;
            }
            return nextClient;
        }
        return nullptr;
    }

    bool IsEmpty() const {
        return front == nullptr;
    }
};
#endif
