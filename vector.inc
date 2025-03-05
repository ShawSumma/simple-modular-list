
#if !defined(ELEM) || !defined(LIST)
#error PLEASE DEFINE: ELEM
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#if defined(VECTOR)

struct LIST(t);
typedef struct LIST(t) LIST(t);

struct LIST(t){
    size_t len;
    ELEM *data;
    size_t alloc;
};

static inline LIST(t) LIST(new) (void) {
    return (LIST(t)) {
        .len = 0,
    };
}

static inline void LIST(delete) (LIST(t)vec) {
    free(vec.data);
}

static inline void LIST(push) (LIST(t) *vec, ELEM elem) {
    size_t pos = vec->len++;
    if (pos >= vec->alloc) {
        vec->alloc = vec->len * 2;
        vec->data = realloc(vec->data, vec->alloc * sizeof(ELEM ));
    }
    vec->data[pos] = elem;
}

static inline ELEM LIST(index) (LIST(t) *vec, size_t index) {
    #if defined(SAFE)
        if (index >= vec->len) {
            SAFE("OUT OF BOUNDS %zu", index);
        }
    #endif
    return vec->data[index];
}

static inline ELEM LIST(pop) (LIST(t) *vec) {
    #if defined(SAFE)
        if (vec->len == 0) {
            SAFE("POP FROM EMPTY LIST");
        }
    #endif
    return vec->data[--vec->len];
}

static inline size_t LIST(size) (LIST(t) *vec) {
    return vec->len;
}

#elif defined(LINKED)

#error LINKED

#else

#error UNKNOWN

#endif

static inline _Bool LIST(is_empty) (LIST(t) *vec) {
    return LIST(size)(vec) == 0;
}

#undef ELEM
#undef LIST
