#include <stdio.h>
#include <stdlib.h>

void test_memory_operations(int path) {
    char *buffer1 = (char *)malloc(64);  // Allocate 64 bytes
    char *buffer2 = (char *)malloc(128); // Allocate 128 bytes

    if (!buffer1 || !buffer2) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Memory allocated\n");

    if (path == 1) { // NORMAL_PATH
        free(buffer1);
        free(buffer2);
        printf("Memory freed normally\n");
    } else if (path == 2) { // DOUBLE_FREE_PATH
        free(buffer1);
        free(buffer1); // Double-free error
        free(buffer2);
        printf("Double-free triggered\n");
    } else if (path == 3) { // USE_AFTER_FREE_PATH
        free(buffer1);
        buffer1[0] = 'A'; // Use-after-free error
        free(buffer2);
        printf("Use-after-free triggered\n");
    } else if (path == 4) { // MALLOC_LEAK_PATH
        free(buffer1);
        // buffer2 is intentionally not freed, causing a memory leak
        printf("Malloc leak triggered\n");
    } else {
        printf("Unknown path\n");
        free(buffer1);
        free(buffer2);
    }
}

int main() {
    printf("Testing NORMAL_PATH:\n");
    test_memory_operations(1);

    printf("\nTesting DOUBLE_FREE_PATH:\n");
    test_memory_operations(2);

    printf("\nTesting USE_AFTER_FREE_PATH:\n");
    test_memory_operations(3);

    printf("\nTesting MALLOC_LEAK_PATH:\n");
    test_memory_operations(4);

    return 0;
}
