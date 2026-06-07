#define STACK_SIZE 5
int stack_table[STACK_SIZE] = { 0 };
int stack_index = 0;
int front_index_2 = 0;
int count = 0;
int isStackEmpty(void)
{
    return (count == 0) ? 1 : 0;
}

int isStackFull(void)
{
    return (count == (STACK_SIZE)) ? 1 : 0;
}


int Pop(void)
{
    if (!isStackEmpty())
    {
        int temp = stack_table[front_index_2];;
        front_index_2 = (front_index_2 +1) % STACK_SIZE;
        count--;

        return temp;
    }

    return stack_table[0];
}
int Front(void)
{
    if (!isStackEmpty())
    {
        int temp = stack_table[front_index_2];
        return temp;
    }

    return stack_table[0];
}

void Push(int val)
{
    if (!isStackFull())
    {
        stack_table[stack_index] = val;
        stack_index = (stack_index +1) % STACK_SIZE;
        count++;
    }
}