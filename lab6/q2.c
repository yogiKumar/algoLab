// students arranged according to CGPA

#include <stdio.h>

struct node
{
	
	char name[50];
	char rollno[20];
	float CGPA;
};

void swap(struct node *a, struct node *b){
	struct node temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void min_heapify(struct node data[], int n, int i){
	int smallest = i ;
	int l = 2*i + 1;
	int r = 2*i + 2;
	
	if (l < n && data[l].CGPA < data[smallest].CGPA){
		smallest = l;
	}
	
	if (r < n && data[r].CGPA < data[smallest].CGPA){
		smallest = r;
	}
	
	if (smallest != i){
		swap (&data[i], &data[smallest]);
		min_heapify (data, n, smallest); 
	}
}

void heapsort(struct node data[], int n){
	int i;
	for (i = n/2 -1 ; i >= 0 ; i--){
		min_heapify (data, n, i);
	}
	for (i = n-1 ; i >=0 ; i--){
		swap (&data[0], &data[i]);
		min_heapify (data, i, 0);
	}
	
}

int main (){
	int i,n,j;
	float arr[100];
	printf("enter the no.of students\n");
	scanf("%d", &n);
	struct node data[n];
	printf("Enter the name, roll no, CGPA\n");
	for (i=0 ; i < n ; i++){
		scanf("%s",data[i].name);
		scanf("%s", data[i].rollno);
		scanf ("%f", &data[i].CGPA);
	}	
	heapsort(data, n);
	printf("\nThe highest cg student is: ");
	printf("%s \n", data[0].name);	
	return 0;
}	
