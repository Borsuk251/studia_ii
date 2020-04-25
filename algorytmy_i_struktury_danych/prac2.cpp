#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>

#include <time.h>

using namespace std;

double up_limit_perimeter = 10e8; //10e8
double max_box_size = 10e7;

double main_loop;
clock_t a1, b1;
double tmp;

//operujemy na intach
struct point{
  int x, y;
  point();
  point(int x, int y) : x(x), y(y) {};
};

vector<point> candidate;
vector<point> box_line;
double res = up_limit_perimeter;
//custom comparators for sorting
struct compare_by_x{
  bool operator()( point &p,  point &q){
    if(p.x != q.x){
      if(p.x > q.x)
        return true;
      return false;
    }
    if(p.y > q.y)
      return true;
    return false;
  }
}comparatorX;

struct compare_by_y{
  bool operator()( point &p,  point &q){
    if(p.y != q.y){
      if(p.y > q.y)
        return true;
      return false;
    }
    if(p.x > q.x)
      return true;
    return false;
  }
}comparatorY;

//long long zeby sie nie psulo
double length( point &p, point &q){
  return sqrt((long long)(p.x-q.x) * (long long)(p.x-q.x)
              + (long long)(p.y-q.y) * (long long)(p.y-q.y));
}

double perimeter( point &p, point &q, point &r){
  return length(p,q) + length(q,r) + length(r,p);
}

point middle_point(point &p, point &q){
  return point((p.x+q.x)/2, (p.y+q.y)/2);
}


double search(int n, point sorted_X[],  vector<point> &sorted_Y){

  if(n<3) return up_limit_perimeter;

  int left_size, right_size;
  left_size = n/2; right_size = n - left_size;
  vector<point> left_points_Y;
  vector<point> right_points_Y;
  left_points_Y.reserve(left_size);
  right_points_Y.reserve(right_size);

  point middle_p = middle_point(sorted_X[left_size-1], sorted_X[left_size]);

  for(int i=0; i<n; i++){
    if(comparatorX(sorted_Y[i], sorted_X[left_size]))
      left_points_Y.push_back(sorted_Y[i]);
    else
      right_points_Y.push_back(sorted_Y[i]);
  }

  res = min(res, search(left_size, sorted_X, left_points_Y));
  res = min(res, search(right_size, sorted_X+left_size, right_points_Y));

  box_line.clear();
  box_line.reserve(n);
  int box_size;
  if(res > max_box_size/2) box_size = max_box_size;
  else box_size = int(res/2+1);

  int begin = 0; //indeks poczatku boxa

  for(int i=0; i<sorted_Y.size(); i++){

    point p = sorted_Y[i];

    if(abs(p.x - middle_p.x) > box_size + 1) continue;
     while(begin < box_line.size() &&
           -p.y + box_line[begin].y > box_size + 1) begin++;

    for(int i=begin;i<box_line.size(); i++){
      if((box_line[i].x-middle_p.x)*(box_line[i+1].x-middle_p.x)<0) i++;

      for(int k=i+1; k<box_line.size(); k++){
        tmp = perimeter(p, box_line[i], box_line[k]);
        if(tmp < res){
          res=tmp;
          candidate.clear();
          candidate.push_back(p);
          candidate.push_back(box_line[i]);
          candidate.push_back(box_line[k]);
        }
      }
    }box_line.push_back(p);
  }

  return res;
}

void search_points(vector<point> &sorted_X, int n){

  candidate.reserve(3);
  vector<point> sorted_Y;
  sorted_Y.reserve(n);
  sort(sorted_X.begin(), sorted_X.end(), comparatorY);
  sorted_Y = sorted_X;
  sort(sorted_X.begin(), sorted_X.end(), comparatorX);
  search(sorted_X.size(), &sorted_X[0], sorted_Y);
  for(int i=0; i<3; i++){
    printf("%d %d\n", candidate[i].x, candidate[i].y);
  }
}


int main(){
  clock_t s1, e1;
  
  int n;
  scanf("%d", &n); //ile puktow
  vector<point> points; //vector pkt
  points.reserve(n); //rezerwujemy pamiec
  box_line.reserve(n);
  for(int i=0; i<n; i++){
    int x,y; scanf("%d %d", &x, &y); //wczytywanie
    points.push_back(point(x,y));
  }
  s1 = clock();
  search_points(points, n); //obliczanie wyniku
  e1 = clock();

  double time_taken = double(e1 - s1) / double(CLOCKS_PER_SEC);
  printf("\n%lf\n", time_taken );

}
