#include<iostream>
#include <memory.h>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

set<string> dictionary;
ofstream out_data_short("TopWordsShort.txt");
ofstream out_data_final("FinalWords.txt");

void setDictionary() {
    ifstream inFile;
    inFile.open("dictionary.txt");
    string dicWord;
    while (inFile.good()) {
        inFile >> dicWord;
        dictionary.insert(dicWord);
    }
}

bool check(string word){
    return (dictionary.find(word) != dictionary.end());
}

bool contains(vector<string> words, const string b) {
    bool within;
    for (int i = 0; i < words.size() - 1; i++) {
        if (words[i] == b) {
            within = true;
            return within;
        }
    }
    within = false;
    return within;
}


void generate1(string word, int start, int length,int size) {
    int i;
    if (start == length) {
        string temp = word;
        int big = temp.length() - size;
        temp.erase(temp.end() - big, temp.end());
        if (check(temp)) {
            out_data_short << temp << endl;
        }
    } else {
        for (i = start; i <= length; i++) {
            swap((word[start]), (word[i]));
            generate1(word, start + 1, length,size);
            swap((word[start]), (word[i])); //backtrack
        }
    }
}

void shrink() {
    ifstream inFile;
    inFile.open("TopWordsShort.txt");
    set<string> words;
    set<string>::iterator wordsIT;
    string currentWord;
    while (inFile >> currentWord) {
        string temp = currentWord;
        if (words.find(temp) == words.end()) {
            words.insert(temp);
        }
    }
    for(wordsIT=words.begin(); wordsIT!=words.end();++wordsIT) {
        cout<<(*wordsIT)<<endl;
    }
}

int main() {
    setDictionary();
    string word;
    int size;
    cout<<"Enter the letters:"<<endl;
    cin>>word;
    cout<<"Enter the size of the wanted word:"<<endl;
    cin>>size;
    int length = word.length();
    generate1(word, 0, length - 1,size);
    cout<<"Possible words: "<<endl;
    shrink();
    cout<<""<<endl;
    cout << "DONE" << endl;
    return 0;
}