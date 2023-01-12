-- 1).
CREATE OR REPLACE PACKAGE pachet_mng AS
    -- a).
    PROCEDURE p_adaug (nume employees.last_name%TYPE,
                       prenume employees.first_name%TYPE,
                       telefon employees.phone_number%TYPE,
                       email employees.email%TYPE,
                       nume_job jobs.job_title%TYPE,
                       nume_manager employees.last_name%TYPE,
                       prenume_manager employees.first_name%TYPE,
                       nume_departament departments.department_name%TYPE);
                       
    FUNCTION f_cod_job (nume_job jobs.job_title%TYPE)
    RETURN jobs.job_title%TYPE;
    
    FUNCTION f_cod_manager (nume_manager employees.last_name%TYPE,
                            prenume_manager employees.first_name%TYPE)
    RETURN employees.employee_id%TYPE;
    
    FUNCTION f_cod_departament (nume_departament departments.department_name%TYPE)
    RETURN departments.department_id%TYPE;
    
    -- b).
    PROCEDURE p_mutare (nume employees.last_name%TYPE,
                        prenume employees.first_name%TYPE,
                        nume_job jobs.job_title%TYPE,
                        nume_manager employees.last_name%TYPE,
                        prenume_manager employees.first_name%TYPE,
                        nume_departament departments.department_name%TYPE);
    
    -- c).
    FUNCTION f_nr_subalterni (nume employees.last_name%TYPE,
                              prenume employees.first_name%TYPE)
    RETURN NUMBER;
    
    -- d).
    PROCEDURE p_promovare (nume employees.last_name%TYPE,
                           prenume employees.first_name%TYPE);
    
    -- e).
    PROCEDURE p_actualizare (nume employees.last_name%TYPE,
                             prenume employees.first_name%TYPE,
                             salariu NUMBER);
    
    -- f).
    CURSOR c_lista_angajat (cod_job employees.job_id%TYPE)
    RETURN employees%ROWTYPE;

    -- g).     
    CURSOR c_lista_job
    RETURN jobs%ROWTYPE;
  
END pachet_mng;
/

CREATE OR REPLACE PACKAGE BODY pachet_mng AS
    -- f).
    CURSOR c_lista_angajat (cod_job employees.job_id%TYPE)
    RETURN employees%ROWTYPE IS
        SELECT *
        FROM employees
        WHERE job_id = cod_job;
        
    -- g).
    CURSOR c_lista_job 
    RETURN JOBS%ROWTYPE IS
        SELECT *
        FROM jobs;
        
    -- a).
    PROCEDURE p_adaug (nume employees.last_name%TYPE,
                       prenume employees.first_name%TYPE,
                       telefon employees.phone_number%TYPE,
                       email employees.email%TYPE,
                       nume_job jobs.job_title%TYPE,
                       nume_manager employees.last_name%TYPE,
                       prenume_manager employees.first_name%TYPE,
                       nume_departament departments.department_name%TYPE) IS
        
        cod_job         	employees.job_id%TYPE;
        cod_departament 	departments.department_id%TYPE;
        cod_manager     	employees.employee_id%TYPE;
        salariu         	employees.salary%TYPE := 0;
        
    BEGIN
        cod_job := f_cod_job(nume_job);
        cod_departament := f_cod_departament(nume_departament);
        cod_manager := f_cod_manager(nume_manager, prenume_manager);
        
        SELECT MIN(salary) INTO salariu
        FROM employees
        WHERE job_id = cod_job AND department_id = cod_departament;
        
        INSERT INTO emp_mng 
        VALUES (302, nume, prenume, email, telefon, sysdate, cod_job, salariu, NULL, cod_manager, cod_departament);
    END p_adaug;
    
    
    FUNCTION f_cod_job (nume_job jobs.job_title%TYPE)
    RETURN jobs.job_title%TYPE IS
        cod_job             employees.job_id%TYPE := 'nimic';
    BEGIN
        SELECT job_id INTO cod_job
        FROM jobs
        WHERE job_title = nume_job;
        
        IF cod_job = 'nimic' THEN
            RAISE_APPLICATION_ERROR(-20001, 'Numele jobului nu exista!');
        END IF;
        
        RETURN cod_job;
    END f_cod_job;
    
    
    FUNCTION f_cod_manager (nume_manager employees.last_name%TYPE,
                            prenume_manager employees.first_name%TYPE)
    RETURN employees.employee_id%TYPE IS
        cod_manager         employees.employee_id%TYPE := 'nimic';
    BEGIN
        SELECT employee_id INTO cod_manager
        FROM employees
        WHERE last_name = nume_manager AND first_name = prenume_manager;
        
        IF cod_manager = 'nimic' THEN
            RAISE_APPLICATION_ERROR(-20001, 'Numele managerului nu exista!');
        END IF;
        
        RETURN cod_manager;
    END f_cod_manager;
    
    
    FUNCTION f_cod_departament (nume_departament departments.department_name%TYPE)
    RETURN departments.department_id%TYPE IS
        cod_departament         departments.department_id%TYPE := 'nimic';
    BEGIN
        SELECT department_id INTO cod_departament
        FROM departments
        WHERE department_name = nume_departament;
        
        IF cod_departament = 'nimic' THEN
            RAISE_APPLICATION_ERROR(-20001, 'Numele departamentului nu exista!');
        END IF;
        
        RETURN cod_departament;
    END f_cod_departament;

    
    -- b).
    PROCEDURE p_mutare (nume employees.last_name%TYPE,
                        prenume employees.first_name%TYPE,
                        nume_job jobs.job_title%TYPE,
                        nume_manager employees.last_name%TYPE,
                        prenume_manager employees.first_name%TYPE,
                        nume_departament departments.department_name%TYPE) IS
        
        numarator           NUMBER := 0;
        cod_angajat         employees.employee_id%TYPE;
        cod_job         	  employees.job_id%TYPE;
        cod_departament 	  departments.department_id%TYPE;
        cod_manager     	  employees.employee_id%TYPE;
        salariu         	  employees.salary%TYPE;
        salariu_minim   	  employees.salary%TYPE := 0;
        comision        	  employees.commission_pct%TYPE := 0;
        
    BEGIN
        SELECT COUNT(*) INTO numarator
        FROM employees
        WHERE last_name = nume AND first_name = prenume;
        
        IF numarator = 0 THEN
            RAISE_APPLICATION_ERROR(-20001, 'Nu exista niciun angajat cu acest nume!');
        END IF;
        
        cod_job := f_cod_job(nume_job);
        cod_departament := f_cod_departament(nume_departament);
        cod_manager := f_cod_manager(nume_manager, prenume_manager);
        
        SELECT employee_id INTO cod_angajat
        FROM employees
        WHERE last_name = nume AND first_name = prenume;
        
        SELECT salary INTO salariu
        FROM employees
        WHERE last_name = nume AND first_name = prenume;
        
        SELECT MIN(salary) INTO salariu_minim
        FROM employees
        WHERE job_id = cod_job AND department_id = cod_departament;
        
        IF salariu < salariu_minim THEN
            salariu := salariu_minim;
        END IF;
            
        SELECT MIN(commission_pct) INTO comision
        FROM employees
        WHERE job_id = cod_job AND department_id = cod_departament;
        
        UPDATE emp_mng
        SET job_id = cod_job,
            department_id = cod_departament,
            manager_id = cod_manager,
            salary = salariu,
            commission_pct = comision,
            hire_date = sysdate
        WHERE employee_id = cod_angajat;
    END p_mutare;
    
    -- c).
    FUNCTION f_nr_subalterni (nume employees.last_name%TYPE,
                              prenume employees.first_name%TYPE)
    RETURN NUMBER IS 
        numarator           NUMBER := 0;
        cod_manager         employees.employee_id%TYPE;
    BEGIN 
        cod_manager := f_cod_manager(nume, prenume);

        SELECT COUNT(*) INTO numarator
        FROM employees
        START WITH employee_id = cod_manager
        CONNECT BY PRIOR employee_id = manager_id;

        RETURN numarator;        
    END f_nr_subalterni;
    
    -- d).
    PROCEDURE p_promovare(nume employees.last_name%TYPE,
                          prenume employees.first_name%TYPE) IS
        cod_angajat         employees.employee_id%TYPE;
        cod_manager_1       employees.employee_id%TYPE;
        cod_manager_2       employees.employee_id%TYPE;
    BEGIN
        SELECT employee_id INTO cod_angajat
        FROM employees
        WHERE last_name = nume AND first_name = prenume;
        
        SELECT manager_id INTO cod_manager_1
        FROM employees
        WHERE employee_id = cod_angajat;
        
        IF cod_manager_1 IS NULL THEN
            DBMS_OUTPUT.PUT_LINE('Angajatul introdus are rang maxim!');
        ELSE
            SELECT manager_id INTO cod_manager_2
            FROM employees
            WHERE employee_id = cod_manager_1;
        
            UPDATE emp_mng
            SET manager_id = cod_angajat
            WHERE employee_id = cod_manager_1;
            
            UPDATE emp_mng
            SET manager_id = cod_manager_2
            WHERE employee_id = cod_angajat;
        END IF;
    END p_promovare;
    
    -- e).
    PROCEDURE p_actualizare (nume employees.last_name%TYPE,
                             prenume employees.first_name%TYPE,
                             salariu NUMBER) IS                
        CURSOR c IS
            SELECT last_name nume, first_name prenume
            FROM employees 
            WHERE last_name = nume;
                
        numarator           NUMBER;
        cod_angajat         employees.employee_id%TYPE;
        salariu_minim       jobs.min_salary%TYPE;
        salariu_maxim       jobs.max_salary%TYPE;
    BEGIN 
        SELECT COUNT(*) INTO numarator
        FROM employees
        WHERE last_name = nume;
        
        IF numarator > 1 THEN
            DBMS_OUTPUT.PUT_LINE('Exista mai multi angajati cu acest nume! Lista acestora este: ');
            
            FOR i IN c LOOP
                EXIT WHEN c%NOTFOUND;
                DBMS_OUTPUT.PUT_LINE('Nume: ' || i.nume || '; Prenume: ' || i.prenume);
            END LOOP;
            
        ELSIF numarator = 1 THEN
            SELECT employee_id INTO cod_angajat
            FROM employees
            WHERE last_name = nume AND first_name = prenume;
        
            SELECT min_salary INTO salariu_minim
            FROM employees e, jobs j
            WHERE employee_id = cod_angajat AND e.job_id = j.job_id;
        
            SELECT max_salary INTO salariu_maxim
            FROM employees e, jobs j
            WHERE employee_id = cod_angajat AND e.job_id = j.job_id;
        
            IF salariu < salariu_minim AND salariu > salariu_maxim THEN
                RAISE_APPLICATION_ERROR(-20001, 'Salariul nu este corespunzator!');
            ELSE
                UPDATE emp_mng
                SET salary = salariu
                WHERE employee_id = cod_angajat;
            END IF;
            
        ELSE 
            RAISE_APPLICATION_ERROR(-20001, 'Nu exista niciun angajat cu acest nume!');
        END IF; 
    END p_actualizare;  
END pachet_mng;
/


