#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include<stdio.h>
#include <cstring>

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
	string FullDate;
} date;

void darj() {

	date d;
	marsole m;
	fstream marsolefile("file.txt", ios::in);
	if (!marsolefile) {
		cerr << "somrthing went wrong during opening the file please make sure that the file that you chose exists!" << endl;
		exit(1);
	}
	string line;//read file
	while (getline(marsolefile, line)) { cout << line<<endl; }

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
	// get time
	for (int i = 0; i < 1; i++) {
		cout << "enter sending day:" << endl;
		cin >> d.sday;
		if (d.sday > 31 || d.sday < 0) { i--; cout << "Please enter the date correctly\n"; }

	}
	for (int i = 0; i < 1; i++) {
		cout << "enter sending month:" << endl;
		cin >> d.smonth;
		if (d.smonth > 12 || d.smonth < 0) { i--; cout << "Please enter the date correctly\n"; };
	}
	for (int i = 0; i < 1; i++) {
		cout << "enter reciving day:" << endl;
		cin >> d.rday;
		if (d.rday > 31 || d.rday < 0) { i--; cout << "Please enter the date correctly\n"; };
	}
	for (int i = 0; i < 1; i++) {
		cout << "enter reciving month" << endl;
		cin >> d.rmonth;
		if (d.rmonth > 12 || d.rmonth < 0) { i--; cout << "Please enter the date correctly\n"; } 
	}
	//file 1 ok
	
		
		marsolefile << m.postcode << setw(10) << m.sendername << setw(10) << d.smonth << '/' << d.rday << setw(10) << m.recivername << setw(10) << m.recivercity << setw(10) << m.postpaid << endl;
		cout << "Data successfully recorded\n";
		marsolefile.close();
	
	
}


void tahvil() { //function 2  OK
	fstream get("get.txt", ios::app); //create file 2 ok
	if (!get) {
		cerr << "somrthing went wrong during opening the file please make sure that the file that you chose exists!" << endl;
		exit(1);
	}
		int p, d, m;
		cin >> p;
		cout << "enter your postcode:" << endl;
		get.close();
		for (int i = 0; i < 1; i++) {
			cout << "enter reciving day:" << endl;
			cin >> d;
			if (d > 31 || d < 0) { i--; cout << "Please enter the date correctly\n"; }
		}
		for (int i = 0; i < 1; i++) {
			cout << "enter reciving month:" << endl;
			cin >> m;
			if (m > 12 || m < 0) { i--; cout << "Please enter the date correctly\n"; };
		}
		get << p << setw(10) << m << '/' << d << endl;	
		cout << "Data successfully recorded" << endl;

}
/*
void rate(int rate,float price) { //not okay.
	float sum[12];
	sum[0] = 0;
	int month;

	
	switch (rate)

	{
	case 1:
			sum[1] += price;
	case 2:
			sum[2] += price;
	case 3:
			sum[3] += price;
	case 4:
			sum[4] += price;
	case 5:
			sum[5] += price;
	case 6:
			sum[6] += price;
	case 7:
			sum[7] += price;
	case 8:
			sum[8] += price;
	case 9:
			sum[9] += price;
	case 10:
			sum[10] += price;
	case 11:
			sum[11] += price;
	case 12:
			sum[12] += price;

	default:
		break;
	}

	cout << "enter your month: ";
	cin >> month;
	cout << "price is:" << sum[month];


}
*/



void info() {
	string code;
	string line;
	cout << "enter your post code:";
	cin >> code;
	fstream data("file.txt", ios::in);
	fstream DataDate("get.txt", ios::in);

	while (!data.eof()) { //read a line
		int i = 0;
		getline(data, line);
		while(1){
			bool test = line.find(code, i);
		if (!test) {				// find word 
			cout << line << endl;//outing without date receive  
			                                      
													while (!DataDate.eof()){    //read date receive 
														int j = 0;
													string Line;
													getline(DataDate, Line);
													while (1) {

														bool test = Line.find(code, i);
														if (!test) {

															cout << Line << endl;;
															break;
														}
														else
														{
															j++;
															break;

														}

				}
				


									}

			break;
		}
		else
		{
			i++;
			break;
		}

	}
	}


}


int main() {
	
	while (1) {
		int n;
		system("color 2");
		system("cls");
		cout
			<< "1- register a new shipment       \n"
			<< "2- indert receipt time         \n"
			<< "3- View Daily Posts         \n"
			<< "4-View Package Information     \n"
			<< "5-                 \n"
			<< "6-                   \n"
			<< "7-Monthly income           \n"
			<< "8-Number of intercity shipments  \n\n"
			<< "Please enter your request number:\n";

		cin >> n;

		while(1){
		switch (n) {
		case 1:
			darj();
			break;
		case 2:
			tahvil();
			break;
		case 4:
		info();
		break;
		case 0:
			continue;
		default: cout << "wrong number";
										}
		cout << "do you want to continue?(y/n)\n";
		char ch;
		cin >> ch;
		if (ch == 'n' || ch == 'N') break;
					
		}
	}
	
}



