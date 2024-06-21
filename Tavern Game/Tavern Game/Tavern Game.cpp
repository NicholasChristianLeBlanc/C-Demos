/*
    Nick L.

    Dennis H.

    Introduction to Programming
    
    28 August 2020
    ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
   
    Dont ask why I used MLA formatting because I don't even know XD

    Purpose: to make an inventory system where the user can purchase new items and sell their old ones

    Extra stuff I added for god knows what reason: Difficulty system that changes the value of the merchant's inventory and the user's inventory, a randomiser system so that the merchant can have a random selection of items depending on their level, achievements, a system that also kicks the user out of the program for trying to break the game

    Stuff I forgot to add: Switch statement, mage weapons (magic staff)
*/

//  Hello, I'm going to add a TON of comments, so if you see a bunch of green, you know why, also warning that there is some foul language in this program

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::rand;
using std::string;
using std::cerr;
using std::vector;

//  I'm using a reference veriable for potion, melee, shield and bow because those variables have to be the exact same throughout the entire program
void itemChooser(int traderLevel, string& potion, string& melee, string& shield, string& bow);

//  List of every single melee weapon in the entire game
vector<string> allMeleeWeapons = {
    "Rusty Iron Sword",
    "Fine Iron Sword",
    "Mighty Battle Axe",
    "Great Broadsword",
    "Ultra Mace"
};

//  Base price of every single melee weapon in the game
vector<int> meleeWeaponBasePrice = {
    50,     //  Rusty Iron Sword
    80,     //  Fine Iron Sword
    160,    //  Mighty Battle Axe
    300,    //  Great Broadsword
    800     //  Ultra Mace
};

//  List of every single shield in the game
vector<string> allShields = {
    "Tattered Leather Shield",
    "Sturdy Leather Shield",
    "Worn Iron Shield",
    "Fine Iron Shield"
};

//  Base price of every single shield in the game
vector<int> shieldBasePrice = {
    40,     //  Tattered Leather Shield
    75,     //  Sturdy Leather Shield
    100,    //  Worn Iron Shield
    180     //  Fine Iron Shield
};

//  Every single bow that the game has to offer
vector<string> allBows = {
    "Inaccurate Crossbow",
    "Battle-Scarred Recurve Bow",
    "Sturdy Recurve Bow",
    "Accurate Crossbow",
    "Futuristic Compound Bow"   //  Bow from the future, literally
};

//  Base price for every single bow
vector<int> bowBasePrice = {
    65,     //  Inaccurate Crossbow
    130,    //  Battle-Scarred Recurve Bow
    220,    //  Sturdy Recurve Bow
    340,    //  Accurate Crossbow
    600     //  Futuristic Compound Bow
};

//  All of the potions in the game
vector<string> allPotions = {
    "Minor Healing Potion",
    "Minor Mana Potion",
    "Major Healing Potion",
    "Major Mana Potion"
};

//  Every potions base cost
vector<int> potionBasePrice = {
    15,     //  Minor Healing Potion
    20,     //  Minor Mana Potion
    50,     //  Major Healing Potion
    60      //  Major Mana Potion
};

int main() {
    int attempts = 0, numAttempts = 0, difficultyNum;
    double itemCost, inventoryValue;
    char yesNo;

    //  Difficulty selector because I want the cost of items to go up with difficulty and the value of the player inventory to go down with difficulty
    cout << "please select a difficulty" << endl;
    do {

        //  The list of each difficulty in the game
        cout << "1. Baby bitch mode \n2. A child could beat this mode \n3. Less of a bitch mode \n4. Real MANLY mode \n5. You will die (seriously) mode\n" << endl;

        //  A little do loop so that the user can't get past this part of the game until they choose a difficulty
        do {
            cin >> difficultyNum;

            //  this is just a failsafe so that the user can't break the program by placing say a string inside of an variable looking for an integer, if it picks up an error then it will execute the following code
            if (cin.fail()) {
                numAttempts++;

                // this entire chunk of code just makes sure that the user doesn't attempt to break the code too many times, thus why I set the max amount of attempts to 10 or greater (just in case they succeed in breaking the code somehow)
                if (numAttempts >= 10) {
                    cout << "okay thats it, I'm done with your shit" << endl;
                    cout << "goodbye" << endl;
                    cout << "\n*Achieved \"The Worst Ending Possible, Cunt\"*" << endl;
                    return 0;
                }

                cerr << "Sorry but stop being an idiot and please insert a valid number" << endl;   //  If the user attempts to put an invalid character or number into the integer of difficultyNum then the program will pick up on it and output to the user that they made a mistake in the only way I know how, by ridiculing them and making them feel bad
                cin.clear();    //  I believe this clears the error with the cin, but I literally don't know 100% as I searched it up on google

                #undef max  //  you have to do this because the next part in the code does not work without it for some reason, I'm not 100% sure why though

                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  //  this deletes everything that the user typed out from the display (I think, it might be the .clear function though)
                continue;
            }

            else if (difficultyNum > 5 || difficultyNum < 1) {
                numAttempts++;
                
                // this entire chunk of code just makes sure that the user doesn't attempt to break the code too many times, thus why I set the max amount of attempts to 10 or greater (just in case they succeed in breaking the code somehow)
                if (numAttempts > 5) {
                    cout << "okay thats it, I'm done with your shit" << endl;
                    cout << "goodbye" << endl;
                    cout << "\n*Achieved \"The Worst Ending Possible, Cunt\"*" << endl;
                    return 0;
                }
                cerr << "idiot, its a number from 1 to 5, no higher and no lower, now give me a proper answer" << endl;
                
                // this block is kind of complex so I'll comment on what each line does
                cin.clear();                                                    // this clears the error flag so that you can use the IO operations again
                #undef max                                                      // this suppresses the max definition in Windef.h so that i could actually use max in the next line
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // removes the new line AND the text from the previous cin / input from the stream so that the next input will be on the same line as the last cin
                continue;
            }
            else {
                numAttempts = 0;    // if the user actually puts a number thats valid then we reset the amount of attempts they get, just so if they say no later on to if they want to stay on the difficulty then they won't get slapped for making one mistake
            }
        } while (difficultyNum > 5 || difficultyNum < 1);

        //  Baby Bitch Mode
        if (difficultyNum == 1) {

            //  I just wanted to ridicule the user for choosing the easiest difficulty
            cout << "wow, choosing the baby bitch difficulty huh? you really are a pussy, afraid to have fun?" << endl;
            cout << "are you sure you want to play on Baby Bitch Mode? (y/n)\n" << endl;

            cin >> yesNo;

            if (yesNo == 'y' || yesNo == 'Y') {
                cout << "okay, fine, play on the easiest difficulty then, see if I care (which I DON'T)" << endl;
                itemCost = 0.5;
                inventoryValue = 1.5;
                break;
            }
            else if (yesNo == 'n' || yesNo == 'N') {
                cout << "\nokay good, now choose a difficulty that isn't absolute shit" << endl;
                attempts++;
                continue; 
            }

            //  I could have forced the user to keep the difficulty, but if they put something other than y or n then it will still bring back the difficulty selector
            else {
                cout << "its either y or n, there is no in between, but I'll assume you want a different difficulty since baby bitch mode is such trash" << endl;
                cout << "so... please choose a difficulty" << endl;
                attempts++;
                continue;
            }
        }

        //  A child could beat this mode
        else if (difficultyNum == 2) {
            cout << "well, its not baby bitch mode, but it still isn't anything difficult" << endl;
            cout << "are you sure that this mode is for you? (y/n)\n" << endl;

            cin >> yesNo;

            if (yesNo == 'y' || yesNo == 'Y') {
                cout << "sure, lets just go with this mode then, I'm still going to judge you though" << endl;
                itemCost = 0.75;
                inventoryValue = 1.25;
                break;
            }
            else if (yesNo == 'n' || yesNo == 'N') {
                cout << "\nfine, choose a different difficulty, or the same one just to screw with me" << endl;
                attempts++;
                continue;
            }
            else {
                cout << "close enough to n, we'll just pretend you meant to put that and you just... collapsed on your desk! yes, you were going to say 'n' but then you passed out!" << endl;
                cout << "\nso... please choose a difficulty, if you are still with us" << endl;
                attempts++;
                continue;
            }
        }

        //  Less of a bitch mode (normal mode)
        else if (difficultyNum == 3) {
            cout << "so... basically normal mode? I bet you would also choose plain vanilla ice cream over any other flavor, huh?" << endl;
            cout << "now, did you make a mistake and really meant to choose another difficulty? (y/n)\n" << endl;

            cin >> yesNo;

            if (yesNo == 'y' || yesNo == 'Y') {
                cout << "wow, still a plain bitch, but whatever" << endl;
                itemCost = 1;
                inventoryValue = 1;
                break;
            }
            else if (yesNo == 'n' || yesNo == 'N') {
                cout << "okay, can't make up your mind? just... choose a difficulty" << endl;
                attempts++;
                continue;
            }
            else {
                cout << "I'm going to do a coin flip to see if you meant 'y' or 'n', heads is going to equal 'y' and tails will be 'n'" << endl;
                cout << "and... its tails!!" << endl;
                cout << "\ntime to choose another difficulty!" << endl;
                attempts++;
                continue;
            }
        }

        //  Real MANLY mode
        else if (difficultyNum == 4) {
            cout << "hell yeah, a real MAN! finally some good shit" << endl;
            cout << "but, do you think you have what it takes for this difficulty? would you like to switch to a different mode? (y/n)\n" << endl;

            cin >> yesNo;

            if (yesNo == 'y' || yesNo == 'Y') {
                cout << "damn right, we got ourselves a real man over here, now lets have some fun!" << endl;
                itemCost = 1.25;
                inventoryValue = 0.75;
                break;
            }
            else if (yesNo == 'n' || yesNo == 'N') {
                cout << "oh come on! right when I think you are going to make the right decision!" << endl;
                cout << "\noh well, guess you are a disappointment like the rest, now choose a goddamn difficulty" << endl;
                attempts++;
                continue;
            }
            else {
                cout << "did you have a stroke? what the hell type of answer was that?" << endl;
                cout << "it's a simple 'y' or 'n', but I'll just make you choose a new difficulty because why the hell not?" << endl;
                cout << "\nchoose a difficulty, and make it quick" << endl;
                attempts++;
                continue;
            }
        }

        //  You will die (seriously) mode
        else {

            difficultyNum = 5;

            cout << "now thats what I'm talking about! a TRUE gameplay experience" << endl;
            cout << "now, are you sure you are ready for a real challenge? I wouldn't want to force you into pure chaos mode (y/n)\n" << endl;

            cin >> yesNo;

            if (yesNo == 'y' || yesNo == 'Y') {
                cout << "fuck yeah!! its about time we get somebody with balls to play on the hardest difficulty!" << endl;
                itemCost = 1.5;
                inventoryValue = 0.5;
                break;
            }
            else if (yesNo == 'n' || yesNo == 'N') {
                cout << "oh, disappointment as usual" << endl;
                cout << "\nJust choose a goddamn difficulty" << endl;
                attempts++;
                continue;
            }
            else {
                cout << "did you have a stroke? Its a simple 'y' or 'n'" << endl;
                cout << "I'll just assume that you want to change difficulties then, pussy" << endl;
                cout << "\nChoose a difficulty (again)" << endl;
                attempts++;
                continue;
            }
        }
    } while (attempts < 5);

    if (attempts >= 5) {
        cout << "this has gone on too long, I am seriously done with your shit, now get out of my game" << endl;
        cout << "\n*Achieved \"fuck you, stop being an asshole ending\"*" << endl;
        return 0;
    }

    //  since its a demo thing I'm just going to ask the user to choose a level for the trader so they can test out the differences
    cout << "Before we start this section of the demo, what level would you like the trader to be? (min 1, max 2,147,483,647)\n" << endl;

    int traderLevel = 0;

    attempts = 1;

    //  literally the only reason that I'm using 2,147,483,647 as the number is because the trader's level can be anything I want it to be
    do {
        cin >> traderLevel;

        if (cin.fail()) {

            if (attempts >= 10) {
                cout << "okay thats it, I'm done with your shit" << endl;
                cout << "goodbye" << endl;
                cout << "\n*Achieved \"The Worst Ending Possible, Cunt\"*" << endl;
                return 0;
            }
            cerr << "it can't be a number lower than 1, and it cannot be any higher than 2,147,483,647. So enter a goddamn valid number" << endl;   //  literally the only reason that I'm using 2,147,483,647 as the number is because the trader's level can be anything the user wants it to be, depending on what you want you can easily change the level requirements
            cin.clear();

            #undef max

            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            traderLevel = 0;
            attempts++;
            
            continue;
        }
        else if (traderLevel < 1) {
            cout << "it can't be a number lower than 1, and it cannot be any higher than 2,147,483,647" << endl;    //  literally the only reason that I'm using 2,147,483,647 as the number is because the trader's level can be anything I want it to be
            attempts++;
            continue;
        }
    } while (traderLevel < 1 || traderLevel > 2147483647);

    int tavernInput;

    vector<int> userMeleeAmount = {
        1,      //  Rusty Iron Sword
        0,      //  Fine Iron Sword
        0,      //  Mighty Battle Axe
        0,      //  Great Broadsword
        0       //  Ultra Mace
    };

    vector<int> userShieldAmount = {
        1,      //  Tattered Leather Shield
        0,      //  Sturdy Leather Shield
        0,      //  Worn Iron Shield
        0       //  Fine Iron Shield
    };

    vector<int> userBowAmount = {
        1,      //  Inaccurate Crossbow
        0,      //  Battle-Scarred Recurve Bow
        0,      //  Sturdy Recurve Bow
        0,      //  Accurate Crossbow
        0       //  Futuristic Compound Bow
    };

    vector<int> userPotionAmount = {
        2,      //  Minor Healing Potion
        0,      //  Minor Mana Potion
        0,      //  Major Healing Potion
        0       //  Major Mana Potion
    };

    int userMoney = 500;    //  500 coins because... f u, I don't know why I choose 500

    string potion, melee, shield, bow;
    itemChooser(traderLevel, potion, melee, shield, bow);

    int buyInput, sellInput, counter = 0, meleeVariable = 0, shieldVariable = 0, bowVariable = 0, potionVariable = 0, endVariable = 0;
    int meleeCost, shieldCost, bowCost, potionCost;

    //  
    if (melee != "") {
        vector<int>::iterator meleeCostIter;    //  this iterator is to read what the cost for a melee weapon is, by taking the position that the melee weapon is located in the string vector allMeleeWeapons we can hereby find the cost

        int meleePosition = 0;  //  start the position at zero so that we can count up and find the position the melee weapon appears in the vector
        for (vector<string>::iterator findMeleeWeapon = allMeleeWeapons.begin(); *findMeleeWeapon != melee; findMeleeWeapon++) {    //  for loop so that we can count up until we find the melee weapon it is that we are looking for, if we know the position on 1 vector, we can easily use the same position to find it on any other vectors sharing either the same variable OR if the vector is the stats for the allMeleeWeapons vector
            meleePosition++;    //  with this position counter, I'll use it later to find the cost of whatever the melee weapon was, since I'm using randoms this will help me out with making sure I have the same weapon stats, name price and all
        }

        meleeCostIter = meleeWeaponBasePrice.begin() + meleePosition;   //  using the meleePosition from earlier we make meleeCostIter point to the position that the melee weapons base price is equal to
        meleeCost = (int)round(*meleeCostIter * itemCost);  //  the cost for the melee weapon that the merchant is selling, I have to use round here because itemCost is a double since I want to get a percentage taken off or added to the base price
    }

    //  Shield cost and positioning, its the same as the first one (melee) and the next 2 are the exact same as well, so basically I'm not typing out how it works 3 more times
    if (shield != "") {
        vector<int>::iterator shieldCostIter;

        int shieldPosition = 0;
        for (vector<string>::iterator findShield = allShields.begin(); *findShield != shield; findShield++) {
            shieldPosition++;
        }

        shieldCostIter = shieldBasePrice.begin() + shieldPosition;
        shieldCost = (int)round(*shieldCostIter * itemCost);
    }

    //  Bow cost
    if (bow != "") {
        vector<int>::iterator bowCostIter;

        int bowPosition = 0;
        for (vector<string>::iterator findBow = allBows.begin(); *findBow != bow; findBow++) {
            bowPosition++;
        }

        bowCostIter = bowBasePrice.begin() + bowPosition;
        bowCost = (int)round(*bowCostIter * itemCost);
    }

    //  Potion cost
    if (potion != "") {
        vector<int>::iterator potionCostIter;

        int potionPosition = 0;
        for (vector<string>::iterator findPotion = allPotions.begin(); *findPotion != potion; findPotion++) {
            potionPosition++;
        }

        potionCostIter = potionBasePrice.begin() + potionPosition;
        potionCost = (int)round(*potionCostIter * itemCost);
    }

    //  The amount of items the trader has, I'm randomising them because I feel like it, it makes the program feel more "organinc" if thats even possible in any way
    vector<int> traderAmount = {
        (rand() % 2 + 1),      // Melee
        (rand() % 2 + 1),      // Shields
        (rand() % 2 + 1),      // Bows
        (rand() % 20 + 1)      // Potions
    };

    cout << "\nLevel " << traderLevel << " Trader: Hello traveller! What can I do for you?" << endl;

    do {
        cout << "1. Buy \n2. Sell Items \n3. Check Inventory \n4. Exit\n" << endl;

        attempts = 1;
        do {
            cin >> tavernInput;

            //  Same failsafe as the last one and literally every single one in the program, its just to check if the cin failed
            if (cin.fail()) {

                if (numAttempts >= 10) {
                    cout << "okay thats it, I'm done with your shit" << endl;
                    cout << "goodbye" << endl;
                    cout << "\n*Achieved \"The Worst Ending Possible, Cunt\"*" << endl;
                    return 0;
                }
                cerr << "Sorry but stop being an idiot and please insert a valid number" << endl;
                cin.clear();

#undef max

                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            //  I want to check for an input from 1 to 4 as those are all the options displayed to the user at this point
            else if (tavernInput < 1 || tavernInput > 4) {
                if (attempts == 1) {
                    cout << "you do realize its a number from 1 to 4, right?\n" << endl;
                    attempts++;
                    continue;
                }
                else if (attempts == 2) {
                    cout << "dumbass, what did I just say to you? READ MY WORDS!\n" << endl;
                    attempts++;
                    continue;
                }
                else if (attempts == 3) {
                    cout << "okay, are you brain dead or are you just illiterate? IT IS A NUMBER FROM 1 TO 4!!!\n" << endl;
                    attempts++;
                    continue;
                }
                else if (attempts == 4) {
                    cout << "thats it, I'm only giving you one more try, it is a number from 1 to 4, no higher, no lower, just 1, 2, 3 and 4\n" << endl;
                    attempts++;
                    continue;
                }
                else {
                    cout << "get out" << endl;
                    return 0;
                }
            }
        } while (tavernInput < 1 || tavernInput > 4);

        //  Buy page
        if (tavernInput == 1) {

            cout << "Tavern Inventory:" << endl;
            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

            counter = 0;

            //  since I have the inventory randomized for the tavern based on its level I need to make sure that if the tavern doesn't have the items in stock that they won't display anything where it should be, you know, like how a trader wouldn't just display something they don't actually have as thats sort of IMPOSSIBLE
            if (melee != "") {

                vector<int>::iterator meleeIter;    //  this is just going to be used to check what melee weapon the trader has in their inventory
                meleeIter = traderAmount.begin();   //  the melee weapon the trader gets will always be the first item in the trader's inventory

                counter++;  //  counter is just going to be used just to display the items in order, AND the number is going to be used so that the user can choose which item to buy using only numbers
                meleeVariable = counter;    //  the meleeVariable is going to be used later on so that I can know if the user wants to buy the melee weapon the tavern has, ALSO it helps me to know if the tavern even HAS a melee weapon

                if (melee != "Sold Out") {  //  if the tavern still has a melee weapon (that the user has not purchased yet) then it will display the item and what number its located at
                    cout << counter << ". " << *meleeIter << "x " << melee << " - " << meleeCost << " Coins" << endl;
                }
                else {  //  if the user has purchased all of the tavern's stock then that item will be displayed as SOLD OUT
                    cout << counter << ". " << "Sold Out" << endl;
                }
            }

            //  shield, bow and potion are all going to be the same as the melee code, so go read that if you care so much
            if (shield != "") {

                vector<int>::iterator shieldIter;
                shieldIter = traderAmount.begin() + 1;

                counter++;
                shieldVariable = counter;
                cout << counter << ". " << *shieldIter << "x " << shield << " - " << shieldCost << " Coins" << endl;
            }

            if (bow != "") {

                vector<int>::iterator bowIter;
                bowIter = traderAmount.begin() + 2;

                counter++;
                bowVariable = counter;
                cout << counter << ". " << *bowIter << "x " << bow << " - " << bowCost << " Coins" << endl;
            }

            if (potion != "") {

                vector<int>::iterator potionIter;
                potionIter = traderAmount.begin() + 3;

                counter++;
                potionVariable = counter;
                cout << counter << ". " << *potionIter << "x " << potion << " - " << potionCost << " Coins" << endl;
            }

            counter++;
            endVariable = counter;
            cout << counter << ". Back\n" << endl;

            cout << "You have: " << userMoney << " Coins\n" << endl;    //  does this even need explanation? it displays the amount of coins the user has, I know, isn't it insane? what is this technological advancement?

            attempts = 1;
            
            //  the same exact do loop that is scattered all over this program
            do {
                cin >> buyInput;

                if (cin.fail()) {

                    attempts++;

                    if (attempts >= 5) {
                        cout << "okay thats it, I'm done with your shit" << endl;
                        cout << "goodbye" << endl;
                        cout << "\n*Achieved \"The Worst Ending Possible, Cunt\"*" << endl;
                        return 0;
                    }
                    cerr << "Sorry but stop being an idiot and please insert a valid number" << endl;
                    cin.clear();

#undef max

                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
                else if (buyInput < 1 || buyInput > counter) {
                    if (attempts == 1) {
                        cout << "you do realize its a number from 1 to " << counter << ", right?\n" << endl;
                        attempts++;
                        continue;
                    }
                    else if (attempts == 2) {
                        cout << "dumbass, what did I just say to you? READ MY WORDS!\n" << endl;
                        attempts++;
                        continue;
                    }
                    else if (attempts == 3) {
                        cout << "okay, are you brain dead or are you just illiterate? IT IS A NUMBER FROM 1 TO " << counter << "!!!\n" << endl;
                        attempts++;
                        continue;
                    }
                    else if (attempts == 4) {
                        cout << "thats it, I'm only giving you one more try, it is a number from 1 to " << counter << ", no higher, no lower\n" << endl;
                        attempts++;
                        continue;
                    }
                    else {
                        cout << "get out\n" << endl;
                        cout << "*Achieved \"getting thrown out of the tavern\"*" << endl;
                        return 0;
                    }
                }
            } while (buyInput < 1 || buyInput > counter);

            //  if the user wants to buy the tavern's melee weapon then do this shit
            if (buyInput == meleeVariable) {

                if (melee == "Sold Out") {  //  I don't want the user trying to buy something that is sold out so... this code
                    cout << "Level " << traderLevel << " Trader: Sorry traveller, but that item appears to be sold out" << endl;
                    cout << "Anything else I can do for you though?" << endl;
                    continue;
                }

                else if (userMoney >= meleeCost) {  //  if the user actually has enough money then the following code will be excecuted:
                    vector<int>::iterator meleeAmountIter;  //  I make an iterator here so that later I can use it to check how many of the one melee weapon the tavern has in stock
                    meleeAmountIter = traderAmount.begin(); //  as I think I stated earlier, the tavern will only ever have ONE melee weapon, and the melee weapon will always be the first item in the tavern's inventory
                    
                    //  at this point I'm fed up with explaining the code, so don't mind the decrease in comment quality. 
                    vector<int>::iterator userMeleeIter;    //  this is the iterator to check the melee weapons that the user has in their inventory

                    int position = 0;
                    for (vector<string>::iterator allMeleeIter = allMeleeWeapons.begin(); *allMeleeIter != melee; allMeleeIter++) { //  I'm using this for loop to check what position the melee weapon (that the tavern has) is, by locating it in the vector for all the weapons in the game I can check the price no matter which item it is
                        position++; //  idk why you are reading this comment, its just the position that the melee weapon is located at
                    }

                    userMeleeIter = userMeleeAmount.begin() + position; //  we start at the beginning of the user's melee weapons and go to the position that the tavern's melee weapon is located at
                    *userMeleeIter = *userMeleeIter + 1;    //  add one to simulate the user purchasing the item

                    cout << "Added 1 " << melee << " to your Inventory\n" << endl;  //  cout to inform the user that the item was added to their inventory

                    userMoney = userMoney - meleeCost;  //  since the items are not free we have to take away what the value of the item was by using meleeCost from earlier (before the program even displays the tavern's options)

                    *meleeAmountIter = *meleeAmountIter - 1;    //  we then take 1 away from the tavern's inventory to simulate that item being sold 

                    if (*meleeAmountIter < 1) { //  next we check if there are any of that item left in stock, if not then we change the name to Sold Out as there is no longer anything for sale in that slot
                        melee = "Sold Out";
                    }

                    //  then we go back to the very first options page from the tavern by just continuing the loop
                    cout << "\nLevel " << traderLevel << " Trader: Anything else I can do for you traveller?" << endl;
                    continue;
                }

                //  if the user does not have enough money for the tavern's item then the program will inform the user and then go back to the start of the loop
                else {
                    cout << "Oops, it looks like you dont have enough funds to purchase that item" << endl;
                    cout << "\nLevel " << traderLevel << " Trader: Anything else I can do for you though traveller?" << endl;
                    continue;
                }
            }

            //  all 3 of the next loops are literally the exact same as the melee one, minus the titles, so if you would like to read up on what code does what then simply go back to the melee code
            else if (buyInput == shieldVariable) {
                if (shield == "Sold Out") {
                    cout << "Level " << traderLevel << " Trader: Sorry traveller, but that item appears to be sold out" << endl;
                    cout << "Anything else I can do for you though?" << endl;
                    continue;
                }
                else if (userMoney >= shieldCost) {

                    vector<int>::iterator shieldAmountIter;
                    shieldAmountIter = traderAmount.begin() + 1;

                    vector<int>::iterator userShieldIter;

                    int position = 0;
                    for (vector<string>::iterator allShieldIter = allShields.begin(); *allShieldIter != shield; allShieldIter++) {
                        position++;
                    }

                    userShieldIter = userShieldAmount.begin() + position;
                    *userShieldIter = *userShieldIter + 1;

                    cout << "Added 1 " << shield << " to your Inventory\n" << endl;

                    userMoney = userMoney - shieldCost;

                    *shieldAmountIter = *shieldAmountIter - 1;

                    if (*shieldAmountIter <= 0) {
                        shield = "Sold Out";
                    }

                    cout << "\nLevel " << traderLevel << " Trader: Anything else I can do for you traveller?" << endl;
                    continue;
                    
                }
                else {
                    cout << "Oops, it looks like you dont have enough funds to purchase that item" << endl;
                    cout << "\nLevel " << traderLevel << " Trader: Anything else I can do for you though traveller?" << endl;
                    continue;
                }
            }
            else if (buyInput == bowVariable) {
                if (bow == "Sold Out") {
                    cout << "Level " << traderLevel << " Trader: Sorry traveller, but that item appears to be sold out" << endl;
                    cout << "Anything else I can do for you though?" << endl;
                    continue;
                }
                else if (userMoney >= bowCost) {
                    vector<int>::iterator bowAmountIter;
                    bowAmountIter = traderAmount.begin() + 2;

                    vector<int>::iterator userBowIter;

                    int position = 0;
                    for (vector<string>::iterator allBowIter = allBows.begin(); *allBowIter != bow; allBowIter++) {
                        position++;
                    }

                    userBowIter = userBowAmount.begin() + position;
                    *userBowIter = *userBowIter + 1;

                    cout << "Added 1 " << bow << " to your Inventory\n" << endl;

                    userMoney = userMoney - bowCost;

                    *bowAmountIter = *bowAmountIter - 1;

                    if (*bowAmountIter < 1) {
                        bow = "Sold Out";
                    }

                    cout << "Level " << traderLevel << " Trader: Anything else I can do for you traveller?" << endl;
                    continue;
                }
                else {
                    cout << "Oops, it looks like you dont have enough funds to purchase that item" << endl;
                    cout << "\nLevel " << traderLevel << " Trader: Anything else I can do for you though traveller?" << endl;
                    continue;
                }
            }
            else if (buyInput == potionVariable) {
            
                if (potion == "Sold Out") {
                    cout << "Level " << traderLevel << " Trader: Sorry traveller, but that item appears to be sold out" << endl;
                    cout << "Anything else I can do for you though?" << endl;
                    continue;
                }
                else if (userMoney >= potionCost) {
                        
                    vector<int>::iterator potionAmountIter;
                    potionAmountIter = traderAmount.begin() + 3;

                    vector<int>::iterator userPotionIter;

                    int position = 0;
                    for (vector<string>::iterator allPotionIter = allPotions.begin(); *allPotionIter != potion; allPotionIter++) {
                        position++;
                    }

                    userPotionIter = userPotionAmount.begin() + position;
                    *userPotionIter = *userPotionIter + 1;

                    cout << "Added 1 " << potion << " to your Inventory\n" << endl;

                    userMoney = userMoney - potionCost;

                    *potionAmountIter = *potionAmountIter - 1;

                    if (*potionAmountIter < 1) {
                        potion = "Sold Out";
                    }

                    cout << "Level " << traderLevel << " Trader: Anything else I can do for you traveller?" << endl;
                    continue;
                }
                else {
                    cout << "Oops, it looks like you dont have enough funds to purchase that item" << endl;
                    cout << "\nLevel " << traderLevel << " Trader: Anything else I can do for you though traveller?" << endl;
                    continue;
                }
            }
            else if (buyInput == endVariable) {
                cout << "\nLevel " << traderLevel << " Trader: Alright, anything else I can do for you traveller?" << endl;
                continue;
            }
        }

        //  Sell page, this whole page is a blur to me, I basically just spaced out while coding this entire section
        else if (tavernInput == 2) {
           cout << "\nUser Inventory:\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;  //  this is a stylistic choice, I'm doing this only for looks

           //   2 vectors used later to read the cost of the user's items and also what items the user has in their inventory to sell
           vector<int> userItemCost;        //  this vector is for holding the value that each item has
           vector<string> userSellItems;    //  this vector is going to hold the names of all the items that the user has

           userItemCost.clear();    //  I'm clearing because if I do not then the program has troubles when trying to sell for a second time. Also, the user could have a different inventory when they go to sell so...

           counter = 0;

            int position = -1;  //  it has to start off as -1 as if I started position off at 0 then the iterator would point to the next object in the vector rather than the one we actually want to point at
            for (vector<int>::iterator userMeleeIter = userMeleeAmount.begin(); userMeleeIter != userMeleeAmount.end(); userMeleeIter++) {  //  big for loop so I'll have to break it down, first we make an iterator called userMeleeIter and start it off at the very beginning of the user's melee weapons (the ones they own), next we want the loop to go until we hit the end of the vector, lastly we make the iterator move to the next position
                position++; //  position keeps track on where the iterator is pointing to so I can make later iterators go to that exact spot
                if (*userMeleeIter == 0) {
                    continue;   //  if the user does not have a single one of the melee weapon the iterator is pointing to, then just go back to the start of the loop
                }
                else {
                    counter++;  //  this counter is going to be used so its easier for the user to pick which items they want to sell

                    vector<string>::iterator meleeNameIter;
                    meleeNameIter = allMeleeWeapons.begin() + position; //  the meleeNameIter is going to look at all the melee weapons in the game to find what the name is for the weapon at x position

                    userSellItems.push_back(*meleeNameIter);    //  we add the name of the weapon that the user has by using the exact value that meleeNameIter is pointing to

                    vector<int>::iterator meleeCostIter;    
                    meleeCostIter = meleeWeaponBasePrice.begin() + position;    //  to find the cost its pretty much the exact same as finding the name, we use the position to look at all the melee weapon costs and the iterator will point directly at the weapon's base price

                    int cost = *meleeCostIter / 2 * inventoryValue; //  the cost for the weapon is based on the difficulty so we multiply the base price by the decimal point/percentage that inventoryValue holds, we also divide the cost by 2 because used items will always cost less than buying new
                    userItemCost.push_back(cost);   //  we add the current cost into the integer vector in the order we find the cost at, that way we know what items cost what

                    cout << counter << ". " << *meleeNameIter << " " << cost << " Coins x" << *userMeleeIter <<endl;    //  lastly, we output counter to show a list counting up so that the user can choose which items they want to sell, then the name of the weapon is displayed, then how much the item is worth, and then we display how many the user has in their inventory
                }
            }

            //  the 3 for loops under this comment are the exact same as the one above it, I'm not commenting all of them if they are exactly the same (minus a few variables)

            position = -1;
            for (vector<int>::iterator userShieldIter = userShieldAmount.begin(); userShieldIter != userShieldAmount.end(); userShieldIter++) {
                position++;
                if (*userShieldIter == 0) {
                    continue;
                }
                else {
                    counter++;

                    vector<string>::iterator shieldNameIter;
                    shieldNameIter = allShields.begin() + position;

                    userSellItems.push_back(*shieldNameIter);

                    vector<int>::iterator shieldCostIter;
                    shieldCostIter = shieldBasePrice.begin() + position;

                    int cost = *shieldCostIter / 2 * inventoryValue;
                    userItemCost.push_back(cost);

                    cout << counter << ". " << *shieldNameIter << " " << cost << " Coins x" << *userShieldIter << endl;
                }
            }

            position = -1;
            for (vector<int>::iterator userBowIter = userBowAmount.begin(); userBowIter != userBowAmount.end(); userBowIter++) {
                position++;
                if (*userBowIter == 0) {
                    continue;
                }
                else {
                    counter++;
                    
                    vector<string>::iterator bowNameIter;
                    bowNameIter = allBows.begin() + position;

                    userSellItems.push_back(*bowNameIter);

                    vector<int>::iterator bowCostIter;
                    bowCostIter = bowBasePrice.begin() + position;

                    int cost = *bowCostIter / 2 * inventoryValue;
                    userItemCost.push_back(cost);

                    cout << counter << ". " << *bowNameIter << " " << cost << " Coins x" << *userBowIter << endl;
               }
            }

            position = -1;
            for (vector<int>::iterator userPotionIter = userPotionAmount.begin(); userPotionIter != userPotionAmount.end(); userPotionIter++) {
                position++;
                if (*userPotionIter == 0) {
                    continue;
                }
                else {
                    counter++; 

                    vector<string>::iterator potionNameIter;
                    potionNameIter = allPotions.begin() + position;

                    userSellItems.push_back(*potionNameIter);

                    vector<int>::iterator potionCostIter;
                    potionCostIter = potionBasePrice.begin() + position;

                    int cost = *potionCostIter / 2 * inventoryValue;
                    userItemCost.push_back(cost);

                    cout << counter << ". " << *potionNameIter << " " << cost << " Coins x" << *userPotionIter << endl;
                }
            }

            //  I make a back button so the user is not stuck in the sell page
            counter++;
            cout << counter << ". Back\n" << endl;  
            int exitVariable = counter;

            attempts = 1;
            do {
                cin >> sellInput;

                if (cin.fail()) {

                   attempts++;

                   if (attempts >= 5) {
                       cout << "okay thats it, I'm done with your shit" << endl;
                       cout << "goodbye" << endl;
                       cout << "\n*Achieved \"The Worst Ending Possible, Cunt\"*" << endl;
                       return 0;
                   }
                   cerr << "Sorry but stop being an idiot and please insert a valid number" << endl;
                   cin.clear();

                    #undef max

                   cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                   continue;
               }

                //  this if statement is so that the user doesn't use an invalid number more than a certain amount of times
                else if (sellInput < 1 || sellInput > counter) {
                   if (attempts == 1) {
                       cout << "you do realize its a number from 1 to " << counter << ", right?\n" << endl;
                       attempts++;
                       continue;
                   }
                   else if (attempts == 2) {
                       cout << "dumbass, what did I just say to you? READ MY WORDS!\n" << endl;
                       attempts++;
                       continue;
                   }
                   else if (attempts == 3) {
                       cout << "okay, are you brain dead or are you just illiterate? IT IS A NUMBER FROM 1 TO " << counter << "!!!\n" << endl;
                       attempts++;
                       continue;
                   }
                   else if (attempts == 4) {
                       cout << "thats it, I'm only giving you one more try, it is a number from 1 to " << counter << ", no higher, no lower\n" << endl;
                       attempts++;
                       continue;
                   }
                   else {
                       cout << "get out\n" << endl;
                       cout << "*Achieved \"getting thrown out of the tavern\"*" << endl;
                       return 0;
                   }
               }
            } while (sellInput < 1 || sellInput > counter);

            //  basically, if the user wants to exit, then the program will go back to the traveler display
            if (sellInput == exitVariable) {
                cout << "\nLevel " << traderLevel << " Trader: Alright, anything else I can do for you traveller?" << endl;
                continue;
            }

            //  if the user doesn't want to exit, and therefor chooses an item to sell, this block of code executes
            else {
                cout << "Are you sure that you want to sell a / an " << userSellItems[sellInput - 1] << " for " << userItemCost[sellInput - 1] << " Coins? (y/n)\n" << endl;    //  just asks the user if they do indeed want to sell the item thay choose by going to the vector with all the users items by name and then using sellInput to find the position (-1 on sellInput though because the vector starts at 0 whereas sellInput starts at 1) and then we display the amount of coins the user would make from the trade by doing the same for the userItemCost vector

                attempts = 1;
                do {
                    cin >> yesNo;

                    if (yesNo == 'y' || yesNo == 'Y') { //  if they choose to sell the item then we need to actually find the item in their inventory and delete it but because I'm using a vector for each type of item the user can has we need to do a bit of digging

                        //  since all these loops are literally the exact same (minus the variables being used), I'm only going to comment on the first one

                        position = 0;
                        for (vector<string>::iterator sellCheckMelee = allMeleeWeapons.begin(); sellCheckMelee != allMeleeWeapons.end(); sellCheckMelee++) {    //  so, first we make a new iterator so that we can go through allMeleeWeapons looking for the item that the user wants to sell, we want to find out what vector that the item is located in so we make the iterator point to the next variable each loop and end the loop when we hit the end of the vector
                            position++; //  add one to position just so we know which object the item is locaded at if it just so happens to be a melee weapon

                            if (*sellCheckMelee == userSellItems[sellInput - 1]) {  //  if we find the same exact item name as the user wants to sell inside of allMeleeWeapons then we of course know that the item is a melee weapon and then we also know its position in all vectors involving it (except for the sell page vectors, those are different)
                                userMeleeAmount[position - 1] = userMeleeAmount[position - 1] - 1;  //  we go to the exact position that the item is located in the user's inventory, then take away 1 from the total count
                                userMoney += userItemCost[sellInput - 1];   //  we then add the appropriate amount of coins that the item was worth to the user's money count

                                break;  //  and of course we then end the loop
                            }
                        }

                        position = 0;
                        for (vector<string>::iterator sellCheckShield = allShields.begin(); sellCheckShield != allShields.end(); sellCheckShield++) {
                            position++;

                            if (*sellCheckShield == userSellItems[sellInput - 1]) {
                                userShieldAmount[position - 1] = userShieldAmount[position - 1] - 1;
                                userMoney += userItemCost[sellInput - 1];

                                break;
                            }
                            else {
                                continue;
                            }
                        }

                        position = 0;
                        for (vector<string>::iterator sellCheckBow = allBows.begin(); sellCheckBow != allBows.end(); sellCheckBow++) {
                            position++;

                            if (*sellCheckBow == userSellItems[sellInput - 1]) {
                                userBowAmount[position - 1] = userBowAmount[position - 1] - 1;
                                userMoney += userItemCost[sellInput - 1];

                                break;
                            }
                            else {
                                continue;
                            }
                        }

                        position = 0;
                        for (vector<string>::iterator sellCheckPotions = allPotions.begin(); sellCheckPotions != allPotions.end(); sellCheckPotions++) {
                            position++;

                            if (*sellCheckPotions == userSellItems[sellInput - 1]) {
                                userPotionAmount[position - 1] = userPotionAmount[position - 1] - 1;
                                userMoney += userItemCost[sellInput - 1];

                                break;
                            }
                            else {
                                continue;
                            }
                        }

                        break;  //  end the entire do loop
                    }
                    else if (yesNo == 'n' || yesNo == 'N') {
                        break;  //  pretty simple, if the user doesn't want to sell the item then we just end the loop
                    }
                    else {
                        attempts++;
                        if (attempts >= 5) {    //  if the user has more than (or equal to) 5 then we just kick them out of the program/tavern
                            cout << "Level " << traderLevel << " Trader: Stop wasting my time traveler" << endl;
                            cout << "Get out of my tavern traveler" << endl;

                            return 0;
                        }
                        else {  //  if the user has less than 5 attempts and they make a mistake then we tell them that its a simple yes or no (y or n)
                            cout << "It's a yes or no question (y/n)" << endl;
                            continue;
                        }
                    }
                } while (yesNo != 'y' && yesNo != 'Y' || yesNo != 'n' && yesNo != 'N');

                cout << "\nLevel " << traderLevel << " Trader: Alright, anything else I can do for you?" << endl;
                continue;   //  we go back to the start of all the traders options
            }
        }

        //  The users inventory
        else if (tavernInput == 3) {
            
            cout << "User Inventory:\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

            int position = -1;  //  I made it easier on me this time by starting position at -1 rather than 0 (like on the sell page)
            for (vector<int>::iterator userMeleeIter = userMeleeAmount.begin(); userMeleeIter != userMeleeAmount.end(); userMeleeIter++) {  //  we're just doing a for loop that goes through every object in the user's melee inventory
                position++; //  well obviously this keeps track on what position the iterator is located at (except that its not even meant for that, its used so that we can display the name of the item by just using position and allMeleeWeapons)
                
                //  if the user doesn't have any of an item in their inventory then obviously we won't display the name of it, so we just go back to the next instance of the loop
                if (*userMeleeIter <= 0) {  
                    continue;
                }

                else {  //  well the user either has or doesn't have the object and I already commented on the user NOT having it so... this block of code:
                    vector<string>::iterator meleeNameIter; //  this itorator is going to be used to point at the exact name the item has in the very next line, so go read that comment, no really idk why you are still reading this comment when you can be reading the nect one, there is no more valid information hidden in this comment somewhere, and even if there was why would you possibly waste your time looking for it? Then you might counter with the question "if there is no more information located in this comment, then why is it still going?" and my answer to that question is as follows: screw you, I can comment however long I want to comment, you don't have control over my actions, I will always and forever have the element of surprise on my side just as that kid on vine had and will always have the power of god and anime on his side, he's so powerful man. You should really just move on to the next comment man, I'm kinda just going to keep going until you leave me alone, I'm just trying to listen to Riot Overkill and comment my code, side note: Riot Overkill is fucking amazing and I wish there were more songs like it, the mix of metal and dubstep is a concept I never would have thought worked together so well. are you seriously still reading this? why though? why would you do that? its not like I'm going to say or do anything that really goes with the program, I'm just ranting and for some reason you decided it would be a good idea to just read along and see how far this rabbit hole goes, well guess what? it goes far, currently we are at 1568 characters in just this one line, now we reached 1622 characters and with every single word I type I add more, and at some point you've decided it would be worthwhile to come along for the journey, the journey being that I wanted to make a comment that just goes on for an extremely long time, so long in fact that I've been typing this for roughly 2 or 3 minutes by now, just stop reading this comment right now, I order you to listen and read the next comment instead, it has much more information located on it than anything this comment has to offer, so why would you possibly want to read literally all of this? I'm still going to keep typing out more on this comment but that don't mean that you should literally read every single bit of it, like at this point I am just ranting about you reading this comment and its not like you are stopping or anything so I see no reason that I should stop either, I am determined to make this comment so rediculously long that you will lose interest and move on to the next line of code and thus comments and you will happily leave this comment here without further notice. This comment is owned by me, the comment writer and thus you by law can't steal it and use it on any other programs, but also thats probably not how the law works so I'm probably just screwed. y'know its kinda weird, the whole fact that you are STILL reading this comment, vet you are not really noticing all the spelling errors I've been making and not really caring to fix, bet you should probably start this comment over and see how many spelling errors I've made, have I really made spelling errors or am I just screwing with you to make you go back to the beginning of the comment and thus start over all the progress you've made thus far? we will never truly know, unless of course you do end up going to the beginning, maybe I'm just typing this code and you've already moved back to the beginning, only time will really tell. while you are at the beginning of this comment you should count every single character this entire line of code has in it, and no cheating!! If you individually count every single character this comment has to offer then that would be a massive waste of time since there really is no payoff to it, I don't have a prize at the end for you or anything, you are basically wasting so much of your time right now that its honestly hillarious to me. this time could be spent on literally anything other than this comment, its really too much effort for you and especially me to be working on, so I am absolutely mind boggled right now on why you would be reading this all the way through despite my warnings. I really don't have anything more interesting to say so its strange to me that you would want to seek out the ending to this comment as its probably going to be extremely anti-climactic and overall just a massive waste of your time, you could be doing literally anything productive right now and you've choosen to read through this entire god damn comment and its really facinating just how bored you must be, is this how you have your fun around here? by reading through this comment completely until I just give up? is it awarding to you? do you feel like this is some sort of reward? are you going to go up to people being like "oh this comment in Nick's code was my favorite part of it, truly a masterpiece in commenting code" I hope that people find this rather disturbing. There was nothing here. No choice to make, No path to follow, Just an empty broom closet. No reason to still be here. It was baffling that Stanley was still just sitting in the broom closet. He wasn't even doing anything, At least if there were something to interact with, he'd be justified in some way. As it is, he's literally just standing there, doing sweet FA. you like my Stanley Parable tie in there? I worked really hard on that you know, I also worked on a text based version of it on an game or an app called "One Synth" which at the time of typing this comment out has about 137	Current Subscribers to it, so I'd say that was time well spent, it is afterall one of my favorite game experiences and if you have never played it before I highly recommend that you pick it up at some point and try it for yourself. At this point I'm really trying to test out how long Visual Studio will let me write on one line of code and it appears to be near endless, but my insanity knows no bounds! I am afterall the one who commented all the way up to this point aren't I? So.... why not just keep going, I mean you obviously don't seem like you are going to stop readding this one comment since you've already wasted countless amounts of time reading it, and I obviously won't stop since I've just been going and going and going on and on about stuff so I could probably get keep this code going on forever, if I felt like it that is, I don't know when I'll lose interest in this one comment and move onto something actually important, like assignment 2, but I'm still here talking about doing it rather than actually doing it that maybe I should just give up and choose to work on it, but I am dedicated to this joke right now so I guess I'll just keep going then. Unless I don't, thats also a possibility. But I'm bored now so I guess you've won, you have made it to the end of the code, you gain no rewards or anything, I hope you are happy you wasted your time.
                    meleeNameIter = allMeleeWeapons.begin() + position; //  so, as the last comment told you, the meleeNameIter is used here to first start at the beginning of all the melee weapons in the entire game's titles, and then using the position we find the one that is located inside the player's inventory
                    
                    cout << *userMeleeIter << "x " << *meleeNameIter << endl;   //  using the userMeleeIter we just output the number of the item located inside the player's inventory, then we display the name of that item
                }
            }

            position = -1;
            for (vector<int>::iterator userShieldIter = userShieldAmount.begin(); userShieldIter != userShieldAmount.end(); userShieldIter++) {
                position++;
                if (*userShieldIter == 0) {
                    continue;
                }
                else {
                    vector<string>::iterator shieldNameIter;
                    shieldNameIter = allShields.begin() + position;

                    cout << *userShieldIter << "x " << *shieldNameIter << endl;
                }
            }

            position = -1;
            for (vector<int>::iterator userBowIter = userBowAmount.begin(); userBowIter != userBowAmount.end(); userBowIter++) {
                position++;
                if (*userBowIter == 0) {
                    continue;
                }
                else {
                    vector<string>::iterator bowNameIter;
                    bowNameIter = allBows.begin() + position;

                    cout << *userBowIter << "x " << *bowNameIter << endl;
                }
            }

            position = -1;
            for (vector<int>::iterator userPotionIter = userPotionAmount.begin(); userPotionIter != userPotionAmount.end(); userPotionIter++) {
                position++;
                if (*userPotionIter == 0) {
                    continue;
                }
                else {
                    vector<string>::iterator potionNameIter;
                    potionNameIter = allPotions.begin() + position;

                    cout << *userPotionIter << "x " << *potionNameIter << endl;
                }
            }

            cout << "\n" << userMoney << " Coins" << endl;

            cout << "\nLevel " << traderLevel << " Trader: Anything I can do for you?" << endl;
        }

        //  Exit, it just breaks / ends the loop
        else if (tavernInput == 4) {
        break;
        }

        //  If the user somehow gets past my failsafes then I just throw them out of my program, like a true programmer would
        else {
            cout << "I don't even know how you did it, but you broke the game, congrats, you are officially a professional asshole" << endl;
            cout << "just get out of my game, I don't want you here if this is what you are going to be doing" << endl;
            cout << "\n*Achieved \"Fuck you, you are not even getting an achivement for this exploit\"" << endl;
            return 0;
        }
    } while (tavernInput != 4);
}

//  to make every item available set the max levels to 0, to make every item unavailable then insert the word NULL
void itemChooser(int traderLevel, string& potion, string& melee, string& shield, string& bow) {

    bool potionsYesNo, bowsYesNo, shieldsYesNo, swordsYesNo;

    if (traderLevel >= 1 && traderLevel <=10) {
        potionsYesNo = true;
        bowsYesNo = false;
        shieldsYesNo = false;
        swordsYesNo = false;
    }
    else if (traderLevel > 10 && traderLevel <= 20) {
        potionsYesNo = true;
        bowsYesNo = false;
        shieldsYesNo = true;
        swordsYesNo = false;
    }
    else if (traderLevel > 20 && traderLevel <=30) {
        potionsYesNo = true;
        bowsYesNo = false;
        shieldsYesNo = true;
        swordsYesNo = true;
    }
    else {
        potionsYesNo = true;
        bowsYesNo = true;
        shieldsYesNo = true;
        swordsYesNo = true;
    }

    srand(time(NULL));

    vector<string>::iterator iterPotions, iterShields, iterBows, iterMelee;

    //  yes, all of the if statements are the exact same but with different variables

    if (potionsYesNo == true) { //  I'm pretty sure that potionsYesNo is always going to be true, but if I want to make a complex trading system at some point I'm going to kepp this if statement a thing

        int potionsLevel; 

        if (traderLevel <= 20) {
            potionsLevel = rand() % (allPotions.size() / 2);    //  potionsLevel is used to find which potion is going to be used for trading, based on the level of the trader we are going to make half or all potions available, in this very line its halved since we want only the base potions (minor healing and mana) available until after level 20

            iterPotions = allPotions.begin() + potionsLevel;    //  we then make the iterator for all potions point to the random number we generated, in this case it will either be a 1 or a 2 since right now we only have 4 total potions in the game
            potion = *iterPotions;  //  reference variable potion is equal to the potion name that the iterator is pointing at
        }
        else {
            potionsLevel = rand() % allPotions.size();  //  if the trader's level is over 20 then all potions will become available, of course if we wanted we could easily make it so that each potion unlocks at a certain point, but for this demo we are spliting it into halves

            iterPotions = allPotions.begin() + potionsLevel;
            potion = *iterPotions;
        }
    }
    else {
        potion = "";    //  is potionsYesNo were to be false then we make the potion reference variable equal to just "" since I have code written for that in the main function
    }

    if (bowsYesNo == true) {

        int bowLevel;

        if (traderLevel < 40) {
            bowLevel = rand() % (allBows.size() / 2);

            iterBows = allBows.begin() + bowLevel;
            bow = *iterBows;
        }
        else {
            bowLevel = rand() % allBows.size();

            iterBows = allBows.begin() + bowLevel;
            bow = *iterBows;
        }
    }
    else {
        bow = "";
    }

    if (shieldsYesNo == true) {

        int shieldLevel;

        if (traderLevel <= 20) {
            shieldLevel = rand() % (allShields.size() / 2);

            iterShields = allShields.begin() + shieldLevel;
            shield = *iterShields;
        }
        else {
            shieldLevel = rand() % allShields.size();

            iterShields = allShields.begin() + shieldLevel;
            shield = *iterShields;
        }
    }
    else {
        shield = "";
    }

    if (swordsYesNo == true) {

        int meleeWeaponLevel;

        if (traderLevel <= 30) {
            meleeWeaponLevel = rand() % (allMeleeWeapons.size() / 2);

            iterMelee = allMeleeWeapons.begin() + meleeWeaponLevel;
            melee = *iterMelee;
        }
        else {
            meleeWeaponLevel = rand() % allMeleeWeapons.size();

            iterMelee = allMeleeWeapons.begin() + meleeWeaponLevel;
            melee = *iterMelee;
        }
    } 
    else {
        melee = "";
    }
}

//  end of program demo, hope you learned something, or not, I don't really care actually.