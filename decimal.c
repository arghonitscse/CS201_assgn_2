#include <stdio.h>
#include <stdlib.h>

void divide_to_n_decimals(int x, int y, int n) {
    printf("%d.", x / y);  // Integer division for the whole part
    
    for (int i = 0; i < n; i++) {
        x = (x % y) * 10;  // Update x with the remainder and multiply by 10
        printf("%d", x / y);
    }
    
    printf("\n");
}

int main() {
    int x, y, n;
    
    printf("Enter the numerator (x): ");
    scanf("%d", &x);
    
    printf("Enter the denominator (y): ");
    scanf("%d", &y);
    
    printf("Enter the number of decimal points (n): ");
    scanf("%d", &n);
    
    divide_to_n_decimals(x, y, n);
    
    return 0;
