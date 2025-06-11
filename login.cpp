#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <functional> 

using namespace std;

const string DATABASE_FILE = "users.txt";

//Creating a simple hash function 
string hashPassword(const string& password) {
    hash<string> hasher;
    return to_string(hasher(password));
}

unordered_map<string, string> loadUsers() {
    unordered_map<string, string> users;
    ifstream file(DATABASE_FILE);
    string line;
    
    while (getline(file, line)) {
        stringstream ss(line);
        string username, hashedPassword;
        getline(ss, username, ',');
        getline(ss, hashedPassword);
        users[username] = hashedPassword;
    }

    return users;
}

// Register function
void registerUser() {
    string username ,password;

    cout << "\n.....Registration....." << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    if (username.empty() || password.empty()) {
        cout << "Username or password cannot be empty."<<endl;
        return;
    }

    unordered_map<string, string> users = loadUsers();

    if (users.find(username) != users.end()) {
        cout << "Username already exists. Try a different one.\n";
        return;
    }

    string hashed = hashPassword(password);

    ofstream file(DATABASE_FILE, ios::app);
    file << username << "," << hashed << "\n";

    cout << "Registration successful!\n";
}

// Login existing user
void loginUser() {
    string username, password;

    cout << "\n.....Login....." << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    unordered_map<string, string> users = loadUsers();

    auto it = users.find(username);
    if (it == users.end()) {
        cout << "Username not found.\n";
        return;
    }

    string hashed = hashPassword(password);
    if (it->second == hashed) {
        cout << "Login successful! Welcome, " << username << ".\n";
    } else {
        cout << "Error: Incorrect password.\n";
    }
}

// Main menu
int main() {
    int choice;

    do {
        cout << "\n ......Login and Registration System......" << endl;
        cout << "1. Register"<<endl;
        cout <<"2.Login"<<endl;
        cout <<"3.Exit"<<endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: 
            registerUser(); 
            break;
            case 2: 
            loginUser(); 
            break;
            case 3: 
            cout << ".....Exiting ....\n"; 
            break;
            default:
            cout << "Invalid option. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
