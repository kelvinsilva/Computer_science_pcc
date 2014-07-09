#include <iostream>
#include <vector>
using namespace std;

int return_max(vector<int>& grades);

int main(){

    vector<int> grades;
    cout << "enter grades, type -1 to quit: \n";

    while (1){

        int grade = 0;
        cin >> grade;
        if (grade == -1){
            break;
        }
        grades.push_back(grade);

    }

    int max_grade = return_max(grades);

    int *histogram = new int[max_grade+1]();

    for (int i = 0; i < grades.size(); i++){
        histogram[grades[i]]++;
    }

    for (int i = 0; i < max_grade+1; i++){
        if (histogram[i] > 0){
            cout << "\nNumber of grade " << i << " is " << histogram[i] << "\n";
        }
    }

    delete []histogram;

    return 0;

}

int return_max(vector<int> &grades){

    int max_num = 0;
    max_num = grades[0];
    for (int i = 1; i < grades.size(); i++){
        max_num = max_num > grades[i] ? max_num : grades[i];
    }
    return max_num;
}
