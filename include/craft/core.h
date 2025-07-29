
#ifndef CRAFT_H
#define CRAFT_H

#include "stddef.h"
#include "stdint.h"

#include "craft/opts.h"

#ifdef __cplusplus
extern "C" {
#endif

int craft_init(const craft_opts_t *opts);
void craft_shutdown();

#ifdef __cplusplus
}
#endif

#endif
