#include <iostream>
using namespace std;

struct Time {
    int hour;
    int minute;
    int second;
};

int main() {
    Time current_time, end_time;
    cin >> current_time.hour >> current_time.minute >> current_time.second;
    cin >> end_time.hour >> end_time.minute >> end_time.second;

    int time_left = end_time.second + current_time.second;
    if (time_left > 60) {
        time_left -= 60;
        current_time.minute++;
    }

    time_left += (end_time.minute + current_time.minute) * 60;
    if (time_left > 3600) {
        time_left -= 3600;
        current_time.hour++;
    }

    current_time.hour += end_time.hour;
    if (current_time.hour >= 24){
        current_time.hour -= 24;
    }
    current_time.minute += (time_left / 60);
    current_time.second += (time_left % 60);
    cout << current_time.hour << ":" << current_time.minute << ":" << current_time.second << endl;

    return 0;
}