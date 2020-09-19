// BS COMPUTER ENGINEERING 2-4 //
//LOMIBAO, ALLEN JED
//MAHAGUAY, EDRIAN CHARLES
//PANGANIBAN,ALVIN CARLOS
//PASCUAL, JOSHUA JOHN 

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <iomanip>

using namespace std;


//Initialization//
void Menu();
void Borders();
void gotoxy();
//////////////////


//////STACK//////////
int  top_stack=-1, up, j=0, k=0, slot_stack=10,departure[10], departure2[10], arrival[10], arrival2[10];
string plate_number_stack;
string 	stack[]={"-","-","-","-","-","-","-","-","-","-"}, 
stack2[]={"-","-","-","-","-","-","-","-","-","-"};
void push(string);
void pop();
void pushbackstack();
bool checkstack(string);
void Park(string);
void Leave(string);
void View();
void menu_stack();
//////////////////////


///////QUEUE//////
string 	queue[]={"-","-","-","-","-","-","-","-","-","-"}, queue2[]={"-","-","-","-","-","-","-","-","-","-"};
string plate_number_queue;
int departure_queue[10], departure_queue2[10], arrival_queue[10], arrival_queue2[10];
int front =0, rear=-1, slot_queue=10;
void enqueue(string);
void dequeue(string);
bool checkqueuea(string);
void park_queue(string);
void leave_queue(string);
void menu_queue();
void view_queue();
////////////////////

////FIBONACCI///
void fibo();
int fibonacci(int n);
////////////////


////FACTORIAL///
void factorial();
int fact(int n);
///////////////


///////////////Hanoi////////////////
void towers(int,char,char,char);
void Hanoi();
///////////////////////////////////


///////Binary Tree///////
void tree();
void treeout();
void Notations();
string node[31]={"-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-","-"};
int nodex[31], nodey[31];
///////////////////////

///////Boatman's Dilemma//////
void bman();
//////////////////////////////


//						Go to XY Function                      //
// Using SetConsoleCursorPosition function in windows.h        //
void gotoxy( int column, int line ){
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }

int wherex()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD  result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.X;
  }

int wherey()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD  result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.Y;
  }
  
////////////////////////////////////////////////////////////////////

void Borders()
	{

	//Corners
	gotoxy(1, 1);printf("%c", 201);
	gotoxy(79, 1);printf("%c", 187);
	gotoxy(1, 25);printf("%c", 200);
	gotoxy(79, 25);printf("%c", 188);
 		
	//Vertical
	for (int i = 1 + 1; i < 79; i++)
		{
		gotoxy(i, 1);printf("%c", 205);
		gotoxy(i, 25);printf("%c", 205);
		}
 
	//Horizontal
	for (int i = 1 + 1; i < 25; i++)
	{
	gotoxy(1, i);printf("%c", 186);
	gotoxy(79, i);printf("%c", 186);
	}
 	
 	//Divider xD
	gotoxy(1,6);
	printf("%c",204);
	for(int i = 2 ; i < 79 ; i++) 
		{
		printf("%c",205);
		};
		printf("%c",185);
	};


int main()
  {
	Menu();
  	system("pause>0");
	return 0;
  }
  
  
void Menu()
	{
		system("cls");
		Borders();
		
		string option;
		
		//Title
		gotoxy(21, 2);printf("POLYTECHNIC UNIVERSITY OF THE PHILIPPINES");
		gotoxy(30, 3);printf("COLLEGE OF ENGINEERING");
		gotoxy(24, 4);printf("DEPARTMENT OF COMPUTER ENGINEERING");
		
			
		//Options	
		gotoxy(25, 8);
			cout<<"A. Bashemin Parking Garage";
		gotoxy(25, 10);
			cout<<"B. Parking Garage (QUEUE)";
		gotoxy(25, 12);
			cout<<"C. Fibonnaci";
		gotoxy(25, 14);
			cout<<"D. Factorial";
		gotoxy(25, 16);
			cout<<"E. Tower of Hanoi";
		gotoxy(25, 18);
			cout<<"F. Binary Tree";
		gotoxy(25,20);
			cout <<"G.The Boatman Dilemma";
			gotoxy(25,22);
		getline( cin,option);
		if(option.empty()){
			Menu();
			
	}
		if (option == "A" || option == "a" )
		{
				menu_stack();
			}
		else if (option == "b" || option == "B" )
		{
				menu_queue();
			}
		
		else if (option == "c" || option == "C" )
			{
				fibo();
				Menu();
			}
			
		else if (option == "D" || option == "d" )
			{
				factorial();
				Menu();
			}
			else if (option == "E" || option == "e" )
			{
				Hanoi();
				Menu();
			}
			else if (option == "F" || option == "f" )
			{
				tree();
				treeout();
				Notations();
				Menu();
				
			}
			else if (option == "G" || option == "g" )
			{
				bman();
			}
		else 
			{
 				gotoxy(39, 15);
 				
 				system("cls");
 				Borders();
 				
 				gotoxy(20, 15);
 				cout<<"Invalid input! Please enter again";
 				Sleep(500);
 				cout << "!";
 				Sleep(500);
 				cout << "!";
 				Sleep(500);
 				cout << "!";
 				Sleep(500);
				Menu();
			}
}  


/////////////////////////GARAGE STACK ///////////////////////////////////

bool checkstack(string z){
	 bool status=false;
	 int x=9;
	 
	while (x>0 && z!=stack[x]){
		status=false;
		x--;
	}
	if(x==-1){
		x++;
	}
	
	 if(z==stack[x]){
		status= true;
	}

	


	return status;
}

void push (string push_ans){
	stack[j] = push_ans;
	top_stack++;
	arrival[j]= arrival[j] +1;
	departure[j]=0;
	j++;
	
}	

void pop(){
	if(top_stack!=-1){
		j--;
		stack2[k]=stack[j];
		stack[j] ="-";
		arrival2[k] = arrival[j];
		arrival[j] =0;
		departure2[k] = departure[j]+1;
		departure[j] =0;
		k++;
		top_stack--;
	}
}

void pushbackstack(){
	k--;
	j=up;
	
	while(k!=-1){
		stack[j] = stack2[k];
		stack2[k] =="-";
		arrival[j] = arrival2[k] +1;
		arrival2[k] = 0;
		departure[j] = departure2[k];
		departure2[k] =0;
		j++;
		top_stack++;
		k--;
	}
	k++;
	
}

void Park(string x){
	string ans_park;
	if(slot_stack!=0) {
			gotoxy(5,15); cout << "Confirm Y/N: ";
		getline(cin,ans_park);
		if(ans_park.empty()){
			menu_stack();
		}
		if (ans_park=="Y" || ans_park=="y"){
		push(x);
		slot_stack--;
		gotoxy(5,16) ;cout << x << " arrived!"; Sleep(1500);
	}
	}
	else{
		gotoxy(5,16); cout << "Parking Full!"; Sleep(1500);
		
	}
}


void Leave(string y){
	string ans_leave, any;
	int x=top_stack--;
	
	if(slot_stack==10){
		gotoxy(5,15); cout << "No car parked!"; Sleep(1500);

		menu_stack();
		
	}
	else{
		gotoxy(5,15); cout << "Confirm Y/N: ";
		getline(cin,ans_leave);
		if(ans_leave.empty()){
			menu_stack();
		}
		if(ans_leave=="Y" || ans_leave=="y"){
		
		slot_stack++;
		while(stack[x]!=y){
		pop();
		x--;
	}
	
	
	gotoxy(5,16); cout << y << " departed! ||" << " Departure count: " << departure[x] << " || Arrival count: " << arrival[x]<<endl;
	gotoxy(5,17); cout << "Enter any key to continue ";
	getline(cin,any);
	up=x;
	stack[x]="-";
	departure[x]=0;
	arrival[x]=0;
	pushbackstack(); 
}

}

menu_stack();
}

void View(){
	system("cls");
	Borders();
		int p=9, x=9;
		string ans_view;
	
		
	gotoxy(29,3); cout << "Bashemin Parking Garage" << endl;
	while(p>=0){
	
		gotoxy(5,x);cout << stack[p] << "\t Departure: " << departure[p] <<"\t Arrival: " << arrival[p] << endl ;
	
		p--;
		x++;
	}
		gotoxy(5,++x);cout << "Enter any key to back"<< endl;
		gotoxy(27,x); getline(cin,ans_view);
		if(ans_view.empty()){
			menu_stack();
	}
		else{
		
			menu_stack();
}
}

void menu_stack(){
	string ans_menu;
	system("cls");
		Borders();
	gotoxy(29,3); cout << "Bashemin Parking Garage" << endl;
	gotoxy(5,9); cout << "Number of Available Parking Space: " << slot_stack << endl;
	gotoxy(5,10); cout << "(A) Arrive" << endl;
	gotoxy(5,11); cout << "(D) Depart" << endl;
	gotoxy(5,12); cout << "(V Garage) View Parking Lot"<< endl;
	gotoxy(5,20); cout << "(B M) Back to Menu";
	gotoxy(5,13); getline(cin,ans_menu); 
		if(ans_menu.empty()){
			menu_stack();
		}
	gotoxy(5,14); getline(cin,plate_number_stack);
		if(plate_number_stack.empty()){
			menu_stack();
		}
if (ans_menu == "A" || ans_menu == "a"){
	if(checkstack(plate_number_stack)==0){
	Park(plate_number_stack);
}
else{
	gotoxy(5,15); cout << "Sorry, your car " << plate_number_stack << " is parked already."; Sleep(1500);
}
}
else if (ans_menu == "D" || ans_menu == "d"){
		
	 if(checkstack(plate_number_stack)==1){
	 
	 Leave(plate_number_stack); }

else {


	gotoxy(5,15);cout << "No car with plate number " << plate_number_stack <<" is parked!"; Sleep(1500);
}
}

else if (ans_menu == "V" || ans_menu == "v" && (plate_number_stack=="Garage" || plate_number_stack=="garage")) {
	View();
}
else if (ans_menu== "B" || ans_menu== "b" && (plate_number_stack=="M"|| plate_number_stack=="m")){
	Menu();
}
else {
	menu_stack();
}
menu_stack();
}

////////////////////////////////////////////////////////////////////////////



///////////////////////////////////////////// G A R A G E (Q U E U E)///////////////////////////////////////////// 

bool checkqueue(string z){
	 bool status=false;
	 int x=9;
	 
	while (x>0 && z!=queue[x]){
		status=false;
		x--;
	}
	if(x==-1){
		x++;
	}
	
	 if(z==queue[x]){
		status= true;
	}
	return status;
}

void enqueue(string enqueue_ans) {
	rear++;
	queue[rear] = enqueue_ans;
	arrival_queue[rear] = arrival_queue[rear]+1;

}

void dequeue(string z){
	int x=1, y=0;
	queue2[front]=queue[front];
	arrival_queue2[front] = arrival_queue[front]+1;
	departure_queue2[front] = departure_queue[front]+1;
	rear--;

	while(x<=9){
	
	queue[y]= queue[x];
	queue[x]= "-";
	arrival_queue[y]=arrival_queue[x];
	arrival_queue[x] = 0;
	departure_queue[y] = departure_queue[x];
	departure_queue[x]=0;
	x++; y++;}
	if(z!= queue2[front]){
	rear++;
	queue[rear] = queue2[front];
	arrival_queue[rear] = arrival_queue2[front];
	departure_queue[rear] = departure_queue2[front];
	}



 }
 
void menu_queue(){
	system("cls");
	Borders();
string ans_menu;
	
	gotoxy(29,3); cout << "Bashemin Parking Garage" << endl;
	gotoxy(5,9); cout << "Number of Available Parking Space: " << slot_queue << endl;
	gotoxy(5,10); cout << "(A) Arrive" << endl;
	gotoxy(5,11); cout << "(D) Depart" << endl;
	gotoxy(5,12); cout << "(V Garage) View Parking Lot"<< endl;
	gotoxy(5,20); cout << "(B M) Back to Menu";
	gotoxy(5,13); getline(cin,ans_menu); 
		if(ans_menu.empty()){
			menu_queue();
		}
	gotoxy(5,14); getline(cin,plate_number_queue);
		if(plate_number_queue.empty()){
			menu_queue();
		}
if (ans_menu == "A" || ans_menu == "a"){
	if(checkqueue(plate_number_queue)==0){
	park_queue(plate_number_queue);
}
else{
	gotoxy(5,15); cout << "Sorry, your car " << plate_number_queue << " is parked already."; Sleep(1500);
}
}
else if (ans_menu == "D" || ans_menu == "d"){
		
	 if(checkqueue(plate_number_queue)==1){
	 
	 leave_queue(plate_number_queue); }

else {


	gotoxy(5,15);cout << "No car with plate number " << plate_number_queue <<" is parked!"; Sleep(1500);
}
}

else if (ans_menu == "V" || ans_menu == "v" && (plate_number_queue=="Garage" || plate_number_queue=="garage")) {
	view_queue();
}
else if (ans_menu== "B" || ans_menu== "b" && (plate_number_queue=="M"|| plate_number_queue=="m")){
	Menu();
}
else {
	menu_queue();
}
menu_queue();
}

void park_queue(string x){
	string ans_park;
	if(slot_queue>0) {
			gotoxy(5,15); cout << "Confirm Y/N: ";
		getline(cin,ans_park);
		if(ans_park.empty()){
			menu_queue();
		}
		if (ans_park=="Y" || ans_park=="y"){
		enqueue(x);
		slot_queue--;
		gotoxy(5,16) ;cout << x << " arrived!"; Sleep(1500);
	}
	}
	else{
		gotoxy(5,16); cout << "Parking Full!"; Sleep(1500);
		
	}
}

void leave_queue(string c){
	string ans_leave, any;
	int x=0;
	if(slot_queue==10){
		gotoxy(5,15); cout << "No car parked!"; Sleep(1500);
	
		menu_queue();
		
	}
	else{
		gotoxy(5,15); cout << "Confirm Y/N: ";
		getline(cin,ans_leave);
		if(ans_leave.empty()){
			menu_queue();
		}
		if(ans_leave=="Y" || ans_leave=="y"){
			
		
		slot_queue++;
		while(queue[x]!=c) {
			x++;
		}
		gotoxy(5,16); cout << c << " departed! ||" << " Departure count: " << departure_queue[x] << " || Arrival count: " << arrival_queue[x]<<endl;
	gotoxy(5,17); cout << "Enter any key to continue ";
	getline(cin,any);
		while(x>=0){
			dequeue(c);
			x--;
		}
	}


		
}
menu_queue();
}

void view_queue(){
	system("cls");
	Borders();
		int p=9, x=9;
		string ans_view;
	
		
	gotoxy(29,3); cout << "Bashemin Parking Garage" << endl;
	while(p>=0){
	
		gotoxy(5,x);cout << queue[p] << "\t Departure: " << departure_queue[p] <<"\t Arrival: " << arrival_queue[p] << endl ;
	
		p--;
		x++;
	}
		gotoxy(5,++x);cout << "Enter any key to back"<< endl;
		gotoxy(27,x); getline(cin,ans_view);
		if(ans_view.empty()){
			menu_queue();
	}
		else{
		
			menu_queue();
}
}

///////////////////////////////////////////// E N D  O F  Q U E U E///////////////////////////////////////////// 


/////////////////////////////////////////////F I B O N A C C I///////////////////////////////////////////// 

int fibonacci(int n)
{
    if((n==1)||(n==0))
    {
        return(n);
    }
    else
    {
        return(fibonacci(n-1)+fibonacci(n-2));
    }
}

void fibo()
	{
		system("cls");
				Borders();
				
			int n=1,i=0;
				int any=5;
				gotoxy(30, 3);
					printf("Fibonnaci Series");
					
				gotoxy(24, 15);
					printf("Enter a number:");
					
				gotoxy(39, 15);
    				cin >> noskipws>> n;
    		
		if ((!cin>>n)||(n < 0))
		{
			gotoxy(39, 15);
 			cin.clear();
 			cin.ignore(999,'\n');
 			system("cls");
 			Borders();
 				
 			gotoxy(20, 15);
 			cout<<"Invalid data type! Please enter again";
 			Sleep(1000);
 			cout << "!";
 			Sleep(1000);
 			cout << "!";
 			Sleep(1000);
 			cout << "!";
 			Sleep(1000);
 				
 			Menu();
 		}
			 		while(i<n)
    			{
        			i++;
					
    			};
    			gotoxy(24,16);cout << fibonacci(i) << endl;
    			gotoxy(24, 18); cout << "Going back to menu in ";
    			for (int j=5; j>0;j--){
    				gotoxy(24,19);cout << j << endl; Sleep(500);
				}
			}		
////////////////////////////E N D  O F  F I B O N A C C I////////////////////////////


////////////////////////////F A C T O R I A L////////////////////////////

int fact(int n) {
	int t;

	if(n <= 1) return 1;

	t = n * fact(n - 1);
	return t;
}

void factorial()
	{
	
		system("cls");
				Borders();
					int any=5;
				int n=-1,i=0;
				
				gotoxy(35, 3);
					printf("Factorial");
					
				gotoxy(24, 15);
					printf("Input a 'positive' integer: ");
    				cin>>noskipws>> n;
				if(n==-1){
					factorial();
				}	
    				
    			
					
	if ((!cin>>n)||(n < 0))
		{
			gotoxy(39, 15);
 			cin.clear();
 			cin.ignore(999,'\n');
 			system("cls");
 			Borders();
 				
 			gotoxy(20, 15);
 			cout<<"Invalid data type! Please enter again";
 			Sleep(500);
 			cout << "!";
 			Sleep(500);
 			cout << "!";
 			Sleep(500);
 			cout << "!";
 			Sleep(500);
 				
 			factorial();
 		}
	 
	else 
		{
			
	gotoxy(24,16);
		cout << n << " factorial is " << fact(n) << endl;
		
	gotoxy(24, 18); 
			cout << "Going back to menu in:";
	
	for(int i=5; i>=0; i--){
		Sleep(500);
		gotoxy(46,18);
			cout<< i ;
		
		}
	
	
	}
	
	}
	
////////////////////////////E N D  O F  F A C T O R I A L////////////////////////////


////////////////////////////T O W E R  O F  H A N O I////////////////////////////////

void towers(int num, char apeg, char bpeg, char cpeg)
{
    if (num == 1)
    {
    	cout << "\n Move disk 1 from peg " << apeg <<" to peg " << cpeg; Sleep(500);
        
		}
	else{
	
    towers(num - 1, apeg, cpeg, bpeg);
    cout <<"\n Move disk " << num << " from peg " << apeg << " to peg " << cpeg; Sleep(500);
    towers(num - 1, bpeg, apeg, cpeg);
  }
    
}

void Hanoi()
{
    int num=-1, any=5;
    system("cls");
    Borders();
 	gotoxy(33,3); cout << "Tower of Hanoi";
    gotoxy(5,10); cout << "Enter number of disks : ";
    cin>> noskipws >> num;
  		if(num==-1){
  			Hanoi();
		  }
				
		if(num > 1000){
			Hanoi();
		}		
		if ((!cin>>num)||(num < 0))
		{
			gotoxy(39, 15);
 			cin.clear();
 			cin.ignore(999,'\n');
 			system("cls");
 			Borders();
 				
 			gotoxy(20, 15);
 			cout<<"Invalid data type! Please enter again";
 			Sleep(500);
 			cout << "!";
 			Sleep(500);
 			cout << "!";
 			Sleep(500);
 			cout << "!";
 			Sleep(500);
 				
 			Hanoi();
 		}
 		else{
 			system("cls");
    			cout <<"The sequence of moves involved in the Tower of Hanoi are :\n";   
    			towers(num, 'A', 'B', 'C');
		 
			
    

	gotoxy(50,5);
	cout << "Returning to menu in: ";
	for (int j=5; j>=0;j--){
					gotoxy(72,5);
    				cout << j << endl; Sleep(500);
				};
	Menu();
}

}

//////////////////////////////////// E N D  O F  H A N O I////////////////////////////////////


////////////////////////////////////B I N A R Y  T R E E//////////////////////////////////////

bool checknode(int z){
	 bool status=false;
	
	if(node[z]=="."||node[z]=="!!!"){
		status=true;
	}
	return status;
}

 void tree()
	{
	int x=0 , y=0, z=0;
	
			
			system("cls");
			Borders();
			
			gotoxy(39,3);
				cout << "NODES";
				
			gotoxy(3,7);
				cout << "Enter a value to the node. Input '.' / a period to enter a empty node.";
			
			//LVL1
			y=39; z=8;
			gotoxy(y,z);
			cout << node[x];
			nodex[x]=y ;nodey[x]=z;
			x++;
			
			Sleep(500);
			//LVL2
			y=24;z=10;
			gotoxy(y,z-1);
			Sleep(100);
	  		cout << "("; 
			
			gotoxy(y,z);
			cout << node[x];
			nodex[x]=y ;nodey[x]=z;
			x++;
				 
			gotoxy(y+30,z-1);
			Sleep(100);
			cout << ")";  
				
			y=54;
			gotoxy(y,z);
			cout << node[x];	 
			nodex[x]=y ;nodey[x]=z;
			x++;
				
			//LEVEL3 
			
			z=13;
			
			gotoxy(17,12);
			Sleep(100);
	  		cout << "("; 
			y=17; 
			gotoxy(y,z);
			cout << node[x];	 
			nodex[x]=y ;nodey[x]=z;	 
			x++;	
				
			gotoxy(31,12);
			Sleep(100);
			cout << ")";  	
				
			y=31; 
			gotoxy(y,z);
			cout << node[x];	 
			nodex[x]=y ;nodey[x]=z;	 
			x++; 
			
			gotoxy(47,12);
			Sleep(100);
	  		cout << "("; 
				
			y=47; 
			gotoxy(y,z);
			cout << node[x];	 
			nodex[x]=y ;nodey[x]=z;	 
			x++;	
				
			gotoxy(61,12);
			Sleep(100);
			cout << ")";  
			
			y=61; 
			gotoxy(y,z);
			cout << node[x];	 
			nodex[x]=y ;nodey[x]=z;
			x++;
			
			//LEVEL4
			z = 16;
			gotoxy(13,15);
			Sleep(100);
	  		cout << "("; 
				
			y=13;
			gotoxy(y,z);
			cout << node[x];	 
			nodex[x]=y ;nodey[x]=z;
			x++;	
		
			gotoxy(20,15);
			Sleep(100);
			cout << ")"; 
			y=20; 
			gotoxy(y,z);
			cout << node[x];	 
			nodex[x]=y ;nodey[x]=z;
				x++; 
			
			gotoxy(27,15);
			Sleep(100);
	  		cout << "("; 
				
			y=27;
			gotoxy(y,z);
			cout << node[x];	 
			nodex[x]=y ;nodey[x]=z;
			x++;	
				
			gotoxy(35,15);
			Sleep(100);
			cout << ")";  
				
			y=35;
			gotoxy(y,z);
			cout << node[x];	 
			nodex[x]=y ;nodey[x]=z;
			x++;
			
			gotoxy(43,15);
			Sleep(100);
	  		cout << "("; 
			
			y=43;
			gotoxy(y,z);
			cout << node[x]; 
			nodex[x]=y ;nodey[x]=z;
			x++;
			
			gotoxy(51,15);
			Sleep(100);
			cout << ")";  
				
			y=51;
			gotoxy(y,z);
			cout << node[x];	 
			nodex[x]=y ;nodey[x]=z;
			x++;	
			
				
			gotoxy(57,15);
			Sleep(100);
	  		cout << "("; 
				
			y=57;
			gotoxy(y,z);
			cout << node[x];	 
			nodex[x]=y ;nodey[x]=z;
			x++;
			
			gotoxy(65,15);
			Sleep(100);
			cout << ")"; 
			y=66; 
			gotoxy(y,z);
			cout << node[x]; 
			nodex[x]=y ;nodey[x]=z;
			x++;  
			
			//LEVEL5
			z=19;
			gotoxy(11,18);
			Sleep(100);
	  		cout << "("; 
				
			y=11;
			gotoxy(y,z);
			cout << node[x];	 
			nodex[x]=y ;nodey[x]=z;
			x++;	
			
			gotoxy(15,18);
			Sleep(100);
			cout << ")"; 
				
			y=15; 
			gotoxy(y,z);
			cout << node[x];	 
			nodex[x]=y ;nodey[x]=z;
			x++;
					
			gotoxy(18,18);
			Sleep(100);
	  		cout << "("; 
			y=18;
			gotoxy(y,z);
			cout << node[x];	 
			nodex[x]=y ;nodey[x]=z;
			x++;
			
			gotoxy(22,18);
			Sleep(100);
			cout << ")"; 
				 
			y=22;
			gotoxy(y,z);
			cout << node[x];
			nodex[x]=y ;nodey[x]=z;
			x++;	
				
			gotoxy(25,18);
				cout << "(";
				 
			y=25; 
			gotoxy(y,z);
			cout << node[x];	 
			nodex[x]=y ;nodey[x]=z;
			x++;
			
			gotoxy(29,18);
			Sleep(100);
			cout << ")";  
			y=29;
			gotoxy(y,z);
			cout << node[x];	 
			nodex[x]=y ;nodey[x]=z;
			x++;
				
			gotoxy(33,18);
			Sleep(100);
	  		cout << "("; 
			y=33; 
			gotoxy(y,z);
			cout << node[x];
			nodex[x]=y ;nodey[x]=z;
				x++;	
				
			gotoxy(37,18);
			Sleep(100);
			cout << ")";  
				
			y=37;
			gotoxy(y,z);
			cout << node[x];
			nodex[x]=y ;nodey[x]=z;
			x++;
			
			gotoxy(41,18);
			Sleep(100);
	  		cout << "("; 
			y=41;
			gotoxy(y,z);
			cout << node[x];
			nodex[x]=y ;nodey[x]=z;
				x++;	
				
			gotoxy(45,18);
			Sleep(100);
			cout << ")"; 
			y=45; 
			gotoxy(y,z);
			cout << node[x];
			nodex[x]=y ;nodey[x]=z;
				x++;
			
			gotoxy(49,18);
			Sleep(100);
	  		cout << "("; 
			y=49;
			gotoxy(y,z);
			cout << node[x];
			nodex[x]=y ;nodey[x]=z;
				x++;	
				
			gotoxy(53,18);
			Sleep(100);
			cout << ")"; 
			y=53; 
			gotoxy(y,z);
			cout << node[x];
			nodex[x]=y ;nodey[x]=z;
				x++;
			
			gotoxy(55,18);
			Sleep(100);
	  		cout << "("; 
			
			y=55; 
			gotoxy(y,z);
			cout << node[x];
			nodex[x]=y ;nodey[x]=z;
				x++;	
				
			gotoxy(59,18);
			Sleep(100);
			cout << ")";  
			y=59;
			gotoxy(y,z);
			cout << node[x];
			nodex[x]=y ;nodey[x]=z;
				x++;
				
			gotoxy(63,18);
			Sleep(100);
	  		cout << "("; 
			y=63;
			gotoxy(y,z);
			cout << node[x];
			nodex[x]=y ;nodey[x]=z; 
				x++;	
				
			gotoxy(67,18);
			Sleep(100);
			cout << ")"; 
			y=67; 
			gotoxy(y,z);
			cout << node[x];
			nodex[x]=y ;nodey[x]=z;
				x++;
					}
void treeout()
	{
		string any;
		for(int i=0;i<=30;i++)
			{
				gotoxy(nodex[i],nodey[i]);
				cin >> node[i];
			}
		
		if(node[0]==".")
					{
					for(int i=1; i<=30 ;i++)
						{
							gotoxy(nodex[i],nodey[i]);
							node[i]="!!!";
						};
					}
		if(node[1]==".")
					{
					node[3]="!!!";
					node[4]="!!!";
					for(int i=7;i<=10;i++)
						{
							node[i]="!!!";
						};
					for(int i=15;i<=22;i++)
						{
							node[i]="!!!";
						};
					}
		if(node[2]==".")
					{
					node[5]="!!!";
					node[6]="!!!";
					for(int i=11;i<=14;i++)
						{
							node[i]="!!!";
						};
					for(int i=23;i<=30;i++)
						{
							node[i]="!!!";
						}
					}
		if(node[3]==".")
				{
				node[7]="!!!";
				node[8]="!!!";
				for(int i=15;i<=18;i++)
					{
						node[i]="!!!";
					}
				}
		if(node[4]==".")
				{
				node[9]="!!!";
				node[10]="!!!";
				for(int i=19;i<=22;i++)
					{
						node[i]="!!!";
					}
				}
		if(node[4]==".")
				{
				node[9]="!!!";
				node[10]="!!!";
				for(int i=19;i<=22;i++)
					{
						node[i]="!!!";
					}
				}
		if(node[5]==".")
				{
				node[11]="!!!";
				node[12]="!!!";
				for(int i=23;i<=26;i++)
					{
						node[i]="!!!";
					}
				}
				
		if(node[6]==".")
				{
				node[13]="!!!";
				node[14]="!!!";
				for(int i=27;i<=30;i++)
					{
						node[i]="!!!";
					}
				}
				
		if(node[7]==".")
					{
						node[15]="!!!";
						node[16]="!!!";
					}
					
		if(node[8]==".")
					{
						node[17]="!!!";
						node[18]="!!!";
					}
		
		if(node[9]==".")
					{
						node[19]="!!!";
						node[20]="!!!";
					}
		
		if(node[10]==".")
					{
						node[21]="!!!";
						node[22]="!!!";
					}
		if(node[11]==".")
					{
						node[23]="!!!";
						node[24]="!!!";
					}
		
		if(node[12]==".")
					{
						node[25]="!!!";
						node[26]="!!!";
					}
		if(node[13]==".")
					{
						node[27]="!!!";
						node[28]="!!!";
					}
		if(node[14]==".")
					{
						node[29]="!!!";
						node[30]="!!!";
					}
	}

	
void Notations()
	{
	system("cls");
	
	int ltr[]={15,7,16,3,17,8,1,19,9,20,4,21,10,22,0,23,11,24,5,25,12,26,2,23,13,18,6,29,14,30};
	int lrt[]={15,16,7,17,18,8,3,19,20,9,21,22,10,4,1,23,24,11,25,26,12,5,27,28,13,29,30,14,6,2,0};
	int tlr[]={0,1,3,7,15,16,8,17,18,4,9,19,20,10,21,22,2,5,11,23,24,12,25,26,6,13,27,28,14,29,30};
	
	//LTR

	cout << "Infix notation: " << endl;
	for(int i=1;i<=30;i++)
        {

			if(checknode(ltr[i])==false)
				{	
					cout << " " << node[ltr[i]];
				};
        };
        cout<<endl;
        
    //TLR
	cout << "Prefix notation: " << endl;
	for(int i=1;i<=30;i++)
        {
            if(checknode(tlr[i])==false)
				{
					cout << " " << node[tlr[i]];
				};
        };
    cout << endl;

	//LRT
	cout << "Postfix notation: " << endl;
	for(int i=1;i<=30;i++)
        {
			if(checknode(lrt[i])==false)
				{
					cout << " " << node[lrt[i]];
				};
        };
    cout << endl;
    gotoxy(1,15);
	cout << "Returning to menu in:";
	for (int j=5; j>=0;j--){
					gotoxy(22,15);
    				cout << j << endl; Sleep(1000);
				};
	gotoxy(22,16);
	Menu();
}
///////////////////////////////// E N D  O F  B I N A R Y  T R E E//////////////////////////////////////////////


////////////////// B O A T M A N ' S  D I L E M A////////////////////////////////////////
void bman()
	{
		system("cls");
		int grain, boatman, chicken, fox;
		Borders();
		
	gotoxy(30,4);
		cout << "The Boatman";
		
	gotoxy(25,8);
		cout << "Two Islands:(1)A or (2)B";
		
	gotoxy(27,9);
		cout << "sack of rice" ;
	
	gotoxy(39,9);
		cin >> grain ;
		
	if ((!cin>> grain)||(grain < 0))
		{
			gotoxy(39, 15);
 			cin.clear();
 			cin.ignore(999,'\n');
 			system("cls");
 			Borders();
 				
 			gotoxy(20, 15);
 			cout<<"Invalid data type! Please enter again";
 			Sleep(500);
 			cout << "!";
 			Sleep(500);
 			cout << "!";
 			Sleep(500);
 			cout << "!";
 			Sleep(500);
 				
 			bman();
 		}
	gotoxy(27,9);
    	cout << "      fox    " ;
    gotoxy(39,9);
    	cin >> fox ;
    if ((!cin>> fox)||(fox >2))
		{
			gotoxy(39, 15);
 			cin.clear();
 			cin.ignore(999,'\n');
 			system("cls");
 			Borders();
 				
 			gotoxy(20, 15);
 			cout<<"Invalid data type! Please enter again";
 			Sleep(500);
 			cout << "!";
 			Sleep(500);
 			cout << "!";
 			Sleep(500);
 			cout << "!";
 			Sleep(500);
 				
 			bman();
 		}
    gotoxy(27,9);
    	cout << "    chicken   " ;
    gotoxy(39,9);
    	cin >> chicken ;
    if ((!cin>> chicken)||(chicken >2))
		{
			gotoxy(39, 15);
 			cin.clear();
 			cin.ignore(999,'\n');
 			system("cls");
 			Borders();
 				
 			gotoxy(20, 15);
 			cout<<"Invalid data type! Please enter again";
 			Sleep(500);
 			cout << "!";
 			Sleep(500);
 			cout << "!";
 			Sleep(500);
 			cout << "!";
 			Sleep(500);
 				
 			bman();
 			
			 }
    gotoxy(27,9);
		cout << "    boatman   " ;
	gotoxy(39,9);
    	cin >> boatman ;
	if ((!cin>> boatman)||(boatman >2))
		{
			gotoxy(39, 15);
 			cin.clear();
 			cin.ignore(999,'\n');
 			system("cls");
 			Borders();
 				
 			gotoxy(20, 15);
 			cout<<"Invalid data type! Please enter again";
 			Sleep(500);
 			cout << "!";
 			Sleep(500);
 			cout << "!";
 			Sleep(500);
 			cout << "!";
 			Sleep(500);
 				
 			bman();
 		}
switch(boatman){
	case 1:{
		switch(fox){
			case 1: {
				switch(chicken){
					case 1:{
						switch(grain){
							case 1:{ 
								gotoxy(27,9);
								cout << "     SAFE!    ";
								break;
							}
							case 2:{ 
							gotoxy(27,9);
							cout << "   SAFE!    ";
								break;
							}	
						}
						break;
					}
					case 2: {
						switch(grain){
							case 1:{ gotoxy(27,9);
								cout << "      SAFE!    ";
								break;
							}
							case 2:{gotoxy(27,9);
								cout << "The rice has been eaten!";
								break;
							}
						}
						break;
					}
				}
				break;
			}
			case 2:{ 
				switch(chicken){
					case 1:{
						switch(grain){
							case 1: { gotoxy(27,9);
							cout << "      SAFE!     ";
								break;
							}
							case 2: { 
							gotoxy(27,9);
							cout << "SAFE!";
								break;
							}
						}
					
					break;
				}
					case 2:{
						switch(grain){
							case 1: {
							gotoxy(27,9);
							 cout << " chicken has been eaten by the fox!";
								break;
							}
							case 2: 
							gotoxy(27,9);
							{ cout << " chicken has been eaten by the fox!";
								break;
							}
						}
						break;
					}
			}
				break;
			}
		}
		break;
	} 
	case 2:{
		switch(fox){
			case 1:{
				switch(chicken){
					case 1:{
						switch(grain){
							case 1: {gotoxy(27,9);
								 cout << "GAMEOVER!";
								break;
							}
							case 2: {gotoxy(27,9);
							 cout << "The fox ate the chicken!";
								break;
							}
						}
						break;
					}
					case 2:{
						switch(grain){
							case 1: {gotoxy(27,9);
							 cout << "     SAFE!    ";
								break;
							}
							case 2: {gotoxy(27,9);
							 cout << "     SAFE    !";
								break;
							}
						}
						break;
					}
				}
				break;
			}
			case 2:
				switch(chicken){
					case 1:
						switch(grain){
							case 1:{gotoxy(27,9);
							 cout << "The sack of rice has been eaten by the chicken" << endl ;
								break;
							}
							case 2: { gotoxy(27,9);
							cout << "SAFE!" << endl ;
								break;
							}
						}
					case 2:
						switch(grain){
							case 1:{ gotoxy(27,9);
							cout << "    SAFE!    ";
								break;
							}
							case 2:{ gotoxy(27,9);
							cout << "     SAFE!   ";
								break;
							}
						}
				}
		}
		break;
	}
}
				gotoxy(24, 18); 
				cout << "Returning in: ";
    			for (int j=5; j>=0;j--){
    				Sleep(500);
    				gotoxy(38,18);
						cout << j ;
    				
				}
		Menu();
}
