/*
Task 01: 

    *
   * *
  * * *
 * * * *
* * * * *
*/


#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cout << "Enter n: ";
	cin >> n;
	for(int i=0; i<n; i++){
	  for(int j=n-1; j>i; j--) cout << " ";
	  for(int j=0; j<i*2+1; j++) cout << "*";
	  cout << endl;
	}
}

