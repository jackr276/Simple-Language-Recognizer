/**
 * Author: Jack Robbins
 * 11/09/2023
 * Simple Language Recognizer
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <stack>
#include <string>

using namespace std;


/**
 * Language Rules: L = {S#S’ , where S is a possibly empty string other than #, and S’ = reverse(S)}
 * So essentially, S and S' are palindromes, and there needs to be a hashtag in the sentence
*/
bool inLanguage(string& inputString);

/**
 * Driver Function, simply iterates through file until we hit EOF, calling inLanguage line by line
 * and printing the approp
*/
int main(int argc, char *argv []){
    string sentence;
    bool isInLanguage;
    int Lcount=0;
    ifstream file;
    if( argc >= 2 ) {
        file.open(argv[1]);
        if( !file) {
        /* error */
        cerr << "File cannot be opened: " << argv[1] << endl;
        exit (1);
        }
    } else {
        cerr << "No file is found" << endl;
        exit (1);
    }
        
    getline(file, sentence);
    if(file.eof() || sentence.length() == 0) {
        cerr << "File is empty." << endl;
        exit (1);
    }
    while (!file.eof()) {
        Lcount++;
        isInLanguage = inLanguage(sentence);
        if (isInLanguage){
            cout << "\"" << sentence << "\"" << " is a sentence in the Language." << endl;
        } else {
            if(sentence.length() != 0) {
            cout << "\"" << sentence << "\"" << " is not a sentence in the Language." << endl;
            }
        }
        getline(file, sentence);
    }
}