
#include "craft/core.h"
#include "craft/opts.h"
#include "craft/context_internal.h"
#include "craft/status.h"

#include "craft/transport.h"

craft_error_e craft_errno = ERR_UNKNOWN;

craft_ctx_t* craft_init(const craft_opts_t *opts) {
    craft_ctx_t *ctx = malloc(sizeof(craft_ctx_mtls_t));
    ctx->listen_port = opts->listen_port;
    ctx->election_timeout_min_ms = opts->election_timeout_min_ms;
    ctx->election_timeout_max_ms = opts->election_timeout_max_ms;
    
    ctx->mtls.ca_file = opts->mtls.ca_file;
    ctx->mtls.cert_file = opts->mtls.cert_file;
    ctx->mtls.key_file = opts->mtls.key_file;

    craft_transport_init(ctx);

    return ctx;
}

void craft_shutdown(craft_ctx_t *ctx) {
    free(ctx);
}
