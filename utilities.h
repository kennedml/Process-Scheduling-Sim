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

#define DEBUG

#ifdef DEBUG
# define DEBUG_PRINT(x) printf x
#else
# define DEBUG_PRINT(x) do {} while (0)
#endif

int get_table_type();
bool from_file();
vector<Proc> import_file(string path, string type);

#endif
