#include "matrix_utils.h"

using std::vector;

vector<vector<double>> transpose(const vector<vector<double>> &matrix)
{
    size_t rows = matrix.size();
    size_t cols = matrix[0].size();

    // create placeholder
    vector<vector<double>> result(cols, vector<double>(rows));

    for(size_t i = 0; i<rows; i++){
        for(size_t j=0; j<cols; j++){
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}

vector<double> matrix_vector_multiply(const vector<vector<double>> &matrix, const vector<double> &vec)
{
    //check if dimensions congrue. matrix cols == vector size
    if(matrix[0].size()!=vec.size()){
        throw std::invalid_argument("Matrix columns and vector size do not match");
    }

    vector<double> result(matrix.size(), 0); //set up resulting vector equal to rows number
    for(size_t i=0; i<matrix.size(); ++i){
        for(size_t j=0; j<vec.size(); j++){
            result[i] += matrix[i][j] * vec[j];
        }
    }
    return result;
}

double vector_norm(const vector<double> &vec)
{
    double sum_sq = 0.0;
    for(double val:vec){
        sum_sq += val*val;
    }
    return std::sqrt(sum_sq);
}

vector<double> normalize_vector(const vector<double> &vec)
{
    double norm = vector_norm(vec);
    if(norm==0) return vec;
    vector<double> result(vec.size());
    for(size_t i=0; i<vec.size(); i++){
        result[i] = vec[i] / norm;
    }
    return result;
}

vector<vector<double>> outer_product(const vector<double> &col_vec, vector<double> &row_vec)
{
    vector<vector<double>> result(col_vec.size(), vector<double>(row_vec.size()));
    for(size_t i=0; i<col_vec.size(); ++i){
        for(size_t j=0; j<row_vec.size(); ++j){
            result[i][j] = col_vec[i]*row_vec[j];
       }
    }
    return result;
}

vector<vector<double>> substract_matrix(const vector<vector<double>> &A, vector<vector<double>> &B)
{
    if(A.size() != B.size() || A[0].size() != B[0].size()){
        throw std::invalid_argument("Matrix sizes do not match.");
    }
    vector<vector<double>> result(A.size(), vector<double>(A[0].size()));
    for(size_t i=0; i<A.size(); ++i){
        for(size_t j=0; j<A[0].size(); ++j){
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}
