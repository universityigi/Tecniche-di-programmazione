#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char TipoInfoSCL;

struct ElemSCL
{
    TipoInfoSCL info;
    struct ElemSCL *next;
};

typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL *TipoSCL;

void sclstring_print(TipoSCL s);
TipoSCL sclstring_create(const char *s);
bool sclstring_equals(TipoSCL scl, const char *s);
void sclstring_remove(TipoSCL *scl_p, char val);

int main()
{
    char *string = "Buongiorno!";
    TipoSCL scl = sclstring_create(string);
    sclstring_print(scl);
    printf("EQUAL = %d\n", sclstring_equals(scl, string));
    sclstring_remove(&scl, 'o');
    sclstring_print(scl);
    return 0;
}

void sclstring_print(TipoSCL scl)
{
    if (scl == NULL)
        ;
    else if ((scl->next) == NULL)
        printf("%c\n", scl->info);
    else
    {
        printf("%c->", scl->info);
        sclstring_print(scl->next);
    }
}

TipoSCL sclstring_create(const char *s)
{
    if (s[0] == '\0')
        return NULL;
    else
    {
        TipoSCL scl = (TipoNodoSCL *)malloc(sizeof(TipoNodoSCL));
        scl->info = s[0];
        scl->next = sclstring_create(s+1);
        return scl;
    }
}

bool sclstring_equals(TipoSCL scl, const char *s)
{
    if (scl == NULL && s[0] == '\0')
        return true;
    else if (scl->info != s[0])
        return false;
    else
        return true & sclstring_equals(scl->next, s + 1);
}

void sclstring_remove(TipoSCL *scl_p, char val)
{
    if (*scl_p == NULL);
    else if ((*scl_p)->info == val)
    {
        TipoSCL to_del = *scl_p;
        *scl_p = (*scl_p)->next;
        free(to_del);
        sclstring_remove(&((*scl_p)->next), val);
    }
    else
        sclstring_remove(&((*scl_p)->next), val);
}