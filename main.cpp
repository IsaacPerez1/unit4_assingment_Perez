//Isaac Perez 11/20/19
//Dr_T fundamentals of programming 2
//A vector to average grades using a negative number to exit the loop
#include <iostream>
#include <vector>
#include<algorithm>//for sorting
#include<fstream>
#include "input_validation.h"
#include "color.h"
#include <iomanip>

using namespace std;



void func(double n, vector<double> &gradesVector)
 {
   gradesVector.push_back(n);
   } 

double avg(vector<double> &vec)
{
  double sum = 0.0;
  for(auto &i : vec)// sum the vector
  {
    sum+= i;
  }
  return(sum/vec.size());//divide the sum by the size of the vector
}

void print(vector<double> &printVector)
{
  sort(printVector.begin(), printVector.end());//sort the vector ASC
  reverse(printVector.begin(), printVector.end());//sort the vector DES, must first sort ASC

   for (int i=0; i<printVector.size(); i++) 
   cout <<"\x1b[" + std::to_string(32) + ";1m" << printVector[i] << " "<<  "\x1b[0m" <<endl ; 

}

void text(vector<double> &printTranscript)
{
   ofstream file;// file becomes cout, can name whatever you want
    file.open("Transcript.txt", ios::trunc);//optional parameters matter
    //for(auto &i : printTranscript){ // caused problems, not printing all values to text file
   // file << i << endl;
   for (int i=0; i<printTranscript.size(); i++) 
   file << printTranscript[i] << " "<< endl ; 
    
    file.close();
    }

int main() 
{
  double n = 0.0;
  char option = '\0';
  vector<double> vect; 
  cout << fixed << setprecision(4) <<endl;
    



  
    //cout << "\033[2J\033[1;1H";
do{
  cout << "Enter the grades that you would like to be averaged [enter a negative to stop]: " << endl;
  
  while(n > -1.0) //-1.0 -Dr_T - finally got to a real computer rather than phone
  {
    
    cout << "GRADE: ";
    n = validateDouble(n);
    if( n > -1.0) //double check, make sure that n is positve before adding it to the vector 
    {
      func(n,vect); //loop until a negative number is entered. this works too. 
    }
    
  }
  

  // for (int i=0; i<vect.size(); i++) 
   //cout << vect[i] << " "<< endl ; 
 // for(auto &i : vect){// alternate method to line 42 and 43
    //cout << i << endl;
 // }


print(vect);
cout << "Average: " <<"\x1b[" + std::to_string(32) + ";1m"<< avg(vect) << "\x1b[0m" << endl;


text(vect);
n = 0.0;// reset value of n, lets me enter new values into the vector 
// n is negative when we exit so we cant re-enter the loop. resetting it lets us enter the loop n >-1 line 66
cout << "y to continue or e to exit: ";
option = validateChar(option);
    
  cout << "\033[2J\033[1;1H";
}while(option != 'e' && option != 'E');
  cout << "Bye"; 
 
  return 0;
}

