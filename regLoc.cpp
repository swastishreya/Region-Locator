#include <bits/stdc++.h>
using namespace std;

typedef struct Strip{
    double left_x, right_x;
    vector<double> y_coordinates;
    map<pair<double,double>,string> y_map;

    void assign(double x1, double x2){
        left_x = x1;
        right_x = x2;
    }

    void addRegion(double y1, double y2, string reg){
        y_map.insert(make_pair(make_pair(y1,y2),reg));
        y_coordinates.push_back(y1);
        y_coordinates.push_back(y2);
    }

    string findRegion(double y){
        double l = 0, r = y_coordinates.size();

        while(l < r){
            double mid = (l+r)/2;
            if(y_coordinates[mid] < y && y < y_coordinates[mid+1]){
                return y_map[make_pair(y_coordinates[mid],y_coordinates[mid+1])];
            }
            else if(y_coordinates[mid] > y && y_coordinates[mid+1] > y){
                r = mid;
            }
            else{
                l = mid;
            }
        }
    }

} strip;

map<pair<double,double>,strip> plane;
vector<double> x_coordinates;

strip findStrip(double x){
    double l = 0, r = x_coordinates.size();

    while(l < r){
        double mid = (l+r)/2;
        if(x_coordinates[mid] < x && x < x_coordinates[mid+1]){
            return plane[make_pair(x_coordinates[mid],x_coordinates[mid+1])];
        }
        else if(x_coordinates[mid] > x && x_coordinates[mid+1] > x){
            r = mid;
        }
        else{
            l = mid;
        }
    }

}

int main(){
    double n, q;
    cin >> n >> q;

    while(n--){
        double x1, x2, num_of_reg;
        cin >> x1 >> x2 >> num_of_reg;
        strip s;
        s.assign(x1,x2);
        x_coordinates.push_back(x1);
        x_coordinates.push_back(x2);
        while(num_of_reg--){
            double y1, y2;
            string reg;
            cin >> y1 >> y2 >> reg;
            s.addRegion(y1,y2,reg);
        }
        plane.insert(make_pair(make_pair(x1,x2),s));
    }

    while(q--){
        double x,y;
        cin >> x >> y;
        strip s1 = findStrip(x);
        cout << "Point (" << x << "," << y << ") lies in the region: " << s1.findRegion(y) << endl;
    }
    return 0;
}