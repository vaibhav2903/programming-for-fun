#include<stdio.h>

int diff,num_func,variables;
double a[100][100],b[100][100];
int c[100];
double fn[100];
int bfs;
double max;

void locate();

void rec(int pos,int var)
{
  if(pos==diff)
    {
      locate();
      return;
    }
  int i;
  for(i=var+1;i<=variables-(diff-pos);i++)
    {
      c[pos]=i;
      rec(pos+1,i);
    }

}

void execute(int q,int w)
{
    int i,t;
    for(i=0;i<=num_func;i++)
    {
        t=b[q][i];
        b[q][i]=b[w][i];
        b[w][i]=t;
    }    
}


double calc(double g[])
{
    int i;
    double total=fn[variables];
    for(i=0;i<variables;i++)
    {
        total+=(g[i]*fn[i]);
    }    
    return total;
}  

void locate()
{
    c[diff]=variables;
    int i,t=0,j,k;
    int p[100];
    for(k=0;k<num_func;k++)
    {
        int l=0;t=0;
        for(i=0;i<=diff;i++)
        {
            for(j=t;j<c[i];j++)
            {
                 b[k][l++]=a[k][j];
                    if(k==0)
                       p[l-1]=j;
              }
           t=c[i]+1;
        }
        b[k][num_func]=a[k][variables];
    }
   
   for(i=1;i<num_func;i++)
    {
        for(j=0;j<i;j++)
        {
         double f=0.0;
         
         if(b[i][j]==0)
             continue;
           if(b[j][j]==0)
               execute(j,i);
               
         f=b[i][j]/b[j][j];
         for(k=j;k<=num_func;k++)
         {
             b[i][k]-=(f*b[j][k]);
         }
        }
    }
  
  double g[100];
  for(i=0;i<diff;i++)
    {
      g[c[i]]=0;
    }
  
  g[p[num_func-1]]=b[num_func-1][num_func]/b[num_func-1][num_func-1];
  for(i=num_func-2;i>=0;i--)
    {
      double r=0.0;
      for(j=i+1;j<num_func;j++)
    {
      r=r+b[i][j]*g[p[j]];
    }
      r=b[i][num_func]-r;
      g[p[i]]=r/b[i][i];
    }
  
    int ng=0;
  for(i=0;i<variables;i++)
    {
        if(g[i]<0||g[i]!=g[i])
           ng=1;
    printf("%lf ",g[i]);
    }
  printf("\n");
  
  if(ng==0)
  {
      bfs++;
      double y=calc(g);
      if(y>max)
          max=y;
  }    
}



int main()
{
  printf("Enter number of functions, number of variables \n");
  scanf("%d %d",&num_func,&variables);
  diff=variables-num_func;
  int i,j,k,l;
  
  printf("Enter the coefficients of equations like: x1+x2 = 10 ==> 1 1 10 \n");
  for(i=0;i<num_func;i++)
    {
      for(j=0;j<=variables;j++)
		{
			scanf("%lf",&a[i][j]);
		}
    }
	
    printf("Enter desired function coefficients similarly Z=x1+x2+3 ==> 1 1 3 \n");
    for(i=0;i<=variables;i++)
    {
        scanf("%lf",&fn[i]);
    }  
	
    bfs=0;
    max=fn[variables];
	
	for(i=0;i<=num_func;i++)
    {
      c[0]=i;
      rec(1,i);
    } 
	
    printf("Total number of Basic Feasable Solution = %d \n",bfs);
    printf("Maximum Value: %lf \n",max);
    return 0;
}