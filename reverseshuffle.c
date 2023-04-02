#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int getInt(const char *prompt,int min,int max){
    int size;
    while(1){
        for(int i = 0; i < strlen(prompt); i++){
            printf("%c",prompt[i]);
        }
        scanf("%i",&size);
        if(size < min || size > max){
            printf("Input must be in the range: %i-%i\n",min,max); 
        }
        else{
            return size;
        }
        continue;
    }

}

void fillBoard(int arr[],int len){
    int input = 1;
    for(int i = 0; i < len; i++){
        arr[i] = input;
        input++;
    }
}

void printBoard(int arr[],int len){
    printf("Board: ");
    for(int i = 0; i < len; i++){
        printf("%i ",arr[i]);
    }
    printf("\n");  
}

void shuffleBoard(int arr[],int len){
    int j;
    int max = arr[len-1];
    int strg;
    int *a;
    int *b;
    for(int i = len-1; i > 1; i--){
        j = random() % (i+1);
        a = &arr[i];
        b = &arr[j];
        strg = *a;
        *a = *b;
        *b = strg;
    }
}

void reverse(int arr[],int len,int input){
    int strg[input];
    int j = 0;
    for(int i = input-1; i >= 0; i--){
        strg[j] = arr[i];
        j++;
    }

    j = 0; 
    for(int i = 0; i < input; i++){
        arr[j] = strg[i];
        j++;
    }
}

int isSorted(int arr[],int len){
    int test = 1;
    for(int i = 0; i < len; i++){
        if(arr[i]<arr[i+1]){
            continue;
        }

        else{
            test = 0;
            break;
        }
    }
    return test;
}

int main(){
    srandom(time(NULL));

    int input;
    int moves = 0;
    int arr[getInt("Please enter a valid board size: ",3,20)];
    int len = sizeof(arr)/sizeof(arr[0]);
    fillBoard(arr,len);
    printBoard(arr,len);
    shuffleBoard(arr,len);
    printBoard(arr,len);

    while(1){
        moves++;
        printf("How many to reverse?");
        scanf("%i",&input);
        if(input > len || input < 1){ // basic error checking (just exits if you ask to reverse more or less elements than you can)
            break;
        }

        reverse(arr,len,input);
        printBoard(arr,len);
        if(isSorted(arr,len)==0){
            continue;
        }
        else{
            printf("You won in %i moves!\n",moves);
            break;
        }
    }

    return 0;
}
