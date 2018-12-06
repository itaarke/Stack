#include <iostream>
#include <string.h>
using namespace std;
struct Node{
    int nopunggung;
    char nama[100],posisi_pem[20];
    Node *next;
};
Node *top;
 
	class Stack{
public:
    void push(int nopunggung, char nama[], char posisi_pem[]);
    void pop();
    void displayStack();
};

	void Stack::push(int no, char nama[], char posisi_pem[]) {
    struct Node *newNoode = new Node;
    newNoode->nopunggung=no;
    strcpy(newNoode->nama,nama);
    strcpy(newNoode->posisi_pem,posisi_pem);
    newNoode->next=top;
    top=newNoode;
}

	void Stack::pop() {
    if(top==NULL){
        cout<<"Stack Kosong"<<endl;
        return;;
    }
    cout<<top->nama<<" Sudah Dihapus"<<endl;
    top=top->next;
}

	void Stack::displayStack() {
    if(top==NULL){
        cout<<"Stack Kosong tidak ada isi"<<endl;
        return;
    }
    struct Node *temp=top;
    while (temp!=NULL){
        cout<<"Nomor Punggung "<<temp->nopunggung<<endl;
        cout<<"Nama "<<temp->nama<<endl;
        cout<<"Posisi "<<temp->posisi_pem<<endl;
        temp=temp->next;
    }
}

int main() {
    Stack stack;
    int in;
    while (true){
        cout<<"---------PROGRAM TENTANG TUMPUKAN--------"<<endl;
        cout<<"1. Push (Tambah)"<<endl;
        cout<<"2. Pop (Hapus)" <<endl;
        cout<<"3. Menampilkan Stack"<<endl;
        cout<<"4. Keluarr"<<endl;
        cout<<"Masukkan Pilihan Anda: ";cin>>in;
        switch (in){
            case 1: {
                Node node;
                cout << "Data Pemain Bola" << endl;
                cout << "----------------------" << endl;
                cout << "Masukkan No Punggung Pemain : ";
                cin>>node.nopunggung;
                cout << "Masukkan Nama Pemain Bola   : ";
                cin.ignore(1);
                cin.getline(node.nama,100);
                cout << "Masukkan Posisi Pemain Bola: ";
                cin.ignore(2);
                cin.getline(node.posisi_pem,20);
                stack.push(node.nopunggung, node.nama, node.posisi_pem);
                break;
            }
            case 2:
                stack.pop();
                break;
            case 3:
                stack.displayStack();
                break;
			 case 4:
               exit (0);
            default:
                cout<<"Pilihan anda salah";
        } } }
