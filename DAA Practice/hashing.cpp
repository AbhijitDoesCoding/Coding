#include <bits/stdc++.h>
using namespace std;

class record
{
    int id, marks;
    char name[20];

    friend class student;
};

class hashing
{
    int id, pos;

public:
    hashing()
    {
        id = -1;
        pos = -1;
    }
    friend class student;
};

class student
{
public:
    record r;
    string file_name;
    hashing h_wr[10];
    hashing h_wor[10];
    int s = sizeof(record), count = 0;
    bool flag = false;

    student()
    {
        for (int i = 0; i < 10; i++)
        {
            h_wr[i].id = -1;
            h_wor[i].id = -1;
            h_wr[i].pos = -1;
            h_wor[i].pos = -1;
        }
        count = 0;
    }
    void createWr();
    void createWor();
    void searchWr();
    void searchWor();
    void display();
    void modifyWr();
    void modifyWor();
    void delete_recordWr();
    void delete_recordWor();
};

void student::createWor()
{
    while (true)
    {
        cout << "Enter ID: ";
        cin >> r.id;
        cout << "Enter Name: ";
        cin >> r.name;
        cout << "Enter Marks: ";
        cin >> r.marks;

        int index = r.id % 10;
        int originalIndex = index;
        bool inserted = false;

        for (int i = 0; i < 10; i++)
        {
            index = (originalIndex + i) % 10;
            if (h_wor[index].id == -1)
            {
                h_wor[index].id = r.id;
                h_wor[index].pos = count;

                fstream file(file_name, ios::binary | ios::in | ios::out);
                file.seekp(count * s, ios::beg);
                file.write((char *)&r, s);
                file.close();

                count++;
                inserted = true;
                cout << "Record inserted at index " << index << "\n";
                break;
            }
        }

        if (!inserted)
        {
            cout << "Hash table is full! Cannot add more records.\n";
            break;
        }

        char choice;
        cout << "Do you want to add another record? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N')
            break;
    }
}

void student::createWr()
{
    while (true)
    {
        cout << "Enter ID: ";
        cin >> r.id;
        cout << "Enter Name: ";
        cin >> r.name;
        cout << "Enter Marks: ";
        cin >> r.marks;

        int index = r.id % 10;

        if (h_wr[index].id == -1)
        {
            h_wr[index].id = r.id;
            h_wr[index].pos = count;

            fstream file(file_name, ios::binary | ios::in | ios::out);
            file.seekp(count * s, ios::beg);
            file.write((char *)&r, s);
            file.close();

            count++;
            cout << "Record inserted at index " << index << "\n";
        }
        else
        {
            int existingHome = h_wr[index].id % 10;

            if (existingHome == index)
            {
                bool inserted = false;
                for (int i = 1; i < 10; i++)
                {
                    int new_index = (index + i) % 10;
                    if (h_wr[new_index].id == -1)
                    {
                        h_wr[new_index].id = r.id;
                        h_wr[new_index].pos = count;

                        fstream file(file_name, ios::binary | ios::in | ios::out);
                        file.seekp(count * s, ios::beg);
                        file.write((char *)&r, s);
                        file.close();

                        count++;
                        cout << "Record inserted at index " << new_index << "\n";
                        inserted = true;
                        break;
                    }
                }
                if (!inserted)
                {
                    cout << "Hash table is full! Cannot insert.\n";
                    break;
                }
            }
            else
            {
                hashing displacedHash = h_wr[index];
                record displacedRecord;

                fstream file(file_name, ios::binary | ios::in | ios::out);

                file.seekg(displacedHash.pos * s, ios::beg);
                file.read((char *)&displacedRecord, s);

                h_wr[index].id = r.id;
                h_wr[index].pos = displacedHash.pos;

                file.seekp(displacedHash.pos * s, ios::beg);
                file.write((char *)&r, s);

                bool inserted = false;
                for (int i = 1; i < 10; i++)
                {
                    int new_index = (index + i) % 10;
                    if (h_wr[new_index].id == -1)
                    {
                        h_wr[new_index].id = displacedRecord.id;
                        h_wr[new_index].pos = count;

                        file.seekp(count * s, ios::beg);
                        file.write((char *)&displacedRecord, s);

                        count++;
                        inserted = true;
                        cout << "Displaced record inserted at index " << new_index << "\n";
                        break;
                    }
                }

                file.close();

                if (!inserted)
                {
                    cout << "Hash table is full! Cannot reinsert displaced record.\n";
                    break;
                }
            }
        }

        char choice;
        cout << "Do you want to add another record? (y/n): ";
        cin >> choice;
        if (choice == 'n' || choice == 'N')
            break;
    }
}

void student::searchWor()
{
    cout << "Enter ID to search: ";
    cin >> r.id;
    int index = r.id % 10;

    // Check the slot
    if (h_wor[index].id == r.id)
    {
        fstream file(file_name, ios::binary | ios::in);
        file.seekg(h_wor[index].pos * s, ios::beg);
        file.read((char *)&r, s);
        file.close();
        cout << "Record found!\n";
        cout << "ID: " << r.id << ", Name: " << r.name << ", Marks: " << r.marks << endl;
    }
    else
    {
        cout << "Record not found!\n";
    }
}

void student::searchWr()
{
    int searchId;
    cout << "Enter ID to search: ";
    cin >> searchId;
    int index = searchId % 10;

    // Check the current slot and subsequent slots
    bool found = false;
    for (int i = 0; i < 10; i++) // Checking up to 10 slots in case of displacement
    {
        int currentIndex = (index + i) % 10;
        if (h_wr[currentIndex].id == searchId)
        {
            record temp;
            fstream file(file_name, ios::binary | ios::in);
            file.seekg(h_wr[currentIndex].pos * s, ios::beg);
            file.read((char *)&temp, s);
            file.close();
            cout << "Record found!\n";
            cout << "ID: " << temp.id << ", Name: " << temp.name << ", Marks: " << temp.marks << endl;
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Record not found!\n";
    }
}

void student::display()
{
    cout << "Displaying all records:\n";
    fstream file(file_name, ios::binary | ios::in);
    record temp;
    for (int i = 0; i < count; i++)
    {
        file.seekg(i * s, ios::beg);
        file.read((char *)&temp, s);
        cout << "ID: " << temp.id << ", Name: " << temp.name << ", Marks: " << temp.marks << endl;
    }
    file.close();
}

void student::modifyWr()
{
    int searchId;
    cout << "Enter ID to modify: ";
    cin >> searchId;
    int index = searchId % 10;

    bool found = false;

    // Check up to 10 slots in case of displacement
    for (int i = 0; i < 10; i++)
    {
        int currentIndex = (index + i) % 10;
        if (h_wr[currentIndex].id == searchId)
        {
            // Record found, modify it
            record temp;
            fstream file(file_name, ios::binary | ios::in | ios::out);
            file.seekg(h_wr[currentIndex].pos * s, ios::beg);
            file.read((char *)&temp, s);

            cout << "Current Record: ID: " << temp.id << ", Name: " << temp.name << ", Marks: " << temp.marks << endl;
            cout << "Enter new Name: ";
            cin >> temp.name;
            cout << "Enter new Marks: ";
            cin >> temp.marks;

            file.seekp(h_wr[currentIndex].pos * s, ios::beg);
            file.write((char *)&temp, s);
            file.close();
            cout << "Record modified successfully!\n";
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Record not found!\n";
    }
}

void student::modifyWor()
{
    cout << "Enter ID to modify: ";
    cin >> r.id;
    int index = r.id % 10;

    bool found = false;

    // Check if the record exists in the hashed index
    if (h_wor[index].id == r.id)
    {
        // Record found, modify it
        fstream file(file_name, ios::binary | ios::in | ios::out);
        file.seekg(h_wor[index].pos * s, ios::beg);
        file.read((char *)&r, s);

        cout << "Current Record: ID: " << r.id << ", Name: " << r.name << ", Marks: " << r.marks << endl;
        cout << "Enter new Name: ";
        cin >> r.name;
        cout << "Enter new Marks: ";
        cin >> r.marks;

        file.seekp(h_wor[index].pos * s, ios::beg);
        file.write((char *)&r, s);
        file.close();
        cout << "Record modified successfully!\n";
        found = true;
    }
    else
    {
        // Check for the record in case of displacement
        for (int i = 0; i < 10; i++)
        {
            int currentIndex = (index + i) % 10;
            if (h_wor[currentIndex].id == r.id)
            {
                // Record found, modify it
                fstream file(file_name, ios::binary | ios::in | ios::out);
                file.seekg(h_wor[currentIndex].pos * s, ios::beg);
                file.read((char *)&r, s);

                cout << "Current Record: ID: " << r.id << ", Name: " << r.name << ", Marks: " << r.marks << endl;
                cout << "Enter new Name: ";
                cin >> r.name;
                cout << "Enter new Marks: ";
                cin >> r.marks;

                file.seekp(h_wor[currentIndex].pos * s, ios::beg);
                file.write((char *)&r, s);
                file.close();
                cout << "Record modified successfully!\n";
                found = true;
                break;
            }
        }
    }

    if (!found)
    {
        cout << "Record not found!\n";
    }
}

int main()
{
    student s1;
    int ch;
    cout << "Welcome to the Student Record System!\n";
    cout << "Choose the hashing method:\n1. With Replacement\n2. Without Replacement\n";
    cout << "Enter your choice: ";
    cin >> ch;

    if (ch == 1)
    {
        s1.flag = true;
        cout << "You have chosen With Replacement method.\n";
    }

    else if (ch == 2)
    {
        s1.flag = false;
        cout << "You have chosen Without Replacement method.\n";
    }

    else
    {
        cout << "Invalid choice! Exiting...\n";
        return 0;
    }

    cout << "Enter the file name where you want to save this data: ";
    cin >> s1.file_name;
    fstream file(s1.file_name, ios::binary | ios::in | ios::out | ios::app);
    if (!file)
    {
        cout << "File not found! Creating a new file...\n";
        file.open(s1.file_name, ios::binary | ios::out | ios::app);
        file.close();
    }
    else
    {
        cout << "File opened successfully!\n";
    }

    if (s1.flag)
        while (1)
        {
            cout << "\n--- Student Record System Menu ---\n";
            cout << "1. Create Record\n2. Search Record\n3. Display Record\n4. Modify Record\n5. Exit\n";
            cout << "Enter your choice: ";
            cin >> ch;
            switch (ch)
            {
            case 1:
                s1.createWr();
                break;
            case 2:
                s1.searchWr();
                break;
            case 3:
                s1.display();
                break;
            case 4:
                s1.modifyWr();
                break;

            case 5:
                exit(0);
            default:
                cout << "Invalid choice! Please try again.\n";
            }
        }
    else
        while (1)
        {
            cout << "\n--- Student Record System Menu ---\n";
            cout << "1. Create Record\n2. Search Record\n3. Display Record\n4. Modify Record\n5. Exit\n";
            cout << "Enter your choice: ";
            cin >> ch;
            switch (ch)
            {
            case 1:
                s1.createWor();
                break;
            case 2:
                s1.searchWor();
                break;
            case 3:
                s1.display();
                break;
            case 4:
                s1.modifyWor();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice! Please try again.\n";
            }
        }
    return 0;
}
