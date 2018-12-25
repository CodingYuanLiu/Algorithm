#include <iostream>
#include <vector>
using namespace std;

class point{
    public:
        int rank;
        int name;
        point *parent;
    point(int n)
    {
        name = n;
        rank = 0;
        parent = NULL;
    }
};

void Union(point *x, point *y);
point* Find(point *x);

int main()
{
    point* points[10];
    point *findresult;
    for (int i = 0; i < 10;i++)
    {
        point *p = new point(i);
        points[i] = p;
    }
    Union(points[1], points[2]);
    Union(points[3], points[4]);
    Union(points[1], points[3]);
    Union(points[5], points[6]);
    Union(points[7], points[8]);
    Union(points[5], points[7]);
    Union(points[8], points[9]);
    findresult = Find(points[5]);
    cout << findresult->name<<endl;
}

void Union(point *u,point *v)
{
    point *x = Find(u);
    point *y = Find(v);
    if(x->rank <= y->rank)
    {
        x->parent = y;
        if(x->rank == y->rank)
        {
            y->rank++;
        }
    }
    
    else
    {
        y->parent = x;
    }
    
}

point* Find(point *x)
{
    point *y = x;
    point* root;
    while(y->parent)
    {
        y = y->parent;
    }
    root = y;
    y = x;
    point *w;
    while(y->parent)
    {
        w = y->parent;
        y->parent = root;
        y = w;
    }
    return root;
}