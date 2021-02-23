#include <iostream>
#include <fstream>

void line(char n = '-', int v = 50);

void Register();

int login();

int main(){
    int choice, r;
    while(true){
        std :: cout << "Login and register system\nRegister[1]\nLogin[2]\nYour choice: ";
        std :: cin >> choice;
        if(choice == 1){
            line();
            Register();
            line();
        }
        else if(choice == 2){
            line();
            r = login();
            if(r == 1){
                std :: cout << "Successfully login\n";
                break;
            }
            else{
                std :: cout << "Username or password wrongs\n";
                line();
            }
            
        }
        else{
            std :: cout << "ERROR, try again\n";
            line();
        }
    }
    system("pause");
    return 0;
}

void Register(){
    std :: string user, password, line, test;
    std :: cout << "Select a username: ";
    std :: cin >> user;
    std :: cout << "Select a password: ";
    std :: cin >> password;
    test = user + " | " + password;
    std :: ifstream arquiveR{"database.txt"};
    std :: ofstream arquiveW{"database.txt", std :: ios :: app};
    if(arquiveR.is_open() && arquiveW.is_open()){
        while(getline(arquiveR, line)){
            if(test == line){
                std :: cout << "Error, username in use, try again\n";
                return;
            }
        }
        arquiveW << test << "\n";
    }
    arquiveR.close();
    arquiveW.close();
}

int login(){
    std :: string user, password, test, line;
    std :: cout << "Username: ";
    std :: cin >> user;
    std :: cout << "Password: ";
    std :: cin >> password;
    test = user + " | " + password;
    std :: ifstream arquiveR("database.txt");
    if(arquiveR.is_open()){
        while(getline(arquiveR, line)){
            if(test == line){
                arquiveR.close();
                return 1;
            }
        }
    }
    arquiveR.close();
    return 0;
}

void line(char n, int v){
    for(int x{0}; x < v; x++){
        std :: cout << n;
    }
    std :: cout << "\n";
}