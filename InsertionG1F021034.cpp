#include <iostream>
using namespace std;

struct filim{
	string judul, sutradara;
	int tahun_tayang;
	
	filim *next;
};

filim *head, *tail, *cur, *newNode;


void createSingleLinkedList(string judul, string sutradara, int tahun_t){
	head = new filim();
	head->judul = judul;
	head->sutradara= sutradara;
	head->tahun_tayang = tahun_t;
	head->next = NULL;
	tail = head;
}


void insertFirst(string judul, string sutradara, int tahun_t){
	newNode = new filim();
	newNode->judul = judul;
	newNode->sutradara = sutradara;
	newNode->tahun_tayang = tahun_t;
	newNode->next = head;
	head = newNode;
}


void insertLast(string judul, string sutradara, int tahun_t){
	newNode = new filim();
	newNode->judul = judul;
	newNode->sutradara = sutradara;
	newNode->tahun_tayang = tahun_t;
	newNode->next = NULL;
	tail->next = newNode;
	tail = newNode;
}


void insertAfter(string judul, string sutradara, int tahun_t, int posisi){
	newNode = new filim();
	newNode->judul = judul;
	newNode->sutradara = sutradara;
	newNode->tahun_tayang = tahun_t;
	
	cur = head;
	int nomor = 1;
	while(nomor < posisi -1){
		cur =  cur->next;
		nomor++;
	}
	
	newNode->next = cur->next;
	cur->next = newNode;

}


void printSingleLinkedList(){
	cur = head;
	while(cur != NULL){
		cout<<"judul filim : "<<cur->judul<<endl;
		cout<<"sutradara filim : "<<cur->sutradara<<endl;
		cout<<"tahun tayang filim : "<<cur->tahun_tayang<<endl;
		
		cur = cur->next;
	}
}

int main(){
	
	createSingleLinkedList("Makmum 2","Makmum 2",2021);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertFirst("spiderman no way home", "Jon Watts", 2019);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertLast("John Wick", "Chad Stahelski", 2014);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertAfter("Laskar Pelang", "Riri Riza", 2008, 3);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	return 0;
}
