#include <iostream>
#include <array>

using namespace std;


uint32_t counter=3;
std::array<std::array<uint32_t,512>,512> matrix;

void tile(uint32_t n, uint32_t x, uint32_t y, uint32_t hole_x, uint32_t hole_y) {

    if(n==2){
        for (uint8_t i = 0; i < 2; ++i) {
            for (uint8_t j = 0; j < 2; ++j) {
                if(x+i !=hole_x || y+j !=hole_y) matrix[x+i][y+j] = counter++/3;
            }
        }
        return;
    }
    for(uint8_t i = 0; i < 2; ++i){
        for(uint8_t j = 0; j < 2; ++j){
            if(x + i*n/2 <= hole_x && hole_x < x + (i+1)*n/2 && y + j*n/2 <= hole_y && hole_y < y + (j+1)*n/2) tile(n/2, x + i*n/2, y + j*n/2, hole_x, hole_y);
            else tile(n/2, x + i*n/2, y + j*n/2, x + n/2 - 1 + i, y + n/2 - 1 + j);
        }
    }
    for(uint8_t i = 0; i < 2; ++i){
        for(uint8_t j = 0; j < 2; ++j) {
            if(x + i*n/2 > hole_x || hole_x >= x + (i+1)*n/2 || y + j*n/2 > hole_y || hole_y >= y + (j+1)*n/2) matrix[x+n/2-1+i][y+n/2-1+j] = counter++/3;
        }
    }
}


int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    std::uint32_t n,x,y;
    cin>>n;
    cin>>x>>y;

    tile(1<<n, 0, 0, --x, --y);
    for(uint32_t i = 0; i < 1<<n; ++i)
    {
        for(uint32_t j = 0; j < 1<<n; ++j) {
            cout<<matrix[i][j]<<"\t";
        }
        cout<<"\n";
    }
    return 0;
}
