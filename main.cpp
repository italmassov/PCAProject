#include <vector>
#include <iostream>
#include <fstream>    // for reading CSV
#include <sstream>    // for CSV parsing
#include <cmath>      // for math functions
#include <algorithm>  // for basic utility

#include "data_loader.h"
#include "pca_algorithm.h"
#include "results.h"

int main(){
    using std::cout, std::getline, std::cin, std::string;

    cout<< "Welcome to the PCA Calculator!" << std::endl;

    string filename;
    cout << "Enter the path to your CSV file [default: data/dji_last_12m.csv]: ";
    getline(cin, filename);
    if(filename.empty()) filename = "data/dji_last_12m.csv";

    auto data = load_csv_data(filename);
    cout << "Data loaded successfully! Matrix size: " << data.size() << " rows x" << data[0].size() << " columns." <<std::endl;
    
    int num_components;
    cout<<"How many principal components to calculate? ";
    cin >> num_components;

    double tolerance = 0.001;
    char custom_tol;
    cout << "Use default tolerance (0.001)? (y/n):";
    cin >> custom_tol;
    if(custom_tol == 'n' || custom_tol == 'N'){
        cout << "Enter tolerance";
        cin >> tolerance;
    }

    auto components = run_pca(data, num_components, tolerance);
    print_results(components);

    char save_choice;
    cout << "Save results to CSV? (y/n): ";
    cin >> save_choice;
    if(save_choice == 'y' || save_choice == 'Y'){
        string out_file;
        cout << "Enter output filename [default: pca_results.csv]";
        cin.ignore();
        getline(cin, out_file);
        if(out_file.empty()) out_file = "pca_results.csv";
        save_results_to_csv(components, out_file);
        cout << "Results saved to " << out_file << std::endl;
    }

    return 0;
}