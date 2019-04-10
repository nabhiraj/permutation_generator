#include<iostream>
#include<stdlib.h>
using namespace std;


//---------------------------------------------  permutation api ------------------------------------------------------------------------------
//-----------------------------------------------------<start>-----------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------
void char_arr_print(char* a,int n){
    int i;
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void setup_routine(char* a,int n,int k){
    //a=new char[n];
    int i;
    for(i=0;i<n;i++){
        a[i]='0';
    }
    for(i=n-1;i>=n-k;i--){
        a[i]='1';
    }
    char_arr_print(a,n);
    //first permutaion is generated.
}
char* next_permutaion(char* data,int n,int k){//n is the length of the array and k is the number of one there should be.
    if(k==n){
        cout<<"no more permutaion are possible\n";
        return NULL;
    }
    int temp_k=k;
    do{
        int i;
        for(i=n-1;i>=0;i--){
            if(data[i]=='0'){
                int j;
                data[i]='1';
                temp_k++;
                for(j=i+1;j<n;j++){
                    data[j]='0';
                    temp_k--;
                }
                if(temp_k==n){
                   //cout<<"is it breaking from here\n";
                    return NULL;
                }
                break;
            }
        }
    }while(temp_k!=k);
    return data;
}
//------------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------ END--------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------------
int main(){
    //cout<<"lets test the things out"<<endl;
    int n=10;
    char* a=new char[n];
    int k=7;
    setup_routine(a,n,k);
    while(next_permutaion(a,n,k)){
        char_arr_print(a,n);
    }

    return 0;
}