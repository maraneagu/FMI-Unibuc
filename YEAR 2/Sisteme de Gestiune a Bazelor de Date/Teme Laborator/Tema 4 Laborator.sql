-- 2).
CREATE OR REPLACE TYPE tip_orase_mng AS VARRAY(10) OF VARCHAR2(20);
/
CREATE TABLE excursie_mng(
    cod_excursie    NUMBER(4) NOT NULL PRIMARY KEY,
    denumire        VARCHAR(20),
    orase           tip_orase_mng,
    status          VARCHAR(20)
);

DECLARE
    c_specificat    excursie_mng.cod_excursie%TYPE;
    o_curente       excursie_mng.orase%TYPE;
    
    o_vizitat_1     VARCHAR2(20);
    id_vizitat_1    INTEGER(5);
    o_vizitat_2     VARCHAR2(20);
    id_vizitat_2    INTEGER(5);
    aux             VARCHAR2(20);
    
    o_specificat    VARCHAR2(20);
    p_sters         INTEGER(5);
    
    TYPE vector IS VARRAY(20) OF excursie_mng.cod_excursie%TYPE;
    c_excursie      vector;
    o_curent        excursie_mng.orase%TYPE;
    
    minim           NUMBER(4);
    
BEGIN
    -- A
    INSERT INTO excursie_mng
    VALUES(1, 'E1', tip_orase_mng('Bucuresti'), 'disponibila');
    
    INSERT INTO excursie_mng
    VALUES(2, 'E2', tip_orase_mng('Campina', 'Ploiesti'), 'disponibila');
    
    INSERT INTO excursie_mng
    VALUES(3, 'E3', tip_orase_mng('Paris', 'Londra', 'Roma', 'Venetia', 'Berlin'), 'anulata');
    
    INSERT INTO excursie_mng
    VALUES(4, 'E4', tip_orase_mng('Sibiu', 'Brasov', 'Cluj', 'Iasi', 'Braila'), 'anulata');
    
    INSERT INTO excursie_mng
    VALUES(5, 'E5', tip_orase_mng('Istanbul'), 'disponibila');
    
	-- B
    c_specificat := &cod_excursie;
    
    SELECT orase INTO o_curente
    FROM excursie_mng
    WHERE cod_excursie = c_specificat;
    
    -- B/1
    o_curente.EXTEND;
    o_curente(o_curente.COUNT) := 'Arad';     
   
    -- B/2
    o_curente.EXTEND;
    
    FOR i IN REVERSE 2..o_curente.COUNT LOOP
        o_curente(i) := o_curente(i-1);
    END LOOP;
    
    o_curente(2) := 'Constanta';
   
    -- B/3
    o_vizitat_1 := '&o_vizitat_1';
    o_vizitat_2 := '&o_vizitat_2';
    
    FOR i IN 1..o_curente.COUNT LOOP
        IF o_curente(i) = o_vizitat_1 THEN
            id_vizitat_1 := i;
        END IF;
        IF o_curente(i) = o_vizitat_2 THEN
            id_vizitat_2 := i;
        END IF;
    END LOOP;
    
    aux := o_curente(id_vizitat_1);
    o_curente(id_vizitat_1) := o_curente(id_vizitat_2);
    o_curente(id_vizitat_2) := aux;
   
    -- B/4
    o_specificat := '&o_specificat';
    
    FOR i IN 1..o_curente.COUNT LOOP
        IF o_curente(i) = o_specificat THEN
            p_sters := i;
        END IF;
    END LOOP;
    
    FOR i IN REVERSE p_sters..o_curente.COUNT LOOP
        o_curente(i) := o_curente(i-1);
    END LOOP;
    
    o_curente.TRIM;
    
    UPDATE excursie_mng
    SET orase = o_curente 
    WHERE cod_excursie = c_specificat;

    -- C
    DBMS_OUTPUT.PUT_LINE('Numar orase: ' || o_curente.COUNT);
    DBMS_OUTPUT.PUT_LINE('Orasele: ');
    
    FOR i IN 1..o_curente.COUNT LOOP
        DBMS_OUTPUT.PUT(o_curente(i) || ' ');
    END LOOP;
	DBMS_OUTPUT.NEW_LINE;
    
    -- D
    SELECT cod_excursie BULK COLLECT INTO c_excursie
    FROM excursie_mng;
    
    FOR i IN 1..c_excursie.COUNT LOOP
        SELECT orase INTO o_curent
        FROM excursie_mng
        WHERE cod_excursie = c_excursie(i);
        
        DBMS_OUTPUT.PUT_LINE('Excursia ' || c_excursie(i) || ': ');
        FOR i IN 1..o_curent.COUNT LOOP
            DBMS_OUTPUT.PUT(o_curent(i) || ' ');
        END LOOP;
		DBMS_OUTPUT.NEW_LINE;
    END LOOP;
    
    -- E
    SELECT orase INTO o_curent
    FROM excursie_mng
    WHERE cod_excursie = c_excursie(1);
    
    minim := o_curent.COUNT;
    
    FOR i IN 2..c_excursie.COUNT LOOP
        SELECT orase INTO o_curent
        FROM excursie_mng
        WHERE cod_excursie = c_excursie(i);
        
        IF o_curent.COUNT < minim THEN
            minim := o_curent.COUNT;
        END IF;
    END LOOP;
    
    FOR i IN 1..c_excursie.COUNT LOOP
        SELECT orase INTO o_curent
        FROM excursie_mng
        WHERE cod_excursie = c_excursie(i);
        
        IF o_curent.COUNT = minim THEN
            UPDATE excursie_mng
            SET status = 'anulat'
            WHERE cod_excursie = c_excursie(i);
        END IF;
    END LOOP;
END;
/

SELECT *
FROM excursie_mng;

-- 3).

