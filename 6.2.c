List Reverse(List L)
{
    if (L == NULL)//如果L为空或者L只有一个数则直接返回
    {
        return L;
    }
    else if (L->Next == NULL || L->Next->Next == NULL)
    {
        return L;
    }
        
    List p = L->Next;
    List q = p->Next;
    if (q->Next == NULL)
    {
        p->Next = NULL;
        q->Next = p;
        
    }else
    {
        List tmp = q->Next;//让tmp为第二个
        p->Next = NULL;//让原来的第一个成为最后一个
        while (tmp)
        {
            q->Next = p;//从第二个开始逆序插到p(第一个)的前面
            p = q;//让p为刚刚插入的
            q = tmp;//tmp为q->Next(也就是第x+1个),让q成为后一个
            tmp = tmp->Next;//让tmp向下一个,例如从第2个到第3个
        }
        q->Next = p;//
    }
    
    L->Next = q;//L头指针为空，因此直接让L->Next == q,因为List为指针类型，所以之前的L1也被修改
    return L;
}
