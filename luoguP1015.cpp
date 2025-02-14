#include <bits/stdc++.h>
using namespace std;
int n, q[1000001], l, w[1000001], ans;//q是高精数组，w是q反转后的数组，l是高精度数的长度，n是进制，ans是所需的步数, s是输入高精度的字符串。
string s;
void add(int a[],int b[])
{
    for(int i = 1; i <= l; i++)
	{
		a[i] += b[i];
		a[i + 1] += a[i] / n;//进位 
		a[i] %= n;
	}
	if(a[l + 1] > 0)//考虑从最高位进位到最高位的下一位 
	{
		l++;//长度++ 
	}
}

void reverse(int a[])
{
    int j = 0;
    for(int i = l;i >= 1;i --)
    {
        w[++j] = a[i];
    }
}

bool f(int a[])
{
    int ln = l;
    int i = 1;
    int j = l;
    while (ln --)
    {
        if(ln < l/2) break;
        if(a[i] != a[j]) return false;
        i ++;
        j --;
    }
    return true;
}

void init()//把s字符串附到q数组里 
{
	int j = 0;
	for(int i = s.length() - 1; i >= 0 ; i--) 
	{
		if(s[i] >= '0' && s[i] <= '9')//数字 
		{
			q[++j] = s[i] - '0';
		}
		else//还有十六进制的 
		{
			q[++j] = s[i] - 'A' + 10;
		} 
	}
}

int main()
{
    cin >> n >> s;
    init(); 
	l = s.length();
	while(!f(q)) 
	{
		reverse(q);
		add(q, w);
		ans++;
		if(ans > 30)
		{
			break;
		}
	}
	if(ans > 30)
	{
		printf("Impossible!");
	}
	else
	{
		printf("STEP=%d", ans);
	}
	return 0;
}