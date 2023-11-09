/**
 * Author: Jack Robbins
 * 11/09/2023
 * Simple Language Recognizer function
 * This file contains the implementation of the inLanguage function
*/

#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;


/**
 * Language Rules: L = {S#S’ , where S is a possibly empty string other than #, and S’ = reverse(S)}
 * So essentially, S and S' are palindromes, and there needs to be a hashtag in the sentence
*/
bool inLanguage(string& inputString){
    bool foundHash = false;

    //If we have a stack for the first "word", and a queue for the last "word", the dequeue of word 2 should be the pop of word1
    stack<char> firstWordStack;
    queue<char> secondWordQueue;

    //If we're given an empty string, no point in continuing
    if (inputString.empty()){
        cout << "Empty string is not in the Language." << endl;
        return false;
    }

    //Iterate through every character
    for(char ch : inputString){
        //If we find the hashtag, we continue
        if (ch == '#'){
            foundHash = true;
            continue;
        }

        if(!foundHash){
            //In theory, if we don't have the hashtag yet we're in the first word
            firstWordStack.push(ch);
        } else {
            //We should be in the second word here
            secondWordQueue.push(ch);
        }
    }

    //If we did not find the hash, the string is by default invalid
    if(!foundHash){
        cout << "string is missing #." << endl;
        return false;
    }

    // "#" is a valid sentence, so as long as we have both stack and queue empty and we found the hash, sentence is valid
    if(firstWordStack.empty() && secondWordQueue.empty()){
        return true;
    }

    // If the queue and stack are of unequal size, that means our words on both sides were not the same, and therefore aren't palindromes
    if(firstWordStack.size() != secondWordQueue.size()){
        return false;
    }

    //If we're here, we have a stack and queue of equal size, so check if they're palindromes
    while(!firstWordStack.empty()) {
        if(firstWordStack.top() != secondWordQueue.front()){
            return false;
        }

        firstWordStack.pop();
        secondWordQueue.pop();
    }

    //If we get here, everything worked so
    return true;
}
