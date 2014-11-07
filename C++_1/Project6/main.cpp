/*
 * A daily organizing planner.
 * User has the ability to setup all days of the week,
 * using notes, and todo lists. The user has the ability
 * to save their inputed data and come back view it later.
 *
 * Gary Pacheco
 * Date created: 11/4/2010
 * Last date modified: 11/11/2010
 *
 * SOURCES USED
 *Cheyanne Taylor
 *Boyd Trollinger
 */

#include <iostream>
#include "CinReader.h"
#include <fstream>

using namespace std;

CinReader reader;

struct day
{
    string name;
    string note;
    string todo1;
    string todo2;
    string todo3;
    string todo4;
    string todo5;
};

void printDay (day anyDay);
void setupDay (day& anyDay);
void setupItem (int number, string& todoItem);
void save (day* ptrDay1, day* ptrDay2,day* ptrDay3,day* ptrDay4,day* ptrDay5,day* ptrDay6,day* ptrDay7);
void retrieve (day* ptrDay1, day* ptrDay2,day* ptrDay3,day* ptrDay4,day* ptrDay5,day* ptrDay6,day* ptrDay7);
int main()
{
    int choice = 0;
    int dayChoice = 0;
    int viewChoice = 0;
    bool quit = false;

    day monday;
    monday.name = "Monday";
    day tuesday;
    tuesday.name = "Tuesday";
    day wednesday;
    wednesday.name = "Wednesday";
    day thursday;
    thursday.name = "Thursday";
    day friday;
    friday.name = "Friday";
    day saturday;
    saturday.name = "Saturday";
    day sunday;
    sunday.name = "Sunday";


    while (quit == false)
    {
        bool quitSetup = false;
        bool quitView = false;

        system ("cls");
        cout << "\t\t\t-Your Daily Planner-" << endl;
        cout << "You have the options:" << endl;
        cout << "[1] Setup Each Day." << endl;
        cout << "[2] View Each Day." << endl;
        cout << "[0] Quit Program." << endl;
        cout << "\nYour choice: ";
        choice = reader.readInt (0,2);

        switch (choice)
        {
        case 1:
            while (quitSetup == false)
            {
                cout << "\nWhat day would you like to setup?\n";
                cout << "[1] Monday\n";
                cout << "[2] Tuesday\n";
                cout << "[3] Wednesday\n";
                cout << "[4] Thursday\n";
                cout << "[5] Friday\n";
                cout << "[6] Saturday\n";
                cout << "[7] Sunday\n";
                cout << "[0] Exit Setup\n";
                cout << "\nYour Choice: ";
                dayChoice = reader.readInt (0,7);
                switch (dayChoice)
                {
                case 1:
                    setupDay(monday);
                    break;
                case 2:
                    setupDay(tuesday);
                    break;
                case 3:
                    setupDay(wednesday);
                    break;
                case 4:
                    setupDay(thursday);
                    break;
                case 5:
                    setupDay(friday);
                    break;
                case 6:
                    setupDay(saturday);
                    break;
                case 7:
                    setupDay(sunday);
                    break;
                case 0:
                    quitSetup = true;
                    break;
                }
            }

            cout << "Would you like to save your data to view later? (Y) or (N)\n";
            cout << "Any unsaved data will be lost\n";
            if (toupper(reader.readChar ("YyNn"))== 'Y')
                save(&monday, &tuesday, &wednesday, &thursday, &friday, &saturday, &sunday);

            break;

        case 2:

            retrieve(&monday, &tuesday, &wednesday, &thursday, &friday, &saturday, &sunday);
            while (quitView == false)
            {
                cout << "\nWhat day would you like to view?\n";
                cout << "[1] Monday\n";
                cout << "[2] Tuesday\n";
                cout << "[3] Wednesday\n";
                cout << "[4] Thursday\n";
                cout << "[5] Friday\n";
                cout << "[6] Saturday\n";
                cout << "[7] Sunday\n";
                cout << "[0] Exit Day Viewing\n";
                cout << "\nYour Choice: ";
                viewChoice = reader.readInt (0,7);

                switch (viewChoice)
                {
                case 1:
                    system("cls");
                    printDay(monday);
                    cout << "Hit enter to continue";
                    reader.readString();
                    break;
                case 2:
                    system("cls");
                    printDay(tuesday);
                    cout << "Hit enter to continue";
                    reader.readString();
                    break;
                case 3:
                    system("cls");
                    printDay(wednesday);
                    cout << "Hit enter to continue";
                    reader.readString();
                    break;
                case 4:
                    system("cls");
                    printDay(thursday);
                    cout << "Hit enter to continue";
                    reader.readString();
                    break;
                case 5:
                    system("cls");
                    printDay(friday);
                    cout << "Hit enter to continue";
                    reader.readString();
                    break;
                case 6:
                    system("cls");
                    printDay(saturday);
                    cout << "Hit enter to continue";
                    reader.readString();
                    break;
                case 7:
                    system("cls");
                    printDay(sunday);
                    cout << "Please Hit Enter to Continue:";
                    reader.readString();
                    break;
                case 0:
                    quitView = true;
                    break;
                }
            }
            break;

        case 0:
            quit = true;

            break;
        }
    }

    return 0;
}

void setupDay(day& anyDay)
{
    system ("cls");
    cout << "You are setting up: " << anyDay.name << "\n\n";

    cout << "Type a note/journal entry (just hit enter to skip): ";
    string input = reader.readString();
    if (input.length() > 0)
        anyDay.note = input;

    setupItem(1, anyDay.todo1);
    setupItem(2, anyDay.todo2);
    setupItem(3, anyDay.todo3);
    setupItem(4, anyDay.todo4);
    setupItem(5, anyDay.todo5);
    cout << "Hit enter to continue";
    reader.readString();

}

void setupItem (int number, string& todoItem)
{
    cout << "Enter todo item #" << number << " (hit enter to skip): ";
    string input = reader.readString();
    if (input.length() > 0)
        todoItem = input;
}
void printDay (day anyDay)
{
    cout << anyDay.name << endl;
    cout << "\n----------------\n";
    cout << "Note: ";
    cout << anyDay.note << endl;
    cout << "\n----------------\n";
    cout << "Todo:\n";
    cout << "1. " << anyDay.todo1 << endl;
    cout << "2. " << anyDay.todo2 << endl;
    cout << "3. " << anyDay.todo3 << endl;
    cout << "4. " << anyDay.todo4 << endl;
    cout << "5. " << anyDay.todo5 << endl;
}

void save (day* ptrDay1, day* ptrDay2,day* ptrDay3,day* ptrDay4,day* ptrDay5,day* ptrDay6,day* ptrDay7)
{
    ofstream fout("days.txt");
    if (!fout.fail())
    {
        fout << ptrDay1->name << endl;
        fout << ptrDay1->note << endl;
        fout << ptrDay1->todo1 << endl;
        fout << ptrDay1 -> todo2 << endl;
        fout << ptrDay1 -> todo3 << endl;
        fout << ptrDay1 -> todo4 << endl;
        fout << ptrDay1 -> todo5 << endl;

        fout << ptrDay2->name << endl;
        fout << ptrDay2->note << endl;
        fout << ptrDay2->todo1 << endl;
        fout << ptrDay2 -> todo2 << endl;
        fout << ptrDay2 -> todo3 << endl;
        fout << ptrDay2 -> todo4 << endl;
        fout << ptrDay2 -> todo5 << endl;

        fout << ptrDay3->name << endl;
        fout << ptrDay3->note << endl;
        fout << ptrDay3->todo1 << endl;
        fout << ptrDay3 -> todo2 << endl;
        fout << ptrDay3 -> todo3 << endl;
        fout << ptrDay3 -> todo4 << endl;
        fout << ptrDay3 -> todo5 << endl;

        fout << ptrDay4->name << endl;
        fout << ptrDay4->note << endl;
        fout << ptrDay4->todo1 << endl;
        fout << ptrDay4 -> todo2 << endl;
        fout << ptrDay4 -> todo3 << endl;
        fout << ptrDay4 -> todo4 << endl;
        fout << ptrDay4 -> todo5 << endl;

        fout << ptrDay5->name << endl;
        fout << ptrDay5->note << endl;
        fout << ptrDay5->todo1 << endl;
        fout << ptrDay5 -> todo2 << endl;
        fout << ptrDay5 -> todo3 << endl;
        fout << ptrDay5 -> todo4 << endl;
        fout << ptrDay5 -> todo5 << endl;

        fout << ptrDay6->name << endl;
        fout << ptrDay6->note << endl;
        fout << ptrDay6->todo1 << endl;
        fout << ptrDay6 -> todo2 << endl;
        fout << ptrDay6 -> todo3 << endl;
        fout << ptrDay6 -> todo4 << endl;
        fout << ptrDay6 -> todo5 << endl;

        fout << ptrDay7->name << endl;
        fout << ptrDay7->note << endl;
        fout << ptrDay7->todo1 << endl;
        fout << ptrDay7 -> todo2 << endl;
        fout << ptrDay7 -> todo3 << endl;
        fout << ptrDay7 -> todo4 << endl;
        fout << ptrDay7 -> todo5 << endl;

        fout.close();
    }
}

void retrieve (day* ptrDay1, day* ptrDay2,day* ptrDay3,day* ptrDay4,day* ptrDay5,day* ptrDay6,day* ptrDay7)
{
    ifstream fin("days.txt");
    if (!fin.fail())
    {
        getline(fin, ptrDay1->name);
        getline(fin, ptrDay1->note);
        getline(fin, ptrDay1->todo1);
        getline(fin, ptrDay1->todo2);
        getline(fin, ptrDay1->todo3);
        getline(fin, ptrDay1->todo4);
        getline(fin, ptrDay1->todo5);

        getline(fin, ptrDay2->name);
        getline(fin, ptrDay2->note);
        getline(fin, ptrDay2->todo1);
        getline(fin, ptrDay2->todo2);
        getline(fin, ptrDay2->todo3);
        getline(fin, ptrDay2->todo4);
        getline(fin, ptrDay2->todo5);

        getline(fin, ptrDay3->name);
        getline(fin, ptrDay3->note);
        getline(fin, ptrDay3->todo1);
        getline(fin, ptrDay3->todo2);
        getline(fin, ptrDay3->todo3);
        getline(fin, ptrDay3->todo4);
        getline(fin, ptrDay3->todo5);

        getline(fin, ptrDay4->name);
        getline(fin, ptrDay4->note);
        getline(fin, ptrDay4->todo1);
        getline(fin, ptrDay4->todo2);
        getline(fin, ptrDay4->todo3);
        getline(fin, ptrDay4->todo4);
        getline(fin, ptrDay4->todo5);

        getline(fin, ptrDay5->name);
        getline(fin, ptrDay5->note);
        getline(fin, ptrDay5->todo1);
        getline(fin, ptrDay5->todo2);
        getline(fin, ptrDay5->todo3);
        getline(fin, ptrDay5->todo4);
        getline(fin, ptrDay5->todo5);

        getline(fin, ptrDay6->name);
        getline(fin, ptrDay6->note);
        getline(fin, ptrDay6->todo1);
        getline(fin, ptrDay6->todo2);
        getline(fin, ptrDay6->todo3);
        getline(fin, ptrDay6->todo4);
        getline(fin, ptrDay6->todo5);

        getline(fin, ptrDay7->name);
        getline(fin, ptrDay7->note);
        getline(fin, ptrDay7->todo1);
        getline(fin, ptrDay7->todo2);
        getline(fin, ptrDay7->todo3);
        getline(fin, ptrDay7->todo4);
        getline(fin, ptrDay7->todo5);

        fin.close();
    }
}
