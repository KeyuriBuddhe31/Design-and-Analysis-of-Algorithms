#include <stdio.h>
#include <stdlib.h>

// Global structures to store discovered subsets for reverse printing
int **discovered_subsets;
int *subset_sizes;
int subset_count = 0;
int max_subsets = 2000; 

void find_subsets(int *set, int n, int target_sum, int index, int current_sum, int *current_subset, int current_size) {
    // Base Case: If current sum matches the target, record it
    if (current_sum == target_sum) {
        if (subset_count >= max_subsets) {
            max_subsets *= 2;
            discovered_subsets = (int **)realloc(discovered_subsets, max_subsets * sizeof(int *));
            subset_sizes = (int *)realloc(subset_sizes, max_subsets * sizeof(int));
        }
        
        discovered_subsets[subset_count] = (int *)malloc(current_size * sizeof(int));
        for (int i = 0; i < current_size; i++) {
            discovered_subsets[subset_count][i] = current_subset[i];
        }
        subset_sizes[subset_count] = current_size;
        subset_count++;
        return;
    }

    // Terminate if sum exceeds target or no elements are left
    if (current_sum > target_sum || index == n) {
        return;
    }

    // Process exclusion first to invert discovery sequence for target reverse printing
    find_subsets(set, n, target_sum, index + 1, current_sum, current_subset, current_size);

    // Process inclusion
    current_subset[current_size] = set[index];
    find_subsets(set, n, target_sum, index + 1, current_sum + set[index], current_subset, current_size + 1);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int *set = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &set[i]) != 1) return 0;
    }

    int target_sum;
    if (scanf("%d", &target_sum) != 1) return 0;

    discovered_subsets = (int **)malloc(max_subsets * sizeof(int *));
    subset_sizes = (int *)malloc(max_subsets * sizeof(int));
    int *current_subset = (int *)malloc(n * sizeof(int));

    find_subsets(set, n, target_sum, 0, 0, current_subset, 0);

    if (subset_count == 0) {
        printf("-1\n");
    } else {
        // Print in reverse order of discovery
        for (int i = subset_count - 1; i >= 0; i--) {
            for (int j = 0; j < subset_sizes[i]; j++) {
                printf("%d", discovered_subsets[i][j]);
                if (j < subset_sizes[i] - 1) {
                    printf(" "); // Explicit single space divider
                }
            }
            printf(" \n");
            free(discovered_subsets[i]);
        }
    }

    free(discovered_subsets);
    free(subset_sizes);
    free(current_subset);
    free(set);

    return 0;
}
