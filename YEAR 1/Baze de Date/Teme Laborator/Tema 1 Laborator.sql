I.

-- 1.
select count(employee_id)
from employees
where upper(last_name) like 'K%';

-- 2. 
select employee_id, last_name, first_name 
from employees e
where salary =(select min(salary)
                 from employees);
                 
-- 3.
select distinct e.manager_id, e.last_name
from employees e
where e.manager_id in (select d.manager_id
                       from departments d
                       where d.department_id=30);
                       
-- 4.
select e.employee_id, e.first_name, e.last_name, (select count(*)
                                                  from employees
                                                  where manager_id=e.employee_id) as "NUMAR_SUBALTERNI"
from employees e;

-- 5.
select e1.employee_id, e1.last_name, e1.first_name
from employees e1
where e1.last_name in (select e2.last_name
                       from employees e2
                       where e2.employee_id!=e1.employee_id);
                       
-- 6.
select distinct d.department_id, d.department_name
from departments d, employees e, employees ee
where e.job_id!=ee.job_id;

II.

-- 7.
select o.qty
from orders_tbl o, products_tbl p
where lower(p.prod_desc) like '%plastic%';

-- 8.
select c.cust_name, 'Client' as TIP
from customer_tbl c
union all
select e.last_name, 'Angajat' as TIP
from employee_tbl e;

-- 10.
select cust_name
from customer_tbl
where cust_id in (select cust_id
                  from orders_tbl
                  where to_char(ord_date,'DD')=17);
                  
-- 11.
select e.last_name, e.first_name, ep.salary, ep.bonus
from employee_tbl e, employee_pay_tbl ep
where e.emp_id=ep.emp_id and greatest(ep.salary,ep.bonus*17)<32000;

-- 12.
select e.last_name, o.qty
from employee_tbl e, orders_tbl o
where e.emp_id=o.sales_rep(+)
group by e.last_name, o.qty
having o.qty>50 or o.qty is null;

-- 13.
select e.last_name, ep.salary, (select max(ord_date)
                                from orders_tbl) as "LAST_ORDER"
from employee_tbl e, employee_pay_tbl ep, orders_tbl o
group by e.last_name, ep.salary
having count(ord_num)>=2;

-- 14.
select prod_desc 
from products_tbl
where cost > (select avg(cost)
              from products_tbl);
              
-- 15.
select e.last_name, e.first_name, ep.salary, ep.bonus, (select sum(salary) from employee_pay_tbl) as "TOTAL_SALARY", (select sum(bonus) from employee_pay_tbl) as "TOTAL_BONUS"
from employee_tbl e, employee_pay_tbl ep
group by e.last_name, e.first_name, ep.salary, ep.bonus;

-- 16.
select e.city
from employee_tbl e, orders_tbl o
where o.qty=(select max(qty)
             from orders_tbl);
             
-- 17.
select distinct e.emp_id, e.last_name, (select count(ord_num)
                               from orders_tbl
                               where to_char(ord_date,'MM')=9) as "SEPTEMBER", (select count(ord_num)
                                                                                from orders_tbl
                                                                                where to_char(ord_date,'MM')=10) as "OCTOBER"
from employee_tbl e, orders_tbl o;

-- 18.
select cust_name, cust_city
from customer_tbl 
where (cust_zip like '0%' or
       cust_zip like '1%' or
       cust_zip like '2%' or
       cust_zip like '3%' or
       cust_zip like '4%' or
       cust_zip like '5%' or
       cust_zip like '6%' or
       cust_zip like '7%' or
       cust_zip like '8%' or
       cust_zip like '9%') and cust_id not in (select cust_id from orders_tbl);
       
-- 19.
select distinct e.emp_id, e.last_name, e.city, c.cust_id, c.cust_name, c.cust_city
from employee_tbl e, customer_tbl c, orders_tbl o
where e.emp_id=o.sales_rep and c.cust_id=o.cust_id;

-- 20.

-- 21.
-- a) DA
-- b) NU

-- 22.
select e.last_name, ep.pay_rate
from employee_tbl e, employee_pay_tbl ep
where ep.pay_rate > (select max(ep.pay_rate)
                     from employee_tbl e, employee_pay_tbl ep
                     where e.last_name like '%LL%' and e.emp_id=ep.emp_id);

