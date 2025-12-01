#include <stdio.h>

#include "poni/poni.h"
#include "poni/poni_glue.h"

static inline
PS_FUN()
ps_strbuf*
read_file(PONI_ABI(ps_strbuf *path)) {
    ps_strbuf *buf = ps_strbuf_new(ctx, 8);
    FILE *file = fopen(path->buffer->contents, "r");

    // Empty string. No error handling. :)
    if(!file) {
        return buf;
    }

    for(;;) {
        int next = fgetc(file);
        if(next == EOF) { break; }

        ps_strfmt_char(ctx, buf, (char)next);
    }

    fclose(file);
    return buf;
}