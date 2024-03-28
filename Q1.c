#include<stdio.h>
#include<stdlib.h>

int calculate_operations(int bucket_contents[], int num_buckets) {
    int operations_count = 0;
    for (int i=0; i<num_buckets; i++) {
        if (bucket_contents[i] % 2 == 0) {
            operations_count++; 
        } else {
            operations_count++;
            int doubled_bucket_contents = bucket_contents[i] * 2;
            if (doubled_bucket_contents < (bucket_contents[i] + (num_buckets - i - 1))) {
                operations_count++;
            } else {
                operations_count += (num_buckets - i - 1);
            }
        }
    }
    return operations_count;
}

int main() {
    int num_buckets;
    printf("Please enter the total number of buckets: ");
    scanf("%d", &num_buckets);
    int bucket_contents[num_buckets];
    printf("Please enter the target quantity of fruits for each bucket respectively:\n");
    for (int i=0; i<num_buckets; i++) {
        scanf("%d", &bucket_contents[i]);
    }
    int min_operations = calculate_operations(bucket_contents, num_buckets);
    printf("The minimum number of required operations is: %d\n", min_operations);
    return 0;
}