#include <vector>
#include <iostream>
#include <fstream>    // for reading CSV
#include <sstream>    // for CSV parsing
#include <cmath>      // for math functions
#include <algorithm>  // for basic utility

using std::vector;
using std::string;

vector<vector<double>> load_csv_data(const string& filename);
