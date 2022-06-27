#include<iostream>
using namespace std;

void tower(int n, char from, char to, char aux){
    if(n==0)    return;
    tower(n-1, from, aux, to);
    cout<<n<<from<<to<<endl;
    tower(n-1, aux, to, from);
}

int main(){
    int n=3;
    tower(n, 'A', 'C', 'B');
}
