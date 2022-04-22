#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int edges[200][200];    
int dist[200];          
int visited[200];       

int dijkstra(int n, int m)
{
    for (int i = 1; i <= n; i++) {              
        int index = -1;                        
        dist[1] = 0;                            
        for (int j = 1; j <= n; j++) {          
            if (!visited[j] && (index == -1 || dist[j] < dist[index])) {                 
                index = j;
            }
        }

        visited[index] = 1;                     
        for (int j = 1; j <= n; j++) {
            if (dist[index] + edges[index][j] < dist[j]) { 
                dist[j] = dist[index] + edges[index][j];
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) {  //如果没有到n点的路径，则返回-1
        return -1;
    }
    return dist[n];
}

int main()
{
    memset(edges, 0x3f, sizeof(edges));
    int n, m;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int start, end, d;
        scanf("%d %d %d", &start, &end, &d);
        edges[start][end] = edges[start][end] > d ? d : edges[start][end];  
    }

    memset(dist, 0x3f, sizeof(dist));  
    memset(visited, 0, sizeof(visited)); // 初始化所有的点都没有被踢出
    printf("%d\n", dijkstra(n, m));
    return 0;
}
