/*
 * Adventure Game of Dragon Bane
 * Player chooses what he/she does by choosing
 * a direction and using items as they find them.
 * You must find the right tools to complete the game.
 * Or you die, if you win high reward!
 * Gary Pacheco
 * Date created: 10/5/2010
 * Last date modified: 10/14/2010
 *
 * SOURCES USED
 *Cheyanne Taylor
 *Boyd Trollinger
 */

#include <fstream>
#include <iostream>
#include "CinReader.h"

using namespace std;

CinReader reader;

// Global Variables
bool quit = false;
bool hasCloak = false;
bool hasGold = false;
bool hasPick = false;
bool hasSword = false;
bool hasRope = false;
bool quitStore = false;
bool hasHead = false;

int direction =  0;
int shopChoice = 0;
int roomScore = 0;
int bagGold = 25;

//Functions
void feild ();
void town ();
void mine ();
void mountain ();
void forest ();
void deepMine ();
void bearsNest ();
void dragonLair ();
void inventory ();
void deathRoom ();

int main()
{
    // welcome message
    system ("cls");

    cout << "You surroundings are quite. The silence fills you with fear. There are 4 paths.\n";
    cout << "You look in all four directions confused as to wich direction to go.\n";
    cout << "Each direction looks as dangerous as the next.\n";
    cout << "Where do you travel?\n\n";

//Choice of Direction


    while (quit == false)
    {
        cout << "\n[1]Go North: Looks like a town ahead\n";
        cout << "[2]Go East: You notice a cave not far away.\n";
        cout << "[3]Go South: A Dark cloud looms over a mountain.\n";
        cout << "[4]Go West: The thick forest wont be easy to travel in.\n";
        cout << "[5]Check Inventory.\n";
        cout << "What do you do next: ";
        direction = reader.readInt (1,5);
        switch (direction)
        {
        case 1:
            feild ();
            break;
        case 2:
            mine ();
            break;
        case 3:
            mountain ();
            break;
        case 4:
            forest ();
            break;
        case 5:
            inventory ();
            break;
        }
    }

    return 0;
}

//Function for feild
void feild ()
{
    system ("cls");
    roomScore ++;
    if (hasRope == true)
    {
        town ();
    }
    if (hasCloak == true)
    {
        town ();
    }

    else if (hasCloak == false)
    {
        cout << "You traveled to a feild before the town, where the grass is about hip high.\n";
        cout << "You notice how nice the weather is as you look up in the sky.\n";
        cout << "Looking up at the sky, you trip over an object. You turn to look\n";
        cout << "and see its a cloak.\n";

        cout << "\nPick up the cloak? (y,n)";

        if (toupper (reader.readChar("YyNn")) == 'Y')
        {
            cout << "\nYou took the cloak. It is a nice cloak looks brand new.\n";
            cout << "You recieved a Cloak.\n\n";
            hasCloak = true;

            cout << "[1] Continue North: Travel to town.\n";
            cout << "[2] Go back the way you came.\n";
            cout << "What do you do next: ";
            direction = reader.readInt (1,2);
            switch (direction)
            {
            case 1:
                town ();
                break;
            }
        }
        else
        {
            cout << "[1] Continue North: Travel to town.\n";
            cout << "[2] Go back the way you came.\n";
            cout << "What do you do next: ";
            direction = reader.readInt (1,2);
            switch (direction)
            {
            case 1:
                town ();
                break;
            }

        }
    }
}




void town ()
{
    system ("cls");
    roomScore ++;
    cout << "The town is old but very well built. People avoid you as you pass.\n";
    cout << "You notice the towns folk look skiddish, but you don't know why.\n";

    if (hasCloak == false)
    {
        cout << "A shop is just ahead. Your intrested in what is wrong with the town.\n";
        cout << "Your pack also seems a bit empty so you enter the store.\n";
        cout << "You walk into the store and the storekeep asks ""What do you want?""\n\n";
        cout << "[1] Pepsi of healing: Looks refreshing!\n";
        cout << "[2] Sword of DragonBane: Looks useful.\n";
        cout << "[3] Ibuprofen: no more back pain.\n";
        cout << "[4] Information.\n";
        cout << "[0] Leave Town.\n";

        while (quitStore == false)
        {
            cout <<"Whats your choice: ";
            shopChoice = reader.readInt (0,4);
            switch (shopChoice)
            {
            case 1:
                cout << "Can't have it son, we are all out.\n";
                break;
            case 2:
                if (hasGold == true)
                {
                    cout << "I'll cut you a deal, how about 399 gold pieces!.\n";
                    cout << "Thats right, only 399. Limited time offer!.\n";
                    cout << "Whew just enough gold!\n";
                    cout << "That will be all your gold plz!\n";
                    cout << "You think to yourself, good thing I found that stash.\n";
                    cout << "\nYou recieved a Sword. \n\n You lost your Gold.\n";
                    hasSword = true;
                    hasGold = false;
                    bagGold = 0;
                }
                else
                    cout << "\nCan't afford it Mr.\n";

                break;
            case 3:
                cout << "\nOoh good stuff, here you g....\n";
                cout << "Darn Woman! Stop taking my pills!";
                cout << "\nYou forget about the ibuprofen and decide to look at other items\n";
                break;
            case 4:
                cout << "\nWell the town is so down because of that...\n";
                cout << " (As he points at the mountain pass)\n";
                cout << "We got a dragon that needs slayin! Best if you kill it.\n";
                cout << "Herd that cave is full of riches up there!\n\n";
                cout << "(After what the old man says you think of how much GOLD?)\n";
                break;
            case 0:
                main ();
                quitStore = true;

                break;

            }
        }
    }
    if (hasCloak == true)
    {
        cout << "A shop is just ahead. Your intrested in what is wrong with the town.\n";
        cout << "Your pack also seems a bit empty so you enter the store.\n";
        cout << "You walk into the store and the storekeep asks ""What do you want?""\n\n";
        cout << "Hay you stole my cloak! Get out of here theif!\n";
        cout << "\n\nYou run back for your campsite.\n\n";
    }

}

void mine ()
{
    system ("cls");
    roomScore ++;
    cout << "You notice its an old abandoned mine as you walk up to it.\n";
    cout << "Looks like nobody's been here for years and doesnt look dangerous\n";
    if (hasPick == false)
    {
        cout << "The mine is very old and overgrown, but you notice a new pickaxe on the side.\n";
        cout << "\nPick up the pick axe (y,n): ";
        if (toupper (reader.readChar("YyNn")) == 'Y')
        {
            cout << "\n\nYou recieved the pickaxe.\n";
            cout << "I wonder what use this has.\n";
            hasPick = true;
        }
    }
    cout << "\nYou notice that there is light in the cave.\n";
    cout << "[1] Travel further into the cave.\n";
    cout << "[2] Go back the way you came.\n";
    cout << "What do you do next: ";
    direction = reader.readInt (1,2);
    switch (direction)
    {
    case 1:
        deepMine ();
        break;

    }
}

void deepMine ()
{
    system ("cls");
    roomScore ++;
    cout << "You travel further into the mine and discover why it was abandoned.\n";
    if (hasCloak == false)
    {
        cout << "A goblin yells something in an unknown language and points at you.\n";
        cout << "Suddenly a club whacks you upside the head...\n";
        deathRoom ();
    }
    if (hasCloak == true)
    {
        cout << "A goblin yells something in an unknown language, but stops.\n";
        cout << "He points to you then jumps up and down.\n";
        cout << "A tall goblin with a crown points to your cloak.\n";
        cout << "You think he wants it, you hand it over to him.\n";
        cout << "He smiles and gives you a rope. You are escorted back out.\n";
        cout << "\n\n You recieved the Rope.\n\n You lost the Cloak.\n";
        hasRope = true;
        hasCloak = false;


    }

}

void mountain ()
{
    system("cls");
    roomScore ++;
    cout << "Walking up to the mountain pass you start to panic.\n";
    cout << "The tall mountain pass up to the dragons lair looks deadly.\n";
    cout << "You realize if you survive the pass you might not survive the dragon.\n";
    cout << "\nWhat do you do next?\n";
    cout << "[1]Climb Mountain Pass.\n";
    cout << "[2]Go back.\n\n";
    cout << "Your choice: ";
    direction = reader.readInt (1,2);
    switch (direction)
    {
    case 1:
        cout << "\nNo you decide. You will overcome your fear and face the mountain.\n";
        cout << "If you can fight a dragon you can climb a mountain!\n";
        cout << "You go full speed starting to climb the deadly cliff.\n\n";

        if (hasRope == true)
        {
            cout << "You tie the rope onto yourself for safety.\n";
            cout << "As you climb you lose your hand hold and start falling.\n";
            cout << "Luckily the rope catches on something and you manage to \n";
            cout << "get your holds back and start climbing.\n";
            cout << "You get to the top and see a dark hole in the mountain \n";
            cout << "that is the dragons liar.\n";
            cout << "You can feel the intense heat from the dragon.\n";
            cout << "\nWhat do you do next?\n";
            cout << "\n[1] Enter the dragons lair.\n";
            cout << "[2] Turn back.\n";
            cout << "Your choice: ";
            direction = reader.readInt (1,2);
            switch (direction)
            {
            case 1:
                dragonLair ();
                break;
            case 2:
                main ();
                break;
            }

        }
        if (hasRope == false)
        {
            cout << "As you climb you lose your hand hold and start falling.\n";
            cout << "You fall trying to grasp the cliff side to save yourself.\n";
            cout << "If only you had a saftey harness, you continue to fall,\n";
            cout << "plummeting to your death.\n";
            deathRoom ();
        }
        break;
    case 2:
        main ();
        break;
    }
}

void dragonLair ()
{
    system ("cls");
    roomScore ++;
    cout << "You enter the dragons lair, tears running down your face.\n";
    cout << "It feels a bit warmer, but that does not comfort you.\n";
    cout << "Suddenly you see the dragon. His big red scales and his \n";
    cout << "dark green eyes lock onto yours.\n";
    if (hasSword == true)
    {
        cout << "He see's you and you see him. You do not hesitate.\n";
        cout << "You run forward and dive to the side as the dragon\n";
        cout << " breathes his fire and slash with all abandon.\n";
        cout << "The dragon bane enchantment slices through the\n";
        cout << " dragon like butter, killing the beast.\n";
        cout << "With the dragon dead, you go and retrieve the loot.\n";
        cout << "In the dragons loot is all that you desire. You leave \n";
        cout << "with all you need feeling heroic.";
        cout << "\n\nYOU WON!!!\n\n";
        cout << "You gained 1 MILLION Gold Piecs.\n";

        bagGold = 1000000;
        hasHead = true;

        string junk = "";
        cout << "Please hit enter to continue";
        getline (cin, junk);

        inventory ();
        quit = true;

    }
    else if (hasSword == false)
    {
        cout << "He see's you and you see him. You do not hesitate.\n";
        cout << "You run forward and dive to the side as the dragon\n";
        cout << " breathes his fire, you punch it doing nothing to the \n";
        cout << "strong scales of a draon. If only you had a weapon.\n";
        cout << "He turns and melts you with fire\n";
        deathRoom ();
    }

}

void forest ()
{
    system("cls");
    roomScore ++;
    if (hasSword == true)
    {
        cout << "You travel into the the thick woods and the further you travel \n";
        cout << "the more the sun fades.The rock is gone, it looks like normal woods.\n";
    }

    else if (hasPick == true)
    {
        cout << "You travel into the the thick woods and the further you travel \n";
        cout << "the more the sun fades. While looking up you stumble on something.\n";
        cout << "It hurt bad, but you realized what you hit. A Rock!\n";
        cout << "No not a rock but a glowing rock. It looks like you should do something.\n";
        cout << "\nYou get the idea to swing your pick at the rock.\n";
        cout << "With a heavy swing the rock busts open revealing a stash of gold.\n";
        cout << "Someone must of hid this. Lucky you discovered it.\n\n";
        cout << "Pick up Gold (y,n): ";
        if (toupper (reader.readChar("YyNn")) == 'Y')
        {
            cout << "\n\nYou recieved the Gold.\n";
            cout << "Wonder what you could buy?\n";
            hasGold = true;
            bagGold = bagGold + 374;

        }
    }
    else if (hasPick == false)
    {
        cout << "You travel into the the thick woods and the further you travel \n";
        cout << "the more the sun fades. While looking up you stumble on something.\n";
        cout << "It hurt bad, but you realized what you hit. A Rock!\n";
        cout << "No not a rock but a glowing rock. It looks like you should do something.\n";
        cout << "You have no idea what to do with this rock.\n";
        cout << "Instead you decide to leave it alone.\n";

    }

    cout << "\nUp ahead you see foot prints leading further into the forest.\n";
    cout << "[1] Follow the foot prints.\n";
    cout << "[2] Go back the way you came.\n";
    cout << "What do you do next: ";
    direction = reader.readInt (1,2);
    switch (direction)
    {
    case 1:
        bearsNest ();
        break;
    case 2:
        main ();
        break;

    }
}

void bearsNest ()
{
    roomScore ++;
    cout << "\n\nThe tracks seem to lead near some sort of animal shelter.\n";
    cout << "You begin to check out the shelter when you hear a roar \n";
    cout << "from behind. As you turn around a giant bear slashes you \n";
    cout << "in the face...\n";
    deathRoom ();

}

void inventory()
{
    system ("cls");
    cout << "\nHere is your current inventory:\n\n";
    if (hasCloak == true)
        cout << "> a Cloak\n";
    if (hasPick == true)
        cout << "> a Pick Axe\n";
    if (hasRope == true)
        cout << "> a Rope\n";
    if (hasSword == true)
        cout << "> a Sword\n";
    if (hasHead == true)
        cout << "> The mighty Dragons Head!\n";
    cout << "You have " << bagGold << " Gold Pieces.\n";
    cout << "Score: rooms visited " << roomScore << ".\n\n";

    string junk = "";
    cout << "Please hit enter to continue";
    getline (cin, junk);
}

void deathRoom ()
{
    system ("cls");
    cout << "\n\nYOU DIED...\n\n";
    cout << "Your score is " << roomScore << " rooms visited, try to get the lowest.\n";
    cout << "Try to overcome the challenge of this adventure.\n";

    string junk = "";
    cout << "Please hit enter to continue";
    getline (cin, junk);

    quit = true;
}

