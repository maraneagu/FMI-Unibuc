-- 2).
select Z, (
    select count(*)
    from rental
    where extract(day from book_date) = extract(day from Z)
    and extract(month from book_date) = extract(month from Z)) as NR
from (select trunc(last_day('01-OCT-2022')-rownum) Z
      from dual 
      connect by rownum < extract(day from last_day('01-OCT-2022')))
order by Z;

-- 3).
DECLARE
    rented_titles NUMBER(3) := 0;
    name VARCHAR(101) := '&nume';
BEGIN
    select count(title) into rented_titles
    from rental r 
    join member m on (r.member_id = m.member_id) 
    join title t on (t.title_id = r.title_id) 
    where lower(last_name) like '%'||lower(name)||'%' or lower(first_name) like '%'||lower(name)||'%' 
    and rownum = 1;
    dbms_output.put_line(name || ': '||rented_titles);
END;

-- 4).
DECLARE
    rented_titles NUMBER(3) := 0;
    titles NUMBER(3) := 0;
    procent NUMBER(3) := 0;
    name VARCHAR(101) := '&name';
BEGIN
    select count(title) into titles
    from title;
    
    select count(title_id) into rented_titles
    from rental r 
    join member m 
    using (member_id)
    where lower(last_name) like '%' || lower(name) || '%' or lower(first_name) like '%' || lower(name) || '%' 
    and rownum = 1;
    
    dbms_output.put_line(name || ': '||rented_titles);
    
    procent := (rented_titles / titles) * 100;
    if procent > 75 then
        dbms_output.put_line('Categoria 1');
    elsif procent > 50 then
        dbms_output.put_line('Categoria 2');
    elsif procent > 25 then
        dbms_output.put_line('Categoria 3');
    else
        dbms_output.put_line('Categoria 4');
    end if;
END;