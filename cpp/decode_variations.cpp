class Solution {
public:
    int numDecodings(string S){
        // your code goes here 1262
        int first = 1, second = 1;
        int pre = 27, cur = 0;
        for(auto it = S.rbegin(); it != S.rend(); ++it) {
          int d = *it - '0';
          if(d == 0) 
            cur = 0;
          else {
            cur = first;
            if(d* 10 + pre < 27)
              cur += second;
          }
          pre = d;
          second = first;
          first = cur;
        }
        return cur;
    }
};
