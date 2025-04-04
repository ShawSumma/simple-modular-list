
#pragma once

#define VECTOR
#define SAFE(...) (fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n"), exit(1))

// int list
#define ELEM int
#define LIST(x) list_int_ ## x 
#include "vector.inc"

#define ELEM void *
#define LIST(x) list_obj_ ## x
#include "vector.inc"

#define ELEM float
#define LIST(x) list_float_ ## x
#include "vector.inc"

#define list(T) list_ ## T ## _t
#define list_new(T) list_ ## T ## _new()
#define list_delete(T, v) list_ ## T ## _delete(v)
#define list_push(T, v, o) list_ ## T ## _push(&v, o)
#define list_index(T, v, i) (*list_ ## T ## _index(&v, (size_t) (i)))
#define list_pop(T, v) list_ ## T ## _pop(&v)
#define list_len(T, v) list_ ## T ## _size(&v)
#define list_is_empty(T, v) list_ ## T ## _is_empty(&v)
