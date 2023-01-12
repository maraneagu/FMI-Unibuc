-- 3. FUNCTIE STOCATA
CREATE OR REPLACE FUNCTION f_mng (oras locations.city%TYPE)
RETURN NUMBER IS
    i_utilizator        VARCHAR(20);
    i_eroare            VARCHAR(100);
    
    e_numar             NUMBER;
BEGIN
    SELECT USER INTO i_utilizator
    FROM DUAL;
    
    IF oras IS NULL THEN
        INSERT INTO info_mng 
        VALUES(i_utilizator, sysdate, NULL, 0, 'Orasul dat ca parametru NU exista!');
        RETURN 0;    
    END IF;

    SELECT COUNT(*) INTO e_numar
    FROM employees e
    JOIN departments d ON (e.department_id = d.department_id)
    JOIN locations l ON (d.location_id = l.location_id)
    WHERE l.city = oras AND (SELECT COUNT(*) 
                             FROM job_history
                             WHERE e.employee_id = employee_id) >= 1;
    
    IF e_numar = 0 THEN 
        i_eroare := 'Nu a fost gasit niciun angajat!';
    END IF;
    
    INSERT INTO info_mng
    VALUES (i_utilizator, sysdate, NULL, 0, i_eroare);
    RETURN e_numar;
END f_mng;

-- 4. PROCEDURA STOCATA
-- FUNCTIE CARE DETERMINA DACA CODUL MANAGERULUI INTRODUS EXISTA
CREATE OR REPLACE FUNCTION e_mng (m_cod employees.employee_id%TYPE)
RETURN NUMBER IS
    CURSOR c IS
        SELECT manager_id cod
        FROM employees;
BEGIN
    FOR m IN c LOOP
        EXIT WHEN c%NOTFOUND;
        
        IF m.cod = m_cod THEN
            RETURN 1;
        END IF;
    END LOOP;
    RETURN 0;
END e_mng;


-- FUNCTIE CARE DETERMINA DACA UN ANGAJAT ESTE CONDUS DIRECT/INDIRECT DE UN MANAGER
CREATE OR REPLACE FUNCTION m_mng (e_cod employees.employee_id%TYPE,
                                  m_cod employees.employee_id%TYPE) 
RETURN NUMBER IS
    m   employees.employee_id%TYPE;
BEGIN
    SELECT manager_id INTO m
    FROM employees
    WHERE employee_id = e_cod;
    
    IF m = m_cod THEN 
        RETURN 1;
    ELSIF m IS NULL THEN 
        RETURN 0;
    ELSE RETURN m_mng(m, m_cod);
    END IF;
END m_mng;


CREATE OR REPLACE PROCEDURE p_mng (m_cod IN employees.employee_id%TYPE) IS
    CURSOR c IS
        SELECT employee_id cod, salary salariu
        FROM employees;
    
    i_utilizator        VARCHAR(20);
    i_eroare            VARCHAR(100);
BEGIN
    SELECT USER into i_utilizator
    FROM DUAL;
    
    IF m_cod IS NULL OR e_mng(m_cod) = 0 THEN
        INSERT INTO info_mng
        VALUES (i_utilizator, sysdate, NULL, 0, 'Nu exista un manager cu acest cod!');
    ELSE
        FOR e IN c LOOP
            EXIT WHEN c%NOTFOUND;
            
            IF m_mng(e.cod, m_cod) = 1 THEN
                e.salariu := e.salariu + e.salariu/10;
                INSERT INTO info_mng
                VALUES (i_utilizator, sysdate, 'Salariul angajatului ' || e.cod || ' a fost modificat!', 1, i_eroare);
            ELSE
                INSERT INTO info_mng
                VALUES (i_utilizator, sysdate, 'Salariul NU a fost modificat!', 0, i_eroare);
            END IF;
        END LOOP;
    END IF;
END p_mng;