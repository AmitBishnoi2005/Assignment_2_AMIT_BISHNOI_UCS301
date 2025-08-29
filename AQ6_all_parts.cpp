#include <iostream>
using namespace std;

class Sparse {
private:
    int r[20], c[20], v[20], n=4, s;
public:
    Sparse(int sz, int e[][3]) : s(sz) {
        for(int i=0; i<s; i++) {
            r[i]=e[i][0];
            c[i]=e[i][1];
            v[i]=e[i][2];
        }
    }
    void print() {
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                int val=0;
                for(int k=0; k<s; k++)
                    if(r[k]==i && c[k]==j) {val=v[k]; break;}
                cout<<val<<" ";
            }
            cout<<endl;
        }
    }
    Sparse transpose() {
        int tr[20], tc[20], tv[20];
        for(int i=0; i<s; i++) {
            tr[i]=c[i];
            tc[i]=r[i];
            tv[i]=v[i];
        }
        int e[20][3];
        for(int i=0; i<s; i++) {
            e[i][0]=tr[i];
            e[i][1]=tc[i];
            e[i][2]=tv[i];
        }
        return Sparse(s, e);
    }
    Sparse add(Sparse &b) {
        int tr[40], tc[40], tv[40], k=0, i=0, j=0;
        while(i<s && j<b.s) {
            if(r[i]<b.r[j] || (r[i]==b.r[j] && c[i]<b.c[j])) {
                tr[k]=r[i]; tc[k]=c[i]; tv[k]=v[i]; i++;
            }
            else if(r[i]>b.r[j] || (r[i]==b.r[j] && c[i]>b.c[j])) {
                tr[k]=b.r[j]; tc[k]=b.c[j]; tv[k]=b.v[j]; j++;
            }
            else {
                tr[k]=r[i]; tc[k]=c[i]; tv[k]=v[i]+b.v[j]; i++; j++;
            }
            k++;
        }
        while(i<s) {tr[k]=r[i]; tc[k]=c[i]; tv[k]=v[i]; i++; k++;}
        while(j<b.s) {tr[k]=b.r[j]; tc[k]=b.c[j]; tv[k]=b.v[j]; j++; k++;}
        int e[40][3];
        for(int m=0; m<k; m++) {
            e[m][0]=tr[m]; e[m][1]=tc[m]; e[m][2]=tv[m];
        }
        return Sparse(k, e);
    }
    Sparse multiply(Sparse &b) {
        int tr[40], tc[40], tv[40], k=0;
        for(int i=0; i<s; i++) {
            for(int j=0; j<b.s; j++) {
                if(c[i]==b.r[j]) {
                    int row=r[i], col=b.c[j], prod=v[i]*b.v[j], f=-1;
                    for(int m=0; m<k; m++)
                        if(tr[m]==row && tc[m]==col) {f=m; break;}
                    if(f!=-1) tv[f]+=prod;
                    else {
                        tr[k]=row; tc[k]=col; tv[k]=prod; k++;
                    }
                }
            }
        }
        int e[40][3];
        for(int m=0; m<k; m++) {
            e[m][0]=tr[m]; e[m][1]=tc[m]; e[m][2]=tv[m];
        }
        return Sparse(k, e);
    }
};

int main() {
    int a[4][3]={{0,0,1},{1,2,2},{2,1,3},{3,3,4}};
    Sparse A(4,a);
    int b[4][3]={{0,1,5},{1,1,6},{2,2,7},{3,0,8}};
    Sparse B(4,b);
    cout<<"Matrix A:\n"; A.print();
    cout<<"\nMatrix B:\n"; B.print();
    cout<<"\nTranspose A:\n"; A.transpose().print();
    cout<<"\nA + B:\n"; A.add(B).print();
    cout<<"\nA * B:\n"; A.multiply(B).print();
    return 0;
}