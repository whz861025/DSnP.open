/****************************************************************************
  FileName     [ p2Main.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define main() function ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2016-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include "p2Json.h"
#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

/**
 * @brief: parse the input command string
 *
 * @param: string command
 *
 * @return: vector<string>
 */
vector<string> getCommandOpt(string command) {
  std::vector<string> parsed_command;
  // Trimmed command
  size_t start = command.find_first_not_of(" ");
  command = command.substr(start);
  while(true){
		size_t pos = command.find_first_of(" ");
		parsed_command.push_back(command.substr(0, pos));
		command = command.substr(pos+1);
		if (pos == string::npos) {
			break;
		}
	}
  return parsed_command;
}

int main() {
  Json json;

  // Read in the csv file. Do NOT change this part of code.
  string jsonFile;
  cout << "Please enter the file name: ";
  cin >> jsonFile;
  if (json.read(jsonFile))
    cout << "File \"" << jsonFile << "\" was read in successfully." << endl;
  else {
    cerr << "Failed to read in file \"" << jsonFile << "\"!" << endl;
    exit(-1); // jsonFile does not exist.
  }

	cin.clear();
	cin.ignore(INT_MAX, '\n');
  // TODO read and execute commands
  while (true) {
    string command;
    cout << "Enter command: ";
		getline(cin, command, '\n');
		vector<string> parsed_command = getCommandOpt(command);

    if (parsed_command[0] == "PRINT") {
      json.print();
    } else if (parsed_command[0] == "SUM") {
      json.sum();
    } else if (parsed_command[0] == "MAX") {
      json.max();
    } else if (parsed_command[0] == "MIN") {
      json.min();
    } else if (parsed_command[0] == "AVE") {
      json.average();
    } else if (parsed_command[0] == "ADD") {
			json.add(parsed_command.at(1), stoi(parsed_command.at(2)));
    } else if (parsed_command[0] == "EXIT") {
      break;
    }
  }
}
