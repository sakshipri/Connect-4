#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int nrows = 6;
const int ncolumns = 7;

void printgame(vector<vector<string>> vect) {
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            cout << vect[i][j] << " ";
        }    
        cout << endl;
    }
    return;
    
}

vector<vector<string>> resetboard(vector<vector<string>> vect) {
    for (int i = 0; i < vect.size(); i++) {
        for (int j = 0; j < vect[i].size(); j++) {
            vect[i][j] = " ";
        }
    }
    return vect;
}

vector<vector<string>> updategame(string s, int column, vector<vector<string>>& vect) {
    
    int row = nrows - 1;
    while (row >= 0 && vect[row][column] != " ") {
        row--;
    }
    if (row < 0) {
        cout << "invalid position" << endl;
    } else {
        vect[row][column]= s;
    }
    return vect;
}

string checkwinner(vector<vector<string>> board, int chance) {
    bool condition = false;
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < 4; j++) {
            condition = condition||((board[i][j]==board[i][j+1])&&(board[i][j+1]==board[i][j+2])&&(board[i][j+2]==board[i][j+3])&&(board[i][j+3] != std::string(" ")));
            if (condition == true) {
                if (chance%2==0) {
                    return "Player1";
                }
                if (chance%2==1) {
                    return "Player2";
                }                
            }
        }
    }
    for (int j = 0; j < ncolumns; j++) {
        for (int i = 0; i < 3; i++) {
            condition = false;
            condition = condition||((board[i][j]==board[i+1][j])&&(board[i+1][j]==board[i+2][j])&&(board[i+2][j]==board[i+3][j])&&(board[i+3][j] != std::string(" ")));
            if (condition == true) {
                if (chance%2==0) {
                    return "Player1";
                }
                if (chance%2==1) {
                    return "Player2";
                }
            }    
        }
    }
    for (int i = 0; i < nrows - 3; i++) {
        for (int j = 0; j < ncolumns - 3; j++) {
            condition = false;
            condition = condition || ((board[i][j] == board[i+1][j+1]) && (board[i+1][j+1] == board[i+2][j+2]) && (board[i+2][j+2] == board[i+3][j+3]) && (board[i][j] != std::string(" ")));
            if (condition == true) {
                if (chance % 2 == 0) {
                    return "Player1";
                }
                else {
                    return "Player2";
                }
            }   
        }
    }

    for (int i = 0; i < nrows - 3; i++) {
        for (int j = 3; j < ncolumns; j++) {
            condition = false;
            condition = condition || ((board[i][j] == board[i+1][j-1]) && (board[i+1][j-1] == board[i+2][j-2]) && (board[i+2][j-2] == board[i+3][j-3]) && (board[i][j] != std::string(" ")));
            if (condition == true) {
                if (chance % 2 == 0) {
                    return "Player1";
                }
                else {
                    return "Player2";
                }
            }
        }
    }
    if (condition = false) {
        return "";
    }
}
int main() { 
    vector<vector<string>> v;
    for (int i = 0; i < nrows; ++i) {
        vector<string> rowV;

        for (int j = 0; j < ncolumns; ++j) {
            rowV.push_back(" ");
        }
        v.push_back(rowV);
    }
    cout << "_______________________________________________________________________________________________________________________________________" << endl;
    cout << "Welcome to Connect 4. This game has 6 rows and 7 columns. Enter 1 to start." << endl;
    int g;
    cin >> g;
    if (g!=1) {
        cout << "Arey yeh kya enter kardiya!!" << endl;
    }
    while (g==1) {
        int column;
        string winner;
        for(int chance = 0; chance < 42; chance++) {
            if (chance % 2 == 0) {
                cout << "Player1's chance. Enter column number." << endl;
            } else {
                cout << "Player2's chance. Enter column number." << endl;
            }
            cin >> column;
            column = column - 1;
            if (column >= 0 && column < 7) {
                if (chance%2==0) {
                    updategame("o", column, v);
                } else {
                    updategame("x", column, v);
                }
            printgame(v);

            winner = checkwinner(v, chance);
            if ((winner == "Player1") || (winner == "Player2")) {
                cout << winner << " has won!" << endl;
                v = resetboard(v);
                break;
            }
            } else {
            cout << "Invalid position!" << endl;
            chance = chance-1;
            continue;
            }
        } 
        if (winner == "") {
            cout << "Game Draw" << endl;
        }
        cout << "Press 1 to play again and 0 to close game." << endl;
        int t;
        cin >> t;
        g = t;
        if (g==1) {
            continue;
        } else if (g==0) {
            exit(0);
        } else {
            cout << "Arey yeh kya enter kardiya!!" << endl;
            exit(0);
        }
    }
    return 0;
}