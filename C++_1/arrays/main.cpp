#include <iostream>
#include "CinReader.h"

using namespace std;

CinReader reader;
struct dummy
{
    string name;
    string greeting;
};
int main()
{
    dummy aBunchOfDummies[10];
bool quit = false;
while (quit == false)
{
    for (int i =0; i < 10; i++)
    {
        cout << i << ": " << aBunchOfDummies[i].name << endl;
    }
    cout << "pick a dummy (0-9): ";
    int dummyIndex = reader.readInt (0,9);
    cout << "You picked " << aBunchOfDummies[dummyIndex].name << endl;
    cout << "who says \"" << aBunchOfDummies[dummyIndex].greeting << endl;
    aBunchOfDummies[dummyIndex].name = reader.readString();
    cout << "new greeting: ";
    aBunchOfDummies [dummyIndex].greeting = reader.readString();
}





    return 0;
}
