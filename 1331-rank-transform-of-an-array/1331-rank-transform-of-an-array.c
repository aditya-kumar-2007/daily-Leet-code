#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

typedef struct
{
    int key;
    int rank;
} Map;

int* arrayRankTransform(int* arr, int arrSize, int* returnSize)
{
    *returnSize = arrSize;

    if (arrSize == 0)
        return arr;

    int *temp = (int *)malloc(arrSize * sizeof(int));

    for (int i = 0; i < arrSize; i++)
        temp[i] = arr[i];

    qsort(temp, arrSize, sizeof(int), compare);

    Map *map = (Map *)malloc(arrSize * sizeof(Map));
    int count = 0, rank = 1;

    map[count].key = temp[0];
    map[count].rank = rank;
    count++;

    for (int i = 1; i < arrSize; i++)
    {
        if (temp[i] != temp[i - 1])
        {
            rank++;
            map[count].key = temp[i];
            map[count].rank = rank;
            count++;
        }
    }

    int *ans = (int *)malloc(arrSize * sizeof(int));

    for (int i = 0; i < arrSize; i++)
    {
        int l = 0, r = count - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (map[mid].key == arr[i])
            {
                ans[i] = map[mid].rank;
                break;
            }
            else if (map[mid].key < arr[i])
                l = mid + 1;
            else
                r = mid - 1;
        }
    }

    free(temp);
    free(map);

    return ans;
}