#include <iostream>
using namespace std;
float hitungjumlah(int nilai[]);
float hitungrata(float total);
int main() {
  int nilai[10]={2,5,1,2,4,6,3,2,7,1};
  float total;
  float rata;
  
  for(int i=0;i<10;i++){
	  cout<<"Nilai ke-"<<i+1<<" = "<<nilai[i]<<endl;
	}
  total=hitungjumlah(nilai);
  rata=hitungrata(total);
  cout<<"Jumlah nilai yang <5 atau >=7 adalah "<<total<<endl;
  cout<<"Rata-rata nilai diatas adalah "<<rata<<endl;
    return 0;
}

float hitungjumlah(int nilai[]){
	float total;
	for(int i=0;i<10;i++){
		if(nilai[i]<5 || nilai[i]>=7){
			total= total+nilai[i];
		}
	}
	return total;
}

float hitungrata(float total){
	float rata;
	rata = total/8;
	return rata;
	}

