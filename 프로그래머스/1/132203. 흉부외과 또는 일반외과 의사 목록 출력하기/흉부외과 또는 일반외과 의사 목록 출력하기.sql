select DR_NAME, DR_ID, MCDP_CD,date_format(hire_ymd, '%Y-%m-%d') as HIRE_YMD
from doctor
where MCDP_CD= 'CS' or MCDP_CD= 'gs'
order by HIRE_YMD desc, DR_NAME asc