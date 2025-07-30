
#ifndef CRAFT_H
#define CRAFT_H

#include "stddef.h"
#include "stdint.h"

#include "craft/opts.h"
#include "craft/context.h"

#ifdef __cplusplus
extern "C" {
#endif

craft_ctx_t* craft_init(const craft_opts_t *opts);
void craft_shutdown(craft_ctx_t *ctx);

#ifdef __cplusplus
}
#endif

#endif
