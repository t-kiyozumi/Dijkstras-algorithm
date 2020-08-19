#include <stdio.h>
class node_pair_state
{
public:
    int node1;
    int node2;
    int cost;
};

class map_state
{
public:
    int Npath;
    int Nnode;
    node_pair_state nodepair[10];
};

int main()
{
    int i;
    map_state map;
    FILE *nodePath;
    nodePath = fopen("example_NodePath.txt", "r");
    fscanf(nodePath, "%d %d", &(map.Npath), &(map.Nnode));
    node_pair_state cost_table[map.Nnode*map.Nnode];


    for (i = 0; i < map.Npath; i++)
    {
        fscanf(nodePath, "%d %d %d", &(map.nodepair[i].node1), &(map.nodepair[i].node2), &(map.nodepair[i].cost));
    }
    /////マップデータの表示////////
    printf("--------MAP_DATA-------------\n");
    printf("%d %d\n", map.Npath, map.Nnode);
    for (i = 0; i < map.Npath; i++)
    {
        printf("%d %d %d\n", map.nodepair[i].node1, map.nodepair[i].node2, map.nodepair[i].cost);
    }

    return 0;
}
