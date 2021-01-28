#include <stdio.h>

void period(char *input) {
    int start = 0, period_len = 1;
    int repetition_count = 0;
    int len = 0;
    int i = 0;

    while (1) {
        for (i = 0; i < period_len && input[start + period_len + i] != '\0'; ++i) {
            if (input[start + i] != input[start + period_len + i])
                /* I'm one step closer to the edge, and I'm about to... */ break;
        }
        if (i == period_len) {
            start += period_len;
            ++repetition_count;
            continue;
        } else if (input[start + period_len + i] == '\0') {
            len = start + period_len + i;
            if (repetition_count) {
                break;
            }
            period_len = 1;
            repetition_count = 0;
            if(++start==len)
                break;
            continue;
        }
        ++period_len;
        repetition_count = 0;
    }
    printf("The string is %d character long.\n", len);
    if (repetition_count)
        printf("The period is %d and the repeating sequence is \"%.*s\".\n", period_len, period_len, input + start);
    else
        puts("The string is not periodic.");
}

int main() {
    period("Teststringwithaperiodicperiodicperiodicperiodicperiodicperio");
    return 0;
}
