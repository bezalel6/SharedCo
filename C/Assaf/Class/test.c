int numOfNodes(List *lst)
{
    List *tl = lst;
    int counter = 0;
    while (tl->head)
    {
        counter++;
        tl->head = tl->head->next;
    }
    return counter;
}
void printNodes(List *lst)
{
    List *tl = lst;
    while (tl->head)
    {
        printf(“%d”, tl->head->data);
        tl = tl->head->next;
    }
}

void deleteNodes(List *lst)
{
    if (lst->head)
        deleteNodes(lst->head->next);
    free(lst->head);
}
