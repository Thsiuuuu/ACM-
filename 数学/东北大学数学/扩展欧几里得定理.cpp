#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

void exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (b == 0) {
        d = a;
        x = 1;
        y = 0;
    } else {
        exgcd(b, a % b, d, y, x);
        y -= (a / b) * x;
    }
}

int main() {
    ll a, b;
    cin >> a >> b;
    ll d, x0, y0;
    exgcd(a, b, d, x0, y0);
    ll a_prime = a / d;
    ll b_prime = b / d;
    ll min_sum = 1e18;
    ll best_x, best_y;
    for (ll t = -100; t <= 100; t++) {
        ll x = x0 + b_prime * t;
        ll y = y0 - a_prime * t;
        ll sum = abs(x) + abs(y);
        if (x <= y && sum < min_sum) {
            min_sum = sum;
            best_x = x;
            best_y = y;
        }
    }
    cout << best_x << " " << best_y << endl;
    return 0;
}