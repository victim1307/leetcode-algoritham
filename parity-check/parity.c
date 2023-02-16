#include <stdio.h>
#include <string.h>

int main() {
    char data[100];
    char parity;
    int count_ones = 0;


    printf("Enter the data: ");
    scanf("%s", data);
    printf("Enter the parity: ")
    scanf(" %c", &parity);
    for (int i = 0; i < strlen(data); i++) {
        if (data[i] == '1') {
            count_ones++;
        }
    }

    if (parity == '0') {  // even parity
        if (count_ones % 2 == 0) {
            printf("True\n");
        } else {
            printf("False\n");
        }
    } else {  // odd parity
        if (count_ones % 2 == 1) {
            printf("True\n");
        } else {
            printf("False\n");
        }
    }

    return 0;
}
