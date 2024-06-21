#include <stdio.h>
#include "Player.h"

Player::Player(string name) {
    m_Name = name;
    m_CurrentLocation = 0;
}

void Player::SetLocation(Location* location) {
    m_CurrentLocation = location;
}

Location* Player::GetLocation() {
    return m_CurrentLocation;
}

void Player::DisplayReactions() {
    if (!m_Reactions.empty()) {
        cout << endl << "Your reactions:" << endl;
        cout << "----------------------------------" << endl;

        for (string reaction : m_Reactions)
        {
            cout << "- " << reaction << endl;
        }
        cout << endl;
    }
    else {
        cout << endl << "You do not have any reactions discovered" << endl;
    }
}

void Player::AddReactions(std::set<string> reactions) {
    for (string reaction : reactions)
    {
        m_Reactions.insert(reaction);
    }
}

string Player::GetName() {
    return m_Name;
}