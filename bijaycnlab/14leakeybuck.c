#include<stdio.h>
#include<stdlib.h>
int main(){
    int income,outgoing,buck_size,n,store=0;
    int entire_duration=0;
    printf("\nenter the bucket size,outgoing rate,no of inputs:\n");
    scanf("%d%d%d",&buck_size,&outgoing,&n);

    printf("\nBucket Size = %d",buck_size);
    printf("\nOutgoing Rate = %d",outgoing);
    printf("\nNumber of inputs = %d",n);

    while(store!=0 || n>0){
        entire_duration++;
        if(n>0){
            printf("\nenter the incomming packet size: \n");
            scanf("%d",&income);

            printf("\nincoming packet size = %d",income);

            if(income<=(buck_size-store)){
                store+=income;
                printf("\nbucket buffer size %d out of %d",store,buck_size);
            }
            else{
                int drop_size=income-(buck_size-store);
                printf("\ndropped %d of packets ",drop_size);

                store=buck_size;
                printf("\nbucket buffer size %d out of %d",store,buck_size);
            }
        }

        store=store-outgoing;
        if(store<0){
            store=0;
        }

        printf("\nafter outgoing %d packet is left over %d in buffer ",store,buck_size);

        n--;
    }

    printf("\nentire duration of transmission is %d clock time",entire_duration);
}