#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* multiply_large_numbers(const char* num1, const char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int result_len = len1 + len2;
    char* result = (char*)malloc((result_len + 1) * sizeof(char));
    if (result == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    
    memset(result, '0', result_len);
    result[result_len] = '\0';
    
    for (int i = len1 - 1; i >= 0; i--) {
        int carry = 0;
        for (int j = len2 - 1; j >= 0; j--) {
            int product = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
            carry = product / 10;
            result[i + j + 1] = (product % 10) + '0';
        }
        result[i] += carry; // Adding any remaining carry to the leftmost digit of the current row
    }
    
    return result;
}

int main() {
    char num1[1025];
    char num2[1025];
    
    printf("Enter the first large number: ");
    scanf("%s", num1);
    
    printf("Enter the second large number: ");
    scanf("%s", num2);
    
    char* product_result = multiply_large_numbers(num1, num2);
    printf("Product: %s\n", product_result);
    
    free(product_result); // Free allocated memory
    
    return 0;
}
