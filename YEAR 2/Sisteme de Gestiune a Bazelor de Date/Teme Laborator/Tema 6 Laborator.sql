-- 1).
-- A. CURSOR CLASIC
DECLARE
    CURSOR c_j IS
        SELECT job_id cod, job_title titlu
        FROM jobs;
    
    CURSOR c_e (j jobs.job_id%TYPE) IS
        SELECT last_name nume, salary salariu
        FROM employees
        WHERE job_id = j;
        
    j_cod       jobs.job_id%TYPE;
    j_titlu     jobs.job_title%TYPE;
    
    e_nume      employees.last_name%TYPE;
    e_salariu   employees.salary%TYPE;
    e_numar     NUMBER(4);

BEGIN
    OPEN c_j;
        LOOP
            FETCH c_j INTO j_cod, j_titlu;
            EXIT WHEN c_j%NOTFOUND;
            
            DBMS_OUTPUT.PUT_LINE('~ * ~');
            DBMS_OUTPUT.PUT_LINE('- ' || j_titlu || ' -');
            DBMS_OUTPUT.NEW_LINE;
            
            e_numar := 0;
            
            DBMS_OUTPUT.PUT_LINE('Lista angajati: ');
            OPEN c_e(j_cod);
                LOOP
                    FETCH c_e INTO e_nume, e_salariu;
                    EXIT WHEN c_e%NOTFOUND;
                    
                    DBMS_OUTPUT.PUT_LINE('Angajat: ' || e_nume || '; Salariu: ' || e_salariu);
                    e_numar := e_numar + 1;
                END LOOP;
            CLOSE c_e;
            DBMS_OUTPUT.NEW_LINE;
            
            IF e_numar = 0 THEN
                DBMS_OUTPUT.PUT_LINE('Nu lucreaza niciun angajat pe postul de ' || j_titlu);
            END IF;
        END LOOP;
    CLOSE c_j;
END;
/

-- B. CICLU CURSOR
DECLARE
    CURSOR c_j IS
        SELECT job_id cod, job_title titlu
        FROM jobs;
        
    CURSOR c_e (j jobs.job_id%TYPE) IS
        SELECT last_name nume, salary salariu
        FROM employees
        WHERE job_id = j;
        
    e_numar     NUMBER(4);

BEGIN
    FOR j IN c_j LOOP
        EXIT WHEN c_j%NOTFOUND;
        
        DBMS_OUTPUT.PUT_LINE('~ * ~');
        DBMS_OUTPUT.PUT_LINE('- ' || j.titlu || ' -');
        DBMS_OUTPUT.NEW_LINE;
        
        e_numar := 0;
        
        DBMS_OUTPUT.PUT_LINE('Lista angajati: ');
        FOR e IN c_e(j.cod) LOOP
            EXIT WHEN c_e%NOTFOUND;
            
            DBMS_OUTPUT.PUT_LINE('Angajat: ' || e.nume || '; Salariu: ' || e.salariu); 
            e_numar := e_numar + 1;
        END LOOP;
        DBMS_OUTPUT.NEW_LINE;
        
        IF e_numar = 0 THEN
            DBMS_OUTPUT.PUT_LINE('Nu lucreaza niciun angajat pe postul de ' || j.titlu);
        END IF;
    END LOOP;
END;
/

-- C. CICLU CURSOR CU SUBCERERI
DECLARE
    e_numar     NUMBER(4);
    
BEGIN
    FOR j IN (SELECT job_id cod, job_title titlu
              FROM jobs) LOOP
        DBMS_OUTPUT.PUT_LINE('~ * ~');
        DBMS_OUTPUT.PUT_LINE('- ' || j.titlu || ' -');
        DBMS_OUTPUT.NEW_LINE;
        
        e_numar := 0;
        
        DBMS_OUTPUT.PUT_LINE('Lista angajati: ');
        FOR e IN (SELECT last_name nume, salary salariu
                  FROM employees
                  WHERE job_id = j.cod) LOOP
            DBMS_OUTPUT.PUT_LINE('Angajat: ' || e.nume || '; Salariu: ' || e.salariu); 
            e_numar := e_numar + 1;
        END LOOP;
        DBMS_OUTPUT.NEW_LINE;
        
        IF e_numar = 0 THEN
            DBMS_OUTPUT.PUT_LINE('Nu lucreaza niciun angajat pe postul de ' || j.titlu);
        END IF;
    END LOOP;
END;
/

-- D. EXPRESII CURSOR
DECLARE
    TYPE refcursor IS REF CURSOR;
    
    CURSOR c_j IS
        SELECT job_title titlu, CURSOR (SELECT last_name nume, salary salariu
                                        FROM employees e
                                        WHERE e.job_id = j.job_id)
        FROM jobs j;
    
    j_titlu     jobs.job_title%TYPE;
    j_cursor    refcursor;
    
    e_nume      employees.last_name%TYPE;
    e_salariu   employees.salary%TYPE;
    e_numar     NUMBER(4);

BEGIN
    OPEN c_j;
        LOOP
            FETCH c_j INTO j_titlu, j_cursor;
            EXIT WHEN c_j%NOTFOUND;
            
            DBMS_OUTPUT.PUT_LINE('~ * ~');
            DBMS_OUTPUT.PUT_LINE('- ' || j_titlu || ' -');
            DBMS_OUTPUT.NEW_LINE;
            
            e_numar := 0;
            
            DBMS_OUTPUT.PUT_LINE('Lista angajati: ');
            LOOP
                FETCH j_cursor INTO e_nume, e_salariu;
                EXIT WHEN j_cursor%NOTFOUND;
                
                DBMS_OUTPUT.PUT_LINE('Angajat: ' || e_nume || '; Salariu: ' || e_salariu);
                e_numar := e_numar + 1;
            END LOOP;
            DBMS_OUTPUT.NEW_LINE;
            
            IF e_numar = 0 THEN
                DBMS_OUTPUT.PUT_LINE('Nu lucreaza niciun angajat pe postul de ' || j_titlu);
            END IF;
        END LOOP;
    CLOSE c_j;
END;
/

-- 2). CICLU CURSOR
DECLARE
    CURSOR c_j IS
        SELECT job_id cod, job_title titlu
        FROM jobs;
        
    CURSOR c_e (j jobs.job_id%TYPE) IS
        SELECT last_name nume, salary salariu
        FROM employees
        WHERE job_id = j;
        
    e_numar             NUMBER(4);    
    v_lunara            NUMBER(8,2);
    v_medie             NUMBER(8,2);
    
    e_numar_total       NUMBER(5) := 0;
    v_lunara_totala     NUMBER(10,2) := 0;
    v_medie_totala      NUMBER(10,2);

BEGIN
   	FOR j IN c_j LOOP
        EXIT WHEN c_j%NOTFOUND;
        
        DBMS_OUTPUT.PUT_LINE('~ * ~');
        DBMS_OUTPUT.PUT_LINE('- ' || j.titlu || ' -');
        
        SELECT COUNT(*) INTO e_numar
        FROM employees
        WHERE job_id = j.cod;
        DBMS_OUTPUT.PUT_LINE('Numar angajati: ' || e_numar);
        DBMS_OUTPUT.NEW_LINE;
        
        e_numar := 0;
        v_lunara := 0;
        
        DBMS_OUTPUT.PUT_LINE('Lista angajati: ');
        FOR e IN c_e(j.cod) LOOP
            EXIT WHEN c_e%NOTFOUND;
            
            DBMS_OUTPUT.PUT_LINE(e_numar + 1 || ': Angajat: ' || e.nume || '; Salariu: ' || e.salariu); 
            e_numar := e_numar + 1;
            v_lunara := v_lunara + e.salariu;
        END LOOP;
        DBMS_OUTPUT.NEW_LINE;
        
        e_numar_total := e_numar_total + e_numar;
        v_lunara_totala := v_lunara_totala + v_lunara;
        
        IF e_numar = 0 THEN
            DBMS_OUTPUT.PUT_LINE('Nu lucreaza niciun angajat pe postul de ' || j.titlu);
        ELSE
            v_medie := v_lunara / e_numar;
            DBMS_OUTPUT.PUT_LINE('Valoarea lunara a veniturilor angajatilor: ' || v_lunara);
            DBMS_OUTPUT.PUT_LINE('Valoarea medie a veniturilor angajatilor: ' || v_medie);
        END IF;
        
        DBMS_OUTPUT.NEW_LINE;
    END LOOP;
    
    v_medie_totala := v_lunara_totala / e_numar_total;
    DBMS_OUTPUT.PUT_LINE('~ * ~');
    DBMS_OUTPUT.PUT_LINE('TOTAL: ');
    DBMS_OUTPUT.PUT_LINE('Valoarea lunara totala a veniturilor angajatilor: ' || v_lunara_totala);
    DBMS_OUTPUT.PUT_LINE('Valoarea medie totala a veniturilor angajatilor: ' || v_medie_totala);
END;
/

-- 3). CICLU CURSOR
DECLARE
    CURSOR c_j IS
        SELECT job_id cod, job_title titlu
        FROM jobs;
        
    CURSOR c_e (j jobs.job_id%TYPE) IS
        SELECT last_name nume, salary salariu, commission_pct procent
        FROM employees
        WHERE job_id = j;
        
    e_numar             NUMBER(4);    
    v_lunara            NUMBER(8,2);
    v_medie             NUMBER(8,2);
    
    e_numar_total       NUMBER(5) := 0;
    v_lunara_totala     NUMBER(10,2) := 0;
    v_medie_totala      NUMBER(10,2);
    
    s_totala            NUMBER(10,2);
    p_s_totala          NUMBER(10,2);

BEGIN
    FOR j IN c_j LOOP
        EXIT WHEN c_j%NOTFOUND;
        
        DBMS_OUTPUT.PUT_LINE('~ * ~');
        DBMS_OUTPUT.PUT_LINE('- ' || j.titlu || ' -');
        
        SELECT COUNT(*) INTO e_numar
        FROM employees
        WHERE job_id = j.cod;
        DBMS_OUTPUT.PUT_LINE('Numar angajati: ' || e_numar);
        
        SELECT SUM(salary) + SUM(salary * commission_pct) INTO s_totala
        FROM employees;
        DBMS_OUTPUT.PUT_LINE('Suma totala alocata lunar pentru plata salariilor si comisioanelor angajatilor: ' || s_totala);
        DBMS_OUTPUT.NEW_LINE;
        
        e_numar := 0;
        v_lunara := 0;
        
        DBMS_OUTPUT.PUT_LINE('Lista angajati: ');
        FOR e IN c_e(j.cod) LOOP
            EXIT WHEN c_e%NOTFOUND;
            
            p_s_totala := (e.salariu + (e.salariu * nvl(e.procent,0))) * 100 / s_totala;
            
            DBMS_OUTPUT.PUT_LINE(e_numar + 1 || '. Angajat: ' || e.nume || '; Salariu: ' || e.salariu || '; Procent suma totala:' || TO_CHAR(p_s_totala, '0.00') || '%'); 
            
            e_numar := e_numar + 1;
            v_lunara := v_lunara + e.salariu;
        END LOOP;
        DBMS_OUTPUT.NEW_LINE;
		
        e_numar_total := e_numar_total + e_numar;
        v_lunara_totala := v_lunara_totala + v_lunara;
        
        IF e_numar = 0 THEN
            DBMS_OUTPUT.PUT_LINE('Nu lucreaza niciun angajat pe postul de ' || j.titlu);
        ELSE
            v_medie := v_lunara / e_numar;
            DBMS_OUTPUT.PUT_LINE('Valoarea lunara a veniturilor angajatilor: ' || v_lunara);
            DBMS_OUTPUT.PUT_LINE('Valoarea medie a veniturilor angajatilor: ' || v_medie);
        END IF;
        
        DBMS_OUTPUT.NEW_LINE;
    END LOOP;
    
    v_medie_totala := v_lunara_totala / e_numar_total;
    DBMS_OUTPUT.PUT_LINE('~ * ~');
    DBMS_OUTPUT.PUT_LINE('TOTAL: ');
    DBMS_OUTPUT.PUT_LINE('Valoarea lunara totala a veniturilor angajatilor: ' || v_lunara_totala);
    DBMS_OUTPUT.PUT_LINE('Valoarea medie totala a veniturilor angajatilor: ' || v_medie_totala);
END;
/

-- 4). CICLU CURSOR
DECLARE
    CURSOR c_j IS
        SELECT job_id cod, job_title titlu
        FROM jobs;
        
    CURSOR c_e (j jobs.job_id%TYPE) IS
        SELECT last_name nume, salary salariu, commission_pct procent
        FROM employees
        WHERE job_id = j
        ORDER BY salary DESC;
        
    e_numar             NUMBER(4);    
    v_lunara            NUMBER(8,2);
    v_medie             NUMBER(8,2);
    
    e_numar_total       NUMBER(5) := 0;
    v_lunara_totala     NUMBER(10,2) := 0;
    v_medie_totala      NUMBER(10,2);
    
    s_totala            NUMBER(10,2);
    p_s_totala          NUMBER(10,2);

BEGIN
    FOR j IN c_j LOOP
        EXIT WHEN c_j%NOTFOUND;
        
        DBMS_OUTPUT.PUT_LINE('~ * ~');
        DBMS_OUTPUT.PUT_LINE('- ' || j.titlu || ' -');
        
        SELECT COUNT(*) INTO e_numar
        FROM employees
        WHERE job_id = j.cod;
        IF e_numar >= 5 THEN 
            DBMS_OUTPUT.PUT_LINE('Numar angajati: ' || e_numar);
        ELSE
            DBMS_OUTPUT.PUT_LINE('Lucreaza mai putin de 5 angajati pe postul de ' || j.titlu);
        END IF;
        
        SELECT SUM(salary) + SUM(salary * commission_pct) INTO s_totala
        FROM employees;
        DBMS_OUTPUT.PUT_LINE('Suma totala alocata lunar pentru plata salariilor si comisioanelor angajatilor: ' || s_totala);
        DBMS_OUTPUT.NEW_LINE;
        
        e_numar := 0;
        v_lunara := 0;
        
        DBMS_OUTPUT.PUT_LINE('Lista angajati: ');
        FOR e IN c_e(j.cod) LOOP
            EXIT WHEN c_e%NOTFOUND OR c_e%ROWCOUNT > 5;
            
            p_s_totala := (e.salariu + (e.salariu * nvl(e.procent,0))) * 100 / s_totala;
            
            DBMS_OUTPUT.PUT_LINE(e_numar + 1 || '. Angajat: ' || e.nume || '; Salariu: ' || e.salariu || '; Procent suma totala:' || TO_CHAR(p_s_totala, '0.00') || '%'); 
            
            e_numar := e_numar + 1;
            v_lunara := v_lunara + e.salariu;
        END LOOP;
        DBMS_OUTPUT.NEW_LINE;
		
        e_numar_total := e_numar_total + e_numar;
        v_lunara_totala := v_lunara_totala + v_lunara;
        
        IF e_numar = 0 THEN
            DBMS_OUTPUT.PUT_LINE('Nu lucreaza niciun angajat pe postul de ' || j.titlu);
        ELSE
            v_medie := v_lunara / e_numar;
            DBMS_OUTPUT.PUT_LINE('Valoarea lunara a veniturilor angajatilor: ' || v_lunara);
            DBMS_OUTPUT.PUT_LINE('Valoarea medie a veniturilor angajatilor: ' || v_medie);
        END IF;
        
        DBMS_OUTPUT.NEW_LINE;
    END LOOP;
    
    v_medie_totala := v_lunara_totala / e_numar_total;
    DBMS_OUTPUT.PUT_LINE('~ * ~');
    DBMS_OUTPUT.PUT_LINE('TOTAL: ');
    DBMS_OUTPUT.PUT_LINE('Valoarea lunara totala a veniturilor angajatilor: ' || v_lunara_totala);
    DBMS_OUTPUT.PUT_LINE('Valoarea medie totala a veniturilor angajatilor: ' || v_medie_totala);
END;
/