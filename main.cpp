#include<iostream>
#include <memory.h>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

set<string> dictionary;
set<string> finalWords;


void setDictionary() {
    ifstream inFile;
    inFile.open("dictionary.txt");
    string dicWord;
    while (inFile.good()) {
        inFile >> dicWord;
        dictionary.insert(dicWord);
    }
}

bool check(string word) {
    return (dictionary.find(word) != dictionary.end());
}



void generate1(string word, int start, int length, int size) {
    int i;
    if (start == length) {
        string temp = word;
        int big = temp.length() - size;
        temp.erase(temp.end() - big, temp.end());
        if (check(temp)) {
            finalWords.insert(temp);
        }
    } else {
        for (i = start; i <= length; i++) {
            swap((word[start]), (word[i]));
            generate1(word, start + 1, length, size);
            swap((word[start]), (word[i])); //backtrack
        }
    }
}

void print(){
    set<string>::iterator wordsIT;
    for (wordsIT = finalWords.begin(); wordsIT != finalWords.end(); ++wordsIT) {
        cout << (*wordsIT) << endl;
    }
}

int main() {
    setDictionary();
    string word;
    int size;
    cout << "Enter the letters:" << endl;
    cin >> word;
    cout << "Enter the size of the wanted word:" << endl;
    cin >> size;
    int length = word.length();
    generate1(word, 0, length - 1, size);
    cout << "Possible words: " << endl;
    print();
    cout << "" << endl;
    cout << "DONE" << endl;
    return 0;
}