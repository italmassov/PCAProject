#include "pca_algorithm.h"
#include "matrix_utils.h"
#include <iostream>
#include <cmath>

using std::vector, std::cout;

vector<vector<double>> run_pca(vector<vector<double>> &data, int num_components, double tolerance, int max_iterations)
{
    vector<vector<double>> components;

    for(int i = 0; i<num_components; ++i){
        cout << "Calculating principal component #" <<(i+1)<<std::endl;

        auto t_i = find_principal_component(data, tolerance, max_iterations);

        auto Xt = transpose(data);
        auto p_i = matrix_vector_multiply(Xt, t_i);
        p_i = normalize_vector(p_i);

        components.push_back(p_i);

        cout<<"Principal component #" <<(i+1) << " found. Shrinking the data matrix.. " <<std::endl;

        shrink_matrix(data, t_i, p_i);
    }

    return components;
}

vector<double> find_principal_component(vector<vector<double>> &data, double tolerance, int max_iterations)
{
    vector<double> t_i;
    for(const auto& row: data){
        t_i.push_back(row[0]);
    }

    for(int iter=0; iter<max_iterations; ++iter){
        auto Xt = transpose(data);
        auto p_i = matrix_vector_multiply(Xt, t_i);
        p_i = normalize_vector(p_i);

        auto t_new = matrix_vector_multiply(data, p_i);

        double diff = 0.0;
        for(size_t i=0; i<t_i.size(); ++i){
            double d = t_new[i] - t_i[i];
            diff += d*d;
        }
        diff = std::sqrt(diff);
        cout << "Iteration " << iter+1 << ", Δ = " << diff << std::endl;

        if(diff<tolerance){
            cout<<"Converged in " << iter + 1 << " iterations." <<std::endl;
            return t_new;
        }
        t_i = t_new;
    }

    cout << "Warning: Convergence not reached after " << max_iterations << " iterations." << std::endl;
    return t_i;
}

void shrink_matrix(vector<vector<double>>& data,
                    const vector<double>& t_i, const vector<double>& p_i){
    auto tp = outer_product(t_i, p_i);
    auto shrunk = substract_matrix(data, tp);
    data = shrunk;  
}
