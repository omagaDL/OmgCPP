#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    double averageGrade;
};

int main() {
    vector<Student> students(10);

    for (int i = 0; i < 10; i++) {
       // getline(cin, students[i].name);
        cin >> students[i].name;
        cin >> students[i].averageGrade;
        cout << endl;
    }

    int thresholdGrade;
    cin >> thresholdGrade;

    for (const auto& student : students) {
        if (student.averageGrade >= thresholdGrade) {
            cout << student.name << ' ';
        } 
    }cout << endl;

    return 0;
}