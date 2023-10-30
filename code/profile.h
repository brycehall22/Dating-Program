#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Profile
{
  string name;
  int age;
  string gender;
  string location;
  string preferences;
};

Profile createProfile()
{
  Profile profile;

  cout << "Name: ";
  cin >> profile.name;
  cout << "Age: ";
  cin >> profile.age;
  cout << "Gender: ";
  cin >> profile.gender;
  cout << "Location: ";
  cin >> profile.location;
  cout << "Preference: ";
  cin >> profile.preferences;

  return profile;
}

void storeProfile(const Profile &profile)
{
  ofstream profileFile("profiles.txt", ios::app);
  if (!profileFile.is_open())
  {
    cout << "Error opening profile file!" << endl;
    return;
  }
  profileFile << profile.name << "," << profile.age << "," << profile.gender << "," << profile.location << "," << profile.preferences << endl;
  profileFile.close();
}

vector<Profile> loadProfiles()
{
  vector<Profile> profiles;

  ifstream profileFile("profiles.txt");
  if (!profileFile.is_open())
  {
    cerr << "Error opening profile file!" << endl;
    return profiles;
  }

  string line;
  while (getline(profileFile, line))
  {
    istringstream lineStream(line);
    string field;

    Profile profile;
    getline(lineStream, profile.name, ',');
    getline(lineStream, field, ',');
    profile.age = stoi(field);
    getline(lineStream, profile.gender, ',');
    getline(lineStream, profile.location, ',');
    getline(lineStream, profile.preferences, ',');

    profiles.push_back(profile);
  }

  profileFile.close();
  return profiles;
}

Profile getCurrentProfile(const string &username)
{
  ifstream profileFile("profiles.txt");
  if (!profileFile.is_open())
  {
    cerr << "Error opening profile file!" << endl;
    return {};
  }

  string line;
  while (getline(profileFile, line))
  {
    istringstream lineStream(line);
    string field;

    Profile profile;
    getline(lineStream, profile.name, ',');
    if (profile.name == username)
    {
      getline(lineStream, field, ',');
      profile.age = stoi(field);
      getline(lineStream, profile.gender, ',');
      getline(lineStream, profile.location, ',');
      getline(lineStream, profile.preferences, ',');
      return profile;
    }
  }
  profileFile.close();
  cout << "Error: Could not find profile with username '" << username << "'." << endl;
  return {};
}

vector<Profile> matchProfiles(const Profile &currentProfile, const vector<Profile> &profiles)
{
  vector<Profile> matches;
  for (const auto &profile : profiles)
  {
    if (profile.gender == currentProfile.preferences &&
        abs(profile.age - currentProfile.age) <= 5 &&
        profile.location == currentProfile.location)
    {
      matches.push_back(profile);
    }
  }
  return matches;
}