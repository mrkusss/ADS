/*
               KMP (Knuth-Morris-Pratt) algorithm is an efficient string-matching algorithm
                 that searches for a pattern in a text by avoiding redundant comparisons.
 It uses a prefix table (also called the LPS array) to determine how much to shift the pattern when a mismatch occurs.
        KMP is widely used in text editors, search engines, and bioinformatics for fast pattern matching.
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> lps;
vector<int> occurences;

void compute_lps_array(string pattern){

    lps.emplace_back(0);

    int c = 0;

    for (int i = 1; i < pattern.length() ; ++i){
        if(pattern[c] == pattern[i]){
            c = c+ 1;
        } else if (pattern[i] == pattern[0]){
          c = 1;
        }
        else{
            c = 0;
        }
        lps.emplace_back(c);
    }
}

void kmp(string text, string pattern){
    compute_lps_array(pattern);
    int i = 0;
    int j = 0;
    while (i < text.length()){
        if (pattern[j] == text[i]){
            i += 1;
            j += 1;

            if (j == pattern.length()){
                occurences.emplace_back((i - j));
                j = lps[j - 1];
            }
        }
        else {
            if (j != 0){
                j = lps[j - 1];
            }
            else{
              i += 1;
            }
        }
    }
}

int main(){
    kmp("ABABA", "ABA");
    cout << "Pattern  \"ABA\" " << "found at indices: [ ";
    for(auto elt: occurences){
        cout << elt << " ";
    }
    cout << "]";
    cout << " in the text " << "\"ABABA\"";
}