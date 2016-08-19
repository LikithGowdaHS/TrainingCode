#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;

bool isRedundent(string reference, char value){
    int lenght = reference.length();
    for(int i=0;i<lenght;i++){
        if(reference[i] == value){
            return true;
        }
    }
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    std::string source;
    std::getline (std::cin,source);
    std::string reference;

    int sourceLength = source.length();
    for(int i=0; i<sourceLength; i++){
        if(isalpha(source[i])){
            char c = source[i];
            if(isupper(c)){
                c = c+32;
            }
            if(!(isRedundent(reference,c))){
                reference.append(1,c);
            }
        }
    }
    
    const int alphaCount=26;
    if(reference.length()==alphaCount){
        cout << "pangram" << endl;
    }
    else{
        cout << "not pangram" << endl;
    }
    
    return 0;
}
