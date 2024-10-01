class Solution {
    public String solution(String s) {
        String answer = "";
        String tmp[] = s.split(" ");
        int min ,max, n;
        n = Integer.parseInt(tmp[0]);
        min = n;
        max = n;
        for(var i=0;i<tmp.length;i++)
        {
            n = Integer.parseInt(tmp[i]);
            if(min > n) min = n;
            if(max < n) max = n;
        }
        return min + " " + max;
    }
}