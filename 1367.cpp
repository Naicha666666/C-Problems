#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const double k = 0.99;
const double st = 100000;
const double et = 1e-9;
const int L = 100;
int n;
double x[10000], y[10000];
double getAns(double nx, double ny) {
    double dis = 0;
    for (int i = 1; i <= n; i++) {
        dis += sqrt(pow(nx - x[i], 2) + pow(ny - y[i], 2));
    }
    return dis;
}

double sa() {
    double t = st;
    double x = 0, Y = 0;
    double e = getAns(x, Y);
    double ans = e;
    while (t > et) {
        for (int i = 1; i <= L; i++) {
            double nx = x + (rand() * 2 - RAND_MAX) * t;
            double ny = Y + (rand() * 2 - RAND_MAX) * t;
            double ne = getAns(nx, ny);
            double de = ne - e;
            if (de < 0 || exp(-de / t) > rand() / RAND_MAX) {
                x = nx;
                Y = ny;
                e = ne;
            }
            ans = min(ans, e);
        }
        t *= k;
    }
    return ans;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }
    printf("%.0lf\n", sa());
    return 0;
}
