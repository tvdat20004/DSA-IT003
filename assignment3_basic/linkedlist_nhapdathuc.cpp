/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
###End banned keyword*/
#include <bits/stdc++.h>
using namespace std;


struct DONTHUC{
	int somu;
	double heso;
	
	DONTHUC(double _heso = 0,int _somu=0){
		heso = _heso;
		somu  = _somu;
	}
	
	DONTHUC& operator = (const DONTHUC &rhs){
		if (this == &rhs) return *this;
		this->heso = rhs.heso;
		this->somu = rhs.somu;
		return *this;
	}
};


struct Node{
	DONTHUC* data;
	Node* next;
	
	Node(DONTHUC* _data = nullptr){
		this->data = _data;
		this->next = nullptr;
	}
	
};

struct DATHUC{
	Node* head;
	Node* tail;
	DATHUC(){
		this->head = nullptr;
		this->tail = nullptr;
	}
};
void Nhap(DATHUC &B, double heso,int  somu){
	DONTHUC * donthuc = new DONTHUC(heso, somu);
	if(B.head == nullptr){
		B.head = new Node(donthuc);
		B.tail = B.head;
	}
	else {
		Node* tmp = new Node(donthuc);
		B.tail->next = tmp;
		B.tail = tmp;
	}
}
void Xuat(DATHUC& B) {
    Node* tmp = B.head;
    bool is_first = true;

    while (tmp != nullptr) {
        DONTHUC* dt = tmp->data;
        if (dt->heso == 0) {
        }
        else if (dt->somu == 0) {
            if (dt->heso > 0) {
                if (is_first) {
                    cout << dt->heso;
                    is_first = false;
                }
                else {
                    cout << "+" << dt->heso;
                }
            }
            else {
                cout << dt->heso;
                is_first = false;
            }
        }
        else if (dt->somu == 1) {
            if (dt->heso > 0) {
                if (is_first) {
                    cout << dt->heso << "x";
                    is_first = false;
                }
                else {
                    cout << "+" << dt->heso << "x";
                }
            }
            else {
                cout << "-" << -dt->heso << "x";
                is_first = false;
            }
        }
        else if (dt->heso == 1 && dt->somu != 1) {
            if (is_first) {
                cout << "x^" << dt->somu;
                is_first = false;
            }
            else {
                cout << "+" << "x^" << dt->somu;
            }
        }
        else if (dt->heso == -1 && dt->somu != 1) {
            if (is_first) {
                cout << "-" << "x^" << dt->somu;
                is_first = false;
            }
            else {
                cout << "-" << "x^" << dt->somu;
            }
        }
        else {
            if (dt->heso > 0) {
                if (is_first) {
                    cout << dt->heso << "x^" << dt->somu;
                    is_first = false;
                }
                else {
                    cout << "+" << dt->heso << "x^" << dt->somu;
                }
            }
            else {
                cout << "-" << -dt->heso << "x^" << dt->somu;
                is_first = false;
            }
        }
        tmp = tmp->next;
    }

    if (is_first) {
        cout << "0";
    }
}

double TinhDaThuc(DATHUC &B, double x){
	double re = 0;
	Node *tmp = B.head;
	while(tmp != nullptr){
		re += tmp->data->heso * pow(x,tmp->data->somu);
		tmp = tmp->next;
	}
	return re;
}

//###INSERT CODE HERE -

int main() {
    DATHUC B;
    int N;
    
    cin >> N;
    for (int test = 0; test < N; test++){
		double heso; int somu;
		cin >> heso >> somu;
		Nhap(B,heso,somu);
    }
    
    
    cout << "Da thuc vua nhap la: "; Xuat(B);
    double x; cin >> x;
    cout << "\nVoi x=" << x << ", gia tri da thuc la: "
         << setprecision(2) << fixed << TinhDaThuc(B, x);
    return 0;
}
