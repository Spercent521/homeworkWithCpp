/**
 * in int return double
 * -------------------------
 * in:1,2;2,1;2,7;4,2;15,4;
 * int:2,1;4,2;15,4;
 * return:16,2;
 * double:
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
using namespace std;

typedef struct pos{
    int line;
    int index;
}pos;

bool thisposok(int index,const string &lineNeedToFind,const string &word){
    if (index < 0 || index + word.size() > lineNeedToFind.size()) return false;
    for (size_t i = 0; i < word.size(); i++) {
        if (word[i] != lineNeedToFind[index + i])
            return false;
    }
    return true;
}

void findThisWordInFile(string &word,ifstream &input,
                        map<string,vector<pos>> &ans){
    // find a word in input , store position in ans
    int line =1;
    string lineNeedToFind;

    // reset input
    input.clear();
    input.seekg(0, ios::beg);

    while(getline(input,lineNeedToFind)){
        // find this word in this line
        int maxIndex=lineNeedToFind.size()-word.size()+1;
        for(int index=0;index<=maxIndex;++index){
            if(thisposok(index,lineNeedToFind,word)) 
                ans[word].push_back({line,index});
        }
        ++line;
    }
}

map<string,vector<pos>> findWordsInFile(const string& fileName, const vector<string>& words) {
    ifstream input(fileName);

    if(!input.is_open()){
        cerr<<"cannot open"<<endl;
        exit(-1);
    }

    map<string,vector<pos>> ans;

    for(string thisWord:words){
        findThisWordInFile(thisWord,input,ans);
    }

    return ans;
}

int main(){
    vector<string> words;
    string word;

    string inputLine;
    getline(cin, inputLine);

    // 使用istringstream分割单词
    istringstream iss(inputLine);
    while (iss >> word) {
        words.push_back(word);
    }

    map<string,vector<pos>> ans=findWordsInFile("in.c",words);

    ofstream output("found.txt");
    for(string str:words){
        output<<str<<":";

        const vector<pos> &posList=ans[str];
        
        for(const pos &tp:posList){
            output<<tp.line<<","<<(tp.index+1)<<";";
        }
        
        // if(posList.size()==0) output<<";";

        output<<endl;
    }


    return 0;
}