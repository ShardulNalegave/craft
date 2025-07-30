
#ifndef CRAFT_CONTEXT_INTERNAL_H
#define CRAFT_CONTEXT_INTERNAL_H

#include "stdint.h"
#include "pthread.h"
#include "openssl/ssl.h"

#include "craft/context.h"

struct craft_ctx_mtls {
    SSL_CTX* server_ctx;
    SSL_CTX* client_ctx;
    char* cert_file;
    char* key_file;
    char* ca_file;
};

struct craft_ctx {
    uint16_t listen_port;

    uint32_t election_timeout_min_ms;
    uint32_t election_timeout_max_ms;
    uint32_t heartbeat_interval_ms;

    craft_ctx_mtls_t mtls;
};

#endif
