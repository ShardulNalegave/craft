
#ifndef CRAFT_STATUS_H
#define CRAFT_STATUS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum craft_error {
    ERR_UNKNOWN = 0
} craft_error_e;

typedef enum craft_status {
    CRAFT_OK        = 0,
    CRAFT_FAIL      = -1,
    CRAFT_RETRY     = -2,
} craft_status_e;

#define CRAFT_ATTEMPT(max_attempts, out_var, expr)              \
    do {                                                        \
        int _ccask_retry_cnt = 0;                               \
        for (; _ccask_retry_cnt < (max_attempts);               \
            ++_ccask_retry_cnt)                                 \
        {                                                       \
        (out_var) = (expr);                                     \
        if (out_var != CCASK_RETRY)                             \
            break;                                              \
        }                                                       \
    } while (0)

extern craft_error_e craft_errno;

#ifdef __cplusplus
}
#endif

#endif
