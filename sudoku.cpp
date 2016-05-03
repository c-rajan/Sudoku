#include <iostream>
#include <cmath>
using namespace std;

int r[9][10];
int c[9][10];
int a[9][10];
int s[9][10];

void initialise()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			{
				if(a[i][j]!=0)
				{
					r[i][a[i][j]]=1;
					c[j][a[i][j]]=1;
					s[(i/3)*3+(j/3)][a[i][j]]=1;

				}
			}
	}
}
void display()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			cout <<a[i][j]<<" ";
		cout<<endl;

	}

}

bool isValid(int i,int j,int m)
{

	if(r[i][m]==1)
		return false;
	if(c[j][m]==1)
		return false;
	if(s[(i/3)*3+(j/3)][m]==1)
		return false;
	return true;
}

void case1(int i,int j)
{
	//cout<<"asoj"<<endl;
	if(i==8&&j==9)
		display();
	else if(j==9)
		case1(i+1,0);
	else
	{
		if(a[i][j]!=0)
			case1(i,j+1);
		else
		{
			for(int x=1;x<=9;x++)
			{
				if(!isValid(i,j,x))
					continue;
				a[i][j]=x;
				r[i][x]=1;
				c[j][x]=1;
				s[(i/3)*3+(j/3)][x]=1;

				case1(i,j+1);

				a[i][j]=0;
				r[i][x]=0;
				c[j][x]=0;
				s[(i/3)*3+(j/3)][x]=0;


			}
		}
	}

}






int main()
{
	//int n;
	//cin >> n;
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			a[i][j]=0;
	}
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<10;j++)
			r[i][j]=0;
	}
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<10;j++)
			c[i][j]=0;
	}
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<10;j++)
			s[i][j]=0;
	}

	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
			cin >>a[i][j];
	}
	initialise();
	case1(0,0);

}