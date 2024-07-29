//Leaky bucket
#include<stdio.h>

int main(){
    int incoming, outgoing, buck_size, n, store = 0;
    int entire_duration=0;
    printf("Enter bucket size, outgoing rate and no of inputs: ");
    scanf("%d %d %d", &buck_size, &outgoing, &n);
    printf("\nBucket size = %d",buck_size);
    printf("\nOutgoing rate = %d",outgoing);
    printf("\nNo.of inputs = %d\n\n",n);

    while (store!=0 || n>0) {
        entire_duration++;
        if(n>0){
            printf("\nEnter the incoming packet size : ");
            scanf("%d", &incoming);
            printf("Incoming packet size = %d\n", incoming);
            if (incoming <= (buck_size - store)){
                store += incoming;
                printf("Bucket buffer size %d out of %d\n", store, buck_size);
            } else {
                int drop_size=incoming - (buck_size - store);
                printf("Dropped %d no of packets\n", drop_size);
                store=buck_size; //bucket full
                printf("Bucket buffer size %d out of %d\n", store, buck_size);
                // store = buck_size;
            }
        }
        
        store = store - outgoing;
        if(store<0){
            store=0;
        }
        printf("\nAfter outgoing, %d packets left out of %d in buffer\n", store, buck_size);
        n--;
    }
    printf("\n\nThe entire duration for the transmission is %d clock tick",entire_duration);
}