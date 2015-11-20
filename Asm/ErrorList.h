

#define LOG_PRINT_(fmt, value) printf("%d " fmt "\n", __LINE__ , value);

#define LOG_PRINT(fmt) printf(fmt "\n");
#define LOG_ERROR(error_code, fmt) {printf("%d error: " fmt "\n", __LINE__); \
                        return error_code;}


enum ERRORS
{
    ERR_STACK_EMPTY = 1,
    STACK_IS_EMPTY =  2,
    CALLOC_ERROR = 3,
    DUMP_CALLED = 4,
    NULL_POINTER = 5,
    STACK_IS_FULL = 6,
    NULL_DATA_STACK_POINTER = 7,
    NULL_STACK_POINTER = 8,
    READ_ERROR = 9,
    ARRAY_IS_FULL = 10

};