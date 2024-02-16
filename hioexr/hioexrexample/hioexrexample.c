#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#include "openexr-c.h"


int64_t exr_AssetRead_Func(
    exr_const_context_t         ctxt,
    void* userdata,
    void* buffer,
    uint64_t                    sz,
    uint64_t                    offset,
    exr_stream_error_func_ptr_t error_cb)
{
    uint8_t * buf = (uint8_t *)malloc(sz);
    memcpy_s(buf, sz, buffer, sz);

    int i;
    for (i = 0; i < sz; i++)
    {
        if (i > 0) printf(":");
        printf("%02X", buf[i]);
    }
    return 0;
}

static void _AttributeReadCallback(void* self_, exr_context_t exr)
{};

int main()
{
    printf("Hello, World! This is a native C program compiled on the command line (By Microsoft).\n");

    char* FN = "Desk.exr";
    nanoexr_Reader_t _exrReader = {};
    nanoexr_set_defaults(FN, &_exrReader);

    int subimage = 0;
    int rv = nanoexr_read_header(&_exrReader,
        NULL,
        NULL,
        NULL,
        subimage);

    printf("Width = %d, Height = %d, Wrapmode = %d", _exrReader.width, _exrReader.height, _exrReader.wrapMode);

    scanf_s("%d", &rv);
    return 0;
}