#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <set>

using std::string;
using std::cout;
using std::endl;
using std::vector;

// Location

// - may have NPC

class Location {
private:
    vector<Location*> m_Rides;
    bool m_IsRide;
    //    vector<Interactable*> m_Interactables;
    //    vector<Items*> m_Items;
    //    vector<NPC*> m_NPCs;
    std::set<string> m_Reactions;
protected:
    string m_Name;
    string m_Description;
    bool m_IsTrain = false;

    vector<Location*> m_Areas;
public:
    Location(string name = "Empty Room", string description = "It's an empty room.", bool isRide = false);
    virtual ~Location() = default;

    void DisplayLocation();
    void AddArea(Location* location);
    void AddRide(Location* location);
    void AddReaction(string reaction);

    std::set<string> GetReactions();

    string GetName();
    Location* AreaName(int areaNumber);
    Location* RideName(int exitNumber);

    int NumberOfExits();
    int NumberOfAreas();
    int NumberOfRides();

    int AreaNumber(Location* areaName);

    bool IsRide();
    bool IsTrain();

    //static vector<string> AllReactions;
};