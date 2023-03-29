#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct segment{
    int start;
    int end;
};

bool cmp(segment a, segment b){
    return a.start < b.start;
}

int main(){
    int n;
    cin >> n;

    vector<segment> segments(n);
    for(int i = 0; i < n; i++){
        cin >> segments[i].start >> segments[i].end;
    }

    sort(segments.begin(), segments.end(), cmp);

    int max_end = segments[0].end;
    bool confidentiality = true;

    for(int i = 1; i < n; i++){
        if(segments[i].start <= max_end){
            max_end = max(max_end, segments[i].end);
        }else{
            confidentiality = false;
            break;
        }
    }

    if(confidentiality){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}