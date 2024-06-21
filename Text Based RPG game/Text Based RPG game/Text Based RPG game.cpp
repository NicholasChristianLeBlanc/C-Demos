//  What my plan is: I want to make a text based game similar to Undertale, you can either fight the enemies/monsters or you can talk to them and spare them, you can also open your inventory to hel during combat, but you do lose a move

//  Story Ideas:
    //  Your character is having a nightmare, and the only way to get out of the nightmare is to defeat the final boss
        //  if you spare every enemy then you will befriend the final boss and your character will not fear going back to sleep again, in fact they will look forward to seeing their new friends again
        //  if you decide to kill every enemy you face then your character will have conqured their fear, but they will have to go through more Nightmares in the future
        //  if your character dies after every battle then you will be trapped in the Nightmare realm, eternal fear will conquer you and you will never get back home in the real world

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  So, since I want a game similar to Undertale I'm going to make a class for combat that will have all the actions the player can do during combat:
    //  Attack
    //  Talk
    //  Spare
    //  Inventory

//  what Attack should do:
    //  Attack is going to use a randomizer from 1 to 100
        //  if randomizer is less than or equal to 20 then your attack is going to miss
            //  you (the user) miss your attack and thus miss your turn, no damage is dealt to the enemy
        //  if randomizer is greater than 20 then your attack is going to land
            //  so the attack lands, do a minus health from the creature class that I'm going to make later on that contains health as one of its variables
        //  if randomizer is greater than 90 then you are going to land a critical hit
            //  you get a critical hit, I want the critical hit to be 1.5x the power of a regular hit

//  what Talk should do:
    //  Show multiple options to talk to the "enemy" i'll just go with 2 options for now (a wrong option and a right option)
        //  if you choose a wrong option 
            //  you will be hit for the enemy's full damage potential (user health - creature damage)
        //  if you choose a correct option 
            //  the enemy will deal only 75% of their damage
            //  a counter for how many correct options required to spare will go down
                //  if the counter reaches 0 then the spare option will work
                    //  also tell the user they can now spare

//  Spare:
    //  if the spare option is not available:
        //  inform the player that they cannot spare yet
        //  display the combat options again
    //  if the user is able to spare:
        //  the monster will say something about being spared
        //  the battle will end and the creature will still be alive
            //  the amount of attempts to spare the monster will go down for the next fight with them

//  Inventory:
    //  Display the items that player has that do different things:
        //  Healing items:
            //  will add to the player's health up to max health (depending on the item)
        //  More damage items:
            //  will add to the user's base damage (for x amount of moves)

//  after each move:
    //  Enemy will attack you and take away player health
    //  maybe the enemy will say something

//  class for the main character
    //  strength - determine damage, will be changed by the armor you have on
    //  agility - determine chance to dodge/hit, determined by how heavy the weapon is (heavier = harder to swing, easier to dodge, but deals more damage. light = easier to swing, harder to dodge, but deals less damage)
    //  attack damage, will be changed by the weapon
    //  current health
    //  max health

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  Merchant system
    //  after each quest the merchent will get a new selection of items
        //  randomizer to get a random selection    
            //  randomizer used so that an iterator will point at spaces in a vector that has all the weapons, shields, potions, etc in the entire game
                //  each type will get its own vector that holds all the items of that type (weapon, shield, potions)
                //  vector that holds a counter of how many of each item the merchant has
        //  1 weapon, 1 shield/armor item and 2 different healing items (healing items will have infinite stock, but you can only use one healing item per turn)
    //  public void display all the items the merchant has
    //  public void randomize stock so that we can have a different stock after each quest

//  display the items that the merchant has
    //  make an iterator that will point at the names for all the merchant's items
        //  find the number of items the merchant has in each category
            //  point the iterator at the name for each item in each category (weapons, shied and for potions it will point twice)
                
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//  Main Class:
    //  Start off with 3 options:
        //  Shop (3 options)
            //  Buy:
                //  bring up a buy page of items the user can purchase to help them on their quests
                    //  let them choose what they want to buy
                        //  whichever item they choose ask the player if they are sure they want to buy
                            //  if no then return to the buy page
                            // if yes then add the item to the user's inventory and take away the appropriate amount of money from the user's bank
                                //  after this is done go back to the buy page
                    //  if the user chooses to exit then go back to the shop page       
            //  Sell :
                //  bring up the user's inventory with the value of each item
                    //  allow the user to choose an item they want to sell
                        //  when the user chooses an item ask them if they really want to sell the item or not
                            //  if yes then remove the item from the user's inventory and add the appropriate money to the user's bank
                    //  let the user exit back to the shop page if they do not wish to sell any items
            //  Exit/Back:
                //  exit out to the main options page
        //  Quest:
            //  Face off against 1 of 3 enemies
                //  Randomizer that chooses a number from 1 to 3 
                    //  depending on the enemy there will be 4 things that would change:
                        //  Damage they deal
                            //  the damage will be calculated by taking the base damage then multiplied by the attack strength (75% damage, 100% damage, 125% damage)
                        //  Health
                        //  Dialogue
                        //  amount of talking needed to spare them
            //  Boss fight / Final quest (Final Boss Name: Nightmare)
                //  dialogue: 
                    //  if you spared everything: 
                        //  "You may have talked your way out of every last battle, but I won't be so easy on you. For I am the ruler of this realm!!"
                    //  if you killed everything up to this point:
                        //  "Everything you have faced up to this point will look like a cakewalk compared to me. Be ready to perish in my wake"
                //  if you died to every enemy then you will not be able to fight the boss, instead the boss will one shot you and the game will end, so to break it down:
                    //  if you died every game
                        //  boss damage equals the player's max health, or I could go with 9999
                            //  ending dialogue on how you are trapped in the Nightmare realm forever
                                //  end game
        //  Exit Game
            //  return 0;

#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <thread>

using namespace std;

int rollDice(int sides = 6, int number = 1);

vector<string> allWeapons = {
    "Frail Stick",
    "Bone Trumpet",
    "Web Harp",
    "Mirror"
};

vector<int> weaponDamage = {
    0,
    3,
    5,
    8
};

vector<int> weaponBaseValue = {
    3,
    6,
    18,
    25
};

vector<int> userWeaponAmount = {
    1,
    0,
    0,
    0
};

vector<string> allArmor = {
    "Used Bandage",
    "Leather Jacket",
    "Tapdancing Shoes",
    "Confidence Boosting High Heels"
};

vector<int> armorDefence = {
    0,
    4,
    8,
    13
};

vector<int> armorBasePrice = {
    2,
    12,
    20,
    28
};

vector<int> userArmorAmount = {
    1,
    0,
    0,
    0
};

vector<string> allHealingItems = {
    "Unused Bandage",
    "Spider Donut",
    "Instant Noodles",
    "Greasy Burger",
    "Spaghetti"
};

vector<int> healingStats = {
    5,
    15,
    35,
    50,
    80
};

vector<int> healingBaseCost = {
    3,
    5,
    7,
    9,
    30
};

vector<int> userHealingItems = {
    1,
    0,
    0,
    0,
    0
};

vector<string> userEquipped = {
    "Frail Stick",  //  weapon
    "Used Bandage"  //  armor
};

class Protag {
private:
    string name;
    int defence;            //  determined by the armor that the user is wearing, will determine the amount of damage that the protag will take
    int baseDefence;
    int strength;           //  determined by the weapon that the user has equipped, will effect the amount of damage the protag will deal
    int baseStrength;
    int chance;             //  determines chance to hit the enemy
    int healthPoints;       //  will autimatically replenish after a quest/battle
    int healthPointsMax;    //  only goes up if you attack the enemy and gain xp (but I'm not doing an xp system so I'll just increase the number after each battle)
    int money = 0;
public:
    Protag(string n, int def, int str, int cth, int hp);

    string GetName();

    void ShowInventory();
    void InventorySellDisplay();

    void SetDefence(int def);
    void SetStrength(int weapon);
    void SetChance(int cth);
    void TakeDamage(int damage);
    void AddHealth(int healingPotion);
    void SetHealthPointsMax(int newMax);
    void MinusMoney(int cost);
    void AddMoney(int gained);

    int GetDefence();
    int GetStrength();
    int GetChance();
    int GetHealthPoints();
    int GetHealthPointsMax();
    int GetMoney();
};

Protag::Protag(string n, int def, int str, int cth, int hp) :
    name(n),
    baseDefence(def),           //  def - defense  
    defence(def),
    baseStrength(str),          //  str - strength
    strength(str),
    chance(cth),            //  cth - chance to hit
    healthPoints(hp),       //  hp - health / hit points
    healthPointsMax(hp)     
{}

string Protag::GetName() {
    return name;
}

vector<string> userDisplayedItems;
vector<int> userDisplayedItemsAmount;

int counter;

void Protag::ShowInventory() {

    userDisplayedItems.clear();
    userDisplayedItemsAmount.clear();

    cout << "Equipped Weapon: " << userEquipped[0] << endl;
    cout << "Equipped Armor: " << userEquipped[1] << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Inventory Items:" << endl;

    int weaponPosition, armorPosition, healthPosition;
    counter = 0;
    vector<string>::iterator allItemsIter;

    for (weaponPosition = 0; weaponPosition < allWeapons.size(); weaponPosition++) {
        if (userWeaponAmount[weaponPosition] < 1) {
            continue;
        }
        else {
            if (userEquipped[0] == allWeapons[weaponPosition]) {
                continue;
            }
            else {
                allItemsIter = allWeapons.begin() + weaponPosition;

                counter++;

                userDisplayedItems.push_back(*allItemsIter);
                userDisplayedItemsAmount.push_back(userWeaponAmount[weaponPosition]);

                cout << counter << ". " << *allItemsIter << " - " << weaponDamage[weaponPosition] << " ATK" << endl;
            }
        }
    }

    for (armorPosition = 0; armorPosition < allArmor.size(); armorPosition++) {
        if (userArmorAmount[armorPosition] < 1) {
            continue;
        }
        else {
            if (userEquipped[1] == allArmor[armorPosition]) {
                continue;
            }
            else {
                allItemsIter = allArmor.begin() + armorPosition;

                counter++;

                userDisplayedItems.push_back(*allItemsIter);
                userDisplayedItemsAmount.push_back(userArmorAmount[armorPosition]);

                cout << counter << ". " << *allItemsIter << " - " << armorDefence[armorPosition] << " DEF" << endl;
            }
        }
    }
    
    for (healthPosition = 0; healthPosition < allHealingItems.size(); healthPosition++) {
        if (userHealingItems[healthPosition] < 1) {
            continue;
        }
        else {
            allItemsIter = allHealingItems.begin() + healthPosition;

            counter++;

            userDisplayedItems.push_back(*allItemsIter);
            userDisplayedItemsAmount.push_back(userHealingItems[healthPosition]);

            cout << counter << ". " << *allItemsIter << " - " << healingStats[healthPosition] << " HP" << " x" << userHealingItems[healthPosition] << endl;
        }
    }
}

vector<int> userInventoryWorth;

vector<int>::iterator weaponDamageIter;
vector<int>::iterator armorDefenceIter;

void Protag::InventorySellDisplay() {

    int weaponPosition, armorPosition, healthPosition;

    userDisplayedItems.clear();
    userDisplayedItemsAmount.clear();
    userInventoryWorth.clear();

    for (weaponPosition = 0; weaponPosition < allWeapons.size(); weaponPosition++) {
        if (userEquipped[0] == allWeapons[weaponPosition]) {

            cout << "Equipped Weapon: " << userEquipped[0] << " - " << weaponDamage[weaponPosition] << " ATK" << endl;

            break;
        }
    }

    for (armorPosition = 0; armorPosition < allArmor.size(); armorPosition++) {
        if (userEquipped[1] == allArmor[armorPosition]) {

            cout << "Equipped Armor: " << userEquipped[1] << " - " << armorDefence[armorPosition] << " DEF" << endl;

            break;
        }
    }

    cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Inventory Items:" << endl;

    counter = 0;
    vector<string>::iterator allItemsIter;

    for (weaponPosition = 0; weaponPosition < allWeapons.size(); weaponPosition++) {
        if (userWeaponAmount[weaponPosition] < 1) {
            continue;
        }
        else {
            if (userEquipped[0] == allWeapons[weaponPosition]) {
                continue;
            }
            else {
                allItemsIter = allWeapons.begin() + weaponPosition;

                userInventoryWorth.push_back((int)(weaponBaseValue[weaponPosition] / 1.5));

                counter++;

                userDisplayedItems.push_back(*allItemsIter);
                userDisplayedItemsAmount.push_back(userWeaponAmount[weaponPosition]);

                cout << counter << ". " << *allItemsIter << " - " << weaponDamage[weaponPosition] << " ATK" <<  " -> " << (int)(weaponBaseValue[weaponPosition] / 1.5) << " Coins" << endl;
            }
        }
    }

    for (armorPosition = 0; armorPosition < allArmor.size(); armorPosition++) {
        if (userArmorAmount[armorPosition] < 1) {
            continue;
        }
        else {
            if (userEquipped[1] == allArmor[armorPosition]) {
                continue;
            }
            else {
                allItemsIter = allArmor.begin() + armorPosition;

                userInventoryWorth.push_back((int)(armorBasePrice[armorPosition] / 1.5));

                counter++;

                userDisplayedItems.push_back(*allItemsIter);
                userDisplayedItemsAmount.push_back(userArmorAmount[armorPosition]);

                cout << counter << ". " << *allItemsIter << " - " << armorDefence[armorPosition] << " DEF" << " -> " << (int)(armorBasePrice[armorPosition] / 1.5) << " Coins" << endl;
            }
        }
    }

    for (healthPosition = 0; healthPosition < allHealingItems.size(); healthPosition++) {
        if (userHealingItems[healthPosition] < 1) {
            continue;
        }
        else {
            allItemsIter = allHealingItems.begin() + healthPosition;

            userInventoryWorth.push_back((int)(healingBaseCost[healthPosition] / 1.5));

            counter++;

            userDisplayedItems.push_back(*allItemsIter);
            userDisplayedItemsAmount.push_back(userHealingItems[healthPosition]);

            cout << counter << ". " << *allItemsIter << " x" << userHealingItems[healthPosition] << " -> " << (int)(healingBaseCost[healthPosition] / 1.5) << " Coins" << endl;
        }
    }
}

void Protag::SetDefence(int armor) {
    defence = baseDefence + armor;
}

int Protag::GetDefence() {
    return defence;
}

void Protag::SetStrength(int weapon) {
    strength = baseStrength + weapon;
}

int Protag::GetStrength() {
    return strength;
}

void Protag::SetChance(int cth) {
    chance = cth;
}

int Protag::GetChance() {
    return chance;
}

void Protag::TakeDamage(int damage) {
    healthPoints -= damage;
}

void Protag::AddHealth(int healingPotion) {
    healthPoints += healingPotion;

    if (healthPoints >= healthPointsMax) {
        healthPoints = healthPointsMax;

        cout << "Your health has been healed fully\n" << endl;
    }
    else {
        cout << "You have been healed for " << healingPotion << "hp\n" << endl;
    }
}

int Protag::GetHealthPoints() {
    return healthPoints;
}

void Protag::SetHealthPointsMax(int newMax) {
    healthPointsMax = newMax;
}

int Protag::GetHealthPointsMax() {
    return healthPointsMax;
}

void Protag::MinusMoney(int cost) {
    money -= cost;
}

void Protag::AddMoney(int gained) {
    money += gained;

    cout << "You have gained " << gained << " coins!" << endl;
}

int Protag::GetMoney() {
    return money;
}

class Creature {
private:
    string name;
    int strength;           //  amount of base damage they deal
    int defaultStrength;
    int chance;             //  chance for their hit to land
    int defense;
    int healthPoints;       
    int healthPointsMax;    
    bool spareable = false;
public:
    Creature(string n, int str, int cth, int def, int hp);

    string GetName();

    void TakeDamage(int damage);

    void SetSpare(bool spareTF);
    void SetStrength(int str);
    void SetChance(int cth);

    int GetStrength();
    int GetDefaultStrength();
    int GetDefense();
    int GetHealthPoints();
    int GetHealthPointsMax();
    bool GetSpare();
};

Creature::Creature(string n, int str, int cth, int def, int hp) :
    name(n),
    strength(str),
    defaultStrength(str),
    chance(cth),
    defense(def),
    healthPoints(hp),
    healthPointsMax(hp)
{}

string Creature::GetName() {
    return name;
}

void Creature::SetStrength(int str) {
    strength = str;
}

int Creature::GetStrength() {
    return strength;
}

int Creature::GetDefaultStrength() {
    return defaultStrength;
}

void Creature::SetChance(int cth) {
    chance = cth;
}

int Creature::GetDefense() {
    return defense;
}

void Creature::TakeDamage(int damage = 1) { 
    healthPoints -= damage;
}

int Creature::GetHealthPoints() {
    return healthPoints;
}

int Creature::GetHealthPointsMax() {
    return healthPointsMax;
}

void Creature::SetSpare(bool spareTF = false) {
    spareable = spareTF;
}

bool Creature::GetSpare() {
    return spareable;
}

class Combat {
public:
    void Attack(Protag &main, Creature &enemy);
    void Talk(Creature enemy);
    //  since inventory can be opened in 3 different places I'm not going to make a void just for it in combat
    void Mercy(Creature enemy);
};

vector<string>::iterator allWeaponsIter = allWeapons.begin();
vector<int>::iterator weaponStatsIter;
void Combat::Attack(Protag &main, Creature &enemy) {

    int position = -1;

    for (allWeaponsIter; allWeaponsIter != allWeapons.end(); allWeaponsIter++) {
        position++;

        if (userEquipped[0] == *allWeaponsIter) {
            weaponStatsIter = weaponDamage.begin() + position;
        }
        else {
            continue;
        }
    }

    int attackRoll = rollDice(6, 1) + main.GetChance();
    int defenseRoll = rollDice(2, 1) + enemy.GetDefense();

    if (attackRoll > defenseRoll) {
        cout << "Hit for: ";

        int damage;
        damage = rollDice(6, 1) + main.GetStrength() + *weaponStatsIter;

        cout << damage << " damage!" << endl;

        enemy.TakeDamage(damage);
    }
    else {
        cout << "Oh no, you missed!" << endl;
    }
}

vector<string> possibleOptions = {
    "Nothing"
};

vector<string>::iterator possibleOptionsIter = possibleOptions.begin();

void Combat::Talk(Creature enemy) {

    possibleOptions.clear();

    cout << "What would you like to do?" << endl;

    if (enemy.GetName() == "Spooky Scary Skeleton") {
        cout << "1. Play xylophone \n2. Do a spooky dance \n3. Tell a joke \n4. Make Spaghetti" << endl;

        possibleOptions.push_back("Play xylophone");
        possibleOptions.push_back("Do a spooky dance"); //  refers to the spooky scary skeletons dance / song
        possibleOptions.push_back("Tell a joke");       //  you sure know how to tickle somebody's funnybone
        possibleOptions.push_back("Make Spaghetti");    //  undertale reference / bone appetit
    }
    else if (enemy.GetName() == "Tapdancing Spider") {
        cout << "1. Challenge \n2. Dance \n3. Show Off" << endl;

        possibleOptions.push_back("Challenge");
        possibleOptions.push_back("Dance");
        possibleOptions.push_back("Show Off");
    }
    else if (enemy.GetName() == "Shy Ghost") {
        cout << "1. Compliment \n2. Bully" << endl;

        possibleOptions.push_back("Compliment");
        possibleOptions.push_back("Bully");
    }
    else if (enemy.GetName() == "NIGHTMARE The Destroyer Of Dreams") {
        cout << "1. Distract \n2. Plead for mercy" << endl;

        possibleOptions.push_back("Distract");
        possibleOptions.push_back("Plead for mercy");
    }
}

//  if I really was making a game like undertale I would make different enemies for different areas, but I'm not going that complex right now
//  Creature(name, strength, chance to hit, defense, health points);
vector<Creature> allEnemies = {
    Creature("Spooky Scary Skeleton", 3, 2, 3, 15),
    Creature("Tapdancing Spider", 2, 2, 2, 12),
    Creature("Shy Ghost", 2, 1, 1, 23)
};

vector<Creature> allBosses = {
    Creature("NIGHTMARE The Destroyer Of Dreams", 5, 3, 5, 35)
};

void Combat::Mercy(Creature enemy) {
    if (enemy.GetSpare() == false) {
        if (enemy.GetName() == "Spooky Scary Skeleton") {
            cout << enemy.GetName() << ": why would you possibly want to run when we're having so much fun? \n" << endl;
        }
        else if (enemy.GetName() == "Tapdancing Spider") {
            cout << enemy.GetName() << ": I thought you enjoyed my dancing ;-; \n" << endl;
        }
        else if (enemy.GetName() == "Shy Ghost") {
            if (*possibleOptionsIter == "Compliment") {
                cout << enemy.GetName() << ": ooh, do you dislike me that much? I thought that you were nice \n" << endl;
            }
            else if (*possibleOptionsIter == "Bully") {
                cout << enemy.GetName() << ": first you bully me then you try to run away? you really are a jerk aren't you? \n" << endl;
            }
        }
    }
    else {
        if (enemy.GetName() == "Spooky Scary Skeleton") {
            cout << enemy.GetName() << ": thanks, that was a lot of fun! I could tell you were good I could feel it in my bones! \n" << endl;
        }
        else if (enemy.GetName() == "Tapdancing Spider") {
            cout << enemy.GetName() << ": that was absolutely amazing! I might just have to friend you on the web sometime \n" << endl;
        }
        else if (enemy.GetName() == "Shy Ghost") {
            cout << enemy.GetName() << ": you know, i really did have fun \n" << endl;
        }
    }
}

vector<string> merchantInventory;

class Merchant {

private:
    vector<string> inventory;
    int level;
    string name;
public:
    Merchant(string n, int lvl);

    void refreshInventory();
    void removeItem(int number);
    void displayInventory();

    int GetLevel();
};

Merchant::Merchant(string n, int lvl = 1) :
    name(n),
    level(lvl) 
{}

vector<int> merchantItemCost = {
    0,
    0,
    0,
    0
};

int merchantWeaponDamage = 0, merchantArmorDefence = 0, merchantHealthBoost1 = 0, merchantHealthBoost2 = 0;

void Merchant::refreshInventory() {

    merchantInventory.clear();

    int randomizer;

    if (level <= 12) {
        randomizer = rand() % (allWeapons.size() / 2);
    }
    else {
        randomizer = rand() % allWeapons.size();
    }

    merchantInventory.push_back(allWeapons[randomizer]);
    merchantItemCost[0] = weaponBaseValue[randomizer];
    merchantWeaponDamage = weaponDamage[randomizer];

    if (level <= 12) {
        randomizer = rand() % (allArmor.size() / 2);
    }
    else {
        randomizer = rand() % allArmor.size();
    }

    merchantInventory.push_back(allArmor[randomizer]);
    merchantItemCost[1] = armorBasePrice[randomizer];
    merchantArmorDefence = armorDefence[randomizer];

    if (level <= 12) {
        randomizer = rand() % ((allHealingItems.size() -1) / 2);
    }
    else {
        randomizer = rand() % (allHealingItems.size() - 1);
    }

    merchantInventory.push_back(allHealingItems[randomizer]);
    merchantItemCost[2] = healingBaseCost[randomizer];
    merchantHealthBoost1 = healingStats[randomizer];

    if (level <= 12) {
        randomizer = rand() % ((allHealingItems.size() - 1) / 2);
    }
    else {
        randomizer = rand() % (allHealingItems.size() - 1);
    }

    merchantInventory.push_back(allHealingItems[randomizer]);
    merchantItemCost[3] = healingBaseCost[randomizer];
    merchantHealthBoost2 = healingStats[randomizer];
}

void Merchant::displayInventory() {

    cout << name << "'s Inventory:" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;

    int position = 0;

    for (vector<string>::iterator merchantDisplayer = merchantInventory.begin(); merchantDisplayer != merchantInventory.end(); merchantDisplayer++) {
        position++;

        if (position == 1) {
            cout << position << ". " << *merchantDisplayer << " - " << merchantWeaponDamage << " ATK -> " << merchantItemCost[position - 1] << " Coins" << endl;
        }
        else if (position == 2) {
            cout << position << ". " << *merchantDisplayer << " - " << merchantArmorDefence << " DEF -> " << merchantItemCost[position - 1] << " Coins" << endl;
        }
        else if (position == 3) {
            cout << position << ". " << *merchantDisplayer << " - " << merchantHealthBoost1 << " HP -> " << merchantItemCost[position - 1] << " Coins" << endl;
        }
        else {
            cout << position << ". " << *merchantDisplayer << " - " << merchantHealthBoost2 << " HP -> " << merchantItemCost[position - 1] << " Coins" << endl;
        }
    }
}

void Merchant::removeItem(int number) {
    merchantInventory[number] = "Sold Out";
}

int Merchant::GetLevel() {
    return level;
}

Creature randomEnemy(bool bossYesNo);

Combat combat;

int merchantLevel = rand() % 24 + 1;
Merchant tavern("Daydream Tavern", merchantLevel);

int main() {

    srand((unsigned)time(NULL));

    string name = "";
    char yesNo;
    int selfEsteem = 0; //  this variable is going to be used later on for a joke
    int counter = 0;
    bool tryAgain = true, tavernRefresh = false;

    tavern.refreshInventory();

    do {
        if (tavernRefresh == true) {
            tavern.refreshInventory();
            tavernRefresh = false;
        }

        cout << "Please insert your name: " << endl;

        cin >> name;

        if (name.size() < 3 || name.size() > 15) {
            cout << "\nYour name can only be between 3 and 15 characters long, please try again\n" << endl;

            continue;
        }

        cout << endl;

        do {

            cout << "Are you sure that you want " << name << " to be your name? (y/n)" << endl;

            cin >> yesNo;

            if (yesNo == 'Y' || yesNo == 'y') {

                if (counter > 1) {
                    cout << "\nthat took you " << counter << " attempts to get right" << endl;
                }

                tryAgain = false;

                cout << "\nVery well, welcome " << name;

                this_thread::sleep_for(1s);
                cout << " TO";

                this_thread::sleep_for(0.1s);
                cout << " YOUR";

                this_thread::sleep_for(0.1s);
                cout << " GREATEST";

                this_thread::sleep_for(0.1s);
                cout << " NIGHTMARE!";

                this_thread::sleep_for(0.25s);
                cout << "\rVery well, welcome " << name << "                            " << endl;

                break;
            }
            else if (yesNo == 'n' || yesNo == 'N') {
                cout << "\nAlrighty then, ";

                tryAgain = true;

                break;
            }
            else {
                counter++;
                
                switch (counter) {
                case 1: {
                    cout << "\nNope, thats not a y or an n, try again" << endl;
                    break;
                }
                case 2: {
                    cout << "\nAgain, thats not a y or an n" << endl;
                    break;
                }
                case 3: {
                    cout << "\nAre you reading these? Because that is STILL not a y or an n" << endl;
                    break;
                }
                case 4: {
                    cout << "\nOkay, maybe you just have trouble reading or something like that";
                    this_thread::sleep_for(0.5s);
                    cout << " IT";
                    this_thread::sleep_for(0.5s);
                    cout << " IS";
                    this_thread::sleep_for(0.5s);
                    cout << " EITHER";
                    this_thread::sleep_for(0.5s);
                    cout << " Y";
                    this_thread::sleep_for(0.5s);
                    cout << " OR";
                    this_thread::sleep_for(0.5s);
                    cout << " N" << endl;
                    this_thread::sleep_for(0.5s);
                    break;
                }
                case 5: {
                    cout << "\nI hate you, just type the proper letters!!!" << endl;
                    break;
                }
                case 6: {
                    cout << "\nBet you think it's SO funny just putting in the wrong inputs every single time, just give me a y or an n already" << endl;
                    break;
                }
                case 7: {
                    cout << "\nNo";
                    this_thread::sleep_for(0.5s);
                    cout << " just";
                    this_thread::sleep_for(0.5s);
                    cout << " no" << endl;
                    this_thread::sleep_for(0.5s);
                    break;
                }
                  defaut: {
                      cout << "\nI'm done with you" << endl;
                      break;
                  }
                }
                
                continue;
            }
        } while (true);

        if (tryAgain == true) {
            continue;
        }
        else {
            break;
        }
    } while (true);

    //  name, defense, strength, chance to hit, health points)
    Protag mainCharacter(name, 2, 2, 1, 20);

    int input, combatInput, tavernInput, inventoryInput;
    int battlesCompleted = 0, attacksWon = 0, sparesCompleted = 0;
    
    Creature enemy("" , 0, 0, 0, 0);

    cout << "\nYou wake up in a panic" << endl;
    this_thread::sleep_for(2s);
    cout << "You aren't sleeping in the same bed you were in last night, and this definately doesn't look like your room" << endl;
    this_thread::sleep_for(2s);
    cout << "You get up out of bed and get dressed, luckily there is already clothing on top of the dresser waiting for you" << endl;
    this_thread::sleep_for(2s);
    cout << "After getting dressed you open the door and into a";
    this_thread::sleep_for(0.5s);
    cout << ".";
    this_thread::sleep_for(0.5s);
    cout << ".";
    this_thread::sleep_for(0.5s);
    cout << ".";
    this_thread::sleep_for(1s);
    cout << " tavern?" << endl;
    this_thread::sleep_for(2s);
    cout << "This definately isn't your home, \"where in the world am I?\" you wonder to yourself" << endl;
    this_thread::sleep_for(2s);
    cout << "As you are pondering about everything a man notices you and walks over\n" << endl;
    this_thread::sleep_for(2s);
    cout << "Mystery Man: Ah I see you're finally awake ";  //  I don't fkn know what accent this is, but I swear that I'm not racist!!
    this_thread::sleep_for(1s);
    cout << "or asleep, whichever way you want to look at it\n" << endl;
    this_thread::sleep_for(2s);
    cout << "You wonder what he means by this, and who he is\n" << endl;
    this_thread::sleep_for(2s);
    cout << "Mystery Man: oh right, I haven't introduced myself yet, huh" << endl;
    this_thread::sleep_for(2s);
    cout << "The mystery man introduces himself as \"Dennis, the owner of the tavern\"\n" << endl;
    this_thread::sleep_for(2s);
    cout << "Dennis the Tavern Owner: you are currently trapped here in the Nightmare Realm" << endl;
    this_thread::sleep_for(2s);
    cout << "When you fell asleep last night your concious was brought over to this land" << endl;
    this_thread::sleep_for(2s);
    cout << "The only way for you to get out of here is to survive 5 battles with the ruler's minions" << endl;
    this_thread::sleep_for(2s);
    cout << "But please don't kill them, they all have lives to live and they only roam the realm because the ruler tells them to" << endl;
    this_thread::sleep_for(2s);
    cout << "They are good monsters, I promise you that" << endl;
    this_thread::sleep_for(2s);
    cout << "Well, I'm going to go back to attending the tavern, you decide on what you would like to do \n" << endl;
    this_thread::sleep_for(2s);

    do {
        cout << "What would you like to do?";

        if (battlesCompleted < 5) {
            cout << "\n1. Quest";

            enemy = randomEnemy(false);
        }
        else if (battlesCompleted >= 6) {


            break;
        }
        else {
            cout << "\n1. Final Quest (Your Worst Nightmare)";

            enemy = randomEnemy(true);
        }

        cout << "\n2. Trade \n3. Open Inventory \n4. Exit Game \n" << endl;
        do {
            cin >> input;

            if (cin.fail()) {

                cerr << "Please insert a number from 1 to 4\n" << endl;
                cin.clear();

                #undef max

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            else if (input < 1 || input > 4) {
                cout << "Please insert a number from 1 to 4\n" << endl;
            }
            else {
                break;
            }
        } while (input < 1 || input > 4);

        //  Do quest / final quest
        if (input == 1) {
            if (enemy.GetName() == "NIGHTMARE The Destroyer Of Dreams") {
                cout << "You ";
                this_thread::sleep_for(0.75s);
                cout << "encounter ";
                this_thread::sleep_for(0.75s);
                cout << "a";
                this_thread::sleep_for(0.75s);
                cout << ".";
                this_thread::sleep_for(0.75s);
                cout << ".";
                this_thread::sleep_for(0.75s);
                cout << ".";
                this_thread::sleep_for(0.25s);
                cout << ".";
                this_thread::sleep_for(0.25s);
                cout << ".";
                this_thread::sleep_for(0.25s);
                cout << ".";
                this_thread::sleep_for(0.1s);
                cout << ".";
                this_thread::sleep_for(0.1s);
                cout << ".";
                this_thread::sleep_for(0.1s);
                cout << ".";
                this_thread::sleep_for(0.1s);
                cout << ".";
                this_thread::sleep_for(0.05s);
                cout << ".";
                this_thread::sleep_for(0.05s);
                cout << ".";
                this_thread::sleep_for(0.05s);
                cout << ".";
                this_thread::sleep_for(0.05s);
                cout << ".";
                this_thread::sleep_for(0.05s);
                cout << ".";
                this_thread::sleep_for(0.05s);
                cout << ".";
                this_thread::sleep_for(0.05s);
                cout << ".";
                this_thread::sleep_for(0.05s);
                cout << ".";
                this_thread::sleep_for(0.05s);
                cout << ".";
                this_thread::sleep_for(0.025s);
                cout << ".";
                this_thread::sleep_for(0.025s);
                cout << ".";
                this_thread::sleep_for(0.025s);
                cout << ".";
                this_thread::sleep_for(0.025s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".";
                this_thread::sleep_for(0.01s);
                cout << ".\n" << endl;
                this_thread::sleep_for(0.5s);
                cout << "You begin to feel your body getting cold" << endl;
                this_thread::sleep_for(0.25s);
                cout << "You feel uneasy, as if something is not right\n" << endl;
                this_thread::sleep_for(0.50s);
                cout << "You encounter " << enemy.GetName() << endl << endl;
            }
            else {
                cout << "You encounter a " << enemy.GetName() << endl << endl;
            }

            bool spare = false, spaghetti = true, ghostBully = false, ghostCompliment = false;
            int counterToSpare = 0;

            do {

                enemy.SetStrength(enemy.GetDefaultStrength());

                cout << enemy.GetName() << " - " << enemy.GetHealthPoints() << " hp" << endl;
                cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
                cout << mainCharacter.GetName() << " - " << mainCharacter.GetHealthPoints() << " hp\n" << endl;
                cout << "What would you like to do? \n1. Attack \n2. Talk \n3. Inventory \n4. Mercy \n" << endl;

                do {
                    cin >> combatInput;

                    if (cin.fail()) {

                        cerr << "Please insert a number from 1 to 4\n" << endl;
                        cin.clear();

                        #undef max

                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }
                    else if (combatInput < 1 || combatInput > 4) {
                        cout << "Please insert a number from 1 to 4\n" << endl;
                        continue;
                    }
                } while (combatInput < 1 || combatInput > 4);

                //  Attack
                if (combatInput == 1) {   
                    combat.Attack(mainCharacter, enemy);
                }

                //  Talk
                else if (combatInput == 2) {    

                    int talkInput;

                    combat.Talk(enemy);

                    cout << (possibleOptions.size() + 1) << ". Back\n" << endl;

                    do {
                        cin >> talkInput;

                        if (cin.fail()) {

                            cerr << "Please insert a number from 1 to \n" << possibleOptions.size() + 1 << endl;
                            cin.clear();

                            #undef max

                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            continue;
                        }
                        else if (talkInput < 1 || talkInput >(possibleOptions.size() + 1)) {
                            cout << "Please insert a number from 1 to \n" << possibleOptions.size() + 1 << endl;
                            continue;
                        }
                    } while (talkInput < 1 || talkInput >(possibleOptions.size() + 1));

                    if (talkInput == possibleOptions.size() + 1) {
                        cout << endl;
                        continue;
                    }
                    else {
                        possibleOptionsIter = possibleOptions.begin() + talkInput - 1;

                        if (enemy.GetName() == "Spooky Scary Skeleton") {
                            if (*possibleOptionsIter == "Play xylophone") {
                                cout << "You pick up 2 sticks from the ground and start hitting the skeletons ribcage like you are playing the xylophone" << endl;
                                this_thread::sleep_for(1s);
                                cout << enemy.GetName() << ": wh-";
                                this_thread::sleep_for(0.5s); 
                                cout << " what are you doing human?" << endl;
                                this_thread::sleep_for(1s);
                                cout << "The skeleton gives you a puzzled look" << endl;
                                this_thread::sleep_for(1s);
                                cout << "s-";
                                this_thread::sleep_for(0.5s);
                                cout << " stop that!" << endl;

                                counterToSpare--;

                                enemy.SetStrength(5);
                            }
                            else if (*possibleOptionsIter == "Do a spooky dance") {
                                cout << "You begin to dance in front of the skeleton" << endl;
                                this_thread::sleep_for(1s);
                                cout << "The skeleton looks intrigued" << endl;
                                this_thread::sleep_for(2s);
                                cout << enemy.GetName() << ": human, how do you know the dance of my people?" << endl;
                                this_thread::sleep_for(3s);
                                cout << "The skeleton ponders for a minute then begins to dance along with you" << endl;

                                counterToSpare++;
                            }
                            else if (*possibleOptionsIter == "Tell a joke") {
                                cout << "The Skeleton pauses for a moment ";
                                this_thread::sleep_for(1s);
                                cout << "then begins to laugh at your joke" << endl;
                                this_thread::sleep_for(1s);
                                cout << enemy.GetName() << ": ah, that joke really does tickle my funny bone!" << endl;

                                counterToSpare++;

                                enemy.SetStrength(1);
                            }
                            else if (*possibleOptionsIter == "Make Spaghetti") {
                                if (spaghetti == true) {

                                    int spaghettiPosition = -1;
                                    for (vector<string>::iterator i = allHealingItems.begin(); i != allHealingItems.end(); i++) {
                                        spaghettiPosition++;

                                        if (*i == "Spaghetti") {

                                            cout << "You make a plate of Spaghetti" << endl;
                                            this_thread::sleep_for(1s);
                                            cout << "\n" << enemy.GetName() << ": human, how did you know my weakness was Spaghetti?!? Can I have some?" << endl;
                                            this_thread::sleep_for(1s);
                                            cout << "\nYou decide to give the " << enemy.GetName() << " some of your Spaghetti" << endl;
                                            this_thread::sleep_for(1s);


                                            counterToSpare += 2;
                                            userHealingItems[spaghettiPosition]++;
                                            break;
                                        }
                                        else {
                                            continue;
                                        }
                                    }
                                }
                                else {

                                    cout << "You already made spaghetti this encounter" << endl;

                                    continue;
                                }
                            }
                        }
                        else if (enemy.GetName() == "Tapdancing Spider") {
                            if (*possibleOptionsIter == "Challenge") {
                                cout << "You challenge the Spider to a tapdancing battle\n" << endl;

                                this_thread::sleep_for(1s);
                                cout << enemy.GetName() << ": how dare you challenge me! Allow me to shhhow you my moves!\n" << endl;

                                counterToSpare--;

                                enemy.SetStrength(4);
                                
                            }
                            else if (*possibleOptionsIter == "Dance") {
                                cout << enemy.GetName() << ": you call thhhhat danthing?" << endl;
                                this_thread::sleep_for(1s);
                                cout << "I'll shhow you how to danthe \n" << endl;  //  the spider has a lisp okay? fight me
                                this_thread::sleep_for(1s);
                                cout << "The spider starts showing you how to dance, but it forgets that you only have 2 legs rather than 8... \n" << endl;

                                counterToSpare++;

                                enemy.SetStrength(0);
                            }
                            else if (*possibleOptionsIter == "Show Off") {
                                cout << "You try showing off your dance moves but you are still highly inexperienced and end up falling over" << endl;
                                this_thread::sleep_for(1s);
                                cout << "The spider starts laughing at you\n" << endl;

                                selfEsteem--;

                                cout << "-1 to your Self Esteem" << endl;
                                cout << "Self Esteem: " << selfEsteem << endl << endl;

                                cout << "You also scraped your knee when you fell over so -1 to your health as well\n" << endl;

                                mainCharacter.TakeDamage(1);
                            }
                        }
                        else if (enemy.GetName() == "Shy Ghost") {
                            if (*possibleOptionsIter == "Bully") {

                                if (ghostCompliment == true) {
                                    cout << enemy.GetName() << ": s- so your compliment to me was just a lie then?" << endl;
                                    this_thread::sleep_for(1s);
                                    cout << "why do you have to be so cruel to me?\n" << endl;
                                    this_thread::sleep_for(1s);
                                    cout << "The ghost begins to cry\n" << endl;

                                    ghostBully = true;
                                    ghostCompliment = false;

                                    counterToSpare--;
                                    enemy.SetStrength(4);
                                }
                                else {
                                    cout << enemy.GetName() << ": th- that was not a nice thing to say... " << endl;
                                    this_thread::sleep_for(1s);
                                    cout << "The ghost starts to cry \n" << endl;

                                    ghostCompliment = false;
                                    ghostBully = true;

                                    counterToSpare--;

                                    enemy.SetStrength(3);
                                }
                            }

                            else if (*possibleOptionsIter == "Compliment") {

                                if (ghostBully == true) {
                                    cout << enemy.GetName() << ": you are going to bully me then compliment me after i call you out for it?" << endl;
                                    this_thread::sleep_for(1s);
                                    cout << "you are a terrible person and you'll have to try harder than that" << endl;

                                    counterToSpare--;
                                    enemy.SetStrength(3);

                                    ghostCompliment = false;
                                    ghostBully = false;
                                }
                                else {
                                    cout << enemy.GetName() << ": d- do you really mean that? " << endl;
                                    this_thread::sleep_for(1s);
                                    cout << "nobody's ever said something so nice to me before... " << endl;
                                    this_thread::sleep_for(1s);
                                    cout << "say, where do you get your confidence from?" << endl;

                                    if (userEquipped[1] == "Leather Jacket") {
                                        this_thread::sleep_for(1s);
                                        cout << "guess it must be that leather jacket you've got on there\n" << endl;
                                        this_thread::sleep_for(1s);
                                        cout << "The " << enemy.GetName() << " smiles at you\n" << endl;
                                        this_thread::sleep_for(1s);
                                        cout << enemy.GetName() << ": i really should get one of those for myself" << endl;
                                    }
                                    else if (userEquipped[1] == "Tapdancing Shoes") {
                                        this_thread::sleep_for(1s);
                                        cout << "guess it must be those tapdancing shoes you've got on\n" << endl;
                                        this_thread::sleep_for(1s);
                                        cout << "The " << enemy.GetName() << " smiles at you\n" << endl;
                                        this_thread::sleep_for(1s);
                                        cout << enemy.GetName() << ": i really should get one of those for myself" << endl;
                                    }
                                    else if (userEquipped[1] == "Confidence Boosting High Heels") {
                                        this_thread::sleep_for(1s);
                                        cout << "it absolutely has to be those high heels that you've got on\n" << endl;
                                        this_thread::sleep_for(1s);
                                        cout << "The " << enemy.GetName() << " smiles at you\n" << endl;
                                        this_thread::sleep_for(1s);
                                        cout << enemy.GetName() << ": i really should get one of those for myself" << endl;
                                    }
                                    else {
                                        this_thread::sleep_for(1s);
                                        cout << "whetever it is i hope that i can find mine as well someday\n" << endl;
                                    }

                                    ghostCompliment = true;
                                    ghostBully = false;

                                    counterToSpare += 2;
                                    enemy.SetStrength(0);
                                }

                                //  in a full game I would make it so that if you get the Shy Ghost again after this compliment then their name wouldn't be Shy Ghost anymore, maybe it would be Confident Ghost instead and the ghost would be wearing whatever it is that the player has on as well
                            }
                        }
                        else if (enemy.GetName() == "NIGHTMARE The Destroyer Of Dreams") {
                            if (*possibleOptionsIter == "Plead for mercy") {
                                cout << enemy.GetName() << ": HAHAHA, how pathetic. " << endl;

                                if (sparesCompleted > attacksWon) {
                                    cout << "You may have been able to get mercy from all my other subjects, but there will be no pity points coming from me!\n" << endl;
                                }
                                else if (sparesCompleted < attacksWon) {
                                    cout << "My other subjects may have fallen to you, but you will not get mercy because of it from me.\n" << endl;
                                }
                                else {
                                    cout << "You were too weak for my other subjects, what makes you think I'd give mercy for such a puny weak human like yourself?\n" << endl;
                                }

                                enemy.SetStrength(10);
                            }
                        }
                    }
                }

                //  Inventory
                else if (combatInput == 3) {
                    mainCharacter.ShowInventory();

                    int inventoryInput, exitVariable = userDisplayedItems.size() + 1;

                    cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << exitVariable << ". Back\n" << endl;

                    do {
                        cin >> inventoryInput;

                        if (cin.fail()) {

                            cerr << "Please insert a number from 1 to " << exitVariable << "\n" << endl;
                            cin.clear();

                            #undef max

                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            continue;
                        }
                    } while (inventoryInput < 1 && inventoryInput > exitVariable);

                    if (inventoryInput == exitVariable) {
                        continue;
                    }
                    
                    bool inventoryTurn = false;

                    int position = -1;
                    for (vector<string>::iterator i = allWeapons.begin(); i != allWeapons.end(); i++) {

                        position++;

                        if (userDisplayedItems[inventoryInput - 1] == *i) {
                            cout << "Are you sure that you would like to swap your " << userEquipped[0] << " for " << userDisplayedItems[inventoryInput - 1] << "? (y/n)\n" << endl;


                            yesNo = NULL;
                            do {
                                cin >> yesNo;

                                if (cin.fail()) {

                                    cerr << "Please insert 'y' or an 'n'\n" << endl;
                                    cin.clear();

                                    #undef max

                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    continue;
                                }
                                else if (yesNo == 'y' || yesNo == 'Y' || yesNo == 'n' || yesNo == 'N') {
                                    break;
                                }
                                else {
                                    cout << "Please insert 'y' or an 'n'\n" << endl;
                                    continue;
                                }
                            } while (yesNo != 'n' && yesNo != 'N' || yesNo != 'y' && yesNo != 'Y' || yesNo == NULL);

                            if (yesNo == 'y' || yesNo == 'Y') {
                                userEquipped[0] = userDisplayedItems[inventoryInput - 1];
                                mainCharacter.SetStrength(weaponDamage[position]);

                                inventoryTurn = true;
                            }
                            else {
                                break;
                            }
                        }
                        else if (i == allWeapons.end()) {
                            break;
                        }
                        else {
                            continue;
                        }
                    }

                    position = -1;
                    for (vector<string>::iterator i = allArmor.begin(); i != allArmor.end(); i++) {
                        position++;

                        if (userDisplayedItems[inventoryInput - 1] == *i) {
                            cout << "Are you sure that you would like to swap your " << userEquipped[1] << " for " << userDisplayedItems[inventoryInput - 1] << "? (y/n)\n" << endl;


                            yesNo = NULL;
                            do {
                                cin >> yesNo;

                                if (cin.fail()) {

                                    cerr << "Please insert 'y' or an 'n'\n" << endl;
                                    cin.clear();

                                    #undef max

                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    continue;
                                }
                                else if (yesNo == 'y' || yesNo == 'Y' || yesNo == 'n' || yesNo == 'N') {
                                    break;
                                }
                                else {
                                    cout << "Please insert 'y' or an 'n'\n" << endl;
                                    continue;
                                }
                            } while (yesNo != 'n' && yesNo != 'N' || yesNo != 'y' && yesNo != 'Y' || yesNo == NULL);

                            if (yesNo == 'y' || yesNo == 'Y') {
                                userEquipped[1] = userDisplayedItems[inventoryInput - 1];
                                mainCharacter.SetDefence(armorDefence[position]);

                                inventoryTurn = true;
                            }
                            else {
                                break;
                            }
                        }
                        else if (i == allArmor.end()) {
                            break;
                        }
                        else {
                            continue;
                        }
                    }

                    position = -1;
                    for (vector<string>::iterator i = allHealingItems.begin(); i != allHealingItems.end(); i++) {
                        position++;

                        if (userDisplayedItems[inventoryInput - 1] == *i) {
                            cout << "Are you sure you want to use a " << userDisplayedItems[inventoryInput - 1] << "? (y/n)\n" << endl;

                            yesNo = NULL;
                            do {
                                cin >> yesNo;

                                if (cin.fail()) {

                                    cerr << "Please insert 'y' or an 'n'\n" << endl;
                                    cin.clear();

                                    #undef max

                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    continue;
                                }
                                else if (yesNo == 'y' || yesNo == 'Y' || yesNo == 'n' || yesNo == 'N') {
                                    break;
                                }
                                else {
                                    cout << "Please insert 'y' or an 'n'\n" << endl;
                                    continue;
                                }
                            } while (yesNo != 'n' && yesNo != 'N' || yesNo != 'y' && yesNo != 'Y' || yesNo == NULL);

                            if (yesNo == 'y' || yesNo == 'Y') {

                                
                                vector<int>::iterator healthStatsIter = healingStats.begin() + position;

                                mainCharacter.AddHealth(*healthStatsIter);

                                inventoryTurn = true;

                                break;
                            }
                            else {
                                break;
                            }
                        }
                        else if (i == allHealingItems.end()) {
                            break;
                        }
                        else {
                            continue;
                        }
                    }

                    if (inventoryTurn == true) {

                    }
                    else {
                        continue;
                    }
                }

                //  Mercy
                else if (combatInput == 4) {

                    if (enemy.GetName() != "NIGHTMARE The Destroyer Of Dreams") {
                        if (counterToSpare >= 3) {
                            enemy.SetSpare(true);
                        }
                    }
                    else {
                        if (counterToSpare >= 10) {
                            enemy.SetSpare(true);
                        }
                        else {
                            counterToSpare++;
                        }
                    }

                    combat.Mercy(enemy);

                    if (enemy.GetSpare() == true) {

                        break;
                    }
                    else {
                        continue;
                    }
                }

                if (enemy.GetName() == "Spooky Scary Skeleton" && *possibleOptionsIter == "Do a spooky dance") {
                    cout << "\nThe Skeleton is too busy dancing along to attack \n" << endl;
                    continue;
                }
                else if (enemy.GetName() == "Spooky Scary Skeleton" && *possibleOptionsIter == "Tell a joke") {
                    cout << "\nThe Skeleton is laughing too much to attack \n" << endl;
                    continue;
                }
                else if (enemy.GetName() == "Spooky Scary Skeleton" && *possibleOptionsIter == "Make Spaghetti") {
                    cout << "\nThe Skeleton is too busy enjoying your Spaghetti to attack right now \n" << endl;
                    continue;
                }
                else if (enemy.GetName() == "Tapdancing Spider" && *possibleOptionsIter == "Dance") {
                    cout << "The spider is too busy trying to teach you how to dance that it doesn't attack you \n" << endl;
                    continue;
                }
                else if (enemy.GetName() == "Shy Ghost" && *possibleOptionsIter == "Compliment") {
                    cout << "The " << enemy.GetName() << " chooses not to attack you after your compliment\n" << endl;
                    continue;
                }

                int damage = rollDice(2, 1) + enemy.GetStrength();

                if (damage > mainCharacter.GetDefence()) {

                    damage -= mainCharacter.GetDefence();

                    mainCharacter.TakeDamage(damage);

                    if (*possibleOptionsIter == "Challenge" && enemy.GetName() == "Tapdancing Spider") {
                        cout << "the " << enemy.GetName() << " does an extremely complex dance that you have never seen before, you take " << damage << " damage physically and to your self esteem \n" << endl;
                        
                        selfEsteem -= damage;
                        
                        cout << "Self esteem: " << selfEsteem << endl;
                    }
                    else {
                        cout << "the " << enemy.GetName() << " also hit you for " << damage << " damage! \n" << endl;
                    }
                    
                }
                else {
                    if (enemy.GetName() == "Shy Ghost") {
                        cout << enemy.GetName() << ": i'm not really feeling up to it right now so... pretend i did something just now\n" << endl;
                    }
                    else {
                        cout << "the " << enemy.GetName() << " was blocked by your defence!\n" << endl;
                    }
                }
            } while (enemy.GetHealthPoints() > 0 && mainCharacter.GetHealthPoints() > 0 && spare != true);

            //  you kill the enemy
            if (enemy.GetHealthPoints() < 1) {
                attacksWon++;

                //  this entire output is just one Undertale reference
                if (enemy.GetName() == "Shy Ghost") {
                    this_thread::sleep_for(1s);
                    cout << "umm... you do know you cant kill ghosts, right ?" << endl;
                    this_thread::sleep_for(3s);
                    cout << "we're sorta incorporeal and all" << endl;
                    this_thread::sleep_for(3s);
                    cout << "i was just lowering my hp because i didnt want to be rude" << endl;
                    this_thread::sleep_for(3s);
                    cout << "sorry... i just made this more awkward..." << endl;
                    this_thread::sleep_for(3s);
                    cout << "pretend you beat me..." << endl;
                    this_thread::sleep_for(3s);
                    cout << "oooooooooo" << endl;
                    this_thread::sleep_for(3s);
                    cout << endl;
                }

                cout << "congrats! it seems that you have defeated the " << enemy.GetName() << "! your max hp and your attack damage have both increased!\n" << endl;

                int position = 0;

                switch (attacksWon) {
                case 1:
                    mainCharacter.SetHealthPointsMax(24);
                    break;
                case 2:
                    mainCharacter.SetHealthPointsMax(32);
                    break;
                case 3:
                    mainCharacter.SetHealthPointsMax(64);
                    break;
                case 4:
                    mainCharacter.SetHealthPointsMax(92);
                    break;
                case 5:
                    cout << "Oh... it appears that you already have the highest hp possible, good job! as a reward here's a Greasy Burger" << endl;

                    for (vector<string>::iterator i = allHealingItems.begin(); i != allHealingItems.end(); i++) {

                        position++;

                        if (*i == "Greasy Burger") {
                            
                            vector<int>::iterator userHealingIter = userHealingItems.begin() + position;
                            *userHealingIter++;

                            break;
                        }
                    }

                    mainCharacter.SetHealthPointsMax(92);
                    break;
                default :
                    mainCharacter.SetHealthPointsMax(20);
                    break;
                }

                if (enemy.GetName() != "NIGHTMARE The Destroyer Of Dreams") {
                    int randomMoneyGained = rand() % 12 + 13;

                    mainCharacter.AddMoney(randomMoneyGained);
                }
                else {
                    cout << enemy.GetName() << ": you may think that you have defeated me... but I won't be gone for long, you will have to fall asleep again at some point" << endl;
                }
            }

            //  you die
            else if (mainCharacter.GetHealthPoints() < 1) {
                if (battlesCompleted >= 5) {

                    cout << "oh no! it looks like you've lost the battle! you wake back at the tavern, you can attempt this fight however many times you want \n" << endl;

                    mainCharacter.AddHealth(999);

                    continue;
                }
                else {
                    cout << "oh no! it looks like you've lost the battle! you wake back at the tavern \n" << endl;
                }
                
            }

            //  you spare the enemy
            else {
                sparesCompleted++;

                cout << "Congrats, you have beat the " << enemy.GetName() << "!" << endl;

                if (enemy.GetName() != "NIGHTMARE The Destroyer Of Dreams") {
                    int randomMoneyGained = rand() % 12 + 13;

                    mainCharacter.AddMoney(randomMoneyGained);
                }
                else {
                    //  insert the final dialogue for sparing the boss
                }
            }

            mainCharacter.AddHealth(999);

            battlesCompleted++;
        }

        //  Trading
        else if (input == 2) {
            
        cout << "Tavern Owner: Welcome to the Daydream Tavern, ";

            do {
                cout << "what can I do for you? \n1. Buy \n2. Sell \n3. Check inventory \n4. Back \n" << endl;

                do {
                    cin >> tavernInput;

                    if (cin.fail()) {

                        cerr << "Please insert a number from 1 to 4\n" << endl;
                        cin.clear();

                        #undef max

                        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        continue;
                    }
                } while (tavernInput < 1 || tavernInput > 4);

                //  buy
                if (tavernInput == 1) {

                    int buyInput;

                    tavern.displayInventory();
                    cout << "5. Back \n" << endl;
                    cout << "Your Money: " << mainCharacter.GetMoney() << " Coins \n" << endl;

                    do {
                        cin >> buyInput;

                        if (cin.fail()) {

                            cerr << "Please insert a number from 1 to 5\n" << endl;
                            cin.clear();

                            #undef max

                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            continue;
                        }
                        else if (buyInput < 1 || buyInput > 5) {
                            cout << "Please insert a number from 1 to 5\n" << endl;
                            continue;
                        }
                    } while (buyInput < 1 || buyInput > 5);

                    if (buyInput == 1) {
                        cout << "are you sure that you would like to add " << merchantInventory[0] << " to your inventory for " << merchantItemCost[0] << " Coins? (y/n) \n" << endl;

                        yesNo = NULL;
                        do {
                            cin >> yesNo;

                            if (cin.fail()) {

                                cerr << "Please insert 'y' or an 'n'\n" << endl;
                                cin.clear();

                                #undef max

                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                continue;
                            }
                            else if (yesNo == 'y' || yesNo == 'Y' || yesNo == 'n' || yesNo == 'N') {
                                break;
                            }
                            else {
                                cout << "Please insert 'y' or an 'n'\n" << endl;
                                continue;
                            }
                        } while (yesNo != 'n' && yesNo != 'N' || yesNo != 'y' && yesNo != 'Y' || yesNo == NULL);

                        if (yesNo == 'y' || yesNo == 'Y') {

                            if (mainCharacter.GetMoney() < merchantItemCost[0]) {
                                cout << "You do not have enough coins for this item, this item costs " << merchantItemCost[0] << " Coins, and you only have " << mainCharacter.GetMoney() << " Coins\n" << endl;
                            }
                            else {
                                
                                int position;
                                for (position = 0; position < allWeapons.size(); position++) {
                                    if (merchantInventory[0] == allWeapons[position]) {
                                        if (userWeaponAmount[position] == 1) {
                                            cout << "It looks like you've already got one of these in your inventory" << endl;
                                        }
                                        else {
                                            userWeaponAmount[position]++;

                                            mainCharacter.MinusMoney(merchantItemCost[0]);

                                            cout << "Added " << merchantInventory[0] << " to your inventory \n" << endl;

                                            tavern.removeItem(0);

                                            break;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                            }
                        }
                        else {
                            continue;
                        }
                    }

                    else if (buyInput == 2) {
                        cout << "are you sure that you would like to add " << merchantInventory[1] << " to your inventory for " << merchantItemCost[1] << " Coins? (y/n) \n" << endl;

                        yesNo = NULL;
                        do {
                            cin >> yesNo;

                            if (cin.fail()) {

                                cerr << "Please insert 'y' or an 'n'\n" << endl;
                                cin.clear();

                                #undef max

                                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                continue;
                            }
                            else if (yesNo == 'y' || yesNo == 'Y' || yesNo == 'n' || yesNo == 'N') {
                                break;
                            }
                            else {
                                cout << "Please insert 'y' or an 'n'\n" << endl;
                                continue;
                            }
                        } while (yesNo != 'n' && yesNo != 'N' || yesNo != 'y' && yesNo != 'Y' || yesNo == NULL);

                        if (yesNo == 'y' || yesNo == 'Y') {

                            if (mainCharacter.GetMoney() < merchantItemCost[1]) {
                                cout << "You do not have enough coins for this item, this item costs " << merchantItemCost[1] << " Coins, and you only have " << mainCharacter.GetMoney() << " Coins\n" << endl;
                            }
                            else {
                                
                                int position;
                                for (position = 0; position < allArmor.size(); position++) {
                                    if (merchantInventory[1] == allArmor[position]) {
                                        if (userArmorAmount[position] == 1) {
                                            cout << "It looks like you've already got one of these in your inventory" << endl;
                                        }
                                        else {
                                            userArmorAmount[position]++;

                                            mainCharacter.MinusMoney(merchantItemCost[1]);

                                            cout << "Added " << merchantInventory[1] << " to your inventory \n" << endl;

                                            tavern.removeItem(1);

                                            break;
                                        }
                                    }
                                    else {
                                        continue;
                                    }
                                }
                            }
                        }
                        else {
                            continue;
                        }   
                    }

                    else if (buyInput == 3) {
                        if (mainCharacter.GetMoney() < merchantItemCost[2]) {
                            cout << "You do not have enough coins for this item, this item costs " << merchantItemCost[2] << " Coins, and you only have " << mainCharacter.GetMoney() << " Coins\n" << endl;
                        }
                        else {

                            int position = -1;
                            for (vector<string>::iterator healingNameIter = allHealingItems.begin(); healingNameIter != allHealingItems.end(); healingNameIter++) {
                                position++;

                                if (*healingNameIter == merchantInventory[2]) {
                                    break;
                                }
                                else {
                                    continue;
                                }
                            }

                            userHealingItems[position]++;
                            mainCharacter.MinusMoney(merchantItemCost[1]);

                            cout << "Added 1 " << merchantInventory[2] << " to your inventory\n" << endl;

                            tavern.removeItem(2);
                        }
                    }
                    else if (buyInput == 4) {
                        if (mainCharacter.GetMoney() < merchantItemCost[3]) {
                            cout << "You do not have enough coins for this item, this item costs " << merchantItemCost[3] << " Coins, and you only have " << mainCharacter.GetMoney() << " Coins\n" << endl;
                        }
                        else {
                            
                            int position = -1;
                            for (vector<string>::iterator healingNameIter = allHealingItems.begin(); healingNameIter != allHealingItems.end(); healingNameIter++) {
                                position++;

                                if (*healingNameIter == merchantInventory[3]) {
                                    break;
                                }
                                else {
                                    continue;
                                }
                            }

                            userHealingItems[position]++;
                            mainCharacter.MinusMoney(merchantItemCost[3]);

                            cout << "Added 1 " << merchantInventory[3] << " to your inventory\n" << endl;

                            tavern.removeItem(3);
                        }
                    }

                    continue;
                }

                //  sell
                else if (tavernInput == 2) {
                    mainCharacter.InventorySellDisplay();
                    cout << userDisplayedItems.size() << ". Back \n" << endl;

                    int sellInput;
                    do {
                        cin >> sellInput;

                        if (cin.fail()) {

                            cerr << "Please insert a number from 1 to " << userDisplayedItems.size() + 1 << "\n" << endl;
                            cin.clear();

                            #undef max

                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            continue;
                        }
                        else if (sellInput < 1 || sellInput > userDisplayedItems.size() + 1) {
                            cerr << "Please insert a number from 1 to " << userDisplayedItems.size() + 1 << "\n" << endl;
                        }
                    } while (sellInput < 1 || sellInput > userDisplayedItems.size() + 1);



                    continue;
                }

                //  Check Inventory
                else if (tavernInput == 3) {

                    mainCharacter.ShowInventory();

                    int inventoryInput, exitVariable = userDisplayedItems.size() + 1;

                    cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
                    cout << exitVariable << ". Back\n" << endl;

                    do {
                        cin >> inventoryInput;

                        if (cin.fail()) {

                            cerr << "Please insert a number from 1 to " << exitVariable << "\n" << endl;
                            cin.clear();

                            #undef max

                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            continue;
                        }
                    } while (inventoryInput < 1 && inventoryInput > exitVariable);

                    if (inventoryInput == exitVariable) {
                        continue;
                    }

                    bool inventoryTurn = false;

                    int position = -1;
                    for (vector<string>::iterator i = allWeapons.begin(); i != allWeapons.end(); i++) {

                        position++;

                        if (userDisplayedItems[inventoryInput - 1] == *i) {
                            cout << "Are you sure that you would like to swap your " << userEquipped[0] << " for " << userDisplayedItems[inventoryInput - 1] << "? (y/n)\n" << endl;


                            yesNo = NULL;
                            do {
                                cin >> yesNo;

                                if (cin.fail()) {

                                    cerr << "Please insert 'y' or an 'n'\n" << endl;
                                    cin.clear();

                                    #undef max

                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    continue;
                                }
                                else if (yesNo == 'y' || yesNo == 'Y' || yesNo == 'n' || yesNo == 'N') {
                                    break;
                                }
                                else {
                                    cout << "Please insert 'y' or an 'n'\n" << endl;
                                    continue;
                                }
                            } while (yesNo != 'n' && yesNo != 'N' || yesNo != 'y' && yesNo != 'Y' || yesNo == NULL);

                            if (yesNo == 'y' || yesNo == 'Y') {
                                userEquipped[0] = userDisplayedItems[inventoryInput - 1];
                                mainCharacter.SetStrength(weaponDamage[position]);

                                inventoryTurn = true;
                            }
                            else {
                                break;
                            }
                        }
                        else if (i == allWeapons.end()) {
                            break;
                        }
                        else {
                            continue;
                        }
                    }

                    position = -1;
                    for (vector<string>::iterator i = allArmor.begin(); i != allArmor.end(); i++) {
                        position++;

                        if (userDisplayedItems[inventoryInput - 1] == *i) {
                            cout << "Are you sure that you would like to swap your " << userEquipped[1] << " for " << userDisplayedItems[inventoryInput - 1] << "? (y/n)\n" << endl;


                            yesNo = NULL;
                            do {
                                cin >> yesNo;

                                if (cin.fail()) {

                                    cerr << "Please insert 'y' or an 'n'\n" << endl;
                                    cin.clear();

                                    #undef max

                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    continue;
                                }
                                else if (yesNo == 'y' || yesNo == 'Y' || yesNo == 'n' || yesNo == 'N') {
                                    break;
                                }
                                else {
                                    cout << "Please insert 'y' or an 'n'\n" << endl;
                                    continue;
                                }
                            } while (yesNo != 'n' && yesNo != 'N' || yesNo != 'y' && yesNo != 'Y' || yesNo == NULL);

                            if (yesNo == 'y' || yesNo == 'Y') {
                                userEquipped[1] = userDisplayedItems[inventoryInput - 1];
                                mainCharacter.SetDefence(armorDefence[position]);

                                inventoryTurn = true;
                            }
                            else {
                                break;
                            }
                        }
                        else if (i == allArmor.end()) {
                            break;
                        }
                        else {
                            continue;
                        }
                    }

                    position = -1;
                    for (vector<string>::iterator i = allHealingItems.begin(); i != allHealingItems.end(); i++) {
                        position++;

                        if (userDisplayedItems[inventoryInput - 1] == *i) {
                            cout << "Are you sure you want to use a " << userDisplayedItems[inventoryInput - 1] << "? (y/n)\n" << endl;

                            yesNo = NULL;
                            do {
                                cin >> yesNo;

                                if (cin.fail()) {

                                    cerr << "Please insert 'y' or an 'n'\n" << endl;
                                    cin.clear();

                                    #undef max

                                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                                    continue;
                                }
                                else if (yesNo == 'y' || yesNo == 'Y' || yesNo == 'n' || yesNo == 'N') {
                                    break;
                                }
                                else {
                                    cout << "Please insert 'y' or an 'n'\n" << endl;
                                    continue;
                                }
                            } while (yesNo != 'n' && yesNo != 'N' || yesNo != 'y' && yesNo != 'Y' || yesNo == NULL);

                            if (yesNo == 'y' || yesNo == 'Y') {


                                vector<int>::iterator healthStatsIter = healingStats.begin() + position;

                                mainCharacter.AddHealth(*healthStatsIter);

                                inventoryTurn = true;

                                break;
                            }
                            else {
                                break;
                            }
                        }
                        else if (i == allHealingItems.end()) {
                            break;
                        }
                        else {
                            continue;
                        }
                    }

                    if (inventoryTurn == true) {

                    }
                    else {
                        continue;
                    }
                }

                //  back / exit
                else {
                    break;
                }

            } while (tavernInput != 4);
        }

        //  Open Inventory
        else if (input == 3) {
            mainCharacter.ShowInventory();

            int inventoryInput, exitVariable = userDisplayedItems.size() + 1;

            cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
            cout << exitVariable << ". Back\n" << endl;

            do {
                cin >> inventoryInput;

                if (cin.fail()) {

                    cerr << "Please insert a number from 1 to " << exitVariable << "\n" << endl;
                    cin.clear();

                    #undef max

                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    continue;
                }
            } while (inventoryInput < 1 && inventoryInput > exitVariable);

            if (inventoryInput == exitVariable) {
                continue;
            }

            int position = -1;
            for (vector<string>::iterator i = allWeapons.begin(); i != allWeapons.end(); i++) {

                position++;

                if (userDisplayedItems[inventoryInput - 1] == *i) {
                    cout << "Are you sure that you would like to swap your " << userEquipped[0] << " for" << userDisplayedItems[inventoryInput - 1] << "?\n" << endl;


                    yesNo = NULL;
                    do {
                        cin >> yesNo;

                        if (cin.fail()) {

                            cerr << "Please insert 'y' or an 'n'\n" << endl;
                            cin.clear();

                            #undef max

                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            continue;
                        }
                        else if (yesNo == 'y' || yesNo == 'Y' || yesNo == 'n' || yesNo == 'N') {
                            break;
                        }
                        else {
                            cout << "Please insert 'y' or an 'n'\n" << endl;
                            continue;
                        }
                    } while (yesNo != 'n' && yesNo != 'N' || yesNo != 'y' && yesNo != 'Y' || yesNo == NULL);

                    if (yesNo == 'y' || yesNo == 'Y') {
                        userEquipped[0] = userDisplayedItems[inventoryInput - 1];
                        mainCharacter.SetStrength(weaponDamage[position]);
                    }
                    else {
                        break;
                    }
                }
                else if (i == allWeapons.end()) {
                    break;
                }
                else {
                    continue;
                }
            }

            position = -1;
            for (vector<string>::iterator i = allArmor.begin(); i != allArmor.end(); i++) {
                position++;

                if (userDisplayedItems[inventoryInput - 1] == *i) {
                    cout << "Are you sure that you would like to swap your " << userEquipped[1] << " for" << userDisplayedItems[inventoryInput - 1] << "?\n" << endl;


                    yesNo = NULL;
                    do {
                        cin >> yesNo;

                        if (cin.fail()) {

                            cerr << "Please insert 'y' or an 'n'\n" << endl;
                            cin.clear();

                            #undef max

                            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            continue;
                        }
                        else if (yesNo == 'y' || yesNo == 'Y' || yesNo == 'n' || yesNo == 'N') {
                            break;
                        }
                        else {
                            cout << "Please insert 'y' or an 'n'\n" << endl;
                            continue;
                        }
                    } while (yesNo != 'n' && yesNo != 'N' || yesNo != 'y' && yesNo != 'Y' || yesNo == NULL);

                    if (yesNo == 'y' || yesNo == 'Y') {
                        userEquipped[1] = userDisplayedItems[inventoryInput - 1];
                        mainCharacter.SetDefence(armorDefence[position]);
                    }
                    else {
                        break;
                    }
                }
                else if (i == allArmor.end()) {
                    break;
                }
                else {
                    continue;
                }
            }

            for (vector<string>::iterator i = allHealingItems.begin(); i != allHealingItems.end(); i++) {
                if (userDisplayedItems[inventoryInput - 1] == *i) {
                    cout << "There is no need for healing items when out of combat \n" << endl;
                    break;
                }
            }
        }

        //  Exit Game
        else if (input == 4) {
            break;
        }

    } while (true);

    return 0;
}

int rollDice(int sides, int number) {

    int total = 0;

    for (int i = 0; i < number; i++) {
        total += rand() % sides;
    }

    return total;
}

Creature randomEnemy(bool bossYesNo) {

    srand((unsigned)time(NULL));

    vector<Creature>::iterator enemyIter;

    if (bossYesNo == true) {
        int bossSelector = rand() % allBosses.size();

        enemyIter = allBosses.begin() + bossSelector;
    }
    else {
        int enemySelector = rand() % allEnemies.size();
        
        enemyIter = allEnemies.begin() + enemySelector;
    }

    return *enemyIter;
}