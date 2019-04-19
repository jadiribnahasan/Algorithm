#include<bits/stdc++.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<utility>
#include<algorithm>
#define mytype string
#define INF 100000

using namespace std;

struct node
{
    mytype vertex;
    int weight;
    struct node *next;
};

struct edge
{
    mytype u , v;
    int weight;
};

int n;
vector < mytype > v;


bool sortbyweight(edge a , edge b){
    return a.weight<b.weight;
}

map < mytype , mytype > par;

void make_set(mytype node){
    par.insert(pair<mytype,mytype>(node,node));
}

mytype find_set(mytype n){
    if(par[n] == n){
        return n;
    }
    par[n] = find_set(par[n]);
    return par[n];
}

void union_set(mytype a , mytype b){
    mytype u = find_set(a);
    mytype v = find_set(b);
    par[u] = v;
}

vector < edge > taken;
vector < edge > edges;

void Kruskals_MST(map<mytype , node* > ver){


    for(int i = 0 ; i < n ; i++){
        struct node* t = ver[v[i]];
        t = t->next;
        while(t != NULL){
            edge e;
            e.u = v[i];
            e.v = t->vertex;
            e.weight = t->weight;
            edges.push_back(e);
            t = t->next;
        }

    }
    sort(edges.begin() , edges.end() , sortbyweight);
    vector < edge >::iterator it;

    for(int i = 0 ; i < n ; i++){
        make_set(v[i]);
    }
    for(it = edges.begin() ; it != edges.end() ; it++){
        edge e = *it;
        //cout << it-> u << " ->" << it->v << "( " << it->weight << ")" << endl;
        mytype u = find_set(it->u);
        mytype v = find_set(it->v);
        if(u != v){
            union_set(u , v);
            edge e;
            e.u = it-> u;
            e.v = it-> v;
            e.weight = it->weight;
            taken.push_back(e);
        }
    }

    int sum = 0;
    for(int i = 0 ; i < taken.size() ; i++){
        edge e = taken[i];
        cout << e.u << " -> " << e.v << endl;
        sum += e.weight;
    }
    cout << "Cost : " << sum << endl;
}

vector < vector < edge > > t;

int K(map<mytype , node* > ver , edge ek){

    par.clear();
    vector < edge > tt;
    for(int i = 0 ; i < n ; i++){
        make_set(v[i]);
    }
    vector < edge >::iterator it;
    for(it = edges.begin() ; it != edges.end() ; it++){
        edge e = *it;

        //cout << e.u;

        if((e.u == ek.u && e.v == ek.v) || (e.u == ek.v && e.v == ek.u)){
        }
        else{
            mytype u = find_set(it->u);
            mytype v = find_set(it->v);
            if(u != v){
                union_set(u , v);
                edge x;
                x.u = it-> u;
                x.v = it-> v;
                x.weight = it->weight;
                tt.push_back(e);
            }
        }
    }

    t.push_back(tt);
    int sum = 0;
    for(int i = 0 ; i < tt.size() ; i++){
        edge e = tt[i];
        sum += e.weight;
    }
    if(tt.size() == n-1){
        return sum;
    }
    else{
        return 10000000;
    }
}


int main()
{
    cout << "Nodes ? " << endl;
    cin >> n;

    map<mytype , node* > ver;


    cout << "Enter " << n << " vertices : " << endl;
    for(int i = 0 ; i < n ; i++){
        mytype x;
        cin >> x;
        v.push_back(x);
    }


    for(int i = 0 ; i < n ; i++){
        cout << "Enter number of Adjacence node of " << v[i] << " : \n";
        int e;
        cin >> e;
        node *head = new node();
        head->vertex = v[i];
        head->next = NULL;
        node *current = head;
        cout << "Enter Adjacence nodes of " << v[i] << " : \n";
        for(int j = 0 ; j < e ; j++){
            mytype val;
            cin >> val;
            cout << "Enter weight of " << v[i] << " -> " << val << " :\n";
            int w;
            cin >> w;
            node *neww = new node();
            neww->vertex = val;
            neww->weight = w;
            current->next = neww;
            neww->next = NULL;
            current = neww;
        }
        ver.insert(pair < mytype , node* >(v[i] , head));

    }

    cout << "\n(Kruskal's) Edges of Minimum Spanning tree : \n";
    Kruskals_MST(ver);



    int ans = 100000;
    for(int i = 0 ; i < taken.size() ; i++){
        edge e = taken[i];
        ans = min(ans , K(ver , e));
    }
    cout << "2nd Best : " <<  ans << endl;


}

