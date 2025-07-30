
#ifndef CRAFT_OPTS_H
#define CRAFT_OPTS_H

#include "stdint.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char* cert_file;
    char* key_file;
    char* ca_file;
} craft_mtls_opts_t;

typedef struct craft_opts {
    uint16_t listen_port;

    uint32_t election_timeout_min_ms;
    uint32_t election_timeout_max_ms;
    uint32_t heartbeat_interval_ms;

    craft_mtls_opts_t mtls;
} craft_opts_t;

#ifdef __cplusplus
}
#endif

#endif
