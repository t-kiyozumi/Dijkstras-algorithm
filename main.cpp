#include <stdio.h>
class
{
private:
    /* data */
public:
    int Npath;
    int Nnode;
};

class path
{
public:
    int No;
    int cost;
    int node1;
    int node2;
};

int main()
{
    FILE *nodePath;
    nodePath = fopen("example_NodePath.txt", "r");

    // while (fscanf(nodePath, "%s %f %f %f %f %f", str, &f1, &f2, &f3, &f4, &f5) != EOF)
    // {
    //     printf("%s %.1f %.1f %.1f %.1f %.1f\n", str, f1, f2, f3, f4, f5);
    // }
}
