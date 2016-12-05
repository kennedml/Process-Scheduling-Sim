#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include "mfqs_table.h"
#include "proc.h"

using namespace std; 


int get_table_type();
bool from_file();
vector<Proc> import_file(string path);

#endif
