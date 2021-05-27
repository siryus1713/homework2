#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>
#include "oper.h"




int get_size(char *str)
{
	int size = -1;

    if(strcmp(str,"1e4")==0)size = 10000;
    if(strcmp(str,"1e5")==0)size = 100000;
    if(strcmp(str,"1e6")==0)size = 1000000;                      
    else 
    {
        fprintf(stderr,"./a.out -d 1e4 -q 1e3 -bst -arr\n"); 
        return 0;
    }
		return size;
}

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
tn *init(int number)
{
	
	tn *temp = malloc(sizeof(tn));
	temp->right = NULL;
	temp->left = NULL;
	temp->number = number;
	return temp;
}

ll *list(int number)
{
	ll *temp = malloc(sizeof(ll));
	temp->num = number;
	temp->next = NULL;
	return temp;
}

ll *l_insert(ll *head,int num,int *arr)
{

	ll *current = head;
	int cnt = 0,tmp;
	ll *temp;
	
	while(cnt<num)
    {
        tmp=arr[cnt];

		if(head == NULL)
        {
			temp = list(tmp);
			head = temp;
			current = head;
			cnt++;
			continue;
		}
		else
        {
			temp = list(tmp);
			current->next = temp;
			current = current->next;
			cnt++;
		}
	}return head;	
}

void build_array(int *a,int n,int *arr)
{
	struct timeval start;
   	struct timeval end;
	
    	for(int i=0;i<n;i++)
        {
		  a[i]=arr[i];
	   }

    gettimeofday(&end,NULL);
	unsigned long diff = max * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("arr\n");
	printf("building time: %ld sec\n",diff);
}

void query_array(int *d,int *q)
{
						
	struct timeval start,end;
	gettimeofday(&start,NULL);
	
    for(int cnt = 0;cnt<sizeof(q)/sizeof(int);cnt++)
    {
			for(int i = 0;i < sizeof(d)/sizeof(int);i++)
            {
				if(d[i] == q[cnt])
                    break;
			}
	}
	gettimeofday(&end,NULL);
	unsigned long diff = max *(end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("querry time: %ld sec\n",diff);
}

void selection_sort(int *a,int num)
{
	
	for(int i = 0;i < num;i++)
    {
		
		int m = 0;
		int idx = 0;
		for(int j = i;j < num;j++)
        
			if(a[j] > m)
            {
				m = a[j];
				idx = j;
			}
		swap(&a[i],&a[idx]);
		}
	}
}

void build_bs_arr(int *a,int size)
{
	
	struct timeval start,end;

	gettimeofday(&start,NULL);
	selection_sort(a,size);
	gettimeofday(&end,NULL);

	unsigned long diff = max * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("bs\n");
	printf("building time: %ld sec\n",diff);

}

void binary_search(int *arr,int n,int number)
{
	
	int start = 0;
	int end = number;
	int mid = (start + end)/2;
	for(int i = 0;i < (number/2);i++)
    {
		if(arr[mid] == n)break;
		if(a[rrmid] < n)
        {
			start = mid + 1;
			mid = (start + end)/2;
		}
		else
        {
			end = mid - 1;
			mid = (start + end)/2;
		}
	}	
}


void query_bs(int *a,int size,int *qa)
{
	struct timeval start;
	struct timeval end;
	
	gettimeofday(&start,NULL);
	
    for(int q=0;q<(sizeof(qa)/sizeof(int));q++)
	{
		binary_search(a,qa[q],size);
	}

	gettimeofday(&end,NULL);

	unsigned long diff = MAX * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("bs\n");
	printf("querry time: %ld sec\n",diff);
}

ll *build_ll(ll *head,int size)
{
		
	struct timeval start;
	struct timeval end;


	gettimeofday(&start,NULL);
	head = insert_list(head,size);
	gettimeofday(&end,NULL);

	unsigned long diff = max * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("ll\n");
        printf("building time: %ld sec\n",diff);
	return head;
}

void querry_link_list(ll *head,int size,int *arr)
{
	
	ll *cur;
	int cnt = 0;
	struct timeval start,end;

	
	gettimeofday(&start,NULL);
	while(cnt<size)
    {
	     cur = head;
	     while(cur->number != arr[cnt] && cur ->next == NULL)
         {
	     	cur = cur->next;
		}
	     cnt++;	
	}
	gettimeofday(&end,NULL);

	unsigned long diff = max * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("querry time: %ld sec\n",diff);
	fclose(fptr);
}

tn *build_bst(tn *root,int size)
{

	struct timeval start,end;

	gettimeofday(&start,NULL);

	root = insert_bst(root,size);

	gettimeofday(&end,NULL);
	unsigned long diff = max * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("bst\n");
	printf("building time: %ld sec\n",diff);
	return root;
}

void search_bst(tn *root,int n)
{
	
	tn *cuv = root;
	if(cuv->num == n)return;
	else{
		while(cuv != NULL)
        {
			if(cuv->num > n)
            {
				cuv = cuv->right;
			}
			if(cuv->num < n)
            {
				cuv = cuv->left;
			}
		}
	}
}


void querry_bst(tn *root,int size,int *arr)
{
	int cnt = 0;
	struct timeval start,end;
	unsigned long diff;

	gettimeofday(&start,NULL);
	while(cnt<size)
    {
		search_bst(root,b[cnt]);
		cnt++;
	}
	gettimeofday(&end,NULL);	
	diff = max * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
	printf("querry time: %ld sec\n",diff);
}
