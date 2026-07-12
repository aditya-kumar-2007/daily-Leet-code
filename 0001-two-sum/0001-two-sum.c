#include <stdlib.h>

#define SIZE 20011

typedef struct Node
{
    int key;
    int index;
    struct Node *next;
} Node;

Node *table[SIZE];

int hash(int key)
{
    if (key < 0)
        key = -key;
    return key % SIZE;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    for (int i = 0; i < SIZE; i++)
        table[i] = NULL;

    *returnSize = 2;
    int *ans = (int *)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        int need = target - nums[i];
        int h = hash(need);

        Node *cur = table[h];
        while (cur)
        {
            if (cur->key == need)
            {
                ans[0] = cur->index;
                ans[1] = i;
                return ans;
            }
            cur = cur->next;
        }

        h = hash(nums[i]);
        Node *node = (Node *)malloc(sizeof(Node));
        node->key = nums[i];
        node->index = i;
        node->next = table[h];
        table[h] = node;
    }

    return ans;
}