#include<bits/stdc++.h>
using namespace std;

void A(){
    cout << "Hello World" << endl;
}
void B(void(*ptr)()){ // Function pointer as argument
    ptr(); // call-back function that "ptr" points to
}

int compare(int a, int b){
    return a > b;
}

int Compare(const void* a, const void* b){
    int A = *((int*)a); // typecasting to int* and getting value
    int B = *((int*)b);
    return A - B;
}
// callback function should compare two integers, should return 1 if first element has higher rank, 0 if elements are equal and -1 if second element has higher rank.
void Bubble_Sort(int *A, int n, int (*compare)(int, int)){
    for(int i = 0 ; i < n;i++){
        for(int j = 0 ; j < n - 1;j++){
            if(compare(A[j], A[j + 1])){
                swap(A[j], A[j + 1]);
            }
        }
    }
}

void Function_Pointer_and_call_back(){
    void(*ptr)() = A;
    //B(ptr);
    //B(A); // A is callback function
    int A[] = {3, 2, 1, 5, 6, 4};
    qsort(A, 6, sizeof(int), Compare); // qsort can sort any array of(char, int , ...) or any structure type.
    // Bubble_Sort(A, 6, compare);
    for(int i = 0 ; i < 6;i++){
        cout << A[i] << ' ';
    }
}

int cash = 100;
void Play(int bet){
    // char C[3] = {'J', 'Q', 'K'};
    char *C = (char*)malloc(3 * sizeof(char)); // c++: Char *C = new char[3];
    // Every time we call the function it will reserve some memory in the heap to create the array and this will lead to (memory leak).
    C[0] = 'J'; C[1] = 'Q'; C[2] = 'K';
    printf("Shuffling...\n");
    srand(time(nullptr)); // seeding random number generator.
    for(int i = 0 ; i < 5;i++){
        int x = rand() % 3;
        int y = rand() % 3;
        swap(C[x], C[y]);
    }
    int playrGuess;
    printf("What's the position of queen - 1, 2 or 3 ? ");
    scanf("%d", &playrGuess);
    if(C[playrGuess - 1] == 'Q'){
        cash += 3 * bet;
        printf("You Win ! Result = \"%c %c %c\" Total Cash = %d\n", C[0], C[1], C[2], cash);
    }
    else{
        cash -= bet;
        printf("You Loos ! Result = \"%c %c %c\" Total Cash = %d\n", C[0], C[1], C[2], cash);
    }
}

void Memory_Leak(){
    int bet;
    printf("Welcome to the virtual Casino\n");
    printf("Total Cash = $%d\n", cash);
    while(cash > 0){
        printf("What's your bet? $");
        scanf("%d", &bet);
        if(bet <= 0 || bet > cash)break;
        Play(bet);
        printf("**************************************************\n");
    }
}

int main(){

    // Function_Pointer_and_call_back();

    Memory_Leak();

    return 0;
}