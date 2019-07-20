#include <stdio.h>
void readCardNumber(int *cardNumber) {
    int i = 0;
    char c;
    while((c = getchar()) != EOF) {
        if(c == '\n') {
            break;
        }
        if(c != ' '){
            cardNumber[i++] = (int)(c - '0');
        }
    }
}

int checkValidity(int *cardNumber) {
    int i, validityValue = 0, t;
    for(i = 0; i < 16; i += 2) {
        t = cardNumber[i] * 2;
        validityValue += t / 10 + t % 10;
    }
    for(i = 1; i < 16; i += 2) {
        validityValue += cardNumber[i];
    }
    return !(validityValue % 10);
}

int main() {
    int N, cardNumber[16];
    scanf(" %d\n", &N);
    while(N-- > 0) {
        readCardNumber(cardNumber);
        if(checkValidity(cardNumber)) {
            printf("Valid\n");
        } else {
            printf("Invalid\n");
        }
    }
    return 0;
}