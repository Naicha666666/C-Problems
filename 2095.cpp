// #include <iostream>
// using namespace std;
// int main()
// {
//   int ans;
//   ans = 0;
//   for(int i = 0; i < 4; i++){
//     ans += (9**i )
//   }
//   return 0;
// }


#include <iostream>
#include <cmath>
using namespace std;


int main(){
    string s = "2022";
    int ans = 0;
    for (int i=0; i<4; i++) {
        ans += (s[i]-'0')*pow(9,(3-i));
//        cout << i << " " << ans <<"\n";
    }
    cout << ans;
}
