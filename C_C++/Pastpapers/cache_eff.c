typedef struct point
{
    double x, y, z;
} Point;
int find_max_x_argument(int n, Point *elems)
{
    double max = 0;
    int max_index = 0;
    for (int i = 0; i < n; i++)
        if (max < elems[i].x)
        {
            max_index = i;
            max = elems[i].x;
        }
    return max_index;
}