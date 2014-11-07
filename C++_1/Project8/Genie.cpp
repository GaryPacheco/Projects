/*
 * Genie.CPP: Genie is responsible for the definition of
 * the functions called. It deteails the functioning of the
 * programming, such as the D6 generator, it defines
 * the random number generator and "couts" two random numbers.
 *
 * Program:
 * A magical Genie turned computerized!
 * User has the options to name their genie whatever they want
 * and Has the options to choose tasks that the genie will
 * preform, such as roll two d6 dice, Tell how much a tip
 * would be at a certain cost, and your daily adventure(personally made).
 *
 * Gary Pacheco
 * Date created: 12/7/2010
 * Last date modified: 12/14/2010
 *
 * SOURCES USED
 *Cheyanne Taylor
 *Boyd Trollinger
 *Luke S.
 */
#include "Genie.h"
//Define Functions here!
void Genie::luckyNumbers()
{
    system("cls");
    cout << "\nToday's Lucky Lotto Numbers are: \n";
    for (int i = 0; i < 6; i++)
    {
        cout << (rand() % 99 + 1) << " "; //better using a for loop
    }
    cout << endl;
    cout << endl;
}

void Genie::dieCounter()
{
    system("cls");
    cout << "D6 Dice Generator" << endl;
    cout << "\nYour two rolls are: ";
    cout << (rand() % 6+1) << " "
         << (rand() % 6+1) << " "
         << endl << endl;
    string junk = "";
    cout << "Please hit enter to continue";
    getline (cin, junk);
    system("cls");
}
void Genie::tipPercent()
{
    system("cls");
    double percentOne = .10;
    double percentTwo = .15;
    double percentThree = .20;
    double percentFour = .25;

    cout << "How much is your meal? $";
    double meal = genieReader.readDouble();
    cout << "\nTip at 10%: $" << meal*percentOne << endl;
    cout << "Tip at 15%: $" << meal*percentTwo << endl;
    cout << "Tip at 20%: $" << meal*percentThree << endl;
    cout << "Tip at 25%: $" << meal*percentFour << endl << endl;

    string junk = "";
    cout << "Please hit enter to continue";
    getline (cin, junk);
    system("cls");
}

void Genie::adventure()
{
    system("cls");
    cout << "Your daily adventure encounter: " << endl << endl;
    int number =rand() % 5+1;
    if (number == 1)
    {
        cout << "You will have to deal with a couple minions today,\n"
             << "so prepare to deal with a couple obstacles.\n"
             << "Hint: To deal with minions, take one at a time\n"
             << "never take more than one at once. Slowly take\n"
             << "them on, if you deal with all obstacles at once\n"
             << "you will surley be overwhelmed. Use patience and strategy\n\n";
    }
    if (number == 2)
    {
        cout << "Today's adventure consists of coming across great wealth.\n"
             << "There is an option to take a path that can lead to great\n"
             << "happiness.\n\n";
    }
    if (number == 3)
    {
        cout << "Your adventure today is taking on the big boss!\n"
             << "There will be a huge obstacle, when it comes time\n"
             << "use wisdom to get past, blind fighting won't help!\n\n";
    }
    if (number == 4)
    {
        cout << "You search the taverns and you come to realize that there,\n"
             << "are no big quests today, just an average day.\n\n";
    }
    if (number == 5)
    {
        cout << "You have this weird feeling that you don't know whats in store.\n"
             << "Your quest is a mysterious one, you'll go about the day and\n"
             << "complete the quest and never know it will happen until it has been\n"
             << "completed.\n\n";
    }
    string junk = "";
    cout << "Please hit enter to continue";
    getline (cin, junk);
    system("cls");
}
