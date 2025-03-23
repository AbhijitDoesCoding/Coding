#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

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

class Participant : public Person {
public:
    Participant(const string& personName = "", const string& personEmail = "") 
        : Person(personName, personEmail) {}
};

class Judge : public Person {
private:
    string expertiseLevel;
    bool isAssigned; // 0 for not assigned, 1 for assigned

public:
    Judge(const string& personName = "", const string& personEmail = "", const string& expertise = "", bool assigned = 0) 
        : Person(personName, personEmail), expertiseLevel(expertise), isAssigned(assigned) {}

    string getExpertiseLevel() const { return expertiseLevel; }
    bool getAssignedStatus() const { return isAssigned; }
    void setAssignedStatus(bool status) { isAssigned = status; }
};

class Mentor : public Person {
public:
    Mentor(const string& personName = "", const string& personEmail = "") 
        : Person(personName, personEmail) {}
};

class Team {
    string teamName;
    vector<Participant> members;
    vector<Mentor> mentors;
    bool isAssigned; // 0 for not assigned, 1 for assigned

public:
    Team(const string& name, bool assigned = 0) : teamName(name), isAssigned(assigned) {}

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

    void addMentor(const Mentor& mentor) {
        if (mentors.size() < 2) {
            mentors.push_back(mentor);
        } else {
            cout << "Team can have a maximum of 2 mentors." << endl;
        }
    }

    string getTeamName() const {
        return teamName;
    }

    void display() const {
        cout << "Team Name: " << teamName << endl;
        cout << "Assigned: " << (isAssigned ? "Yes" : "No") << endl;
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
    }

    int getMemberCount() const {
        return members.size();
    }

    Participant& getMember(int index) {
        return members[index];
    }

    void setAssignedStatus(bool status) { isAssigned = status; }
    bool getAssignedStatus() const { return isAssigned; }
};

class Hackathon {
    string hackathonName;
    vector<Participant> participants;
    vector<Judge> judges;
    vector<Team> teams;

public:
    Hackathon(const string& name) : hackathonName(name) {}

    void addParticipant(const Participant& p) {
        participants.push_back(p);
        sortParticipants(); // Sort after adding
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

    void addJudge(const Judge& j) {
        judges.push_back(j);
        sortJudges(); // Sort after adding
    }

    void addTeam(const Team& t) {
        teams.push_back(t);
        sortTeams(); // Sort after adding
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
                        cout << i + 1 << ". " << team.getMember(i).getName() << endl;
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
            cout << judge.getName() << " (Expertise: " << judge.getExpertiseLevel() << ", Assigned: " << (judge.getAssignedStatus() ? "Yes" : "No") << ") ";
        }
        cout << endl;

        for (const auto& team : teams) {
            team.display();
        }
    }

    int getTeamsCount() const {
        return teams.size();
    }

    Team& getTeam(int index) {
        return teams[index];
    }

    // Method to add participants directly while creating teams
    void createTeamWithParticipants() {
        string teamName;
        cout << "Enter Team Name: ";
        getline(cin, teamName);
        Team newTeam(teamName); // Default assigned to 0

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

int main() {
    Hackathon hackathon("CodeFest 2024");

    int choice;
    do {
        cout << "\n=== Hackathon Management System ===" << endl;
        cout << "1. Add Participant\n";
        cout << "2. Add Judge\n";
        cout << "3. Create Team\n";
        cout << "4. Edit Team\n";
        cout << "5. Display Details\n";
        cout << "6. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

        switch (choice) {
            case 1: {
                string name, email;
                cout << "Enter Participant Name: ";
                getline(cin, name);
                cout << "Enter Participant Email: ";
                getline(cin, email);
                hackathon.addParticipant(Participant(name, email));
                cout << "Participant added successfully!" << endl;
                break;
            }
            case 2: {
                string name, email, expertise;
                cout << "Enter Judge Name: ";
                getline(cin, name);
                cout << "Enter Judge Email: ";
                getline(cin, email);
                cout << "Enter Judge Expertise Level: ";
                getline(cin, expertise);
                hackathon.addJudge(Judge(name, email, expertise));
                cout << "Judge added successfully!" << endl;
                break;
            }
            case 3:
                hackathon.createTeamWithParticipants();
                break;
            case 4: {
                if (hackathon.getTeamsCount() == 0) {
                    cout << "No teams available to edit." << endl;
                    break;
                }
                cout << "Available Teams:\n";
                for (int i = 0; i < hackathon.getTeamsCount(); ++i) {
                    cout << i + 1 << ". " << hackathon.getTeam(i).getTeamName() << endl;
                }
                int teamIndex;
                cout << "Select a team to edit (enter index): ";
                cin >> teamIndex;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
                hackathon.editTeam(teamIndex - 1);
                break;
            }
            case 5:
                hackathon.displayDetails();
                break;
            case 6:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice! Please choose again." << endl;
        }
    } while (choice != 6);

    return 0;
}
