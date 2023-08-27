#include <stdio.h>
#include <string.h>

char* add_large_numbers(const char* num1, const char* num2) {
    int max_length = strlen(num1) > strlen(num2) ? strlen(num1) : strlen(num2);
    char result[max_length + 2]; // +2 for possible carry and null terminator
    
    int carry = 0;
    int index = max_length;
    result[index + 1] = '\0'; // Set null terminator
    
    int i = strlen(num1) - 1;
    int j = strlen(num2) - 1;
    
    while (i >= 0 || j >= 0 || carry) {
        int digit_sum = carry;
        if (i >= 0) {
            digit_sum += num1[i] - '0';
            i--;
        }
        if (j >= 0) {
            digit_sum += num2[j] - '0';
            j--;
        }
        
        carry = digit_sum / 10;
        result[index] = (digit_sum % 10) + '0';
        index--;
    }
    
    return strdup(result + index + 1); // +1 to skip possible leading zero
}

int main() {
    char num1[1025];
    char num2[1025];
    
    printf("Enter the first large number: ");
    scanf("%s", num1);
    
    printf("Enter the second large number: ");
    scanf("%s", num2);
    
    char* sum_result = add_large_numbers(num1, num2);
    printf("Sum: %s\n", sum_result);
    
    return 0;
}
