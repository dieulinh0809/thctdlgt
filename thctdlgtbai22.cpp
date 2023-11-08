#include<bits/stdc++.h>
using namespace std ;
vector<int> adj[6]; //Khoi tao 1 mang vector chua cac dinh ke no
void themCanh(int u , int v ){
        adj[u].push_back(v);//Canh u them vao vector v-> u canh v
        adj[v].push_back(u);
}
void readG(){
        fstream file("dothi1.txt",ios::in); // 'file ' la doi tuong dai dien cho dothi1.tx`
        string line ;//Khai bao line kieu string <chuoi>
        while(getline(file,line)){ //
                int u , v;
                stringstream ss(line);//xu ly chuoi thanh so
                ss >> u ; //Phan tu dau tien la dinh
                while(ss >> v){ // v la cac dinh lan can
                        themCanh(u,v);
                }
        }
        file.close();
}
void DFS(int v,vector<int> &visited){
        visited[v]= 1;
        cout<<v<<" ";
//ds for each
//      for(int u : adj[v]){ // u duoc gan la 1 dinh lan can v
        for(int i =0 ;i< adj[v].size();i++){
                int u = adj[v][i];
                if(visited[u]==0){
                        DFS(u,visited);
                }
        }
        return ;
}
void dfs(int start)
{
    vector<int> visited(6, 0);
    DFS(start, visited);
}
void BFS(int v){
        vector<int> visited(6,0);
        queue<int> q;//khoi tao 1 hang doi
        q.push(v); //v duoc dua vao hang doi
        visited[v] = 1;
        cout<<v<<" ";
        while(!q.empty()){
                //xoa v khoi Q
                v = q.front();
                q.pop();
                for(int i=0 ;i< adj[v].size();i++){
                        int w = adj[v][i];
                        if(visited[w] == 0){
                                visited[w]=1;
                                cout<<w<<" ";
                                //them w vao q
                                q.push(w);

                        }
                }

        }

}
