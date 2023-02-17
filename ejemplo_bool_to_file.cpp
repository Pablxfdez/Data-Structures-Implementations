#include<vector>
#include<iostream>
#include<string>
#include<fstream>
#include<limits.h>
#include<random>

using namespace std;

void vector_bool_to_file(vector<bool> v, string file_name){
    ofstream f = ofstream(file_name);
    long num_bits = v.size();
    unsigned char c;
    long inic;
    f << num_bits<<endl;
    for(int i = 0;i< num_bits/CHAR_BIT; i++){
        c = 0;
        inic = i*CHAR_BIT;
        for(int j = CHAR_BIT-1;j>=0;j--){ 
           c = c*2+v[inic+j];
        }
        f<<c;
    }
    c = 0;
    inic = (num_bits/CHAR_BIT)*CHAR_BIT;
    for(int j = num_bits%CHAR_BIT-1;j>=0;j--){
        c = c *2 + v[inic + j];
    }
    f << c;
    f.close();
}

vector<bool> file_to_vector_bool(string file_name){
    long num_bits;
    vector<bool> result;
    ifstream f = ifstream(file_name);
    f >> num_bits;
    unsigned char c;
    string s;
    getline(f,s); 
    long pos = 0;
    for(long i =0; i<num_bits/CHAR_BIT; i++){
         c = f.get();
         for(long j = 0 ; j<CHAR_BIT;j++){
              result.push_back(c % 2);
              c = c/2;
              pos++;
         }
    }
    c = f.get();
    for(long j = num_bits%CHAR_BIT-1;j>=0;j--){
        result.push_back(c % 2);
        c = c/2;
    }
    f.close();
    return result; 
}


int main(){
    cout << "bits por char:" << CHAR_BIT << endl; //comprobamos el número de bits en un unsigned char   
    cout << "maximo int:"<<INT_MAX<<endl;  
    vector<bool> b;
    for(int i = 0; i<100000; i++){
        b.push_back(rand()%2);
    }
    cout <<b.size()<<endl;
    vector_bool_to_file(b,"prueba.txt");
    vector<bool> s = file_to_vector_bool("prueba.txt");
    for(int i =0; i< s.size(); i++){
        cout << s[i]<<":";
    }
    cout<<endl;
    for(int i =0; i< b.size(); i++){
        cout << b[i]<<":";
    }
    cout<<endl;
    return 0;
}  
