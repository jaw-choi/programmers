function solution(s) {
    var answer = 0;
    var pm = 1;
    if(s[0]=='-')
        pm*=-1;
    for(var i=1;i<s.length;i++)
        {
            answer += s[i];
            answer*=10;
        }
    return s*1;
}