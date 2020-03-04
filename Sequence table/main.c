#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 20
#define true 1
#define false 0
typedef struct
{
      int data[MAXNUM];

      int length;
}list_type;
void reatelist(list_type *lp)
{
  int i, elem;
  lp->length=0;
  printf("\nplease input datas of the list\n");
  for(i=0; i< MAXNUM; i++)
  {
        scanf(" %d", &elem);
        if(elem== -1) break;
        lp->data[i]=elem;
        lp->length++;
  }
}
void showlist(list_type *lp)
{
  int i;
  printf("\nThese %d records are:\n", lp->length);
  if(lp->length<=0)
  {
       printf("No data!\n");
       return;
  }
  for(i=0; i<lp->length; i++)
      printf(" %d ", lp->data[i]);
  printf("\nlength of the list is:%d", lp->length);
}

int insertlist(list_type *lp, int new_elem, int i)
{  int j;
    if(lp->length>=MAXNUM)
   {
        printf("the list is full,can not insert.");
        return(false);
   }
   if(i<1 || i>lp->length+1)
   {
        printf("\n%d is invalid value",i);
        return(false);
   }
   if(i==lp->length+1)
   {
       lp->length++;
       lp->data[i-1]=new_elem;
       return(true);
   }
   for(j=lp->length-1;j>=i-1;j--)
   {
       lp->data[j+1]=lp->data[j];
   }
   lp->length++;
   lp->data[i-1]=new_elem;
   return(true);
}
int insertyouxu(list_type *lp, int new_elem)
{  int j,i;
    if(lp->length>=MAXNUM)
   {
        printf("the list is full,can not insert.");
        return(false);
   }
   for(i=0;i<lp->length;i++)
   {
       if(i==lp->length-1)
       break;
       if(new_elem>=lp->data[i] && new_elem<=lp->data[i+1])
       {
           break;
       }
   }
   i++;
   for(j=lp->length-1;j>=i;j--)
   {
       lp->data[j+1]=lp->data[j];
   }
   lp->length++;
   lp->data[i]=new_elem;
   return(true);
}
int deletelist(list_type *lp, int i)
{
   int j;
   if(i<1 || i>lp->length)
   {
        printf("elem not exist");
        return(false);
   }
   for(j=i-1;j<lp->length;j++)
    lp->data[j]=lp->data[j+1];
   lp->length--;
   return(true);
}
void fanxu(list_type *lp)
{
    int a[lp->length],i;
    for(i=0;i<lp->length;i++)
        a[i]=lp->data[i];
    for(i=0;i<lp->length;i++)
        lp->data[i]=a[lp->length-1-i];
}
void delete_negative(list_type *lp)
{
    int i,j;
    for(i=0;i<lp->length;i++)
    {
        if(lp->data[i]<0)
        {
            for(j=i;j<lp->length;j++)
            {
                lp->data[j]=lp->data[j+1];
            }
            i--;
            lp->length--;
        }
    }
}

void main( )
{
    list_type list;
    int i, data;
    createlist(&list);
    showlist(&list);
    printf("\ninsert:Enter i and data :\n");
    scanf("%d,%d", &i, &data);
    insertlist(&list, data, i);
    printf("\nlist after insert:\n");
    showlist(&list);
    printf("\ndelete:Enter i:\n");
    scanf("%d", &i);
    deletelist(&list, i);
    printf("\nlist after delete:\n");
    showlist(&list);
    printf("\nPlease enter i\n");
    scanf("%d",&i);
    insertyouxu(&list,i);
    showlist(&list);
    delete_negative(&list);
    printf("\nlist after delete all negative:\n");
    showlist(&list);
    fanxu(&list);
    showlist(&list);
}

