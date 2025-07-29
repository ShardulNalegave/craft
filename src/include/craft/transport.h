
#ifndef CCASK_TRANSPORT_H
#define CCASK_TRANSPORT_H

#include "stdint.h"
#include "openssl/ssl.h"

#include "craft/status.h"

typedef struct ccask_peer_conn {
    uint32_t peer_id;
    int socket_fd;
    bool handshake_done;
    SSL *ssl;
} ccask_peer_conn_t;

typedef struct ccask_transport {
    uint64_t node_id;
    int listen_fd;
    
    ccask_peer_conn_t *conns;
    uint64_t num_conns;
} ccask_transport_t;

craft_status_e craft_transport_init();
void craft_transport_shutdown();

#endif