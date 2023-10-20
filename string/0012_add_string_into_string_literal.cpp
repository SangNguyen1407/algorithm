#include <iostream>
#include <string.h>

using namespace std;

char *addTimeIntoFilename(char *filename){
    string str_time = "_20231010";
    char *newFilename = (char*)malloc( strlen(filename) + str_time.size() + 1 );
    char *arr_filename  = (char*)malloc( strlen(filename) );
    char *extendedFilename;

    // change string literal to char[]
    strcpy(arr_filename, filename);
    extendedFilename = strtok(arr_filename, ".");
    extendedFilename = strtok(NULL, ".");

    strcpy(newFilename, filename);
    strcpy(newFilename + ( strlen(filename)-strlen(extendedFilename)-1 ), str_time.c_str());
    strcpy(newFilename + ( strlen(newFilename) ), ".");
    strcpy(newFilename + ( strlen(newFilename) ), extendedFilename);

    return newFilename;
}


int main (){
    
    char *filename = "testFile.doc";

    //new filename is testFile_20231010.doc
    cout << "new fileName: "<< addTimeIntoFilename(filename) << endl;

    //new filename is testFile_20231010.excel
    filename = "testFile.excel";
    cout << "new fileName: "<< addTimeIntoFilename(filename) << endl;
}