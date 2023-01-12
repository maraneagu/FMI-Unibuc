-- 1.
select s.s_last "Student sau curs", s.s_id "Cod", 'Student' as Tip
from student s
where s.f_id=(select f_id
              from faculty
              where upper(f_last)='BROWN')
union all
select c.course_name "Student sau curs", c.course_no "Cod", 'Curs' as Tip
from course c, course_section cs
where cs.f_id=(select f_id
               from faculty
               where upper(f_last)='BROWN');
               
-- 2.
select s_id, s_last
from student
where s_id in (select s_id
               from enrollment
               where c_sec_id in (select c_sec_id
                                  from course_section
                                  where course_no=(select course_no
                                              from course
                                              where course_name='Database Management'))) 
and s_id not in (select s_id
                 from enrollment
                 where c_sec_id in (select c_sec_id
                                    from course_section
                                    where course_no=(select course_no
                                                     from course
                                                     where course_name='Programming in C++')));
                                              
-- 3.
select s_last
from student
where s_id in (select s_id
               from enrollment
               where upper(grade)='C' or grade is null);
               
-- 4. 
select loc_id, bldg_code, capacity
from location
where capacity=(select max(capacity)
                from location);
                
-- 6.            
select f.f_id "cod profesor", f.f_last "nume profesor",
    case
        when f.f_id in (select s.f_id
                        from student s
                        where f.f_id=s.f_id)then 'Da'
        else 'Nu'
    end "student",
    case 
        when f.f_id in (select cs.f_id
                        from course_section cs
                        where f.f_id=cs.f_id)then 'Da'
        else 'Nu'
    end "curs"
from faculty f;

-- 7.
select t1.term_desc, t2.term_desc
from term t1, term t2
where substr(t1.term_desc,1,length(t1.term_desc)-1) = substr(t2.term_desc,1,length(t2.term_desc)-1)
and substr(t1.term_desc,length(t1.term_desc)-1) <> substr(t2.term_desc,length(t2.term_desc)-1);

--8.
select s.s_last, count(s.f_id)
                 from course_section cs
                 where cs.f_id=s.f_id
from student s;

--9.
select unique cs1.course_no, cs2.course_no
from course_section cs1
inner join (select * from course_section) cs2
on cs1.term_id = cs2.term_id
where cs1.course_no > cs2.course_no

--10.

--11.
select course_no 
from course_section cs
where (select count(1) from course
		where max_enrl < cs.max_enrl)=0;

--12.
select f_last,round((select avg(max_enrl)from course_section where f_id = f.f_id), 2) 
from faculty f;

select s.s_last
from student s, course_section cs1, course_section cs2
where substr(cs1.course_no,5,1) <> substr(cs2.course_no,5,1);

--13.
select f_last, A.cnt from faculty B, 
(select count(*) as cnt, f_id
from student group by f_id) A
where A.f_id = B.f_id and A.cnt>=3;

--14.
select max(l.capacity), c.course_name, l.loc_id
from location l, course c, course_section cs
where l.loc_id=cs.loc_id and c.course_no=cs.course_no
group by c.course_name,l.loc_id;

--15.
select round(avg(max_enrl),2) as "Medie"
from course_section join term using (term_id)
where term_desc like '%2007%';