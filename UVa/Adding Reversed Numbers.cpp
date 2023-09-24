// UVa 713 - Adding Reversed Numbers

#include <bits/stdc++.h>

using namespace std;

string doSum(string a, string b)
{
    if(a.size() < b.size())
        swap(a, b);

    int j = a.size()-1;
    for(int i=b.size()-1; i>=0; i--, j--)
        a[j]+=(b[i]-'0');

    for(int i=a.size()-1; i>0; i--)
    {
        if(a[i] > '9')
        {
            int d = a[i]-'0';
            a[i-1] = ((a[i-1]-'0') + d/10) + '0';
            a[i] = (d%10)+'0';
        }
    }
    if(a[0] > '9')
    {
        string k;
        k+=a[0];
        a[0] = ((a[0]-'0')%10)+'0';
        k[0] = ((k[0]-'0')/10)+'0';
        a = k+a;
    }
    return a;
}

int main(){

    int n, d, ns, idx;
    string n1, n2, n3;
    char tmp;

    scanf("%d", &n);
    while (n--) {

        cin >> n1 >> n2;

        d = n1.size() - n2.size();
        while (d != 0) {
            if (d > 0) n2.append("0");
            else n1.append("0");
            d = n1.size() - n2.size();
        }

        ns = n1.size();
        for (int i=0; i<ns/2; i++) {
            tmp = n1[i];
            n1[i] = n1[ns - (i+1)];
            n1[ns - (i+1)] = tmp;

            tmp = n2[i];
            n2[i] = n2[ns - (i+1)];
            n2[ns - (i+1)] = tmp;
        }

        n3 = doSum(n1, n2);
        ns = n3.size();
        for (int i=0; i<ns/2; i++) {
            tmp = n3[i];
            n3[i] = n3[ns - (i+1)];
            n3[ns - (i+1)] = tmp;
        }

        idx = 0;
        while (n3[idx] == '0') idx++;
        for(int i=idx; i<ns; i++) printf("%c", n3[i]);
        printf("\n");
    }


    return 0;
}