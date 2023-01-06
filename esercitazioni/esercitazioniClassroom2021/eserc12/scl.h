#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#pragma once

typedef int TipoInfoSCL;

struct ElemSCL {
TipoInfoSCL info;
struct ElemSCL *next;
};

typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL * TipoSCL;
