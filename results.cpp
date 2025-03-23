#include "results.h"
#include <iostream>
#include <fstream>

using std::cout; 
void print_results(const vector<vector<double>> &components)
{
    cout << "Principal components:" << std::endl;
    for (size_t i = 0; i<components.size(); ++i) {
        cout<<"\nPrincipal Components:\n";
        for (size_t i=0; i<components.size(); ++i) {
            cout << "Component #" << i+1 << ": ";
            for(double val:components[i]){
                cout << val << " ";
            }
            cout<<"\n";
        }
    }
}

void save_results_to_csv(const vector<vector<double>> &components, const string &filename)
{
    std::ofstream file(filename);
    if(!file.is_open()){
        std::cerr << "Error: Could not open file for writing: " << filename << "\n";
        return;
    }

    for(const auto& comp: components){
        for(size_t i=0; i<comp.size(); ++i){
            file << comp[i];
            if(i != comp.size()-1){
                file<<" ;";
            }
        }
        file << "\n";
    }
    cout << "Results saved successfully to " << filename << "\n";
}
