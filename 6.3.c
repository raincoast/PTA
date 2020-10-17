void list_append(List* list, int value)//给我传递了list的地址，在这里的操作会改变指针指向的节点，所以需要一个tail来保存一些东西
{
    Node* p = (Node*)malloc(sizeof(Node));//分配内存
    p->value = value;
    p->next = NULL;
    if (list->head == NULL)//如果list->head为空,则直接让list->head = p;
    {
        list->head = p;
    }
    if (list->tail)//如果list->tail不为空 tail与head独立，用tail来保存上一个节点的位置，若是用head存储的话则无法保存获取到第一个的地址，这样无法从一个开始输出
    {
        list->tail->next = p;//让tail的下一个节点为p
        p->prev = list->tail;//让p的前一个节点为tail的地址
    }
    list->tail = p;//让tail也为p
    
}
void list_remove(List* list, int value)
{
    Node* p = list->head;//先找到头节点
    Node* k;
    while (p)//遍历链表
    {
        if (p->value == value)//如果找到了要删除的节点
        {
            if (p->next)//节点不在最后,即p->next!=NULL
            {
                
                    if (p == list->head)//若p为链表头节点
                    {
                        list->head->next->prev = NULL;//将下一个节点的指向前一个节点的指针置为NULL
                        list->head = list->head->next;//让头节点指向下一个
                        k = p;//记录要被删除的节点的地址
                        p = k->next;//让p成为要被删除的节点的后一个
                        k->next = NULL;
                        k->prev = NULL;
                        /*将要被删除的节点指向前后的指针都置为空*/
                        free(k);//释放要被删除的节点空间
                    }
                    else {//要被删除的节点不为链表头节点
                        p->next->prev = p->prev;//让p下一个节点指向前一个节点的指针指向p指向前一个节点的指针
                        p->prev->next = p->next;//让p前一个节点指向下一个节点的指针指向p指向的后一个节点的指针
                        k = p;//记录要被删除的节点的地址
                        p = k->next;//让p为要删除的节点的下一个节点,也就是让p到下一个节点
                        k->next = NULL;
                        k->prev = NULL;//清除掉要被删除节点指向前一个和后一个节点的指针
                        free(k);//释放掉要被删除的节点的地址

                    }
                
            }
            else {//如果节点在最后
                p->prev->next = NULL;//直接让p前一个节点指向下一个节点的指针为NULL
                p->prev = NULL;//清除当前要被删除节点指向的下一个节点的指针,
                free(p);//都释放了p完全不需要上一个操作
            }
        }
        else
        {
            p = p->next;//让p到下一个
        }

    }
}
