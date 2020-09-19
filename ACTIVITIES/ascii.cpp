#include <iostream>
using namespace std;

void swap(string* stringAddress, string stringValue){
    *stringAddress = stringValue;
}
int main(){
    string myString = "Alvin";
    string newString = "Laurean";
    //before
    cout << myString << endl;
    string * ptr = &myString;
    swap(ptr, newString);
    // after
    cout << myString << endl;
    return 0;
}


