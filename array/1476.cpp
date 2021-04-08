/* Author: Teng Li
 * Email: i@terrytengli.com
 * Date: 2020-10-23
 */

// solution:

// class SubrectangleQueries {

// vector<vector<int> > rect;

// public:
//     SubrectangleQueries(vector<vector<int> >& rectangle) {
//         rect = rectangle;
//     }
    
//     void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
//         for (; row1 <= row2; row1++)
//         {
//             for (int i = col1; i <= col2; i++)
//             {
//                 rect[row1][i] = newValue;
//             }
//         }
//     }
    
//     int getValue(int row, int col) {
//         return rect[row][col];
//     }
// };

//solution end

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */