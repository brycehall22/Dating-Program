#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <fstream>

using namespace std;

const string LOGIN_FILE = "login.txt";
void loadLogin(queue<pair<string,string>> &logins);
bool login(queue<pair<string,string>> &logins);