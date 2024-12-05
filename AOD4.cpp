///--------------------------AOD 4-----------------------

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//pair <pair<int,int>,char> rcd
struct WordPositionFormat {
    int row;
    int col;
    string dir;
};

string dir_string(int dr,int dc){
    if (dr == 0 && dc == 1) return "Right";
    if (dr == 1 && dc == 0) return "Down";
    if (dr == 0 && dc == -1) return "Left";
    if (dr == -1 && dc == 0) return "Up";
    if (dr == 1 && dc == 1) return "Down-right";
    if (dr == -1 && dc == -1) return "Up-left";
    if (dr == 1 && dc == -1) return "Down-left";
    if (dr == -1 && dc == 1) return "Up-right";
    return "Unknown";
}

void search (const vector<vector<char>> & grid, const string& word, const vector<WordPositionFormat>& found_positions){
    int rows=grid.size();
    int cols=grid[0].size();
    int word_len= word.size();
    vector<pair<int, int>> directions = {
        {0, 1},   // Right
        {1, 0},   // Down
        {0, -1},  // Left
        {-1, 0},  // Up
        {1, 1},   // Down-right (diagonal)
        {-1, -1}, // Up-left (diagonal)
        {1, -1},  // Down-left (diagonal)
        {-1, 1}   // Up-right (diagonal)
    };
    int cnt=0;

    for (int r=0;r<rows;r++){
        for(int c =0; c<cols ; c++){
            for(const auto& dir:directions ){
                int dr=dir.first;
                int dc=dir.second;
                int k=0, nr=r, nc=c;
                while( k<word_len&& nr>=0&& nr<rows && nc>=0 && nc<cols && grid[nr][nc]==word[k]){
                    k++;
                    nr+=dr;
                    nc+=dc;
                }
                if (k==word_len) cnt++;
            }
        }
    }
    cout<< cnt;
}


int main(){
    string word="XMAS";
    vector<vector<char>> grid ;
    vector <WordPositionFormat> found_positions;
    //string input;
   // getline (cin, input);
   //stringstream ss(input);
    string row;

    while(getline(cin,row)){
        vector <char> grid_row(row.begin(),row.end());
        grid.push_back(grid_row);
    }

    search(grid, word, found_positions);
    

}
