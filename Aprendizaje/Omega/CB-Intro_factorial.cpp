#include <iostream>
using namespace std;

long long fib(int n){
    if(n == 0)
        return 1;
    else
        return n * fib(n-1);

}

int main(){
    int n; cin>>n;
    cout<<fib(n);
}
