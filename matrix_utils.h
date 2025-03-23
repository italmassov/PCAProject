#include <vector>
#include <iostream>
#include <stdexcept>  // for exceptions

using std::vector;

vector<vector<double>> transpose(const vector<vector<double>>& matrix);
vector<double> matrix_vector_multiply(const vector<vector<double>>& matrix, const vector<double>& vec);
double vector_norm(const vector<double>& vec);
vector<double> normalize_vector(const vector<double>& vec);
vector<vector<double>> outer_product(const vector<double>& col_vec, const vector<double>& row_vec);
vector<vector<double>> substract_matrix(const vector<vector<double>>& A, vector<vector<double>>& B);
