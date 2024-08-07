class Solution {
public:
    string numberToWords(long long num) {
        if (num == 0) {
            return "Zero";
        }
        return convertToWords(num);
    }

private:
    string one[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string ten[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string thousand[4] = {"", "Thousand", "Million", "Billion"};

    string convertToWords(long long num) {
        if (num == 0) {
            return "";
        }
        string res = "";
        int i = 0;
        while (num > 0) {
            if (num % 1000 != 0) {
                string segment = numberToWordsHelper(num % 1000);
                res = segment + (thousand[i].empty() ? "" : " " + thousand[i]) + (res.empty() ? "" : " " + res);
            }
            num /= 1000;
            i++;
        }
        return res;
    }

    string numberToWordsHelper(int num) {
        if (num == 0) {
            return "";
        }
        if (num < 20) {
            return one[num];
        } else if (num < 100) {
            return ten[num / 10] + (num % 10 ? " " + one[num % 10] : "");
        } else if (num < 1000) {
            return one[num / 100] + " Hundred" + (num % 100 ? " " + numberToWordsHelper(num % 100) : "");
        }
        return "";
    }
};