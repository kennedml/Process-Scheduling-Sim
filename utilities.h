#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std; 

void get_user_input(int& table_type, int& pid, int& burst, int& arrival, int& priority, int& io, int& deadline);
bool from_file();

#endif
