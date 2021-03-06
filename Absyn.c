/* C Abstract Syntax Implementation generated by the BNF Converter. */

#include <stdio.h>
#include <stdlib.h>
#include "Absyn.h"


/********************   EAdd    ********************/
Exp make_EAdd(Exp p1, Exp p2)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating EAdd!\n");
        exit(1);
    }
    tmp->kind = is_EAdd;
    tmp->u.eadd_.exp_1 = p1;
    tmp->u.eadd_.exp_2 = p2;
    return tmp;
}
/********************   ESub    ********************/
Exp make_ESub(Exp p1, Exp p2)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating ESub!\n");
        exit(1);
    }
    tmp->kind = is_ESub;
    tmp->u.esub_.exp_1 = p1;
    tmp->u.esub_.exp_2 = p2;
    return tmp;
}
/********************   EMul    ********************/
Exp make_EMul(Exp p1, Exp p2)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating EMul!\n");
        exit(1);
    }
    tmp->kind = is_EMul;
    tmp->u.emul_.exp_1 = p1;
    tmp->u.emul_.exp_2 = p2;
    return tmp;
}
/********************   EDiv    ********************/
Exp make_EDiv(Exp p1, Exp p2)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating EDiv!\n");
        exit(1);
    }
    tmp->kind = is_EDiv;
    tmp->u.ediv_.exp_1 = p1;
    tmp->u.ediv_.exp_2 = p2;
    return tmp;
}
/********************   EInt    ********************/
Exp make_EInt(Integer p1)
{
    Exp tmp = (Exp) malloc(sizeof(*tmp));
    if (!tmp)
    {
        fprintf(stderr, "Error: out of memory when allocating EInt!\n");
        exit(1);
    }
    tmp->kind = is_EInt;
    tmp->u.eint_.integer_ = p1;
    return tmp;
}
