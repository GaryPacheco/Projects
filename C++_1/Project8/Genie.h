/*
 * Genie.h: Genie.h defines the header of the functions
 * used. It also creates a class for the functions and names
 * and defines what type of functions are going to be used.
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
#include <iostream>
#include "CinReader.h"
#include <cstdlib>
using namespace std;

class Genie
{
public:
    //class data
    string name;
    CinReader genieReader;
    //class function prototypes
    void luckyNumbers();
    void dieCounter();
    void tipPercent();
    void adventure();
};
