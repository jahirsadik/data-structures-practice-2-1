#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double dd;

dd nThPower(dd p, int n){
  double i=1;
  while(n--) i*=p;
  return i;
}

dd nThRoot(dd p, int n){
  dd low = 0.0, high = p, mid;
  int hagu = 30;
  if(p>=0 && p<=1){
    low = p;
    high = 1.00;
  }

  while(hagu--){
    mid = (high+low)/2.0;
    if( p > nThPower(mid, n)) low = mid;
    else high = mid;

  }
  cout << fixed << setprecision(16)  << mid << endl;
  return mid;
}


int main(){
  dd n;
  cout << nThRoot(21.0, 2) << endl;
  return 0;
}







// //
// // C++ Program to find
// // n-th real root of x
// #include<bits/stdc++.h>
// using namespace std;
//
// void findNthRoot(double x, int n)
// {
//
// double low, high;
// if (x >= 0 and x <= 1)
// {
// 	low = x;
// 	high = 1;
// }
// else
// {
// 	low = 1;
// 	high = x;
// }
//
// double epsilon = 0.00000001;
// double guess = (low + high) / 2;
// while (abs((pow(guess, n)) - x) >= epsilon)
// {
// 	if (pow(guess, n) > x)
// 	{
// 		high = guess ;
// 	}
// 	else
// 	{
// 		low = guess ;
// 	}
// 	guess = (low + high) / 2;
// }
//
// cout << fixed << setprecision(16)
// 	<< guess;
// }
//
// // Driver code
// int main()
// {
// 	double x = 5;
// 	int n = 2;
// 	findNthRoot(x, n) ;
// }
// // by Subhadeep
