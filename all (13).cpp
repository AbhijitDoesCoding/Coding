#include <iostream>
using namespace std;
#include<bits/stdc++.h>

int main() 
{
    int numberOfTestCases;
    cin >> numberOfTestCases;
    while(numberOfTestCases--){
      
      int casseroleLength, initialPieces, finalPieces;
      cin >> casseroleLength >> initialPieces >> finalPieces;
      string monkActions;
      cin >> monkActions;
      int currentPieceIndex = initialPieces - 1, wastedPieces = 0, failedOperations = 0;
      for(auto actionIndex = 0; actionIndex < monkActions.size(); actionIndex++){
        char action = monkActions[actionIndex];
        if(action == 'L'){
          currentPieceIndex = initialPieces;
        }
        else if(action == 'W'){
          if(currentPieceIndex <= 0) wastedPieces++;
        }
        else{
          if(currentPieceIndex <= 0) failedOperations++;
        }
        currentPieceIndex--;
      }
      
      if(wastedPieces > finalPieces) failedOperations++;
      
      cout << (failedOperations!= 0? "NO" : "YES") << endl;
      
    }
    return 0;
}