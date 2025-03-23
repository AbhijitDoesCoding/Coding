#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>
#include <utility>
//#include <bits/stdc++.h> // This header file includes all the standard library. It is not recommended to use this header file as it increases the compilation time and also it is not a good practice to include all the libraries. Instead, include only the required libraries.
using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "\n--- Hackathon Management System Menu ---\n";
    cout << "1. Create Team\n";
    cout << "2. Add Judge\n";
    cout << "3. Display Hackathon Details\n";
    cout << "4. Add Room\n";
    cout << "5. Evaluate Teams\n";
    cout << "6. Display Unassigned Teams and Judges\n";
    cout << "7. Exit\n";
    cout << "Choose an option: ";
}

// Base class Person
class Person {
protected:
    string name;
    string email;

public:
    Person(const string& personName = "", const string& personEmail = "") 
        : name(personName), email(personEmail) {}

    string getName() const { return name; }
    string getEmail() const { return email; }
};
// Derived classes Participant, Mentor, and Judge - done
class Participant : public Person {
public:
    Participant(const string& personName = "", const string& personEmail = "") 
        : Person(personName, personEmail) {}
};
// Derived class Mentor - done
class Mentor : public Person {
public:
    Mentor(const string& personName = "", const string& personEmail = "") 
        : Person(personName, personEmail) {}
};

class Judge : public Person {
private:
    string expertiseLevel;
    string expertise;
    bool assigned;

public:
    Judge(const string& personName = "", const string& personEmail = "", const string& expertiseLevel = "", const string& expertise = "") 
        : Person(personName, personEmail), expertiseLevel(expertiseLevel), expertise(expertise), assigned(false) {}
    string getExpertiseLevel() const { return expertiseLevel; }
    string getExpertise() const {return expertise;}
    bool isAssigned() const { return assigned; }
    void assign() { assigned = true; }
    void unassign() { assigned = false; }
};
// Derived class Team - done
class Team {
private:
    string teamName;
    vector<Participant> members;
    vector<Mentor> mentors;
    bool assigned;

public:
    Team(const string& name = "") : teamName(name), assigned(false) {}

    string getTeamName() const { return teamName; }
    
    void addMember(const Participant& member) {
        if (members.size() < 5) {
            members.push_back(member);
        } else {
            cout << "Team is already full (max 5 members)." << endl;
        }
    }

    void removeMember(int index) {
        if (index < 0 || index >= members.size()) {
            cout << "Invalid member index." << endl;
            return;
        }
        members.erase(members.begin() + index);
    }
// Add Mentor function - done Issue in output solved
    void addMentor(const Mentor& mentor) {
        if (mentors.size() < 2) {
            mentors.push_back(mentor);
        } else {
            cout << "Team can have a maximum of 2 mentors." << endl;
        }
    }
// Display function - done Issue in output solved
    void display() const {
        cout << "Team Name: " << teamName << endl;
        cout << "Members: ";
        for (const auto& member : members) {
            cout << member.getName() << " ";
        }
        cout << endl;
        cout << "Mentors: ";
        for (const auto& mentor : mentors) {
            cout << mentor.getName() << " ";
        }
        cout << endl;
        cout << "Assigned: " << (assigned ? "Yes" : "No") << endl;
    }

    int getMemberCount() const {
        return members.size();
 }

    const vector<Participant>& getMembers() const {
        return members;
    }

    const vector<Mentor>& getMentors() const {
        return mentors;
    }

    bool isAssigned() const { return assigned; }
    void assign() { assigned = true; }
    void unassign() { assigned = false; }
};
// Derived class Room - done Issue in output solved
class Room {
private:
    string roomName;
    vector<Judge> judges;
    vector<Team> teams;

public:
    Room(const string& name) : roomName(name) {}

    string getRoomName() const { return roomName; }

    void addJudge(const Judge& judge) {
        judges.push_back(judge);
    }

    void addTeam(const Team& team) {
        teams.push_back(team);
    }

    void display() const {
        cout << "Room Name: " << roomName << endl;
        cout << "Judges: ";
        for (const auto& judge : judges) {
            cout << judge.getName() << " ";
        }
        cout << endl;
        cout << "Teams: ";
        for (const auto& team : teams) {
            cout << team.getTeamName() << " ";
        }
        cout << endl;
    }

    const vector<Judge>& getJudges() const {
        return judges;
    }

    const vector<Team>& getTeams() const {
        return teams;
    }
};
// Derived 
class Hackathon {
private:
    string hackathonName;
    vector<Participant> participants;
    vector<Judge> judges;
    vector<Team> teams;
    vector<Room> rooms;

public:
    Hackathon(const string& name) : hackathonName(name) {}

    void addParticipant(const Participant& p) {
        participants.push_back(p);
        sortParticipants(); // Sort after adding
    }

    void addJudge(const Judge& j) {
        judges.push_back(j);
        sortJudges(); // Sort after adding
    }

    void addTeam(const Team& t) {
        teams.push_back(t);
        sortTeams(); // Sort after adding
    }

    void addRoom(const Room& r) {
        rooms.push_back(r);
    }

    void editTeam(int index) {
        if (index < 0 || index >= teams.size()) {
            cout << "Invalid team index." << endl;
            return;
        }

        Team& team = teams[index];
        int choice;
        do {
            cout << "\nEditing Team: " << team.getTeamName() << endl;
            cout << "1. Add Participant\n";
            cout << "2. Remove Participant\n";
            cout << "3. Add Mentor\n";
            cout << "4. Display Team Details\n";
            cout << "5. Go Back\n";
            cout << "Choose an option: ";
            cin >> choice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

            switch (choice) {
                case 1: { // Add Participant
                    if (participants.empty()) {
                        cout << "No available participants to add." << endl;
                        break;
                    }

                    cout << "Available Participants:\n";
                    for (int i = 0; i < participants.size(); ++i) {
                        cout << i + 1 << ". " << participants[i].getName() << endl;
                    }

                    int memberIndex;
                    cout << "Select a participant to add (enter index): ";
                    cin >> memberIndex;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

                    if (memberIndex < 1 || memberIndex > participants.size()) {
                        cout << "Invalid index." << endl;
                    } else {
                        team.addMember(participants[memberIndex - 1]);
                        cout << "Participant added successfully!" << endl;
                    }
                    break;
                }
                case 2: { // Remove Participant

    if (team.getMemberCount() == 0) {

        cout << "No members to remove." << endl;

        break;

    }


    cout << "Current Members:\n";

    for (int i = 0; i < team.getMemberCount(); ++i) {

        cout << i + 1 << ". " << team.getMembers()[i].getName() << endl; // Change made here

    }


    int removeIndex;

    cout << "Select a member to remove (enter index): ";

    cin >> removeIndex;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer


    team.removeMember(removeIndex - 1);

    cout << "Participant removed successfully!" << endl;

    break;

}
                case 3: { // Add Mentor
                    string name, email;
                    cout << "Enter Mentor Name: ";
                    getline(cin, name);
                    cout << "Enter Mentor Email: ";
                    getline(cin, email);
                    team.addMentor(Mentor(name, email));
                    cout << "Mentor added successfully!" << endl;
                    break;
                }
                case 4: // Display Team Details
                    team.display();
                    break;
                case 5: // Go Back
                    cout << "Going back to main menu." << endl;
                    break;
                default:
                    cout << "Invalid choice! Please choose again." << endl;
            }
        } while (choice != 5);
    }

    void displayDetails() const {
        cout << "Hackathon Name: " << hackathonName << endl;

        cout << "Judges: ";
        for (const auto& judge : judges) {
            cout << judge.getName() << " (Expertise: " << judge.getExpertiseLevel() << ") ";
        }
        cout << endl;

        for (const auto& team : teams) {
            team.display();
        }

        for (const auto& room : rooms) {
            room.display();
        }

        char saveOption;
        cout << "Do you want to save the hackathon details to a file? (y/n): ";
        cin >> saveOption;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

        if (saveOption == 'y' || saveOption == 'Y') {
            ofstream outFile("Hackathon_Details.txt");
            if (!outFile) {
                cout << "Error opening file for writing." << endl;
                return;
            }

            outFile << "Hackathon Name: " << hackathonName << endl;

            outFile << "Judges: ";
            for (const auto& judge : judges) {
                outFile << judge.getName() << " (Expertise: " << judge.getExpertiseLevel() << ") ";
            }
            outFile << endl;

            for (const auto& team : teams) {
                outFile << "Team Name: " << team.getTeamName() << endl;
                outFile << "Members: ";
                for (const auto& member : team.getMembers()) {
                    outFile << member.getName() << " ";
                }
                outFile << endl;
                outFile << "Mentors: ";
                for (const auto& mentor : team.getMentors()) {
                    outFile << mentor.getName() << " ";
                }
                outFile << endl;
                outFile << "Assigned: " << (team.isAssigned() ? "Yes" : "No") << endl;
            }

            for (const auto& room : rooms) {
                outFile << "Room Name: " << room.getRoomName() << endl;
                outFile << "Judges: ";
                for (const auto& judge : room.getJudges()) {
                    outFile << judge.getName() << " ";
                }
                outFile << endl;
                outFile << "Teams: ";
                for (const auto& team : room.getTeams()) {
                    outFile << team.getTeamName() << " ";
                }
                outFile << endl;
            }

            outFile.close();
            cout << "Hackathon details saved to Hackathon_Details.txt" << endl;
        }
    }

    void displayRoomData() const {
        cout << "\n--- Room Data ---\n";
        for (const auto& room : rooms) {
            room.display();
        }

        cout << "\nUnassigned Judges: ";
        for (const auto& judge : judges) {
            if (!judge.isAssigned()) {
                cout << judge.getName() << " ";
            }
        }
        cout << endl;

        cout << "Unassigned Teams: ";
        for (const auto& team : teams) {
            if (!team.isAssigned()) {
                cout << team.getTeamName() << " ";
            }
        }
        cout << endl;
    }

    void displayJudgeDetails() const {
        cout << "\n--- Judges ---\n";
        for (int i = 0; i < judges.size(); ++i) {
            cout << i + 1 << ". " << judges[i].getName() << endl;
        }

        int judgeIndex;
        cout << "Select a judge to view details (enter index): ";
        cin >> judgeIndex;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

        if (judgeIndex < 1 || judgeIndex > judges.size()) {
            cout << "Invalid index." << endl;
        } else {
            const Judge& judge = judges[judgeIndex - 1];
            cout << "Name: " << judge.getName() << endl;
            cout << "Email: " << judge.getEmail() << endl;
            cout << "Expertise: " << judge.getExpertise() << endl;
            cout << "Expertise Level: " << judge.getExpertiseLevel() << endl;
            cout << "Assigned: " << (judge.isAssigned() ? "Yes" : "No") << endl;
        }
    }

    void displayTeamDetails() const {
        cout << "\n--- Teams ---\n";
        for (int i = 0; i < teams.size(); ++i) {
            cout << i + 1 << ". " << teams[i]. getTeamName() << endl;
        }

        int teamIndex;
        cout << "Select a team to view details (enter index): ";
        cin >> teamIndex;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

        if (teamIndex < 1 || teamIndex > teams.size()) {
            cout << "Invalid index." << endl;
        } else {
            const Team& team = teams[teamIndex - 1];
            team.display();
        }
    }

    void displayUnassignedTeams() const {
        cout << "\n--- Unassigned Teams ---\n";
        for (const auto& team : teams) {
            if (!team.isAssigned()) {
                cout << team.getTeamName() << "\n";
            }
        }
    }

    void displayUnassignedJudges() const {
        cout << "\n--- Unassigned Judges ---\n";
        for (const auto& judge : judges) {
            if (!judge.isAssigned()) {
                cout << judge.getName() << " (" << judge.getEmail() << ") - " 
                    << judge.getExpertise() << " (" << judge.getExpertiseLevel() << ")\n";
            }
        }
    }

    void createTeamWithParticipants() {
        string teamName;
        cout << "Enter Team Name: ";
        getline(cin, teamName);
        Team newTeam(teamName);

        while (newTeam.getMemberCount() < 5) {
            string memberName, memberEmail;
            cout << "Enter Participant Name (or 'done' to finish): ";
            getline(cin, memberName);
            if (memberName == "done") break;
            cout << "Enter Participant Email: ";
            getline(cin, memberEmail);
            newTeam.addMember(Participant(memberName, memberEmail));
            cout << "Participant added successfully!" << endl;
        }
        addTeam(newTeam);
        cout << "Team created successfully!" << endl;
    }

    void createRoom() {
        string roomName;
        cout << "Enter Room Name: ";
        getline(cin, roomName);
        Room newRoom(roomName);

        int numJudges, numTeams;
        cout << "Enter number of judges: ";
        cin >> numJudges;
        cout << "Enter number of teams: ";
        cin >> numTeams;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

        int judgeCount = 0, teamCount = 0;
        for (auto& judge : judges) {
            if (!judge.isAssigned() && judgeCount < numJudges) {
                judge.assign();
                newRoom.addJudge(judge);
                judgeCount++;
            }
        }

        for (auto& team : teams) {
            if (!team.isAssigned() && teamCount < numTeams) {
                team.assign();
                newRoom.addTeam(team);
                teamCount++;
            }
        }

        addRoom(newRoom);
        cout << "Room created successfully!" << endl;
    }

    int getTeamsCount() const {
        return teams.size();
    }

    Team& getTeam(int index) {
        return teams[index];
    }

private:
    void sortParticipants() {
        sort(participants.begin(), participants.end(), [](const Participant& a, const Participant& b) {
            return a.getName() < b.getName();
        });
    }

    void sortJudges() {
        sort(judges.begin(), judges.end(), [](const Judge& a, const Judge& b) {
            return a.getName() < b.getName();
        });
    }

    void sortTeams() {
        sort(teams.begin(), teams.end(), [](const Team& a, const Team& b) {
            return a.getTeamName() < b.getTeamName();
        });
    }
};

bool authenticateUser   () {
    string username, password;
    const string correctUsername = "Admin";
    const string correctPassword = "admin@1234";

    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    return (username == correctUsername && password == correctPassword);
}

void evaluateTeams(Hackathon& hackathon) {
    vector<pair<int, Team>> teamScores;

    for (int i = 0; i < hackathon.getTeamsCount(); ++i) {
        Team& team = hackathon.getTeam(i);
        int score;
        cout << "Enter score for team " << team.getTeamName() << ": ";
        cin >> score;
        teamScores.push_back(make_pair(score, team));
    }

    sort(teamScores.begin(), teamScores.end(), [](const pair<int, Team>& a, const pair<int, Team>& b) {
        return a.first > b.first; // Sort in descending order of scores
    });

    cout << "\n--- Team Rankings ---\n";
    for (const auto& teamScore : teamScores) {
        cout << "Team: " << teamScore.second.getTeamName () << " - Score: " << teamScore.first << endl;
    }

    char saveOption;
    cout << "Do you want to save the results to a file? (y/n): ";
    cin >> saveOption;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

    if (saveOption == 'y' || saveOption == 'Y') {
        ofstream outFile("Results.txt");
        if (!outFile) {
            cout << "Error opening file for writing." << endl;
            return;
        }

        outFile << "--- Team Rankings ---\n";
        for (const auto& teamScore : teamScores) {
            outFile << "Team: " << teamScore.second.getTeamName() << " - Score: " << teamScore.first << endl;
        }

        outFile.close();
        cout << "Results saved to Results.txt" << endl;
    }
}

int main() {
    if (!authenticateUser   ()) {
        cout << "Authentication failed. Exiting program." << endl;
        return 0;
    }

    string hackathonName;
    cout << "Enter Hackathon Name: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, hackathonName);
    Hackathon hackathon(hackathonName);

    int choice;
    do {
        displayMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

        switch (choice) {
            case 1: { // Create Team
                hackathon.createTeamWithParticipants();
                break;
            }
            case 2: { // Add Judge
                string name, email, expertise, expertiseLevel;
                cout << "Enter Judge Name: ";
                getline(cin, name);
                cout << "Enter Judge Email: ";
                getline(cin, email);
                cout << "Enter Judge Expertise Level: ";
                getline(cin, expertiseLevel); // New input for expertise level
                cout << "Enter Judge Expertise: ";
                getline(cin, expertise); // New input for expertise
                hackathon.addJudge(Judge(name, email, expertiseLevel, expertise)); // Pass both expertiseLevel and expertise
                cout << "Judge added successfully!" << endl;
                break;
            }
            case 3: { // Display Hackathon Details
                int displayChoice;
                cout << "\n--- Display Options ---\n";
                cout << "1. Show Room Data\n";
                cout << "2. Show Judge Details\n";
                cout << "3. Show Team Details\n";
                cout << "4. Show All Details\n";
                cout << "Choose an option: ";
                cin >> displayChoice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

                switch (displayChoice) {
                    case 1:
                        hackathon.displayRoomData();
                        break;
                    case 2:
                        hackathon.displayJudgeDetails();
                        break;
                    case 3:
                        hackathon.displayTeamDetails();
                        break;
                    case 4:
                        hackathon.displayDetails();
                        break;
                    default:
                        cout << "Invalid choice! Please choose again." << endl;
                }
                break;
            }
            case 4: { // Add Room
                hackathon.createRoom();
                break;
            }
            case 5: { // Evaluate Teams
                evaluateTeams(hackathon);
                break;
            }
            case 6: { // Display Unassigned Teams and Judges
                hackathon.displayUnassignedTeams();
                hackathon.displayUnassignedJudges();
                break;
            }
            case 7: // Exit
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please choose again." << endl;
        }
    } while (choice != 7);

    return 0;
}