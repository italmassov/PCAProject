#include "results.h"

void print_results(const vector<vector<double>> &components)
{
    std::cout << "Principal components:" << std::endl;
    for (const auto& comp : components) {
        for (double val : comp) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

void save_results_to_csv(const vector<vector<double>> &components, const string &filename)
{
}
