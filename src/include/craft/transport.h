
#ifndef CCASK_TRANSPORT_H
#define CCASK_TRANSPORT_H

#include "stdint.h"
#include "stdbool.h"
#include "openssl/ssl.h"

#include "craft/context.h"
#include "craft/status.h"

typedef struct ccask_transport {
    uint64_t node_id;
    int listen_fd;
} ccask_transport_t;

craft_status_e craft_transport_init(craft_ctx_t *ctx);

#endif
