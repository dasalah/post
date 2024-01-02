#include <iostream>
#include <iomanip>
#include <fstream>
#include<string>
#include<stdio.h>
#include <cstring>
#include <sstream>

using namespace std;


typedef struct {
	int postcode;
	int postpaid;
	string sendername;
	string recivername;
	string sendercity;
	string recivercity;
	string viewpost;
	int viewpaid[12];
	
} marsole;
typedef struct {
	int smonth;
	int sday;
	int rmonth;
	int rday;
	char FullDate[6];
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


void tahvil() { //function 2  OK      #struct no made
	fstream get("get.txt", ios::app); //create file 2 ok
	if (!get) {
		cerr << "somrthing went wrong during opening the file please make sure that the file that you chose exists!" << endl;
		exit(1);
	}
	marsole reacive;
	date Reacive;
	int i;
		cout << "enter your postcode:" << endl;
		cin >> reacive.postcode;
		
		
		for (i = 0; i < 1; i++) {
			cout << "enter reciving day:" << endl;
			cin >> Reacive.rday;
			if (Reacive.rday > 31 || Reacive.rday < 0) { i--; cout << "Please enter the date correctly\n"; }
		}
		for (i = 0; i < 1; i++) {
			cout << "enter reciving month:" << endl;
			cin >> Reacive.rmonth;
			if (Reacive.rmonth > 12 || Reacive.rmonth < 0) { i--; cout << "Please enter the date correctly\n"; };
		}
		get << reacive.postcode << setw(10) << Reacive.rmonth << '/' << Reacive.rday << endl;
		cout << "Data successfully recorded." << endl;
		get.close();
}

void rate() { //not okay.
	marsole m;
	date d;
	string line;
	fstream rate("file.txt", ios::in);
	while (!rate.eof())
	{
		//rate.getline(line,sizeof(line),stdin);
		rate >> m.postcode>> m.sendername >> m.sendercity >> d.FullDate >> m.recivername >> m.recivercity >> m.postpaid;
		if (d.FullDate[0] == '0' && d.FullDate[1] == '1') {
			m.viewpost[1] += m.postpaid;
		}
		if (d.FullDate[0] == '0' && d.FullDate[1] == '2') {
			m.viewpost[2] += m.postpaid;

		}
		if (d.FullDate[0] == '0' && d.FullDate[1] == '3') {
			m.viewpost[3] += m.postpaid;

		}
		if (d.FullDate[0] == '0' && d.FullDate[1] == '4') {
			m.viewpost[4] += m.postpaid;

		}
		if (d.FullDate[0] == '0' && d.FullDate[1] == '5') {
			m.viewpost[5] += m.postpaid;

		}
		if (d.FullDate[0] == '0' && d.FullDate[1] == '6') {
			m.viewpost[6] += m.postpaid;

		}
		if (d.FullDate[0] == '0' && d.FullDate[1] == '7') {
			m.viewpost[7] += m.postpaid;

		}
		if (d.FullDate[0] == '0' && d.FullDate[1] == '8') {
			m.viewpost[8] += m.postpaid;

		}
		if (d.FullDate[0] == '0' && d.FullDate[1] == '9') {
			m.viewpost[9] += m.postpaid;

		}
		if (d.FullDate[0] == '1' && d.FullDate[1] == '0') {
			m.viewpost[10] += m.postpaid;

		}
		if (d.FullDate[0] == '1' && d.FullDate[1] == '1') {
			m.viewpost[11] += m.postpaid;

		}
		if (d.FullDate[0] == '1' && d.FullDate[1] == '2') {
			m.viewpost[12] += m.postpaid;

		}
		
	}


}










void info() { 
	string code;
	string line;
	cout << "enter your post code:";
	cin >> code;
	fstream data("file.txt", ios::in);
	fstream DataDate("get.txt", ios::in);
	if (!data&&DataDate) {
		cerr << "somrthing went wrong during opening the file please make sure that the file that you chose exists!" << endl;
		exit(1);
	}

	while (!data.eof()) { //read a line
		
		getline(data, line);
		while(1){
			size_t test = (line.find(code));
			
		if (test<sizeof(line)) {				// find word 
			cout << line << endl;//outing without date receive  
			                                      
													while (!DataDate.eof()){    //read date receive 
														
													string Line;
													getline(DataDate, Line);
													

														size_t test = Line.find(code, 0);
														if (test<sizeof(line)) {

															cout << Line << endl;;
														}
														

																			}
				


									

		
		}
	}
	}

	data.close();
	DataDate.close();
}
void DayInfo() {
	marsole m;							// create struct
	date d;
	fstream file("file.txt", ios::in); //open files
	fstream date("get.txt", ios::in);
	if (!file && date) {
		cerr << "somrthing went wrong during opening the file please make sure that the file that you chose exists!" << endl;
		exit(1);
	}
	cout << "enter your date  (MM/DD)" << endl;; //get data
	cin >> d.FullDate;
	string line;
	string out;
	while (!file.eof())
	{

		getline(file, line);
		size_t check = line.find(d.FullDate, 0); //find date.
		if (check < size(line)) {
			cout << line << endl;

		}
	}
	file.close();
	date.close();
	
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
		case 3:
			DayInfo();
			break;
		case 4:
		info();
		break;
		case 7:
			rate();
			break;
		case 0:
			continue;
		default: cout << "wrong number";
										}
		cout << "do you want to continue?(y/n)\n";
		char ch;
		cin >> ch;
		if (ch == 'n' || ch == 'N') break;
		else {
			break;
		}
		}
	}
	
}



