
#ifndef __RBUFF_INC__
#define __RBUFF_INC__

typedef struct rbuff_t {
    int size;
    int head;
    int  cnt;
    void *ptr;
} rbuff_t;

#define RBUFF_ELEM_PTR(rb, type, pos)    (((type *)((rb)->ptr)) + (pos))

void rbuff_init(rbuff_t *rb, int size, void *buf);

int rbuff_shift(rbuff_t *rb);
int rbuff_unshift(rbuff_t *rb);
int rbuff_push(rbuff_t *rb);
int rbuff_pop(rbuff_t *rb);

static inline int rbuff_is_empty(rbuff_t *rb) {
    return !rb->cnt;
}
static inline int rbuff_is_full(rbuff_t *rb) {
    return rb->cnt == rb->size;
}

#endif /* __RBUFF_INC__ */

