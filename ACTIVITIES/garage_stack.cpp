#include <iostream>
#include <string>
#include <windows.h>

using namespace std;
// This is a parking garage with the principle of stacks.
// Class Parking Garage
class ParkingGarage{
	public:
		void ParkCar(int*);
		void ExitCar(int*);
		void ViewGarage();
		int CheckStack(string*);
		void Push(string*, string*);
		void Pop(string, string, int);
		int isFull(int*);
		
		struct stack{
			string plate_number;
			string name;
		};
		stack Garage[10];
		int ctr = 0;
		
		struct stack2{
			string plate_number2;
			string name2;
		};
		struct stack2 PS[11];
		
		
};

void ParkingGarage::ParkCar(int* s){
	system("cls");
	if(ParkingGarage::isFull(s) == 0){
		cout << "Parking is Full!";
	}
	else{	
		string PN;						//Ask for user its plate number
		string N;
		cout << "Enter plate number: ";
		cin >> PN;
		if(ParkingGarage::CheckStack(&PN) != 10) {	//Check if its already existing
			cout << "Car already parked!"; 
		}
		else{
		cout << "Enter name: ";
		cin >> 	N;
			ParkingGarage::Push(&PN,&N);
			--*s;	
			cout << *s;
		}	
	}
	Sleep(1000);
}
void ParkingGarage::ExitCar(int* s){
	system("cls");
	string PN, N;
	if(ParkingGarage::isFull(s) == 10){
		cout << "Parking is Empty";
	}
	else{
		cout << "Enter plate number:";
		cin >> PN;
		if(ParkingGarage::CheckStack(&PN) == 10){
			cout << "No such car parked.";
		}
		else{
			cout << "Car successfully left!" << endl;
			cout << Garage[ParkingGarage::CheckStack(&PN)].plate_number << endl;
			cout << Garage[ParkingGarage::CheckStack(&PN)].name;
			
		}
		for(int i = ctr, ctr2 = 0; i > ParkingGarage::CheckStack(&PN); i-- ){
			cout << Garage[i].plate_number <<  Garage[i].name ; Sleep(2000);
			ParkingGarage::Pop(Garage[i].plate_number, Garage[i].name, ctr2);
			ctr2++;
		
		}
		ctr--;
		
		Garage[ParkingGarage::CheckStack(&PN)].plate_number = "";
		Garage[ParkingGarage::CheckStack(&PN)].name = "";
	}
	++*s;
	Sleep(2000);
}
void ParkingGarage::ViewGarage(){
	//Print the whole stack
	for (int i = 9; i >= 0; i--){
		cout << i+1 <<Garage[i].plate_number << endl;
	}
	for (int i = 10; i > 0; i--){
		cout << i <<PS[i].plate_number2 << endl;
	}
	Sleep(2000);
}
int ParkingGarage::CheckStack(string* CSPN){
	for(int i = 0; i <=9; i++){
		if(Garage[i].plate_number == *CSPN){
			return i;
		}
	}
	return 10;
}
void ParkingGarage::Push(string* PPN, string* PN){
	Garage[ctr].plate_number = *PPN;
	cout << Garage[ctr].plate_number;
	Garage[ctr].name = *PN;
	cout << Garage[ctr].name;
	ctr++;
}
void ParkingGarage::Pop(string PPN, string PN, int ctr2){
	PS[ctr2].plate_number2 = PPN;
	PS[ctr2].name2 = PN;
}
int ParkingGarage::isFull(int* s){
	return *s;
}
// Class PG
ParkingGarage PG;
// Menu
void MainMenu(int* slot){
	char AnswerInMenu = 0;
	
	system("cls");
	//UI
	
	cout << "Alvin's Parking Garage\n";
	cout << "Slots: " << *slot << endl;
	cout << "(P) Park\n" << "(L) Leave\n" << "(V) View Garage\n";
	cout << "What do you want to do: ";
	cin >> AnswerInMenu;
	if (AnswerInMenu == 'P'){
		PG.ParkCar(slot); 
	}
	else if (AnswerInMenu == 'L' ){
		PG.ExitCar(slot);
	}
	else if (AnswerInMenu == 'V'){
		PG.ViewGarage();
	}
	else {
		MainMenu(slot);
	}
	MainMenu(slot);
}
	
int main(){
	system("cls");
	int slot = 10;
	MainMenu(&slot);
	system("pause>0");
}
