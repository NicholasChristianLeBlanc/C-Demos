#include "Location.h"

/*vector<string> Location::AllReactions = { // todo figure out a replacement reaction for "Enjoyment"
    "Amazement",
    "Whirl",
    "Spooked",
    "Raise Your Arms",
    "Wonder",
    "Sing Along",
    "Dizzy",
    "Spin",
    "Joy",
    "Hold Tight",
    "Scream",
    "Blast",
    "Focus",
    "Relaxation",
    "Awe",
    "Laugh",
    "Zoom",
    "Ragdoll",
    "Take Pictures",    // Specific to Kilimanjaro
    "Recoil",           // Specific to Journey Into Imagination  
    "Dance Along",
    "Holy Shit",        // Specific to Rock N Rollercoaster
    "Woo",
    "\"bro we're in the fkn Millenium Falcon\""
};*/

Location::Location(string name, string description, bool isRide) {
    m_Name = name;
    m_Description = description;
    m_IsRide = isRide;
}

void Location::DisplayLocation() {
    cout << endl << m_Name << endl;
    cout << "----------------------------------" << endl;
    cout << m_Description << endl << endl;
    
    if (!m_IsRide) {
        int locationCounter = 0;
        cout << "You see the following areas:" << endl;
        for (int i = 0; i < m_Areas.size(); i++) {
            cout << locationCounter << ". " << m_Areas[i]->m_Name << endl;
            locationCounter++;
        }

        if (!m_Rides.empty()) {
            cout << endl << "You see the following rides:" << endl;
            for (int i = 0; i < m_Rides.size(); i++) {
                cout << locationCounter << ". " << m_Rides[i]->m_Name << endl;
                locationCounter++;
            }
        }
    }
}

void Location::AddArea(Location* location) {
    m_Areas.push_back(location);
}

void Location::AddRide(Location* location) {
    m_Rides.push_back(location);
}

string Location::GetName() {
    return m_Name;
}

int Location::NumberOfExits() {
    return (int)m_Areas.size() + (int)m_Rides.size();
}

int Location::NumberOfAreas() {
    return (int)m_Areas.size();
}

int Location::NumberOfRides() {
    return (int)m_Rides.size();
}

int Location::AreaNumber(Location* areaName) {
    int counter = 0;
    for (Location* area : m_Areas) {
        if (area->GetName() != areaName->GetName()) {
            counter++;
            continue;
        }
        else {
            break;
        }
    }
    return counter;
}

Location* Location::AreaName(int areaNumber) {
    return m_Areas[areaNumber];
}

Location* Location::RideName(int exitNumber) {
    int rideNumber = exitNumber - m_Areas.size();
    
    return m_Rides[rideNumber];
}

void Location::AddReaction(string reaction) {
    if (m_IsRide) {
        m_Reactions.insert(reaction);
    }
    else {
        cout << m_Name << "Is Not A Ride" << endl;
    }
}

bool Location::IsRide() {
    return m_IsRide;
}

bool Location::IsTrain() {
    return m_IsTrain;
}

std::set<string> Location::GetReactions() {
    return m_Reactions;
}