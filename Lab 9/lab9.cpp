#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std ;

int main()
{
    FILE *f1 , *f2 ;
    f1 = fopen("input.txt","w") ;
    vector<int> v ;
    char c ;
    int count = 1 ;
    while(1)
    {
        c = getchar() ;
        if(c=='$')
        {
            v.push_back(count-1) ;
            count = 0 ;
        }
        else if(c=='\n')
        {
            v.push_back(count) ;
            break ;
        }
        else if(c==' ')
        {
            fprintf(f1,"%c",c) ;
            count++ ;
        }
        else
            fprintf(f1,"%c",c) ;
    }
    fclose(f1) ;

    int total_num = 0 ;
    for(int i=0 ; i<v.size() ; i++)
        total_num += v[i] ;

    f2 = fopen("input.txt","r") ;
    int ans[total_num] , k=0 ;
    for(int i=0 ; i<v.size() ; i++)
    {
        for(int j=0 ; j<v[i] ; j++)
        {
            int t ;
            fscanf(f2,"%d",&t) ;
            ans[k] =  t ;
            k++ ;
        }
    }
    fclose(f2) ;

    sort(ans,ans+total_num) ;
    for(int i=0 ; i<total_num ; i++)
        cout << ans[i] << " " ;
    return 0 ;
}
