#include <iostream>
#include <vector>
using namespace std;

vector<int> occurences;

void brute_force(string text, string pattern){

    for(int i = 0 ; i < text.length() ; ++i){
        for(int j = 0 ; j < pattern.length() ; ++j){
           bool match = text[i+j] == pattern[j];
           if (!match) break;
           if (j == pattern.length() - 1 ){
               occurences.emplace_back(i);
           }
        }
    }
}

int main(){
    string text = "CODEWITHCODER";
    string pattern = "CODE";
    brute_force(text, pattern);

    for(const auto elt: occurences){
        std::cout  << "Sub string "<< pattern
        <<  " found from index: " << elt << " to " << elt + 5 << '\n';
    }
}