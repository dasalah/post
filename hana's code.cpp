#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
typedef struct {
	int postcode;
	int postpaid;
	char sendername[20];
	char recivername[20];
	char sendercity[15];
	char recivercity[15];

} marsole;
typedef struct {
	int smonth;
	int sday;
	int rmonth;
	int rday;
}date;
void printdate(date a) {
	cout << "sending date:" << a.smonth << "/" << a.sday << "   " << "reciving date:" << a.rmonth << "/" << a.rday;
}
void darj() {
	date d;
	marsole m;
	fstream marsolefile("idk.txt", ios::app);
	if (!marsolefile) {
		cerr << "somrthing went wrong during opening the file please make sure that the file that you chose exists!" << endl;
		exit(1);
	}
	cout << "enter your postcode:" << endl;
	cin >> m.postcode;
	cout << "enter the price of your parcel:" << endl;
	cin >> m.postpaid;
	cout << "enter sender's name:" << endl;
	cin >> m.sendername;
	cout << "enter reciver's name:" << endl;
	cin >> m.recivername;
	cout << "enter sender's city:" << endl;
	cin >> m.sendercity;
	cout << "enter reciver's city:" << endl;
	cin >> m.recivercity;
	for (int i = 0; i < 1; i++) {
		cout << "enter sending day:" << endl;
		cin >> d.sday;
		if (d.sday > 31 && d.sday < 0) i--;
	}
	for (int i = 0; i < 1; i++) {
		cout << "enter sending month:" << endl;
		cin >> d.smonth;
		if (d.smonth > 12 && d.smonth < 0) i--;
	}
	for (int i = 0; i < 1; i++) {
		cout << "enter reciving day:" << endl;
		cin >> d.rday;
		if (d.rday > 31 && d.rday < 0) i--;
	}
	for (int i = 0; i < 1; i++) {
		cout << "enter reciving month" << endl;
		cin >> d.rmonth;
		if (d.rmonth > 12 && d.rmonth < 0) i--;
	}
	marsolefile >> m.postcode >> setw(10) >> m.postpaid >> setw(10) >> m.sendername >> setw(10) >> m.sendercity >> setw(10) >> m.recivername >> setw(10) >> m.recivercity;
	//printdate(d);
}
void tahvil() {
	fstream dariaftfile("idc.txt", ios::app);
	if (!dariaftfile) {
		cerr << "somrthing went wrong during opening the file please make sure that the file that you chose exists!" << endl;
		exit(1);}
		int p, d, m;
		char n = '.';
		cout << "enter your postcode:" << endl;
		cin >> p;
		cout << "enter recving day:" << endl;
		cin >> d;
		cout << "enter reciving month:" << endl;
		cin >> m;
		dariaftfile >> p >> setw(10) >> m >> n >> d;
	
}
int main() {
	while (1) {
		int n;
		cout << "if you want to register a new parcal, enter number 1:" << endl << "if you want to register a parcel's delivery, enter number 2:" << endl;
		cin >> n;
		switch (n) {
		case 1:
			darj();
			break;
		case 2:
			tahvil();
			break;
		default: cout << "wrong number";

		}
	}
}
