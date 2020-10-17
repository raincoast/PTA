Polynomial Add(Polynomial a, Polynomial b)
{
    /*若其中一个多项式为空则直接返回另一个多项式*/
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    Polynomial c, d, tmp;
    c = (Polynomial)malloc(sizeof(Polynomial));//先创建一个空的头节点
    d = c;//保存头节点
    a = a->Next;
    b = b->Next;//两个多项式的头节点都是空节点
    while (a != NULL && b != NULL)
    {
        tmp = (Polynomial)malloc(sizeof(Polynomial));
        c->Next = tmp;//分配一个新的内存并将之前定义的新节点的下一个节点指向这里
        if (a->Exponent == b->Exponent)//合并相等指数的
        {
            tmp->Exponent = a->Exponent;//刚刚分配的节点中的指数等于a或b的便可以
            tmp->Coefficient = a->Coefficient + b->Coefficient;
            a = a->Next;
            b = b->Next;
            if (tmp->Coefficient == 0)
            {
                //如果系数相加为0了
                continue;//就进行下一个循环
            }
        }
        else if (a->Exponent > b->Exponent)//指数从大到小输出
        {
            tmp->Exponent = a->Exponent;//a的指数已经大于b的,那么a的这个节点的指数没有相应的b中节点指数与之对应
            tmp->Coefficient = a->Coefficient;
            a = a->Next;
        }
        else//这里就是b此时节点的指数>a此时节点的指数
        {
            tmp->Exponent = b->Exponent;
            tmp->Coefficient = b->Coefficient;
            b = b->Next;
        }
        c = tmp;//让c 为成为c的下一个节点即为c->next(tmp为c->next);
        tmp = tmp->Next;//让tmp到下一个节点,可以换成清除tmp重新来过;

    }
    if (a != NULL)
    {
        //如果b的所有节点都已经循环完了而a的没有循环完
        //可以稍微修改一下while循环中间换成||来精简代码
        c->Next = a;
    }
    else
    {
        c->Next = b;
    }
    return d;
}
