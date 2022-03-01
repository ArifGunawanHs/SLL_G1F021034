#include <iostream>
using namespace std;

    struct filim{ 
	string judul, sutradara;
	int tahun_tayang;
	
	filim *next;
};

filim *head, *tail, *cur, *newNode, *del, *after ;

void createSingleLinkedList(string judul, string sutradara, int tahun_t){
	head = new filim();
	head->judul = judul;
	head->sutradara = sutradara;
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

void deleteFirst(){
	del = head;
	head = head->next;
	delete del;
}


void deleteLast(){
	del = tail;
	cur = head;
	while(cur->next != tail){
		cur = cur->next;
	}
	tail = cur;
	tail->next = NULL;
	delete del;
}


void deleteAfter(int posisi){
	int nomor = 1;
	cur = head;
	while(nomor <= posisi){
		if(nomor == posisi -1){
			after = cur;
		}
		if(nomor == posisi){
			del = cur;
		}
		del = cur->next;
		nomor++;
	}
	after->next = cur->next->next;
	delete del;
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
	
	createSingleLinkedList("Makmum 2","Guntur Soeharjanto",2021);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertFirst("spiderman no way home ", "Jon Watts", 2019);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertLast("John Wick", "Chad Stahelski", 2014);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertAfter("Laskar Pelangi", "Riri Riza", 2008, 3);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	insertAfter("Comic 8", "Anggy Umbara", 2014, 4);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	deleteFirst();
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	deleteLast();
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	deleteAfter(3);
	printSingleLinkedList();
	cout<<"\n\n"<<endl;
	
	return 0;

}
