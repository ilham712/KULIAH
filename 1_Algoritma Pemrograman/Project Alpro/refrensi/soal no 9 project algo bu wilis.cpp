#include <iostream>
using namespace std;
#define PHI 3.14

float luaspersegi(float s);
float luaspersegipanjang(float p,float l);
float luassegitigaa(float a,float t);
float luaslingkaran(float r);
float luasjajargenjang(float a, float t);
float luasbelahketupat(float d1, float d2);
float luaslayang(float d1, float d2);
float luastrapesium(float a1, float a2, float t);

float volumekubus(float s);
float volumebalok(float p,float l, float t);
float volumetabung(float r, float t);
float volumebola(float r);
float volumekerucut(float r, float t);
float volumelimassegitiga(float luassegitiga, float t);
float volumelimassegiempat(float p, float l, float t);
float volumeprismasegitiga(float luassegitiga, float t);

int main(){
	string nama;
	int nim;
	
	float Luas, Volume;
	float s;
	float p, l;
	float a, t;
	float r;
	float d1, d2;
	float a1, a2;
	float luassegitiga;
	
	string ulang;

	cout<<"Nama = ";
	getline(cin,nama);
	cout<<"Nim = ";
	cin>>nim;
	system("cls");
do{
	int pilih;
	do{
		cout<<"Nama = "<<nama<<endl;
		cout<<"Nim = "<<nim<<endl;
		cout<<"=====SELAMAT DATANG DI PROGRAM MENGHITUNG LUAS BANGUN DATAR ATAU VOLUME BANGUN RUANG=====\n";
		cout<<"1. Luas Bangun Datar \n2.Volume Bangun Ruang\n";
		cout<<"Pilih (1/2) = ";
		cin>>pilih;
		system("cls");
		
		
			if (pilih==1){
				int pilihluas;
				do{
					cout<<"Nama = "<<nama<<endl;
					cout<<"Nim = "<<nim<<endl;
					cout<<"\n===Mengitung Luas Bangun Datar===\n"<<endl;
					cout<<"1. Persegi \n2. Persegi Panjang \n3. Segitiga \n4. Lingkaran \n5. Jajar Genjang \n6. Belah Ketupat \n7. Layang-Layang \n8. Trapesium\n"<<endl;
					cout<<"Pilih yang mau dihitung = ";
					cin>>pilihluas;
		
					if (pilihluas==1){
						cout<<"===Luas Persegi===\n";
						cout<<"Masukan panjang sisi nya = ";
						cin>>s;
					
						Luas=luaspersegi(s);
						cout<<"Luas persegi adalah "<<Luas<<endl;
					}
					else if(pilihluas==2){
						cout<<"===Luas Persegi Panjang===\n";
						cout<<"Masukan panjang nya = ";
						cin>>p;
						cout<<"Masukan lebar nya = ";
						cin>>l;
					
						Luas=luaspersegipanjang(p,l);
						cout<<"Luas persegi panjang adalah "<<Luas<<endl;
					}
					else if(pilihluas==3){
						cout<<"===Luas Segitiga===\n";
						cout<<"Masukan alas nya = ";
						cin>>a;
						cout<<"Masukan tinggi nya = ";
						cin>>t;
					
						Luas=luassegitigaa(a,t);
						cout<<"Luas segitiga adalah "<<Luas<<endl;
					}
					else if(pilihluas==4){		
						cout<<"===Luas Lingkaran===\n";
						cout<<"Masukan jari-jarinya nya = ";
						cin>>r;
				
						Luas=luaslingkaran(r);
						cout<<"Luas lingkaran adalah "<<Luas<<endl;
					}
					else if(pilihluas==5){
						cout<<"===Luas Jajar Genjang===\n";
						cout<<"Masukan alas nya = ";
						cin>>a;
						cout<<"Masukan tinggi nya = ";
						cin>>t;
					
						Luas=luasjajargenjang(a,t);
						cout<<"Luas jajar genjang adalah "<<Luas<<endl;
					}
					else if(pilihluas==6){
						cout<<"===Luas Belah Ketupat===\n";
						cout<<"Masukan diagonal ke-1 nya = ";
						cin>>d1;
						cout<<"Masukan diagonal ke-2 nya = ";
						cin>>d2;
					
						Luas=luasbelahketupat(d1,d2);
						cout<<"Luas belah ketupat adalah "<<Luas<<endl;
					}
					else if(pilihluas==7){
						cout<<"===Luas Layang-Layang===\n";
						cout<<"Masukan diagonal ke-1 nya = ";
						cin>>d1;
						cout<<"Masukan diagonal ke-2 nya = ";
						cin>>d2;
					
						Luas=luaslayang(d1,d2);
						cout<<"Luas layang-layang adalah "<<Luas<<endl;
					}
					else if(pilihluas==8){
						cout<<"===Luas Trapesium===\n";
						cout<<"Masukan sisi sejajar ke-1 nya = ";
						cin>>a1;
						cout<<"Masukan sisi sejajar ke-2 nya = ";
						cin>>a2;
						cout<<"Masukan tinggi nya = ";
						cin>>t;
					
						Luas=luastrapesium(a1,a2,t);
						cout<<"Luas trapesium adalah "<<Luas<<endl;
					}
				system("cls");
				}while (pilihluas>8);
			break;
			}
			
			
			else if(pilih==2){
				int pilihvolume;
				do{
					cout<<"Nama = "<<nama<<endl;
					cout<<"Nim = "<<nim<<endl;
					cout<<"\n===Mengitung Volume Bangun Ruang===\n"<<endl;
					cout<<"1. Kubus \n2. Balok \n3. Tabung \n4. Bola \n5. Kerucut \n6. Limas Segitiga \n7. Limas Segiempat \n8. Prisma Segitiga\n"<<endl;
					cout<<"Pilih yang mau dihitung = ";
					cin>>pilihvolume;
		
					if(pilihvolume==1){
						cout<<"===Volume Kubus===\n";
						cout<<"Masukan panjang sisi nya = ";
						cin>>s;
					
						Volume=volumekubus(s);
						cout<<"Volume kubus adalah "<<Volume<<endl;
					}
					else if(pilihvolume==2){
						cout<<"===Volume Balok===\n";
						cout<<"Masukan panjang nya = ";
						cin>>p;
						cout<<"Masukan lebar nya = ";
						cin>>l;
						cout<<"Masukan tinggi nya = ";
						cin>>t;
					
						Volume=volumebalok(p,l,t);
						cout<<"Volume balok adalah "<<Volume<<endl;
					}
					else if(pilihvolume==3){
						cout<<"===Volume Tabung===\n";
						cout<<"Masukan jari-jari nya = ";
						cin>>r;
						cout<<"Masukan tinggi nya = ";
						cin>>t;
					
						Volume=volumetabung(r,t);
						cout<<"Volume tabung adalah "<<Volume<<endl;
					}
					else if(pilihvolume==4){
						cout<<"===Volume Bola===\n";
						cout<<"Masukan jari-jarinya nya = ";
						cin>>r;
				
						Volume=volumebola(r);
						cout<<"Volume bola adalah "<<Volume<<endl;
					}
					else if(pilihvolume==5){
						cout<<"===Volume Kerucut===\n";
						cout<<"Masukan jari-jari nya = ";
						cin>>r;
						cout<<"Masukan tinggi nya = ";
						cin>>t;
					
						Volume=volumekerucut(r,t);
						cout<<"Volume kerucut adalah "<<Volume<<endl;
					}
					else if(pilihvolume==6){
						cout<<"===Volume Limas Segitiga===\n";
						cout<<"Masukan alas bangun datar segitiga nya = ";
						cin>>a;
						cout<<"Masukan tinggi bangun datar segitiga nya = ";
						cin>>t;
						luassegitiga=0.5*a*t;
					
						cout<<"Masukan tinggi Limas Segitiga = ";
						cin>>t;
					
						Volume=volumelimassegitiga(luassegitiga,t);
						cout<<"Volume limas segitiga adalah "<<Volume<<endl;
					}
					else if(pilihvolume==7){
						cout<<"===Volume Limas Segiempat===\n";
						cout<<"Masukan panjang nya = ";
						cin>>p;
						cout<<"Masukan lebar nya = ";
						cin>>l;
						cout<<"Masukan tinggi nya = ";
						cin>>t;
			
						Volume=volumelimassegiempat(p,l,t);
						cout<<"Volume limas segiempat adalah "<<Volume<<endl;
					}
					else if(pilihvolume==8){
						cout<<"===Volume Prisma Segitiga===\n";
						cout<<"Masukan alas bangun datar segitiga nya = ";
						cin>>a;
						cout<<"Masukan tinggi bangun datar segitiga nya = ";
						cin>>t;
						luassegitiga=0.5*a*t;
					
						cout<<"Masukan tinggi Prisma Segitiga = ";
						cin>>t;
					
						Volume=volumeprismasegitiga(luassegitiga,t);
						cout<<"Volume prisma segitiga adalah "<<Volume<<endl;
					}
				}while (pilihvolume>8);
				break;
			}
		system("cls");
	}while(pilih>2);
	
	cout<<"Mau ulang menghitung Luas dan Volume?? (y/t) = ";
	cin>>ulang;
	system("cls");
	if(ulang=="T" || ulang=="t"){
		cout<<"Terima kasih";
	}
}while(ulang=="Y"|| ulang=="y");
}

	
float luaspersegi(float s){
	float Luas;
	Luas=s*s;
	return Luas;
	}
float luaspersegipanjang(float p,float l){
	float Luas;
	Luas=p*l;
	return Luas;
	}
float luassegitigaa(float a,float t){
	float Luas;
	Luas=0.5*a*t;
	return Luas;
	}
float luaslingkaran(float r){
	float Luas;
	Luas=PHI*r*r;
	return Luas;
	}
float luasjajargenjang(float a, float t){
	float Luas;
	Luas=a*t;
	return Luas;
	}
float luasbelahketupat(float d1, float d2){
	float Luas;
	Luas=0.5*d1*d2;
	return Luas;
	}
float luaslayang(float d1, float d2){
	float Luas;
	Luas=0.5*d1*d2;
	return Luas;
	}
float luastrapesium(float a1, float a2, float t){
	float Luas;
	Luas=0.5*(a1+a2)*t;
	return Luas;
	}
	
//******************************************

float volumekubus(float s){
	float Volume;
	Volume=s*s*s;
	return Volume;
	}
float volumebalok(float p,float l, float t){
	float Volume;
	Volume=p*l*t;
	return Volume;
	}
float volumetabung(float r, float t){
	float Volume;
	Volume=PHI*r*r*t;
	return Volume;
	}
float volumebola(float r){
	float Volume;
	Volume=(4.0/3.0)*PHI*r*r*r;
	return Volume;
	}
float volumekerucut(float r, float t){
	float Volume;
	Volume=(1.0/3.0)*PHI*r*r*t;
	return Volume;
	}
float volumelimassegitiga(float luassegitiga, float t){
	float Volume;
	Volume=(1.0/3.0)*luassegitiga*t;
	return Volume;
	}
float volumelimassegiempat(float p, float l, float t){
	float Volume;
	Volume=(1.0/3.0)*p*l*t;
	return Volume;
	}
float volumeprismasegitiga(float luassegitiga, float t){
	float Volume;
	Volume=luassegitiga*t;
	return Volume;
	}

