#include "Compiler.h"
#include <assert.h>
#include <stdio.h>

void compile(Exp _p_)
{
    switch(_p_->kind) {
        case is_EAdd:
        case is_ESub:
        case is_EMul:
        case is_EDiv:
            compile(_p_->u.eadd_.exp_1);
            compile(_p_->u.eadd_.exp_2);
        default:
            break;
    }
    switch(_p_->kind) {
        case is_EAdd:
            printf("+");
            break;
        case is_ESub:
            printf("-");
            break;
        case is_EMul:
            printf("*");
            break;
        case is_EDiv:
            printf("/");
            break;
        case is_EInt:
            for (int a = _p_->u.eint_.integer_; a; a /= 9) {
                compile(_p_);
                printf("9+");
            }
            break;
        default:
            assert(0);
    }
}
