#pragma once

#include "Location.h"

class Player {

    string m_Name;
    std::set<string> m_Reactions;
    Location* m_CurrentLocation;
    //    Inventory * m_Inventory;

public:
    Player(string name = "John Doe");

    void SetLocation(Location* location);
    Location* GetLocation();

    void DisplayReactions();
    void AddReactions(std::set<string> reactions);

    string GetName();
};


// Player
// - name
// - inventory
// - current position