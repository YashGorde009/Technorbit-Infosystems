#include<stdio.h>
int main()
{
    int n1,n2,i,j,count,flag,k,uni,inter;
    int arr[100];
    int brr[100];
    int aub[100], anb[100];

    printf("Enter size of 1st array = ");
    scanf("%d",&n1);
    printf("Enter array Element = ");  // Hi line for loop chy baher takli
    for(i=0 ; i<n1 ; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("Enter size of 2nd array = ");
    scanf("%d",&n2);
    printf("Enter array Element = "); // Hi line for loop chy baher takli
    for(i=0 ; i<n2 ; i++)
    {
        scanf("%d",&brr[i]);
    }

    //INTERSECTION

    inter=0;
    for(i=0;i<n1; i++)
    {
        k=i;
        flag=0;
        while(k>=0)
        {
            k--;
            if(arr[k]==arr[i])
            {
                flag=1;
            }
            
        }
        if(flag==0)
        {
            flag=0;
            for(j=0;j<n2;j++)
            {
                if(arr[i]==brr[j])
                {
                    flag=1;
                    break;
                }   
            }
            if(flag==1)
            {
                anb[inter]=arr[i];
                inter++;
                

            }
        }
    }

    printf("\nIntersection :  ");


    for(i=0 ; i<inter ; i++)
    {
        printf("%d  ",anb[i]);
    }

      
    

    //UNION

    uni=0;

    for(i=0 ; i<n1 ;i++)  //PUTTING UNCOMMON ELEMENTS FROM SET A    
    {
        k=i;
        flag=0;
        while(k>=0)
        {
            k--;
            
            if(arr[k]==arr[i])
            {
                flag=1;
            }
            
        }
        if(flag==0)
        {
            flag=0;
            for(j=0;j<n2;j++)
            {
                if(arr[i]==brr[j])
                {
                    flag=1;
                }
            }
            if(flag==0)
            {
                aub[uni]=arr[i];
                uni++;
            }
        }
    }

    for(i=0;i<n2;i++)  //PUTTING UNCOMMON ELEMENTS FROM SET B
    {
        k=i;
        flag=0;
        while(k>=0)
        {
            k--;
            if(brr[k]==brr[i])
            {
                flag=1;
            }
            
        }
        if(flag==0)
        {
            flag=0;
            for(j=0;j<n1;j++)
            {
                if(brr[i]==arr[j])
                {
                    flag=1;
                }
            }
            if(flag==0)
            {
                aub[uni]=brr[i];
                uni++;
            }
        }
    }

    for(i=0 ; i<inter ; i++)  //PUTTING INTERSECTION SET IN UNION SET
    {
        aub[uni]=anb[i];

        uni++;
    }
    


    printf("\nUnion :  ");
    for(i=0;i<uni;i++)
    {
        
        printf("%d  ", aub[i]);
        
    }

    return 0;

}