#include<iostream>
using namespace std;

int main(){
	int angka[] = {2,3,5,7,11,13,17,19,23,29,31,37};
	int length = sizeof(angka)/sizeof(*angka);
	int cari, hasil_cari;
	
	cout<<"Data Yang Tersedia : "<<endl;
	
	for(int i=0; i<length; i++){
		cout<<"Baris Ke-"<<i<<" : "<<angka[i]<<endl;
	}
	
	cout<<"\nData Yang Dicari : ";
	cin>>cari;
	
	for(int j=0; j<length; j++){
		if(cari==angka[j]){
			hasil_cari++;
		}
	}
	
	if(hasil_cari==0){
		cout<<"Data Tidak Ditemukan"<<endl;
	}else{
		cout<<"Data "<<cari<<" ditemukan di : "<<endl;
		for(int k=0; k<length; k++){
			if(cari == angka[k]){
				cout<<"Baris Ke-"<<k<<endl;
			}
		}
	}
	
	return 0;
}
