//counting freq then sorting on the basis of freq
#include <stdio.h>
int main(){
    printf("Enter the number of elements in the array:\n");
    int n;
    scanf("%d",&n);
    printf("Enter the elements of the array:\n");
    int a[n];
    int freq[n];
    for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    freq[i]=0;
    }
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            freq[i]=1;
            for(int j=i+1;j<n;j++){
                if(a[j]==a[i]){
                    a[j]=0;
                    freq[i]++;
                }
            }
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<n;j++){
            if(freq[j]==i){
                for(int k=0;k<i;k++)
                printf("%d\n",a[j]);
            }
        }
    }
}