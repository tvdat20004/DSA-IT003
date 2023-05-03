#include<bits/stdc++.h>
#define ll long long
using namespace std;
string numStr;
void heapify(int N, int i)
{
    int largest = i, l = 2 * i + 1, r = 2 * i + 2;
    if (l < N && numStr[l] < numStr[largest])
        largest = l;
    if (r < N && numStr[r] < numStr[largest])
        largest = r;
    if (largest != i) {
        swap(numStr[i], numStr[largest]);
        heapify(N, largest);
    }
}
void heapSort(int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(N, i);
    for (int i = N - 1; i > 0; i--) {
        swap(numStr[0], numStr[i]);
        heapify(i, 0);
    }
}
int main()
{
	cin>>numStr;
	// sắp xếp chuỗi số giảm dần
	heapSort(numStr.length());
	//tính tổng các chữ số 
	ll sumOfDigits = 0;
	for (int i = 0; i < numStr.length(); ++i)
	{
		sumOfDigits += numStr[i] - '0';
	}

	if (sumOfDigits % 3 != 0)
	{
		int d = sumOfDigits % 3;
		//tìm vị trí chữ số đầu tiên khác 0 
		int idx;
		for (int i = numStr.length() - 1; i >= 0; --i)
		{
			if(numStr[i] != '0')
			{
				idx = i;
				break;
			}
		}
		//tìm vị trí của chữ số có trọng số nhỏ nhất có cùng số dư với số ban đầu khi chia cho 3
		int pos = -1;
		for (int i = idx; i >= 0; --i)
		{
			if ((numStr[i] - '0') % 3 == d) 
			{
				pos = i;
				break;
			}
		}
		if (pos != -1) numStr.erase(pos,1);//nếu có số có cùng số dư với số ban đầu khi chia cho 3, xóa số ở vị trí pos
		//nếu không có số có cùng số dư với số ban đầu khi chia cho 3, xóa các chữ số không chia hết cho 3 theo thứ 
		//tự trọng số tăng dần cho đến khi số đó chia hết cho 3 thì thôi.
		else 
		{
			while (sumOfDigits % 3 != 0)
			{
				if (numStr[idx] % 3 != 0)
				{
					sumOfDigits -= numStr[idx] - '0';
					numStr.erase(idx,1);
				}
				idx--;
			}

		}
	}
	cout<<numStr;
	return 0;
}