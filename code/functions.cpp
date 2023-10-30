#include "header.h"

void loadLogin(queue<pair<string,string>> &logins)
{
  ifstream loginFile(LOGIN_FILE);
  if (!loginFile.is_open())
  {
    cout << "Error opening login file!" << endl;
  }
  string line;
  while (getline(loginFile, line))
  {
    size_t delimiterPos = line.find(",");
    string username = line.substr(0, delimiterPos);
    string password = line.substr(delimiterPos + 1);
    logins.emplace(username, password);
  }
  loginFile.close();
}

bool login(queue<pair<string,string>> &logins)
{
  string username;
  string password;

  cout << "Enter username: ";
  cin >> username;
  cout << "Enter password: ";
  cin >> password;

  while (!logins.empty())
  {
    if (logins.front().first == username && logins.front().second == password)
    {
      cout << "logged in succesfully\n" << endl;
      return true;
    }
    logins.pop();
  }
  cout << "Invalid username or password!\n" << endl;
  return false;
}