/*
Task 1: 
Write a program to create inverted hollow triangle star pattern of size n
* * * * * * * * * * *
  *               *
    *           *
      *       *
        *   *
          *

*/

#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter n: ";
  cin >> n; 

  for(int i=n; i>=1; i--) {
    for(int j=n; j>i; j--) cout << "  ";
    for(int j=1; j<=i*2-1; j++) {
      if(j == 1 || j == i*2-1 || i == n)cout << "* ";
      else cout << "  ";
    }
    cout << endl;
  }
  return 0;
}
