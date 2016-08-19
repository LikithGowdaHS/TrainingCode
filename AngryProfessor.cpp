#include <iostream>
using namespace std;

bool checkingNumberOfStudents(int arrivalTime[],int numberOfStudents,int studentsLimit){
    int countStudents=0;
    for(int i=0;i<numberOfStudents;i++){
        if(arrivalTime<=0){
            countStudents++;
        }
    }
    if(countStudents==studentsLimit){
        return true;
    }
    return false;
}

int main(){
    int numberOfStudents,studentsLimit;

    cin >> numberOfStudents;
    cin >> studentsLimit;

    int arrivalTime[numberOfStudents];

    bool isConfirmed = checkingNumberOfStudents(arrivalTime, numberOfStudents, studentsLimit);

    if(isConfirmed){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}
