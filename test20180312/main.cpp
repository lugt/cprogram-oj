#include <iostream>
#include <cstring>
#include <vector>
#include <array>
#include <algorithm>

char ensure_alpha(int i);

char extract_alpha(const char mychar);

char extract_base(const char i);

using namespace std;

int main_old(void)
{
    int i, t;
    cin>>t;

    int **p = new int *[100];

    for(i=0;i<100;i++){
        *(p+i) = new int[i+1];
    }

    for(i=0;i<100;i++){
        for(int j=0;j<i;j++){
            p[i][j] = i*j;
        }
    }

    for(i=0;i<100;i++){
        for(int j=0;j<30;j++){
            cout << p[i][j];
        }
    }




    for(i=0;i<t;i++) cout << p[i];

    vector<string> stVector(t);

    for(int i=0; i<t; i++){
        cin >> stVector[i];
    }

    for(int i=0; i<t; i++){
        cout << stVector[i] << ",";
    }


    if(true) return 100;

    stVector[1] = "myWord";


    vector<int> myVector = {10,1,2,3,4,5};
    sort(myVector.begin(),myVector.end());

    //for(auto it = myVector.begin();)

    std::array<int, 100> myArray;


    string mingwen, miyao;

    while(t--)
    {
        int i;
        cin >> mingwen;
        cin >> miyao;

        for(i = 0; i < mingwen.size() ; i++)
        {
            // char 原来的取出来
            int delta = miyao[i % miyao.size()] - '0';
            char a = extract_alpha(mingwen[i]);
            char base = extract_base(mingwen[i]);
            mingwen[i] = (a + delta) % 26 + base; // a,1, b,2 z,3 : 0+1 , 1+2, 25+3// -> c
        }

        cout<<mingwen<<endl;
    }
    return 0;
}

char extract_base(const char mychar) {
    if(mychar >= 'A' && mychar <= 'Z') return 'A';
    else if(mychar >= 'a' && mychar <= 'z') return 'a';
    return 0;
}

char extract_alpha(const char mychar) {
    if(mychar >= 'A' && mychar <= 'Z') return mychar - 'A';
    else if(mychar >= 'a' && mychar <= 'z') return mychar - 'a';
    return 0;
}

char ensure_alpha(int i, int base) {
    if(i > 'z'){

    }
    return 0;
}

/*
 *
            if( *(mingwen+i)+*(miyao+i)-'0'>'Z'&&*(mingwen+i)+*(miyao+i)-'0'<'a')
            {
                *(mingwen+i)+=(*(miyao+i)-'Y'+'A'-'0');
            }
            else if( *(mingwen+i)+*(miyao+i)-'0'>'z')
            {
                *(mingwen+i)+=(*(miyao+i)-'y'+'a'-'0');
            }
            *(mingwen+i)+=*(miyao+i)-'0';
            *(miwen+i) = *(mingwen+i);
            cout<<*(miwen+i);
 */