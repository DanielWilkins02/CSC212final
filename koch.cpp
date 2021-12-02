#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;

int midpoints () {
    
}

void WriteFile(std::string file_name, std::vector<std::vector<int>> * const image_data){
    // Opens the outfile file, prepares it for writing
    std::ofstream output_file(file_name);

    //cout << image_data->size() << ", " << image_data[0][0].size() << endl;

    // Loop rows
    for(unsigned int i = 0; i < image_data->size(); i++){
        // Loop columns
        for(unsigned int j = 0; j < image_data[0][0].size(); j++){
            // Output each value and a space
            output_file << (*image_data)[i][j] << " ";
        }
        // Output a newline character after every row
        output_file << "\n";
    }
}

void koch(vector<vector<int>>* img, int x, int y, int size, int level, int angle){
    
    if (level == 0) {
        return;
    }
    (*img)[y][x] = 1;
    cout << (*img)[y][x] << endl;
    
    level = level - 1;
    angle = angle + 60;
    size = size1;
    
    
    
    koch(&(*img), x, y, size, level, angle); 
    koch(&(*img), x+cos(angle*(M_PI/180))*size, y+sin(angle*(M_PI/180))*size, size, level, angle); 
    koch(&(*img), x-cos(angle*(M_PI/180))*size, y+sin(angle*(M_PI/180))*size, size, level, angle); 
    
    return;
}

int main(int argc, char** argv){
    int size = atoi(argv[1]); //set the size, in col and row. 
    int level = atoi(argv[2]); //how deep we go in the recursion.
    string file_name = argv[3]; //filename. 
    
    vector<vector<int>> img(100, vector<int> (100, 0));
    
    koch(&img, 50, 10, size, level, 60);
    koch(&img, 50+cos(60*(M_PI/180))*size, 10+sin(60*(M_PI/180))*size, size, level, 60); 
    koch(&img, 50-cos(60*(M_PI/180))*size, 10+sin(60*(M_PI/180))*size, size, level, 60);
    
    WriteFile("file.img", &img);
}
