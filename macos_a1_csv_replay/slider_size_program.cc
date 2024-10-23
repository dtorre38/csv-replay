#include <iostream>
#include <fstream>
#include <string>

#include <regex>

using namespace std;

char data_file[256] = "data.csv";

//Counts the number of lines in a file
int countLines(){
    int numLines = 0;
    string line;
    // Opens the file
    ifstream countLinesFile(data_file);
    // Counts the number of lines in the data file
    while(getline(countLinesFile, line)){
      numLines++;
    }
    // Closes the data file
    countLinesFile.close();
    return numLines;
}

int main(int argc, const char** argv) {
    // Check if the correct number of arguments are passed
    if (argc < 2) {
        std::cerr << "Usage: ./slider_size_program <data_file>" << std::endl;
        return 1;
    }

    // argv[1] is the data file path, updating the global variable
    strncpy(data_file, argv[1], sizeof(data_file) - 1);
    data_file[sizeof(data_file) - 1] = '\0';  // Ensure null-terminated

    int num = countLines() - 2;
    string oldText = "{mjITEM_SLIDERINT, \"Time Slider\", 2, &settings.sld_time,  \"0 ";
    string newText = "{mjITEM_SLIDERINT, \"Time Slider\", 2, &settings.sld_time,  \"0 " + to_string(num) + "\"},";
    
    ifstream simulateFile("simulate.cc");
    ofstream tempFile("temp_simulate.cc");
    
    if (!simulateFile.is_open() || !tempFile.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string line;
    while (getline(simulateFile, line)) {
        // Check if the line contains the oldText
        size_t pos = line.find(oldText);
        if (pos != string::npos) {
            // Replace the old text with the new text
            line.replace(pos, oldText.length() + 7, newText);
        }
        tempFile << line << endl;
    }

    simulateFile.close();
    tempFile.close();

    // Replace original file with modified file
    remove("simulate.cc");
    rename("temp_simulate.cc", "simulate.cc");

    return 0;
}

