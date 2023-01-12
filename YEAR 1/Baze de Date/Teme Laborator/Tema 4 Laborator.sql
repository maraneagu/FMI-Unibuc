--1.
select s_last, s_first
from student
where s_id not in (select s.s_id
                   from student s, enrollment e
                   where s.s_id = e.s_id
                   and e.grade is null);

--2.
select distinct f.f_first
from faculty f, course_section c, location l
where (f.f_id=c.f_id and c.max_enrl=(select max(max_enrl)
                                    from course_section)) or 
      (f.loc_id=l.loc_id and l.capacity=(select max(capacity)
                                         from location));

--3.
with CAPACITATE_MAXIMA as (select avg(l.capacity) as CAPACITATE
                           from location l
                           join faculty f on l.loc_id = f.loc_id
                           where upper(f.f_last) = 'MARX' and upper(f.f_first) = 'TERESA'),
NUMAR_LOCURI as (select avg(c.max_enrl) as NUMAR
                 from course_section c
                 join enrollment e on c.c_sec_id = e.c_sec_id
                 join student s on e.s_id = s.s_id
                 where upper(s.s_last) = 'JONES' and upper(s.s_first) = 'TAMMY')
                     
select (CAPACITATE + NUMAR)/2 as MEDIE
from CAPACITATE_MAXIMA, NUMAR_LOCURI;

--4.
select course_no, course_name
from course
where (upper(course_name) like '%JAVA%') or 
      (course_no not in (select c.course_no
						  from course c
                         where upper(c.course_name) like '%JAVA%'));

--5.
select l.loc_id
from location l, course_section c
where l.loc_id=c.loc_id and upper(c.course_no)='DATABASE MANAGEMENT'
intersect
select l.loc_id
from location l, course_section c
where l.loc_id=c.loc_id and upper(c.course_no)='PROGRAMMING IN C++';