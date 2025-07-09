
#ifndef CRAFT_H
#define CRAFT_H

#include "stddef.h"
#include "stdint.h"

typedef struct craft_opts {
    uint16_t listen_port;

    uint32_t election_timeout_min_ms;
    uint32_t election_timeout_max_ms;
    uint32_t heartbeat_interval_ms;
} craft_opts_t;

typedef struct craft_peer_list {
    size_t num;
    uint32_t *peers;
} craft_peer_list_t;

int craft_init(const craft_peer_list_t *peers, const craft_opts_t *opts);
void craft_shutdown();

#endif
