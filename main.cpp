#include"book.h"

int main() {

    PrinterQueue printerQueue;


    PrintStatistics printStatistics;


    printerQueue.AddClient(new PrintClient("Client1", 2));
    printerQueue.AddClient(new PrintClient("Client2", 1));
    printerQueue.AddClient(new PrintClient("Client3", 3));


    while (!printerQueue.IsEmpty()) {
        PrintClient* nextClient = printerQueue.GetNextClient();
        if (nextClient) {
            cout << "Printing: " << nextClient->name << " (Priority: " << nextClient->priority << ")\n";
            printStatistics.AddPrintRecord(nextClient->name);
            delete nextClient;
        }
    }


    printStatistics.PrintStatisticsInfo();

    return 0;
}