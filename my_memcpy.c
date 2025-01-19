#include <stdio.h>
#include <stdlib.h>

// for memcpy...
#include <string.h>

void custom_memcpy(void *_destination, void *_source, int num_bytes)
{
    int bytes_to_copy = num_bytes;
    long long *dest_ptr_long_long = (long long *)_destination;
    long long *src_ptr_long_long = (long long *)_source;

    int nums_loops = 0;

    int copy_long_long = bytes_to_copy / sizeof(long long);
    while (copy_long_long)
    {
        // Copy in 8 bytes chunks.
        *dest_ptr_long_long++ = *src_ptr_long_long++;
        copy_long_long--;
        bytes_to_copy -= sizeof(long long);

        // Count num_loops
        nums_loops++;
    }

    int *dest_ptr_int = (int *)dest_ptr_long_long;
    int *src_ptr_int = (int *)src_ptr_long_long;

    int copy_int = bytes_to_copy / sizeof(int);
    while (copy_int)
    {
        // Copy in 4 bytes chunks.
        *dest_ptr_int++ = *src_ptr_int++;
        copy_int--;
        bytes_to_copy -= sizeof(int);

        // Count num_loops
        nums_loops++;
    }

    char *dest_ptr_char = (char *)_destination;
    char *src_ptr_char = (char *)_source;

    int copy_char = bytes_to_copy / sizeof(char);
    while (copy_char)
    {
        // Copy in 1 byte chunks.
        *dest_ptr_char++ = *src_ptr_char++;
        copy_char--;
        bytes_to_copy -= sizeof(char);

        // Count num_loops
        nums_loops++;
    }

    printf("We looped just %d times to copy %d bytes.!\n", nums_loops, num_bytes);
}

void main()
{
    printf("Hello, This is implementation for custome-memcpy!\n");

    char *source = "9wGk6LcG4cp7T6marEBqsdrOIWhHM4F1cDBDIMMcBnvhSQvTHwy232OlZaWPkOc0RwDjMVfKe5Mrtc8tGgRXd8WEEaMxSQ1Ze48wL2sZVutG8Y48Gip4DXQt3ZbLnnEchrPuhY3O2kURuBjN1eDDwQl7uMVd8hL2bHNUNAJeQ6uTT5x5gatxngHpfqGTphp8FhNZbh4V8dli1LeZ8uyGBEfW1FhJfxYUb3cQYvAMmx8VFvmsK2Z3cTMJYw5zIso2zXORiwiZvd8Sw1tKPb1HAdDmuJ6KsJPKAoLKQeGDbLDeQFyP77q3MdLgdBKUoy4AkQjCEtV0IpKnu6xQ9RmA25YbDcuoyKuJLqvfOh5sE80ko9fZMjbSvYK801BhIBDM8MxQ36PPtcVI6LXKEGb5yb4kigXver3P6HTIInMvC3NDy9xwazVC8awWDAPcmUJjvJfmmBESHxZILYWnbFG3gL2sNe9OFCXGMryBG5Up2D7mx2EsLn2QRjfnTT0wVjx";
    char destination_memcpy[512] = {'\0'};
    char destination_custom_memcpy[512] = {'\0'};

    printf("\n");
    printf("SOURCE ::\n%s\n\n", source);

    memcpy(destination_memcpy, source, 500);

    printf("1) memcpy ::\n%s\n\n", destination_memcpy);

    custom_memcpy(destination_custom_memcpy, source, 500);

    printf("1) custom-memcpy ::\n%s\n\n", destination_custom_memcpy);

    return;
}