
#pragma once

#define VECTOR
#define SAFE(...) (fprintf(stderr, __VA_ARGS__), fprintf(stderr, "\n"), exit(1))

// int list
#define ELEM int
#define LIST(x) list_int_ ## x 
#include "vector.inc"

#define ELEM list_int_t
#define LIST(x) list_list_int_ ## x
#include "vector.inc"
