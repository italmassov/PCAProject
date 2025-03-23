#include "data_loader.h"

vector<vector<double>> load_csv_data(const string &filename)
{
    using std::vector, std::string, std::stringstream;

    // read the file
    std::ifstream file(filename);
    if (!file.is_open()){
        throw std::runtime_error("Could not open the file: " + filename);
    }

    vector<vector<double>> data;
    string line;
    size_t line_number = 0;

    while(std::getline(file, line)){
        ++line_number;
        if(line.empty()) continue;

        stringstream ss(line);
        vector<double> row;
        string cell;

        while(std::getline(ss, cell, ',')){
            try{
                if(cell.empty()){
                    row.push_back(0.0); // handle empty cells
                } else {
                    row.push_back(std::stod(cell));
                }
            } catch(const std::invalid_argument){
                std::cerr << "Warning: Non-numeric value at line " << line_number << ". Skipping cell.\n";
                row.push_back(0.0);
            }    
        }

        if(!row.empty()){
            data.push_back(row);
        }
    }

    return data;
}