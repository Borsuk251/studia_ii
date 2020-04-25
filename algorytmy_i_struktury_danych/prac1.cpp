#include <iostream>
#include <vector>
#include <math.h>
#include <stack>
#include <time.h>

using namespace std;


void revStack(vector<vector<int> > &vec, stack<int> s){
    stack<int> temp;
    while (s.empty() == false){
        temp.push(s.top());
        s.pop();
    }
    while (temp.empty() == false){
        int b = temp.top();
        printf("%d %d %d\n", vec[b][0], vec[b][1], vec[b][2]);
        temp.pop();
    }
}


int find_zero(vector<vector<int> > &vec, int start, int n_rows){
    int search = start;
    while(vec[search][0] != 0){
        search++;
        if(search == n_rows)    search = 0;
        if(search == start) return -1;
    }
    return search;
}

int dfs( vector<vector<int> > &vec, stack<int> &chodnik, vector<int> visited, int n_rows){
    int current = find_zero(vec, 0, n_rows); //pierwsze zero
    chodnik.push(current);//pierwsze zero na stos
    int zero_pos = current;
    int next = current;
    while(vec[current][2] != 0){

        if(vec[next][2] == 0 && chodnik.size()>1){//returnowanie
            if(vec[next][0] == vec[current][0]){
                chodnik.pop();
                chodnik.push(next);
                return 1;
            }
        }

        if(current == n_rows) return -1;
        if(next != current){
            if(next<n_rows){ //do dopisania gdy przeskoczy zakres
                if(vec[current][2] != vec[next][0] ){
                next++; // sprawdzamy kolejny
                if(next == n_rows) next = 0;
                }
            }
            else{
                if(next>=n_rows) next = 0;
            }
        }
        if(next == current){
            int temp = chodnik.top();
            current = temp + 1;//bierzemy kolejny current
            if(current<n_rows) visited[current] = 0;
            int poped = temp;
            chodnik.pop();
            if(!chodnik.empty()){
                current = chodnik.top();
                next = poped + 1;
                if(next >= n_rows)
                    next = current + 1;
            }
            if(chodnik.empty()){
                if(zero_pos == n_rows-1) return -1;
                current = find_zero(vec, zero_pos+1, n_rows);
                if(current == -1)
                    return -1;
                chodnik.push(current);
                next = current + 1;
            }
        }

        if(vec[current][2] == vec[next][0]){ //gdy znajdzie dobrego
            if(visited[next] == 0){
                chodnik.push(next);
                visited[next] = 1;
                current = next; //przesuwamy sie do kolejnego
                next++;
            }
            else next++;
        }
    }
    if(vec[current][2] == 0){
        return 1;
    }
    return -1; //gdy sie nie uda
}


int main(){

 //clock_t start, end, s1, e1;
 //start = clock();

  int row;

  stack<int> chodnik;
  scanf("%d", &row );
  vector<vector<int> > vec(row); //2d array
  vector <int> visited(row);
  for (int i = 0; i < row; i++) {
      vec[i] = vector<int>(3);
      for (int j = 0; j < 3; j++)
          scanf("%d", &vec[i][j]);
  }
  for(unsigned long i=0; i<visited.size(); i++){
      visited[i] = 0;
  }



    int a = dfs(vec, chodnik, visited, row);
    if (a == -1)
        printf("BRAK\n");
    else{
        printf("%lu\n", chodnik.size());
        //s1 = clock();
        revStack(vec, chodnik);
        //e1 = clock();
    }
    //end = clock();
/*
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);

    time_taken = double(e1 - s1) / double(CLOCKS_PER_SEC);
 
    //printf("%ld\n", time_taken);
*/


  return 0;
}
