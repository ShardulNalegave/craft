
#ifndef CRAFT_STATE_H
#define CRAFT_STATE_H

#include "craft/tcp.h"

typedef struct craft_state {
    ccask_tcp_transport transport;
} craft_state_t;

#endif
