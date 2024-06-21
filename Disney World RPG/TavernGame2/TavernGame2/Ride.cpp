#include "Ride.h"

Ride::Ride(string name, string description):
Location(name, description)
{
    
}

void Ride::AddReaction(string reaction) {
    m_Reactions.insert(reaction);
}