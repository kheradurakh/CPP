#include <iostream>
//#include <stdio>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class tic
{
private:
	vector<vector<int>> field;
public:
	int spieler;
	int sieger;
	tic() {
		sieger = 0;
		spieler = 1;
		field = {
			{0,0,0},
			{0,0,0},
			{0,0,0}
		};
		//ausgabe();
	}
	string ausgabe() {
		stringstream hilf;
		hilf<< "-------------" << endl;
		for (int i = 0;i < 3;i++) {
			hilf<< "| ";
			for (int j = 0;j < 3;j++) {
				hilf << field[i][j] << " | ";
			}
			hilf << endl << "-------------" << endl;
		}
		return hilf.str();		
	}

	void zug() {
		int z, s;
		cout << "Spieler " << spieler << " ist dran. Zeile, Enter, Spalte bitte: ";
		cin >> z >> s;
		z--;
		s--;
		if (spieler == 1) {
			if (field[z][s] == 0) {
				field[z][s] = 1;
				winner();
				spieler = 2;
			}
			else {
				cout << "Bitte ein leeres Feld auswählen" << endl;
			}
		}
		else {
			if (field[z][s] == 0) {
				field[z][s] = 2;
				winner();
				spieler = 1;
			}
			else {
				cout << "Bitte ein leeres Feld auswählen" << endl;
			}
		}
		winner();
	}

	void winner() {

		for (int i = 0;i < 3;i++) {
			if (field[i][0] == field[i][1] && field[i][0] == field[i][2] && field[i][0] != 0) {
				sieger = field[i][0];
			}
			else if (field[0][i] == field[1][i] && field[0][i] == field[2][i] && field[0][i] != 0) {
				sieger = field[i][0];
			}
		}

		if (field[0][0] == field[1][1] && field[0][0] == field[2][2] && field[0][0] != 0) {
			sieger = field[0][0];
		}
		else if (field[0][2] == field[1][1] && field[0][2] == field[2][0] && field[0][2] != 0) {
			sieger = field[0][2];
		}
	}
};