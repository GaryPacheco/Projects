/*
 * Medieval Store
 * Replicating a medieval blacksmith
 * shop, players buy what they want and pay me.
 * Gary Pacheco
 * Date created: 9/21/2010
 * Last date modified: 9/30/2010
 *
 * SOURCES USED
 *Cheyanne Taylor
 *Boyd Trollinger
 *Josh Pollastrini
 */

#include <iostream>
#include "CinReader.h"

using namespace std;

CinReader reader;

int main()
{
    bool quit = false;
    int swordPrice = 400;
    int swordBought = 0;
    int swordTotal = 0;
    int hammerPrice = 450;
    int hammerBought = 0;
    int hammerTotal = 0;
    int sheildPrice = 350;
    int sheildBought = 0;
    int sheildTotal = 0;
    int chainmailPrice = 500;
    int chainmailBought = 0;
    int chainmailTotal = 0;
    int repellentPrice = 650;
    int repellentBought= 0;
    int repellentTotal = 0;
    int totalCost = 0;
    int payed = 0;
    int playerChange = 0;




// Welcome Message!!
    cout << "\nYou've Entered Failed Ressurection!\n" << endl;

    cout << "I don't care for beggars... you got gold? (Y)es or (N)o? ";
    char enter = reader.readChar("YyNn");
    enter = tolower (enter);

    while (quit == false)

        //Items in store to select from
    {
        cout << "\n-------------------------------------------------\n";
        cout << "\nWell... buy something, will ya?\n\n";
        cout << "[1] Fiery Longsword " << swordPrice << " Gold Pieces.\n\n";
        cout << "[2] Adamantium Hammer " << hammerPrice << " Gold Pieces.\n\n";
        cout << "[3] Gold Plated Sheild " << sheildPrice << " Gold Pieces.\n\n";
        cout << "[4] Mithril Chainmail " << chainmailPrice << " Gold Pieces.\n\n";
        cout << "[5] Anti-Dragon Repellent " << repellentPrice << " Gold Pieces.\n\n";
        cout << "[0] Leave store.\n\n";

        cout << "----------------------------------------------------------------\n";
        cout << "Your Choice: ";
        int choice = reader.readInt(0,5);

// Reatcion after person buys item, adds up each item bought
        switch (choice)
        {

        case 1:
            cout << "\nHope the smell of your victims don't overwhelm ye... \n\n";
            swordBought++;
            cout << "You grabbed " << swordBought << " Fiery Longsword";
            if (swordBought > 1)
               {
                    cout << "s";
               }
            swordTotal = (swordBought * swordPrice);
            cout << " at the cost of " << swordTotal << " Gold Pieces.";
        break;
        case 2:
            cout << "\nThis baby has crippled a few giants!\n\n";
            hammerBought++;
            cout << "You bought " << hammerBought << " Adamantium Hammer";
            if (hammerBought > 1)
                {
                    cout << "s";
                }
            hammerTotal = (hammerBought * hammerPrice);
            cout << " at the cost of " << hammerTotal << " Gold Pieces.";
        break;
        case 3:
            cout << "\nGold looks nice... blocks sticks at least, haha.\n\n";
            sheildBought++;
            cout <<"You bought " << sheildBought << " Gold Plated Sheild";
            if (sheildBought > 1)
                {
                    cout <<"s";
                }
            sheildTotal = (sheildBought * sheildPrice);
            cout << " at the cost of " << sheildTotal << " Gold Pieces.";
        break;
        case 4:
            cout << "\nAhh.. keeps the dam zombies from gettin to the jewels!\n\n";
            chainmailBought++;
            cout <<"You bought " << chainmailBought << " Mithril Chainmail";
            if ( chainmailBought > 1)
                {
                cout << "s";
                }
            chainmailTotal = (chainmailBought * chainmailPrice);
            cout << " at the cost of " << chainmailTotal << " Gold Pieces.";
        break;
        case 5:
            cout << "\nDon't know how they get it, somethin about Dragon urine... huh!\n\n";
            repellentBought++;
            cout << "You bought " << repellentBought << " Anti-Dragon Repellent";
            if (repellentBought > 1)
                {
                    cout << "s";
                }
            repellentTotal = (repellentBought * repellentPrice);
            cout << " at the cost of " << repellentTotal <<" Gold Pieces.";
        break;

        case 0:
            cout << "\nI didn't like you anyways.\n\n";
            quit = true;
        break;

        }

    if (quit == true)
        {
// Items IN cart RECEIPT
        cout << "_____________________________________________________________\n\n";
        cout << "This is what you picked: \n";
            cout << "\n" << repellentBought << " Anti-Dragon Repellent";
            if (repellentBought > 1)
            cout << "s";
            cout << "\nFor the price of " << repellentTotal << " Gold Pieces.\n";

            cout << "\n\n" << chainmailBought << " Mithril Chainmail";
            if (chainmailBought > 1)
            cout << "s";
            cout << "\nFor the price of " << chainmailTotal << " Gold Pieces.\n";

            cout << "\n" << sheildBought << " Golden Sheild ";
            if (sheildBought > 1)
            cout << "s";
            cout << "\nFor the price of " << sheildTotal << " Gold Pieces.\n";

            cout << "\n" << hammerBought << " Adamantium Hammer";
            if (hammerBought > 1)
                cout << "s";
            cout << "\nFor the price of " << hammerTotal << " Gold Pieces.\n";

            cout << "\n" << swordBought << " Fiery Longsword";
               if (swordBought > 1)
                cout << "s";
            cout << "\nFor the price of " << swordTotal << " Gold Pieces.\n";


        totalCost =(swordTotal + hammerTotal + sheildTotal + chainmailTotal + repellentTotal);
        cout << "\nYou owe me " << totalCost << " Gold Pieces\n\n";

        cout << "Please enter payment amount: ";
        payed = reader.readInt(0);

        while (payed < totalCost)
        {
            if (payed < totalCost)
                {
                    totalCost = (totalCost - payed);
                    cout << "\nYou still owe me... " << totalCost;
                    cout << " Gold Pieces";
                    cout << "\nPlease enter payment amount: ";
                    payed = reader.readInt(0);
                }
        }
            if (payed > totalCost)
                {
                    playerChange = (payed - totalCost);
                    cout << "\nYou overpayed, here is your change\n";
                    cout << "Lucky I didn't keep it! haha.\n";
                    cout <<"\nYour received " << playerChange << " Gold Piece";
                if (playerChange > 1)
                    cout <<"s\n\n";
                }


        cout << "\n\nThanks for shoppin here!\n";
        cout << "Now get lost I got work to do!\n\n";

     }

}


    string junk = "";
    cout << "Please hit enter to continue";
    getline (cin, junk);
    return 0;
}
