#include "Railroad.h"

Railroad::Railroad(string name, string description) : Location(name, description) {
	m_Name = name;
	m_Description = description;
	m_IsTrain = true;
}

void Railroad::AddStation(Location* station, string entranceDialogue, string exitDialogue) {
	AddArea(station);
	m_EntranceDialogue.push_back(entranceDialogue);
	m_ExitDialogue.push_back(exitDialogue);
}

void Railroad::DisplayCurrentLocation(Location* currentLocation) {
    m_EntranceDialogueIter = m_EntranceDialogue.begin() + AreaNumber(currentLocation);

    cout << endl << m_Name << endl;
    cout << "----------------------------------" << endl;
    cout << m_Description << endl << *m_EntranceDialogueIter << endl << endl;

    int locationCounter = 0;
    cout << "There are the following stations you can get off at:" << endl;
    for (int i = 0; i < m_Areas.size(); i++) {
        cout << locationCounter << ". " << m_Areas[i]->GetName() << endl;
        locationCounter++;
    }
}

void Railroad::DisplayDestination(Location* destination) {
    m_ExitDialogueIter = m_ExitDialogue.begin() + AreaNumber(destination);

    cout << endl << m_Name << endl;
    cout << "----------------------------------" << endl;
    cout << *m_ExitDialogueIter << endl << endl;
}