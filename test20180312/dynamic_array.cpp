//
// Created by lugt on 2018/3/19.
//
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>
#include <cstring>

using std::cin;
using std::cerr;
using std::cout;
using std::string;
using std::endl;

void countSort(int *nums, int count);
void reverse_array(int *pointer, int n);

int mai2n(){

    int now_row, t, col;
    int local_max, local_min = 0;
    unsigned int rows = 0,n = 0;
    int **pInt_ptr;
    cin>>t;
    while(t--){
        rows = 1;
        n = 3;
        pInt_ptr = new int *[rows];
        for(now_row=0;now_row<rows;now_row++){
            *(pInt_ptr+now_row) = new int[n];
            int *line = *(pInt_ptr+now_row);
            for (col = 0; col < n; ++col) {
                cin >> line[col];
                if(col == 0 && now_row == 0) local_max = local_min = line[col];
                if(line[col] > local_max){
                    local_max = line[col];
                }
                if(line[col] < local_min) {
                    local_min = line[col];
                }
            }
            countSort(line, n);
            reverse_array(line, n);
            cout << line[0] << " " << line[1] << " " << line[2] << endl;
        }
        // cout << local_min << " " << local_max << endl;

    }
}

void countSort(int *nums, int count) {
    int max = nums[0];
    for (int i = 0; i < count; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    int *buckets = static_cast<int *>(malloc(sizeof(int) * (max + 1)));
    memset(buckets, 0, static_cast<size_t>((max + 1) * sizeof(int) ));
    for (int i = 0; i < count; i++) {
        buckets[nums[i]] += 1;
    }
    for (int i = 0, k = 0; i < max + 1; i++) {
        while (buckets[i]) {
            nums[k++] = i;
            buckets[i]--;
        }
    }
}

void reverse_array(int *pointer, int n)
{
    int *s, c, d;

    s = (int*)malloc(sizeof(int)*n);

    if( s == NULL )
        exit(EXIT_FAILURE);

    for ( c = n - 1, d = 0 ; c >= 0 ; c--, d++ )
        *(s+d) = *(pointer+c);

    for ( c = 0 ; c < n ; c++ )
        *(pointer+c) = *(s+c);

    free(s);
}