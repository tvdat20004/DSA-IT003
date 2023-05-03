/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//###INSERT CODE HERE -
void merge(int *a,int n,int *b, int m, int *c)
{
    int index_a = 0, index_b = 0, index_c = 0;
    while (index_b < m && index_a < n) 
    {
        if(a[index_a] < b[index_b]) 
        {
            c[index_c] = a[index_a];
            index_a++;
        }
        else 
        {
            c[index_c] = b[index_b];
            index_b++;
        }
        index_c++;
    }
    while (index_a < n)
    {
        c[index_c] = a[index_a];
        index_a++;
        index_c++;
    }
    while (index_b < m)
    {
        c[index_c] = b[index_b];
        index_c++;
        index_b++;
    }
}

int main (){
    cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, m;
    int t; cin >> t;
    while (cin >> n >> m || t > 0){ 
        t--;
        int *a = new int [n], *b = new int[m], *c = new int[n+m];
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];

	merge(a, n, b, m, c);
	int nc = n + m;;
        for(int i = 0; i < nc; i++){
            cout << c[i] << " ";
        }
        delete c;
        cout << endl;
    }
}
