#include <vector>
#include <iostream>
#include <fstream>    // for reading CSV
#include <sstream>    // for CSV parsing
#include <stdexcept>  // to throw the exceptions

using std::vector;
using std::string;

vector<vector<double>> load_csv_data(const string& filename);
