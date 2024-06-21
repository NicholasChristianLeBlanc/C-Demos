#pragma once

#include "Location.h"
#include <set>

class Ride : public Location {
private:
	std::set<string> m_Reactions;

public: 
	Ride(string name = "Empty Ride", string description = "Looks like this ride doesn't exist... strange");

	void AddReaction(string reaction);
};