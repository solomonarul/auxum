#include <auxum/std.h>
#include "data/dynarray.c"
#include "data/bitset.c"

int main(int argc, char* argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    test_bitset();
    test_dynarray();

    return 0;
}
