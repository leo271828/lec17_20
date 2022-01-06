#include<stdio.h>
#include<stdlib.h>

struct snack
{
    int id;
    int price;
    int weight;
    double value;
};

int cmp(const void *a, const void *b);
void sort_snacks(struct snack snacks[], int n);

int main() {
    int n;
    struct snack snacks[100];
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        snacks[i].id = i+1;
        scanf("%d %d", &snacks[i].price, &snacks[i].weight);
    }
    sort_snacks(snacks, n);
    printf("\n");
    for(int i=0; i<n; i++) {
        printf("%d %.2f\n", snacks[i].id, snacks[i].value);
    }
    return 0;
}
void sort_snacks(struct snack snacks[], int n) {
    struct snack *v[n];
    for(int i=0;i<n;i++){
        snacks[i].value = (double)snacks[i].weight / (double)snacks[i].price;
        v[i] = &snacks[i];
    }
    qsort(snacks, n, sizeof(struct snack), cmp);
}

int cmp(const void *a, const void *b) {
    struct snack aa = *(struct snack*)a;
    struct snack bb = *(struct snack*)b;
    if( aa.value < bb.value )
        return 1;
    else if ( aa.value > bb.value )
        return 0;
    else{
        if( aa.price > bb.price )
            return 1;
        else if ( aa.price < bb.price )
            return 0;
        else{
            if( aa.id > bb.id )
                return 1;
            else 
                return 0;
        }
    } 

}
