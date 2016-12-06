#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "mfqs_table.h"
#include "rts_proc.h"
#include "mfqs_proc.h"
#include "whs_proc.h"

using namespace std; 

//#define DEBUG

#ifdef DEBUG
# define DEBUG_PRINT(x) printf x
#else
# define DEBUG_PRINT(x) do {} while (0)
#endif

int get_table_type();
bool from_file();
vector<Proc> import_file(string path, string type);

#endif
