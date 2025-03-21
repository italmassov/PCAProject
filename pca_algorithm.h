#include <vector>
#include <iostream>
#include <fstream>    // for reading CSV
#include <sstream>    // for CSV parsing
#include <cmath>      // for math functions
#include <algorithm>  // for basic utility

using std::vector;

vector<vector<double>> run_pca(
    vector<vector<double>>& data,
    int num_components,
    double tolerance = 0.001,
    int max_iterations = 1000
);

vector<double> find_principal_component(
    vector<vector<double>>& data,
    double tolerance,
    int max_iterations
);

void shrik_matrix(
    vector<vector<double>>& data,
    const vector<double>& principal_component   
);