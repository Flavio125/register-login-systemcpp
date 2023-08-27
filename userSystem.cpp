#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void signup(string, string);
bool userExists(string);
bool login(string, string);

bool LOGGED = false;


int main(){
    int choise;
    string username;
    string password;

    cout<<"Dear Sir, would you like to Sign-up(1) or to Sign-in(2)?"<<endl;
    cin >> choise;
    if(choise == 1){
        cout<<"How would you like to be called -->"; cin>>username; cout<<endl;
        if(userExists(username)){
            while(userExists(username)){
                username = "";
                cout<<"Insert another nickname -->"; cin >> username; 
                userExists(username);
            }
            cout<<"Perfect, now type your password -->";cin >> password;
            signup(username, password);
            system("pause");
        }else{
            //writeUsername(username);
            cout<<"Perfect, now type your password -->";cin >> password;
            signup(username, password);
            system("pause");
        }
    }else if (choise == 2){
        cout<<"Type your nickname -->"; cin>>username; cout<<endl;
        if(userExists(username)){
            cout<<"Type your password -->"; cin>>password;
            if(login(username,password)){
                system("pause");
            }else{
                while(!LOGGED){
                    cout<<"Type your password -->"; cin>>password;
                    login(username,password);
                }
                system("pause");
            }
        }else{
            cout<<"User don't found!"<<endl;
            system("pause");
        }
    }

    return 0;
}


void signup(string username, string password){
    ofstream DB;
    DB.open(username + ".txt");
    DB << password; 
    DB.close();
    cout<<"Signed-up successfully"<<endl;
}

bool login(string user, string psw){
    ifstream USERNAME;
    string pass;
    USERNAME.open(user + ".txt");
    if(USERNAME){
        while(getline(USERNAME,pass)){
            if(psw == pass){
                LOGGED = true;
                cout<<"Logged-in!"<<endl;
                USERNAME.close();
                return true;
            }else{
                cout<<"Password doesn't match!"<<endl<<endl;
                USERNAME.close();
                return false;
            }
        }
    }else{
        USERNAME.close();
        cout<<"Database error!"<<endl;
    }
}

bool userExists(string username){
    ifstream USERNAME;
    USERNAME.open(username + ".txt");
    if(USERNAME){
        USERNAME.close();
        return true;
    }else{
        USERNAME.close();
        return false;
    }
}