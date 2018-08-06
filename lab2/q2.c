#include<stdio.h>

int powerNum(int num,int p){
	if(p==1) return num;
	else{
		int x=powerNum(num,p/2);
		if(p%2==0)
			return x*x;
		else return num*x*x;
	}
}

main(){
	int num,p;
	printf("\nenter the number and its power");
	scanf("%d %d",&num,&p);
	int x=powerNum(num,p);
	printf("\nanswer is %d\n",x);

}	
