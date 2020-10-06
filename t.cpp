#include<bits/stdc++.h>
using namespace std;

bool do_something(vector<bool> v, int n) {
    for(int i = 0; i < n; i++) {
        if(i % 2 != 0)
            v[i] = true;
    } // for
} // do_something 

int main() {
    vector<bool> v(10);
    fill(v.begin(), v.end(), false);

    do_something(v, 10);

    for(int i = 0; i < 10; i++) {
        if(v[i])
            cout << "yep-> " << i << endl;
        else
            cout << "no-> " << i << endl;
    } // for

}