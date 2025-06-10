#include <auxum/data/bitset.h>

#include <assert.h>
#include <stdio.h>

void test_bitset(void)
{
    bitset_t self;

    // Test initialization
    bitset_init(&self, 16);
    assert(self.size == 16);
    for (int index = 0; index < 16; index++)
        assert(bitset_get(&self, index) == false);

    // Test set
    bitset_set(&self, 3);
    assert(bitset_get(&self, 3) == true);

    // Test reset
    bitset_reset(&self, 3);
    assert(bitset_get(&self, 3) == false);

    // Test XOR
    bitset_set(&self, 4);
    bitset_xor(&self, 4, true);
    assert(bitset_get(&self, 4) == false);
    bitset_xor(&self, 4, true);
    assert(bitset_get(&self, 4) == true);

    // Test clear
    bitset_clear(&self);
    for (int index = 0; index < self.size; index++)
        assert(bitset_get(&self, index) == false);

    // Test resize up
    bitset_resize(&self, 32);
    assert(self.size == 32);
    for (int index = 0; index < 32; index++)
        assert(bitset_get(&self, index) == false);

    // Test resize down
    bitset_set(&self, 15);
    bitset_resize(&self, 10);
    assert(self.size == 10);
    for (int index = 0; index < 10; ++index)
        assert(bitset_get(&self, index) == false);

    // Cleanup
    bitset_free(&self);
    printf("[TEST]: Bitset tests passed.\n");
}
