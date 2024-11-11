#include <bits/stdc++.h>
using namespace std;

int main()
{

    // int x = -43;
    // unsigned int y = x; // y = 2^32 - x
    // cout << x << "\n";
    // cout << y << "\n";

    // int x = INT_MAX;
    // cout << x << "\n";
    // x++;
    // cout << x << "\n"; // INT_MAX + 1 = INT_MIN

    // cout <<( 2 & 1 )<< "\n"; // x & (2^k - 1) = 0 //if x is divisible by 2^k

    // cout<< ~30 <<"\n"; //  ~x = -x - 1

    // cout << (3 << 2) << endl; // 3 * 2^2
    //  cout << (3 >> 1) << endl; // 3 / 2^1

    //finding the kth bit of a number   
    // cout<< ( 10 & (1<<3)) << "\n"; 
    // int x = 10;
    // for (int k = 31; k >= 0; k--) {
    //     if (x&(1<<k)) cout << "1";   // bit representation
    //     else cout << "0";
    // }
    // cout<<"\n";

    // int x = 10;
    // cout<< __builtin_clz(x)<<"\n";
    // cout<< __builtin_ctz(x)<<"\n";
    // cout<< __builtin_popcount(x)<<"\n";
    // cout<< __builtin_parity(x)<<"\n";



    //bits as set in cpp
    int x = 0; // x is set that can have 32 elements
    //adding elements 1, 3, 4, 8
    x =  x | (1 << 1);
    x =  x | (1 << 3);
    x =  x | (1 << 4);
    x =  x | (1 << 8);
    cout << __builtin_popcount(x) << "\n";

    //now printing all elements in the set
    for(int i=0;i<32;i++){
        if(x & (1<<i)) cout << i << " ";
    }
    cout<<"\n";


}