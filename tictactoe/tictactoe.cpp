#include <iostream>
#include<string>
#include<vector>
#include "tic.cpp"

using namespace std;

int main(int argc, const char * argv[]) {
	tic test;
	string ausg;
	string ende;

	while (test.sieger == 0) {
		system("cls");
		ausg=test.ausgabe();
		cout <<ausg;
		test.zug();
		// ausgabe();
	}

	system("cls");
	cout<<test.ausgabe();
	cout << "Spieler " << test.sieger << " hat gewonnen!";
	cin>>ende;

	return 0;
}