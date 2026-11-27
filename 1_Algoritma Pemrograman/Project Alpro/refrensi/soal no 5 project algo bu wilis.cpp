#include <iostream>
using namespace std;

void banyakPecahan(long uang, long pecahan[], int lembar[]);
	long uang,pecahan[9] = {50000,20000,10000,5000,2000,1000,500,200,100};
	int lembar[9];
	
int main() { 

	cout << "Jumlah Uang Kembali : Rp "; 
	cin >> uang;
	cout << "Pecahan uang kembali: " << endl;
	
	banyakPecahan(uang,pecahan,lembar);
	
	for(int i=0;i<9;i++){
		cout<<lembar[i]<<" lembar "<<pecahan[i]<<endl;
	}
}

void banyakPecahan(long uang, long pecahan[], int lembar[]) {
 for(int i=0 ;i<9;i++){
		if(uang>=pecahan[i]){
		  lembar[i]=uang/pecahan[i];
		  uang=uang-lembar[i]*pecahan[i];
		}
	}

}
