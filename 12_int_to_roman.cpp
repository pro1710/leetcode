// 12_int_to_roman.cpp

class Solution {
public:
    string intToRoman(int num) {
        string res = "";
        convert(res, num/1000, "M");
        num %= 1000;
        convert(res, num/100, "CDM");
        num %= 100;
        convert(res, num/10, "XLC");
        num %= 10;
        convert(res, num, "IVX");
        return res;
    }
    
    void convert(string& res, const int& num, const string& snum) {
        if (num == 0) return;
        // string res = "";
        switch (num) {
            case 3:
                res += snum[0];
            case 2:
                res += snum[0];
            case 1: 
                res += snum[0];
                break;
            case 4:
                res += snum[0];
                res += snum[1];
                break;
            case 8:
            case 7:
            case 6:
            case 5:
                res += snum[1];
                convert(res, num-5, snum);
                break;
            case 9:
                res += snum[0];
                res += snum[2];
            default:
                break;
        }
        // return res;
    }
    
};


