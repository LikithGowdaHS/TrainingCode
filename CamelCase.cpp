#include <string>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;


int main(){
    string s;
    cin >> s;
    
    int wordCount = 1;
    
    int stringLength = s.length();
    for(int i=0 ; i<stringLength; i++){
        if(isupper(s[i])){
            wordCount++;
        }
    }
    cout << wordCount;
    
    return 0;
}
