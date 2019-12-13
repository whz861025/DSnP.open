/****************************************************************************
  FileName     [ p2Json.cpp ]
  PackageName  [ p2 ]
  Synopsis     [ Define member functions of class Json and JsonElem ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2018-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#include "p2Json.h"
#include <climits>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Implement member functions of class Row and Table here

/*******************************************************************************
 *                  Json Object's member function definition                   *
 *******************************************************************************/

bool Json::read(const string &jsonFile) {
  ifstream ifs(jsonFile);
  string s;
  if (ifs) {
    while (getline(ifs, s)) {
      // trim string s first
      if (s.empty()) {
        continue;
      }
      size_t start = s.find_first_not_of(" ");
      size_t end = s.find_last_not_of(" ");
      s = s.substr(start, end - start + 1);

      if (s == "{" || s == "}") {
        // ignore first and last line
        continue;
      } else {
        // get the JSON key and value
        size_t key_start = s.find_first_of("\"") + 1;
        size_t key_end = s.find_last_of("\"") - 1;
        string key = s.substr(key_start, key_end - key_start + 1);
        size_t value_start = s.find_first_of(":");
        s = s.substr(value_start + 1);
        value_start = s.find_first_of("-0123456789");
        size_t value_end = s.find_last_of("0123456789");
        int value = stoi(s.substr(value_start, value_end - value_start + 1));
        this->add(key, value);
      }
    }
  } else {
    return false;
  }

  return true;
}

void Json::print() {
  cout << "{" << endl;
  for (size_t i = 0; i < _obj.size(); ++i) {
    cout << "  " << _obj[i];
    if (i != _obj.size() - 1) {
      cout << ",";
    }
    cout << endl;
  }
  cout << "}" << endl;
}

void Json::add(const string key, int value) {
  _obj.push_back(JsonElem(key, value));
}

void Json::sum() {
  int sum = 0;
  for (size_t i = 0; i < _obj.size(); ++i) {
    sum += _obj[i].getValue();
  }
  cout << "The summation of the values is: " << sum << "." << endl;
}

void Json::average() {
  double AVE = 0;
  for (size_t i = 0; i < _obj.size(); ++i) {
    AVE += _obj[i].getValue();
  }
  AVE /= _obj.size();
  cout << "The average of the values is: " << fixed << setprecision(1) << AVE
       << "." << endl;
}

void Json::max() {
  int MAX = INT_MIN;
  int index = -1;
  for (size_t i = 0; i < _obj.size(); ++i) {
    if (_obj[i].getValue() > MAX) {
      index = i;
      MAX = _obj[i].getValue();
    }
  }
  cout << "The maximum element is: {" << _obj[index] << "}." << endl;
}

void Json::min() {
  int MIN = INT_MAX;
  int index = -1;
  for (size_t i = 0; i < _obj.size(); ++i) {
    if (_obj[i].getValue() < MIN) {
      index = i;
      MIN = _obj[i].getValue();
    }
  }
  cout << "The minimum element is: {" << _obj[index] << "}." << endl;
}

/*******************************************************************************
 *                JsonElem Object's member function definition                 *
 *******************************************************************************/

ostream &operator<<(ostream &os, const JsonElem &j) {
  return (os << "\"" << j._key << "\" : " << j._value);
}
