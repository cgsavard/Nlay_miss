#include <stdio.h>
#include <iostream>
#include <cmath>

using namespace std;

int main(){

  int hitpat;
  cout << "Enter a hitpattern number: ";
  cin >> hitpat;

  int nbits = floor(log2(hitpat)) + 1; //calc num of bits req for num
  
  int lay_i = 0;
  int nlaymiss = 0;
  bool seq = 0;
  for (int i=0; i<nbits; i++){
    lay_i = ((1<<i)&hitpat)>>i; //0 or 1 in ith bit (right to left)
    
    if (lay_i && !seq) seq = 1; //sequence starts when first 1 found
    if (!lay_i && seq) nlaymiss++;
  }
  
  cout << "Number of layers missed in sequence: " << nlaymiss << endl;
  
  return 0;
}
