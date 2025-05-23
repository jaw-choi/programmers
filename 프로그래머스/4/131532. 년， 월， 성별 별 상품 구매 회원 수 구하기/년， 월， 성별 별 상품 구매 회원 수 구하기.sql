-- 코드를 입력하세요
SELECT YEAR(SALES_DATE) YEAR
        ,MONTH(SALES_DATE) MONTH 
        ,GENDER
        ,COUNT(DISTINCT O.USER_ID) USERS
FROM ONLINE_SALE O
JOIN USER_INFO U ON O.USER_ID = U.USER_ID
WHERE GENDER IS NOT NULL
GROUP BY YEAR,MONTH,GENDER
ORDER BY YEAR,MONTH,GENDER

