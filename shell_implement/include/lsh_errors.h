#ifndef LSH_ERRORS_H
#define LSH_ERRORS_H
typedef enum lsh_errors{
    kSUCCESS = 0,
    kTRY_AGAIN,
    kINVALID,
    kFAILED,
    kNO_MEM
} lsh_errors_t;
#endif /*LSH_ERRORS_H*/