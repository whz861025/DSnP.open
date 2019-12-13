/****************************************************************************
  FileName     [ p2Json.h]
  PackageName  [ p2 ]
  Synopsis     [ Header file for class Json JsonElem ]
  Author       [ Chung-Yang (Ric) Huang ]
  Copyright    [ Copyleft(c) 2018-present DVLab, GIEE, NTU, Taiwan ]
****************************************************************************/
#ifndef P2_JSON_H
#define P2_JSON_H

#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class JsonElem {
public:
  // TODO: define constructor & member functions on your own
  JsonElem() {}
  JsonElem(const string &k, int v) : _key(k), _value(v) {}

  friend ostream &operator<<(ostream &, const JsonElem &);

  // getter function
  int getValue() { return this->_value; }
  string getKey() { return this->_key; }

private:
  string _key; // DO NOT change this definition. Use it to store key.
  int _value;  // DO NOT change this definition. Use it to store value.
};

class Json {
public:
  // TODO: define constructor & member functions on your own
  bool read(const string &);

  // TODO: complete member function
  void print();
  void add(string, int);
  void sum();
  void average();
  void max();
  void min();

private:
  vector<JsonElem> _obj; // DO NOT change this definition.
                         // Use it to store JSON elements.
};

#endif // P2_TABLE_H
