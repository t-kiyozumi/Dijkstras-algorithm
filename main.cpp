#include <stdio.h>
#define INF 99999
#define SIZE 1000
class node_state
{
public:
    int confirmed = 0;
};

class route_state
{
public:
    int start = 0;          //スタートのノード
    int goal = 4;           //ゴールのノード
    int to_node_cost[SIZE]; //各ノードまでのコスト
    int via[SIZE];          //経由するノード
};

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
    int i, j;

    ////マップの定義///////////
    map_state map;
    FILE *nodePath;
    nodePath = fopen("example_NodePath.txt", "r");
    fscanf(nodePath, "%d %d", &(map.Npath), &(map.Nnode));

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

    //各ノードの状態を記録する変数
    //確定済みかそうでないかをintで記録
    node_state node[map.Nnode];

    //ルートを記録するクラス変数
    route_state route;

    //コスト表の作成//
    //要素番号がノード番号に対応中身がそのコスト
    int cost_node2node[map.Nnode][map.Nnode];

    /*各変数の初期化*/
    //ルートの初期化
    for (i = 0; i < SIZE; i++)
    {
        route.to_node_cost[i] = INF;
        route.via[i] = -1;
    }

    //コスト表の初期化
    for (i = 0; i < map.Nnode; i++)
    {
        for (j = 0; j < map.Nnode; j++)
        {
            cost_node2node[i][j] = INF;
        }
    }
    //コスト表を更新
    for (i = 0; i < map.Npath; i++)
    {
        printf("%d %d %d\n", map.nodepair[i].node1, map.nodepair[i].node2, map.nodepair[i].cost);
        cost_node2node[map.nodepair[i].node1][map.nodepair[i].node2] = map.nodepair[i].cost;
    }
    //スタートとゴールを設定
    printf("please input the startNodeNo and goalNodeNo\n");
    printf("start:");
    scanf("%d,\n", &route.start);
    printf("goal:");
    scanf("%d,\n", &route.goal);

    //----------------以下ダイクストラ法のアルゴリズム----------------
    int min, target;
    int neighbor;

    route.to_node_cost[route.start] = 0;

    while (1)
    {
        //未確定ノードより最も距離のコストの小さいものを選んで確定する
        min = INF;
        for (i = 0; i < map.Nnode; i++)
        {
            if (!node[i].confirmed && min > route.to_node_cost[i])
            {
                min = route.to_node_cost[i];
                target = i;
            }
        }

        //全ての地点において最短経路が確定される
        if (target == route.goal)
        {
            // return route.to_node_cost[route.goal];
            break;
        }

        //今確定した場所から直交できる
        for (neighbor = 0; neighbor < map.Nnode; neighbor++)
        {
            if (route.to_node_cost[neighbor] > cost_node2node[target][neighbor] + route.to_node_cost[target])
            {
                route.to_node_cost[neighbor] = cost_node2node[target][neighbor] + route.to_node_cost[target];
                route.via[neighbor] = target;
            }
        }
        node[target].confirmed = 1;
    }
    //結果表示
    printf("totalcost:%d\n", route.to_node_cost[route.goal]);
    int Rnode = route.goal;
    printf("%d", Rnode);
    while (1)
    {
        Rnode = route.via[Rnode];
        printf(" -> %d", Rnode);
        if (Rnode == route.start)
        {
            break;
        }
    }

    return 0;
}
