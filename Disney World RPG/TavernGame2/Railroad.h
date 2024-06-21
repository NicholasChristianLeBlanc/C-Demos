#pragma once

#include "Location.h"

class Railroad : public Location {
private:
	vector<string> m_EntranceDialogue;
	vector<string> m_ExitDialogue;

	vector<string>::iterator m_EntranceDialogueIter;
	vector<string>::iterator m_ExitDialogueIter;
public:
	Railroad(string name = "Empty Station", string description = "It's an empty train station.");

	void AddStation(Location* station, string entranceDialogue, string exitDialogue);

	void DisplayCurrentLocation(Location* currentLocation);
	void DisplayDestination(Location* destination);
};