#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;

const int EXIT = 0;
const int ADDLOGIN = 1;
const int LOGIN = 2;

int getChoice(int &realChoice)
{
  bool valid = false;
  cout << "1.  Create Account\n"
              << "2.  Login\n"
              << "Enter Choice:  ";
  do 
  {
    cin >> realChoice;
    if (realChoice == EXIT)
    {
      valid = true;
    }
    else if (realChoice > 0 || realChoice < 3)
      valid = true;
    else
      cout << "please re-enter choice: ";
  } while (!valid);
  return realChoice;
}

int getChoice2(int &realChoice)
{
  bool valid = false;
  cout << "1.  Create Profile\n"
              << "2.  Start Matching\n"
              << "Enter Choice:  ";
  do 
  {
    cin >> realChoice;
    if (realChoice == EXIT)
    {
      valid = true;
    }
    else if (realChoice > 0 || realChoice < 3)
      valid = true;
    else
      cout << "please re-enter choice: ";
  } while (!valid);
  return realChoice;
}