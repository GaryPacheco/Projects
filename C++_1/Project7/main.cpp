#include <iostream>
#include "CinReader.h"

using namespace std;

CinReader reader;
struct item
{
    string name;
    int quantity;
    double price;
};

int main()
{
    int* size;
    cout << "how many items" << endl;
    int amount = reader.readInt (1);
    size = new int[amount];
    for(int i =0; i < amount; i++)
        size[i] = 0;
    delete []size;

    return 0;
}

