#include<cstdio>
using namespace std;
int i,find,k,m,begin;
int check(int remain)
{
    int result=(begin+m-1)%remain;
    if(result>=k){
        begin=result;
        return 1;
    }
    else{return 0;}
}
int main(){
    scanf("%ld",&k);
    m=k;
    while(!find)
     {
        find=1;begin=0;
        for(i=0;i<k;i++)
        {
            if(!check(2*k-i))
            {
                find=0;break;
            }
        }
        m++;
    }
    printf("%d",m-1);
    return 0;
}