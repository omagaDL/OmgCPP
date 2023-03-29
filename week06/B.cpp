#include <iostream>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    float grade;
};


bool compare(Student a, Student b) {
    if (a.grade == b.grade) {
        return a.name > b.name;
    }
    return a.grade < b.grade;
}

int main() {
    int n, m;
    cin >> n;
    Student students[n];
    for (int i = 0; i < n; i++) {
        cin >> students[i].name >> students[i].grade;
    }
    cin >> m;

    sort(students, students + n, compare);
    for (int i = 0; i < n; i++) {
        if (students[i].grade >= m) {
            cout << students[i].name << ' ';
        }
    }
    cout << endl;
    return 0;
}