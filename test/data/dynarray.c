#include <auxum/data/dynarray.h>

#include <assert.h>
#include <stdio.h>

typedef struct {
    int x;
    float y;
} test_struct_t;

void test_dynarray(void)
{
    dynarray_t array;
    dynarray_init(&array, sizeof(test_struct_t), 2);

    assert(array.size == 2);
    assert(array.capacity >= 2);
    assert(array.element_size == sizeof(test_struct_t));

    // Push elements
    test_struct_t item1 = {1, 1.1f};
    test_struct_t item2 = {2, 2.2f};

    dynarray_push_back(&array, &item1);
    dynarray_push_back(&array, &item2);

    assert(array.size == 4);

    // Get and check elements
    test_struct_t* retrieved1 = (test_struct_t*)dynarray_get(array, 2);
    test_struct_t* retrieved2 = (test_struct_t*)dynarray_get(array, 3);

    assert(retrieved1->x == 1 && retrieved1->y == 1.1f);
    assert(retrieved2->x == 2 && retrieved2->y == 2.2f);

    // Remove element
    dynarray_remove(&array, 0);
    dynarray_remove(&array, 0);
    assert(array.size == 2);

    // Pop element
    dynarray_pop_back(&array);
    assert(array.size == 1);

    // Push again and duplicate
    dynarray_push_back(&array, &item2);
    dynarray_t copy = dynarray_duplicate(&array);

    assert(copy.size == 2);
    test_struct_t* copied_item = (test_struct_t*)dynarray_get(copy, 0);
    assert(copied_item->x == item1.x && copied_item->y == item1.y);
    copied_item = (test_struct_t*)dynarray_get(copy, 1);
    assert(copied_item->x == item2.x && copied_item->y == item2.y);

    // Cleanup
    dynarray_free(array);
    dynarray_free(copy);

    printf("[TEST]: Dynarray tests passed.\n");
}
