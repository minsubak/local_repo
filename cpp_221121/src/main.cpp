/**
 * @file    cpp_221121.cpp
 * @author  박민수 - 20194013(Mindou) (minsu5875@naver.com)
 * @brief   cpp pratice lecture code
 * @version not exsit
 * @date    2022-11-21
 * 
 * @copyright Copyright by Mindou (c) 2022
 * 
 */

#include "main.h"

/*Chapter10 - P1****************************************************************/

int main() {

    int ch, count = 0;
    while ((ch=cin.get()) != EOF) {
        if(ch == 'a') count++;
        else if(ch == '\n') break;
    }
    cout << "alphabet 'a': " << count << endl;
}

/*Chapter10 - 13***************************************************************

class PWManager {
    map<string, string> m;
public:
    PWManager() {}
    void insert();
    void check();
};

void linePrinter() {
    for(int i = 0; i < 40; i++)
        cout << "=";
    cout << endl;
}

void PWManager::insert() {
    string name, pass;
    linePrinter();
    cout << "New Name >> ";
    cin >> name;
    cout << "New Pass >> ";
    cin >> pass;
    m[name] = pass;
    linePrinter();
}

void PWManager::check() {
    string name, pass;
        linePrinter();
        cout << "Name >> ";
        cin >> name;
    while(true) {
        cout << "Pass >> ";
        cin >> pass;
        if(pass == m[name]) {
            linePrinter();
            cout << "be vertified" << endl;
            linePrinter();
            break;
        } else
            cout << "fail" << endl;
    }
}

int main() {

    PWManager pwmanager;
    cout << "Activating Password Manage Program" << endl;
    int selectFlag;
    bool exitcode = true;
    while(exitcode) {
        cout << "insert : 1 | check : 2 | exit : 3 >> ";
        cin >> selectFlag;

        switch (selectFlag)
        {
        case 1:
            pwmanager.insert();
            break;
        
        case 2:
            pwmanager.check();
            break;

        case 3:
            exitcode = false;
            break;            

        default:
            cout << "wrong answer, please try again" << endl;
            break;
        }
    }
    cout << "exit the program" << endl;
}*/

/*Chapter10 - 10***************************************************************

class Nation {
    string nation;
    string capital;
public:
    Nation(string nation, string capital) { // constructor
        this->nation = nation;
        this->capital = capital;
    }
    string getNation()  { return nation;  }
    string getCapital() { return capital; }
};

class NationGame {
    vector<Nation> v;
public:
    NationGame ();
    void input();
    void quiz();
};

NationGame::NationGame() {
    Nation n[] = {Nation(    "USA","Washington DC"),
                  Nation(  "Korea","Seoul"        ),
                  Nation(     "UK","London"       ),
                  Nation( "Germen","Berlin"       ),
                  Nation(  "Spain","Mardrid"      ),
                  Nation(  "Japan","Tokyo"        ),
                  Nation(  "China","Beijing"      ),
                  Nation("Ukraine","Kyiv"         ),
                  Nation( "Italia","Rome"         )
                  };
    for(int i = 0; i < 9; i++) {
        v.push_back(n[i]);
    }

    srand((unsigned int)time(NULL));
}

void NationGame::input() {

    string nation, capital;
    cout << "current nation data : " << v.size() << endl;
    cout << "input new nation data (stop s: stop to input)" << endl;
    while(true) {
        cout << v.size()+1 << " >> ";
        cin >> nation >> capital;
        if(nation == "stop") break;

        bool overlapFlag = false;
        for(int i = 0; i < v.size(); i++) {
            if(v[i].getNation() == nation) {
                cout << "already exist!! pleas try again" << endl;
                overlapFlag = true;
            }
        }
        if(overlapFlag) continue;

        Nation n(nation, capital);
        v.push_back(n);
    }
}

void NationGame::quiz() {
    while(true) {
        int i = rand() % v.size();
        string capital;
        cout << "Where is " << v[i].getNation() << "'s capital? >> ";
        cin >> capital;
        if(capital == "exit") return;
        if(v[i].getCapital() == capital)
            cout << "Correct!" << endl;
        else cout << "No!" << "\n\n";
    }
}

int main() {

    NationGame game;
    cout << "GAME: What is this nation's capital?" << "\n\n";

    while(true) {
        cout << "1: data input | 2: quiz game | 3: exit" << endl;
        int flagCode;
        cin >> flagCode;
        if (flagCode == 1) {
            game.input();
        } else if (flagCode == 2) {
            game.quiz();
        } else if (flagCode == 3) {
            cout << "exit the game" << endl;
            return 0;
        } else {
            cout << "wrong enter, please try agin" << endl;
        }
    }
}*/