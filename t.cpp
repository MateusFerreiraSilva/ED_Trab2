#include<bits/stdc++.h>
using namespace std;

int similar_color(unsigned char a, unsigned char b, int x) {
    if(a == b) return true;
    
    unsigned char min, max;
    if(a < b) {
        min = a;
        max = b;
    } else {
        min = b;
        max = a;
    } // else
    int aux = max - min;

    if(aux >= 0 && aux <= x)
        return true;

    return false;

} // similar_color

int main() {
    if(similar_color(100, 131, 30))
        cout << "Yes\n";
    else cout << "No\n";

}