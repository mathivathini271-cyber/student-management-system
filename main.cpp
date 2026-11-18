#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Student
{
    int id;
    string name;
    int age;
    string department;
    int marks;
};

void saveStudents(Student s[], int count)
{
    ofstream file("students.txt");

    for(int i = 0; i < count; i++)
    {
        file << s[i].id << " "
             << s[i].name << " "
             << s[i].age << " "
             << s[i].department << " "
             << s[i].marks << endl;
    }

    file.close();
}

void loadStudents(Student s[], int &count)
{
    ifstream file("students.txt");

    count = 0;

    while(count < 100 &&
          file >> s[count].id
               >> s[count].name
               >> s[count].age
               >> s[count].department
               >> s[count].marks)
    {
        count++;
    }

    file.close();
}

int main()
{
    int choice;
    Student s[100];
    int count = 0;
    loadStudents(s, count);

    do
    {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Update Student";
        cout << "\n5. Delete Student";
        cout << "\n6. Exit";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "\nEnter Student ID: ";
                cin >> s[count].id;

                cout << "Enter Student Name: ";
                cin >> s[count].name;

                cout << "Enter Age: ";
                cin >> s[count].age;

                cout << "Enter Department: ";
                cin >> s[count].department;

                cout << "Enter Marks: ";
                cin >> s[count].marks;

                count++;
                saveStudents(s, count);

                cout << "\nStudent Added Successfully!";
                break;

            case 2:
                cout << "\n===== STUDENT DETAILS =====";

                for(int i = 0; i < count; i++)
                {
                    cout << "\nID: " << s[i].id;
                    cout << "\nName: " << s[i].name;
                    cout << "\nAge: " << s[i].age;
                    cout << "\nDepartment: " << s[i].department;
                    cout << "\nMarks: " << s[i].marks;
                    cout << "\n----------------------";
                }
                break;
            
            case 3:
{
    int searchID;
    bool found = false;

    cout << "\nEnter Student ID to Search: ";
    cin >> searchID;

    for(int i = 0; i < count; i++)
    {
        if(s[i].id == searchID)
        {
            cout << "\nStudent Found!";
            cout << "\nID: " << s[i].id;
            cout << "\nName: " << s[i].name;
            cout << "\nAge: " << s[i].age;
            cout << "\nDepartment: " << s[i].department;
            cout << "\nMarks: " << s[i].marks;

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nStudent Not Found!";
    }

    break;
}

case 4:
{
    int updateID;
    bool found = false;

    cout << "\nEnter Student ID to Update: ";
    cin >> updateID;

    for(int i = 0; i < count; i++)
    {
        if(s[i].id == updateID)
        {
            cout << "\nEnter New Name: ";
            cin >> s[i].name;

            cout << "Enter New Age: ";
            cin >> s[i].age;

            cout << "Enter New Department: ";
            cin >> s[i].department;

            cout << "Enter New Marks: ";
            cin >> s[i].marks;

            cout << "\nStudent Updated Successfully!";
            
            saveStudents(s, count);

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nStudent Not Found!";
    }

    break;
}

case 5:
{
    int deleteID;
    bool found = false;

    cout << "\nEnter Student ID to Delete: ";
    cin >> deleteID;

    for(int i = 0; i < count; i++)
    {
        if(s[i].id == deleteID)
        {
            for(int j = i; j < count - 1; j++)
            {
                s[j] = s[j + 1];
            }

            count--;
            saveStudents(s, count);

            cout << "\nStudent Deleted Successfully!";

            found = true;
            break;
        }
    }

    if(!found)
    {
        cout << "\nStudent Not Found!";
    }

    break;
}

            case 6:
                cout << "\nThank You!";
                break;

            default:
                cout << "\nFeature not implemented yet!";
        }

    } while(choice != 6);

    return 0;
}