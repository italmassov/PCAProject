#include <vector>
#include <iostream>
#include <fstream>    // for reading CSV
#include <sstream>    // for CSV parsing
#include <cmath>      // for math functions
#include <algorithm>  // for basic utility

using std::vector;
using std::string;

void print_results(const vector<vector<double>>& components);
void save_results_to_csv(
    const vector<vector<double>>& components,
    const string& filename
);