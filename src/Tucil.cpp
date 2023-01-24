#include <iostream>
#include <vector>
#include <chrono>
#include <string.h>
#include <fstream>

using namespace std;

string simbolOperasi (int pilihan){
    string operasi;
    if (pilihan == 0){
        operasi = "+";
    }
    else if (pilihan == 1){
        operasi = "-";
    }
    else if (pilihan == 2){
        operasi=  "*";
    }
    else if (pilihan == 3){
        operasi =  "/";
    }
    return operasi;
}

double operasi(double angka1, double angka2, int pilihan){
    double hasil;
    if(pilihan==0){
        hasil = angka1+angka2;
    }
    else if (pilihan ==1){
        hasil = angka1-angka2;
    }
    else if(pilihan==2){
        hasil= angka1*angka2;
    }
    else if(pilihan==3){
        if (angka2 != 0){
            hasil = angka1/angka2;
        }
    }
    return hasil;
}

double stringtoint(string kata){
    if (kata =="A"){
        return 1;
    }
    else if (kata =="J"){
        return 11;
    }
    else if (kata =="Q"){
        return 12;
    }
    else if (kata =="K"){
        return 13;
    }
    else {
        return stoi(kata);
    }
}

vector<string> algo(double pertama, double kedua, double ketiga, double keempat, vector<string> arr) {

    // Output solusi
    int n = 0;

    string satu = to_string(int(pertama));
    string dua = to_string(int(kedua));
    string tiga = to_string(int(ketiga));
    string empat = to_string(int(keempat));
    //((a b)c)d
    for (int i =0;i<4;i++){
        for (int j=0;j<4;j++){
            for(int l = 0;l<4;l++){
                double hasil = pertama;
                hasil = operasi(hasil,kedua,i);
                hasil = operasi(hasil,ketiga,j);
                hasil = operasi(hasil,keempat,l);

                if (hasil == 24){
                    string solusi = "((" + satu + simbolOperasi(i) + dua +")" + simbolOperasi(j) + tiga + ")"+ simbolOperasi(l) + empat;
                    arr.push_back(solusi);
                }
            }
        }
    }

    //(a (b c))d
    for (int i =0;i<4;i++){
        for (int j=0;j<4;j++){
            for(int l = 0;l<4;l++){
                double hasil = kedua;
                hasil = operasi(hasil,ketiga,j);
                hasil = operasi(pertama,hasil,i);
                hasil = operasi(hasil,keempat,l);

                if (hasil == 24){
                    string solusi = "(" + satu + simbolOperasi(i) + "(" + dua + simbolOperasi(j) + tiga + "))"+ simbolOperasi(l) + empat;
                    arr.push_back(solusi);
                }
            }
        }
    }

    //a ((b c)d)
    for (int i =0;i<4;i++){
        for (int j=0;j<4;j++){
            for(int l = 0;l<4;l++){
                double hasil = kedua;
                hasil = operasi(hasil,ketiga,j);
                hasil = operasi(hasil,keempat,l);
                hasil = operasi(pertama,hasil,i);

                if (hasil == 24){
                    string solusi = satu + simbolOperasi(i) + "((" + dua + simbolOperasi(j) + tiga + ")"+ simbolOperasi(l) + empat + ")";
                    arr.push_back(solusi);
                }
            }
        }
    }

    //a (b (c d))
    for (int i =0;i<4;i++){
        for (int j=0;j<4;j++){
            for(int l = 0;l<4;l++){
                double hasil = ketiga;
                hasil = operasi(hasil,keempat,l);
                hasil = operasi(kedua,hasil,j);
                hasil = operasi(pertama,hasil,i);


                if (hasil == 24){
                    string solusi = satu + simbolOperasi(i) + "(" + dua + simbolOperasi(j) + "(" + tiga + simbolOperasi(l) + empat + "))";
                    arr.push_back(solusi);
                }
            }
        }
    }

    //(a b) (c d)
    for (int i =0;i<4;i++){
        for (int j=0;j<4;j++){
            for(int l = 0;l<4;l++){
                double hasil = pertama;
                double hasil2 = ketiga;
                hasil = operasi(hasil,kedua,i);
                hasil2 = operasi(hasil2,keempat,l);
                hasil = operasi(hasil,hasil2,j);

                if (hasil == 24){
                    string solusi = "(" + satu + simbolOperasi(i) + dua +")" + simbolOperasi(j) + "(" + tiga + simbolOperasi(l) + empat + ")";
                    arr.push_back(solusi);
                }
            }
        }
    }
    return arr;

}

void savedata( string kartu[], int solusi, vector<string> semuasolusi){
    ofstream outdata;
    bool checker = false;
    string pilihansave;
    while (!checker){
        cout<<"Apakah anda ingin menyimpan solusi sebagai file? (y/n) : ";
        cin >> pilihansave;
        if (pilihansave == "y"){
            checker = true;
            string namafile;
            cout<< "Masukan nama file yang diinginkan (tanpa .txt): ";
            cin >> namafile;
            outdata.open("test/"+namafile+".txt");
            outdata<< "Kartu Anda adalah : ";
            for (int i = 0;i<4;i++){
                outdata<< kartu[i]<< " ";
            }
            outdata<<endl;
            outdata<<"================================================================"<<endl;
            if (solusi != 0){
                outdata<< "Terdapat solusi sebanyak : "<<solusi<<endl;
                outdata<<"Solusi: "<<endl;
                for (auto elem : semuasolusi){
                    outdata<< elem << endl;
                }
            }
            else {
                outdata<<"Tidak ada solusi"<<endl;
            }
            outdata<<"================================================================"<<endl;
            outdata.close();
            cout<<"File berhasil disimpan"<<endl;
        }
        else if (pilihansave=="n"){
            checker = true;
        }
        else {
            cout<<"Masukan salah, ulangi masukan"<<endl;
            checker = false;
        }
    }
    
}

void permutasiAngka(double a[], string kartu[]){
    clock_t start,end;
    start = clock();
    double temptemp[96];
    vector<string> v;
    bool beda;
    int jumlah = 0;
    for (int j = 0;j<4;j++){
        for (int k = 0;k<4;k++){
            for (int l = 0;l<4;l++){
                for (int m = 0;m<4;m++){
                    beda = true;
                    if ((j!=k)&& (j!=l)&&(j!=m)&&(k!=l)&&(k!=m)&&(l!=m)){
                        if (jumlah>0){
                            int n = 0;
                            while (n<jumlah){
                                if ((temptemp[n]==a[j])&&(temptemp[n+1]==a[k])&&(temptemp[n+2]==a[l])&&(temptemp[n+3]==a[m])){
                                    beda = false;
                                    n=jumlah;
                                }
                                n +=4;
                            }
                        }
                        if(beda==true){

                            v = algo(a[j],a[k],a[l],a[m],v);
                            temptemp[jumlah]=a[j];
                            jumlah+=1;
                            temptemp[jumlah] = a[k];
                            jumlah+=1;
                            temptemp[jumlah]=a[l];
                            jumlah+=1;
                            temptemp[jumlah] = a[m];
                            jumlah+=1;
                        }
                    }
                }
            }
        }
    }
    int total = size(v);
    cout<<"Total solusi ada sebanyak "<<total<<endl;
    cout<<"================================================================"<<endl;
    cout<<"Berikut adalah solusinya : "<<endl;
    for (auto elem : v){
        cout<< elem << endl;
    }
    end = clock();
    double totalwaktu = double(end-start)/double(CLOCKS_PER_SEC);
    cout<< "Total waktu adalah : "<< totalwaktu <<" detik "<<endl;
    cout<<"================================================================"<<endl;
    savedata(kartu,total,v);
}


int main (){
    // ASCII
    string ascii;
    ifstream bacafile ("src/Ascii.txt");
    while (getline(bacafile, ascii)){
        cout<<ascii<<endl;
    }
    bacafile.close();


    cout<<"                         _____"<<endl;
    cout<<"                 _____  |K  ^ |"<<endl;
    cout<<"         _____  |Q  ^ | |^ ^ ^|"<<endl;
    cout<<"  _____ |J  ^ | |^ ^ ^| |^ ^ ^| _____"<<endl;
    cout<<" |10 ^ ||^ ^ ^| |^ ^ ^| |^ ^ ^||A ^  |"<<endl;
    cout<<" |^ ^ ^||^ ^ ^| |^ ^ ^| |____K||^ ^ ^|"<<endl;
    cout<<" |^ ^ ^||^ ^ ^| |____Q|        |^ ^ ^|"<<endl;
    cout<<" |^ ^ ^||____J|                |^ ^ ^|"<<endl;
    cout<<" |___10|                       |____A|"<<endl;
    cout<<endl;

    // input
    string Kartu[4];
    double Kartuint[4];
    int salah;
    bool masukan = false;
    int input;
    bool loop = true;
    string loopconfirm;

    while (loop){
        bool cobalagi = true;
        cout<<"================================================================"<<endl;
        cout<<"Menu : "<<endl;
        cout<<"1. Input sendiri kartu yang diinginkan"<<endl;
        cout<<"2. Me-generate kartu secara otomatis"<<endl;
        cout<<"================================================================"<<endl;
        cout<<"Pilih pilihanmu (1/2) : ";
        cin>>input;
        cout<<"================================================================"<<endl;


        if (input==1){
            cout<<"Masukkan kartu berupa (A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K)" << endl;
            while (masukan == false) {
                string str;
                int j = 0;
                int k = 0;
                int totalspasi = 0;
                salah = 0;
                cout << "Masukkan kartu : ";
                getline(cin >> ws,str);
                char temp = '0';
                for (char spasi : str){
                    if (spasi ==' ' && temp!=' '){
                        totalspasi++;
                        temp =spasi;
                    }
                    else {
                        temp = spasi;
                    }
                }
                if ( totalspasi != 3){
                    masukan == false;
                }
                else {
                    while (j <4){
                        Kartu[j] = str[k];
                        j++;
                        k++;
                        while (str[k]==' '){
                            k++;
                        }
                    }
                }
                cout<<"================================================================"<<endl;
                for (int i = 0; i<4;i++){
                    if ((Kartu[i] == "A") || (Kartu[i] == "2") || (Kartu[i] == "3") || (Kartu[i] == "4") || (Kartu[i] == "5") || (Kartu[i] == "6") || (Kartu[i] == "7") || (Kartu[i] == "8") || (Kartu[i] == "9") || (Kartu[i] == "10") || (Kartu[i] == "J") || (Kartu[i] == "Q") || (Kartu[i] == "K"))
                    {
                        masukan = true;
                    }
                    else {
                        masukan = false;
                        salah +=1;
                    }
                }
                if (salah>0){
                    cout<<"Masukan tidak sesuai"<< endl;
                    masukan = false;
                }
            }
            Kartuint[0] = stringtoint(Kartu[0]);
            Kartuint[1] = stringtoint(Kartu[1]);
            Kartuint[2] = stringtoint(Kartu[2]);
            Kartuint[3] = stringtoint(Kartu[3]);
        }
        else {
            srand(time(0));
            for (int c =0;c<4;c++){
                Kartuint[c] = (rand() % 13)+1;
            }
            for (int d = 0; d<4;d++){
                if ((Kartuint[d]!=1)&&(Kartuint[d]<11)){
                    Kartu[d] = to_string(int(Kartuint[d]));
                }
                else if (Kartuint[d]==1){
                    Kartu[d] = "A";
                }
                else if (Kartuint[d]==11){
                    Kartu[d] = "J";
                }
                else if (Kartuint[d]==12){
                    Kartu[d] = "Q";
                }
                else if (Kartuint[d]==13){
                    Kartu[d] = "K";
                }
            }
        }
        cout << "Kartu anda adalah : "<<Kartu[0]<<" "<<Kartu[1]<<" "<<Kartu[2]<<" "<<Kartu[3]<<endl;
        cout<<"================================================================"<<endl;

        
        permutasiAngka(Kartuint, Kartu);

        cout<<"================================================================"<<endl;

        while (cobalagi){
            cobalagi = false;
            cout<< "Apakah anda ingin mencoba angka lain?(y/n) : ";
            cin >> loopconfirm;
            if (loopconfirm == "y"){
                loop = true;
                cobalagi = false;
            }
            else if (loopconfirm == "n"){
                loop = false;
                cobalagi = false;
                cout<<"Terima kasih sudah menggunakan program ini :) "<<endl;
            }
            else {
                cout<<"Masukan salah, ulangi masukkan "<<endl;
                cobalagi = true;
            }
        }
    }


    return 0;
}