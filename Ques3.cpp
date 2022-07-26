#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char src, char dest, char helper)
{
    if(n == 0) 
    {
        return;
    }
    
    //first we will transfer n-1 disks from source tower to helper
    towerOfHanoi(n-1, src, helper, dest);
    cout << "Move from " << src << " to " << dest << endl;
    towerOfHanoi(n-1, helper, dest, src);

}

int main()
{
    int n;
    cout << "enter the no. of disks: ";
    cin >> n;

    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}