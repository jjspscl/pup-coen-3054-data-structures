#include <iostream>
#include <string>
using namespace std;

class BuckysClass{
	public:
		void setName (string x){
			name = x;
			
		}
		BuckysClass(string z){		// constructor. matik lalabas to
			cout << z ;
		}
		string getName(){
		return name;
		}
	private:
		string name;
};


void AskForName(){
		string nameInput;
		BuckysClass bo("What is your name: ");	// string nasa loob ilalabas agad ng constructor
		cin >> nameInput;
		bo.setName(nameInput);				// call yung set Name sa loob ng class
		cout << "Your name is: " << bo.getName()<<endl; // print yung function sa loob ng class na nagrereturn ng input
		
		
	
}
void AskForNumber(){
		string numberInput;
		BuckysClass bo2("What is your number: "); 		// pwede gamitin yung isang class ibahin lang yung object -- bo bo2 bo3
		cin >> numberInput;
		bo2.setName(numberInput);
		cout << "Your number is: " << bo2.getName()<<endl;
}
int main(){
	
	AskForName();
	AskForNumber();
	
	system("pause>0");
}

