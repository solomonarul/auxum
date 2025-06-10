#include <auxum/std.h>
#include "data/dynarray.c"
#include "data/bitset.c"

#define UNUSED(X) ((void)(X))

int main(int argc, char* argv[])
{
    UNUSED(argc);
    UNUSED(argv);

    test_bitset();
    test_dynarray();

    return 0;
}
