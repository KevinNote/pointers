#include <stdio.h>

struct int_array {
    int capacity;
    int* data;
};

int get(const struct int_array* self, int x) {
    if (x >= self->capacity) return -1;
    return *(self->data + x);
}

int set(const struct int_array* self, int index, int value) {
    if (index >= self->capacity) return 0;
    *(self->data + index) = value;
    return 1;
}

void dispose(struct int_array* self) {

    if (self->data == NULL) {
        printf("Free a null pointer!");
        return;
    }
    
    free(self->data);
    self->capacity = 0;
    self->data = NULL;
}

void print(const struct int_array* self) {
    printf("Array Info: %p\n", self);
    printf("Capacity: %d\n", self->capacity);
    printf("Data:\n");
    for (int i = 0; i < self->capacity; ++i) {
        printf("[%d] -> %d\n", i, *(self->data + i));
    }
}

struct int_array new(int cap) {
    int* _arr = (int*)calloc(cap, sizeof(int));
    printf("_arr: %p", _arr);
    struct int_array arr = { cap, _arr };
    return arr;
}

int main(void) {
    struct int_array arr = new(12);
    print(&arr);
    int v = set(&arr, 1, 12);
    print(&arr);
    printf("Def [1] -> %d\n", get(&arr, 1));
    // free(arr.data);
    dispose(&arr);
    print(&arr);
    //dispose(&arr);
}
