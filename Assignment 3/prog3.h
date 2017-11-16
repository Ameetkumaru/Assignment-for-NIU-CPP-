#ifndef CONSTANT_VALUE
#define CONSTANT_VALUE
#include <iostream>
#include <string>
#include<cstring>
#include<fstream>
using namespace std;
const string PATH="/home/cs689/progs/16s/p3/prog3.d2";
void process_infile(int);
string encodeCaesarCipher(string ,int );
int new_position(char ,int);
void error(string);
#endif
