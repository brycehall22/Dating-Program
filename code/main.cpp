#include "header.h"
#include "choices.h"
#include "text.h"
#include "profile.h"

int main() {
  string username;
  string password;
  int choice = 0;
  Profile profiles;
  queue<pair<string,string>> logins;
  welcome();
  do {
    getChoice(choice);
    if (choice == ADDLOGIN)
    {
      ofstream loginFile(LOGIN_FILE, ofstream::app);
      if (!loginFile.is_open())
      {
        cout << "Error opening login file!" << endl;
      }
      cout << "Enter username: ";
      cin >> username;
      cout << "Enter password: ";
      cin >> password;
      loginFile << username << "," << password << endl;
      loginFile.close();
      cout << endl;
    }
    if (choice == LOGIN)
    {
      loadLogin(logins);
      if (login(logins) == false)
      {
        continue;
      }
      getChoice2(choice);
      if (choice == 1)
      {
        intro();
        storeProfile(createProfile()); 
        choice = 2;
      }
      if (choice == 2)
      {
        vector<Profile> profiles = loadProfiles();
        cout << "what is your username so we can find your account: ";
        cin >> username;
        Profile currentProfile = getCurrentProfile(username);
        vector<Profile> matches = matchProfiles(currentProfile, profiles);
        cout << "matches: ";
        for (int i = 0; i < matches.size(); i++)
        {
          cout << matches[i].name << " , " << matches[i].age << "\n" << endl;
        }
        cout << endl;
      }
    }
  } while (choice != EXIT);
  return 0;
}