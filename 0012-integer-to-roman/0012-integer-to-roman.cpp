class Solution {
public:
    string intToRoman(int num) {
       
        vector<string> thousands = { "", "M", "MM", "MMM" };
        vector<string> hundreds = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
        vector<string> tens = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
        vector<string> units = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };

        string romanAns1 = ( thousands[num/1000] + hundreds[ (num%1000)/100 ] + tens[ (num%100)/10 ] + units[num%10]  );
        //return romanAns1;

        vector<string>roman = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
        vector<int>values = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string romanAns2 = "";
        for(int i=0; i<13; i++){

          
                int repTimes = num / values[i];
                while(repTimes){
                    romanAns2 += roman[i];
                    repTimes--;
                }

                num = num %  values[i];
           
        }

        return romanAns2;

    }
};