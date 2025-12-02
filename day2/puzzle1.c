#include <stdint.h>
#include <stdio.h>
#include <string.h>

void
get_split_vals(int64_t val, int64_t nudge, int64_t *num0, int64_t *num1) {
    char buf[32] = {0};
    sprintf(buf, "%ld", val);
    int len = strlen(buf);

    int i = 0;
    int j = len / 2;
    if(j + j != len) {
        j += nudge;
    }

    *num0 = *num1 = 0;
    while(j < len) {
        *num0 = (*num0 * 10 + buf[i] - '0');
        *num1 = (*num1 * 10 + buf[j] - '0');
        i += 1;
        j += 1;
    }
}

int64_t
nearest_smaller_power_ten(int64_t x) {
    int64_t pow = 1;
    int64_t prev = 1;
    while(pow < x) {
        prev = pow;
        pow *= 10;
    }

    return prev;
}

int main() {
    FILE *f = fopen("input.txt", "r");
    if(!f) return 1;

    int next;
    int64_t sum = 0;
    for(;;) {
        next = fgetc(f);
        if(next == EOF) break;

        int64_t num1 = 0;
        while(next != '-') {
            num1 = (num1 * 10 + next - '0');
            next = fgetc(f);
        }

        next = fgetc(f); // skip -
        int64_t num2 = 0;
        while(next != EOF && next >= '0' && next <= '9') {
            num2 = (num2 * 10 + next - '0');
            next = fgetc(f);
        }
        next = fgetc(f); // skip ,

        int64_t a, b;
        get_split_vals(num1, 1, &a, &b);
        int64_t start = a < b ? a : b;

        get_split_vals(num2, 0, &a, &b);
        int64_t end = a < b ? b : a;

        for(int64_t check = start; check <= end; ++check) {
            int64_t val = check + check * nearest_smaller_power_ten(check);
            if(val >= num1 && val <= num2) {
                sum += val;
            }
        }
    }

    printf("sum = %ld\n", sum);

    fclose(f);
    return 0;
}