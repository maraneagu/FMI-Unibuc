- CERINȚA 12 -

- cerința 1 -

WITH
    O AS (SELECT film_title TITLU, SUM(o_c.number_of_films) PROFIT
          FROM film_mng f
          JOIN order_consists_of o_c ON (f.film_id = o_c.film_id)
          JOIN order_mng o ON (o_c.ord_id = o.ord_id)
          JOIN works_in w_i ON (o.emp_id = w_i.emp_id)
          JOIN store_mng s ON (w_i.store_id = s.store_id)
          WHERE UPPER(s.store_name) = 'THE VELVET STAGE'
          GROUP BY film_title),
    R AS (SELECT film_title TITLU, COUNT(r_c.film_id) PROFIT
          FROM film_mng f
          JOIN rental_consists_of r_c ON (f.film_id = r_c.film_id)
          JOIN rental_mng r ON (r_c.rental_id = r.rental_id)
          JOIN works_in w_i ON (r.emp_id = w_i.emp_id)
          JOIN store_mng s ON (w_i.store_id = s.store_id)
          WHERE UPPER(s.store_name) = 'THE VELVET STAGE'
          GROUP BY film_title)
SELECT TITLU, PROFIT_VANZARI, PROFIT_INCHIRIERI, PROFIT_TOTAL
FROM (SELECT O.TITLU TITLU, O.PROFIT PROFIT_VANZARI, R.PROFIT PROFIT_INCHIRIERI, (O.PROFIT + R.PROFIT) PROFIT_TOTAL
      FROM O JOIN R ON (O.TITLU = R.TITLU)
      ORDER BY PROFIT_TOTAL DESC)
WHERE ROWNUM = 1;


- cerința 2 -

SELECT cust_last NUME, cust_first PRENUME, 
       DECODE(NVL(cust_email, NULL), NULL, 'EMAIL NECOMPLETAT', 'ANUNT!: PE DATA DE 30.10.2022, "THE VELVET STAGE" ORGANIZEAZA UN MARATON DE FILME HORROR!, EMAIL: ' || cust_email) ANUNT_OFERTA,
       NUMAR_INCHIRIERI
FROM customer_mng,
    (SELECT c.cust_id ID, COUNT(*) NUMAR_INCHIRIERI
     FROM customer_mng c
     JOIN rental_mng r ON (c.cust_id = r.cust_id)
     JOIN employee_mng e ON (r.emp_id = e.emp_id)
     JOIN works_in w_i ON (e.emp_id = w_i.emp_id)
     JOIN store_mng s ON (w_i.store_id = s.store_id)
     JOIN rental_consists_of r_c ON (r.rental_id = r_c.rental_id)
     JOIN film_mng f ON (r_c.film_id = f.film_id)
     JOIN category_mng cy ON (f.category_id = cy.category_id)
     WHERE LOWER(category_name) = 'groaza'
     AND UPPER(store_name) = 'THE VELVET STAGE CONSTANTA'
     GROUP BY c.cust_id) R
WHERE cust_id = R.ID          
ORDER BY NUMAR_INCHIRIERI DESC;


- cerința 3 -

SELECT cust_last NUME, cust_first PRENUME, PRET_INITIAL, 
CASE
    WHEN PRET_INITIAL <= 50 THEN 10
    WHEN PRET_INITIAL > 50 AND PRET_INITIAL <= 100 THEN 15
    WHEN PRET_INITIAL > 100 AND PRET_INITIAL <= 200 THEN 20
    WHEN PRET_INITIAL > 200 THEN 25
END AS DISCOUNT,
CASE 
    WHEN PRET_INITIAL <= 50 THEN (PRET_INITIAL - PRET_FILME_ROMANTICE / 10)
    WHEN PRET_INITIAL > 50 AND PRET_INITIAL <= 100 THEN (PRET_INITIAL - PRET_FILME_ROMANTICE * 15 / 100)
    WHEN PRET_INITIAL > 100 AND PRET_INITIAL <= 200 THEN (PRET_INITIAL - PRET_FILME_ROMANTICE * 20 / 100)
    WHEN PRET_INITIAL > 200 THEN (PRET_INITIAL - PRET_FILME_ROMANTICE * 25 / 100)
END AS PRET_DUPA_DISCOUNT
FROM (SELECT o.ord_id, cust_id ID, ord_price PRET_INITIAL, SUM(number_of_films * film_order_price) PRET_FILME_ROMANTICE
      FROM order_mng o
      JOIN order_consists_of o_c ON (o.ord_id = o_c.ord_id)
      JOIN film_mng f ON (o_c.film_id = f.film_id)
      JOIN category_mng c ON (f.category_id = c.category_id)
      WHERE UPPER(category_name) = 'ROMANTIC'
      AND EXTRACT (MONTH FROM ord_date) = 2
      AND EXTRACT (DAY FROM ord_date) >= 1 AND EXTRACT (DAY FROM ord_date) <= 14
      GROUP BY o.ord_id, cust_id, ord_price) F_R,
      customer_mng c
WHERE cust_id = F_R.ID;


- cerința 4 -

SELECT store_name NUME,
      (SELECT COUNT(*)
       FROM employee_mng e
       JOIN works_in w_i ON (e.emp_id = w_i.emp_id)
       WHERE w_i.store_id = s.store_id) NUMAR_ANGAJATI,
       
      (SELECT COUNT(*) 
       FROM order_mng o
       JOIN employee_mng e ON (o.emp_id = e.emp_id)
       JOIN works_in w_i ON (e.emp_id = w_i.emp_id)
       WHERE w_i.store_id = s.store_id
       AND EXTRACT (YEAR FROM ord_date) = 2022) NUMAR_VANZARI_2022,
       
      (SELECT 'TITLU: ' || TITLU || ' - NUMAR VANZARI: ' || NUMAR_VANZARI
       FROM store_mng s_m,
           (SELECT w_i.store_id ID, film_title TITLU, COUNT(*) NUMAR_VANZARI
            FROM film_mng f
            JOIN order_consists_of o_c ON (f.film_id = o_c.film_id)
            JOIN order_mng o ON (o_c.ord_id = o.ord_id)
            JOIN employee_mng e ON (o.emp_id = e.emp_id)
            JOIN works_in w_i ON (e.emp_id = w_i.emp_id)
            WHERE EXTRACT (YEAR FROM ord_date) = 2022
            GROUP BY w_i.store_id, film_title
            ORDER BY ID, NUMAR_VANZARI DESC) F
       WHERE s_m.store_id = F.ID AND s_m.store_id = s.store_id AND ROWNUM = 1) FILM_VANZARI_2022,
       
      (SELECT COUNT(*) 
       FROM rental_mng r
       JOIN employee_mng e ON (r.emp_id = e.emp_id)
       JOIN works_in w_i ON (e.emp_id = w_i.emp_id)
       WHERE w_i.store_id = s.store_id
       AND EXTRACT (YEAR FROM rental_date) = 2022) NUMAR_INCHIRIERI_2022,
       
      (SELECT 'TITLU: ' || TITLU || ' - NUMAR INCHIRIERI: ' || NUMAR_INCHIRIERI
       FROM store_mng s_m,
           (SELECT w_i.store_id ID, film_title TITLU, COUNT(*) NUMAR_INCHIRIERI
            FROM film_mng f
            JOIN rental_consists_of r_c ON (f.film_id = r_c.film_id)
            JOIN rental_mng r ON (r_c.rental_id = r.rental_id)
            JOIN employee_mng e ON (r.emp_id = e.emp_id)
            JOIN works_in w_i ON (e.emp_id = w_i.emp_id)
            WHERE EXTRACT (YEAR FROM rental_date) = 2022
            GROUP BY w_i.store_id, film_title
            ORDER BY ID, NUMAR_INCHIRIERI DESC) F
       WHERE s_m.store_id = F.ID AND s_m.store_id = s.store_id AND ROWNUM = 1) FILM_INCHIRIERI_2022
FROM store_mng s
ORDER BY (NUMAR_VANZARI_2022 + NUMAR_INCHIRIERI_2022) DESC;


- cerința 5 -

SELECT film_title TITLU_FILM,
      (SELECT director_first || ' ' || director_last
       FROM director_mng d
       JOIN film_mng f_m ON (d.director_id = f_m.director_id)
       WHERE UPPER(f_m.film_title) = UPPER(f.film_title)) REGIZOR,
       
      (SELECT category_name 
       FROM category_mng 
       WHERE category_id = R.ID_CATEGORIE) NUME_CATEGORIE,
       
       R.RATING_MAXIM RATING_MAXIM
FROM film_mng f, 
    (SELECT MAX(f_m.film_rating) RATING_MAXIM, f_m.category_id ID_CATEGORIE 
     FROM film_mng f_m 
     GROUP BY f_m.category_id) R
WHERE f.film_rating = R.RATING_MAXIM and f.category_id = ID_CATEGORIE
ORDER BY NUME_CATEGORIE;


- CERINȚA 13 -

- operația 1 -

UPDATE rental_mng
SET rental_price = 
    (CASE
        WHEN rental_price <= 30 THEN rental_price - rental_price * 10 / 100
        WHEN rental_price > 30 AND rental_price <= 70 THEN rental_price - rental_price * 15 / 100
        WHEN rental_price > 70 AND rental_price <= 100 THEN rental_price - rental_price * 20 / 100
        WHEN rental_price > 100 THEN rental_price - rental_price * 25 / 100
    END)
WHERE rental_id IN (SELECT r.rental_id
                    FROM rental_mng r
                    JOIN rental_consists_of r_c ON (r.rental_id = r_c.rental_id)
                    JOIN film_mng f ON (r_c.film_id = f.film_id)
                    JOIN category_mng c ON (f.category_id = c.category_id)
                    WHERE UPPER(category_name) = 'MUZICAL');


- operația 2 -

UPDATE rental_mng
SET rental_return_date = rental_return_date + 7
WHERE rental_id IN (SELECT r.rental_id
                    FROM rental_mng r
                    WHERE rental_date >= TO_DATE('22-02-2022') AND rental_date <= TO_DATE('08-03-2022'));


- operația 3 -

DELETE FROM order_consists_of
WHERE ord_id IN (SELECT o.ord_id
                 FROM order_mng o
                 WHERE o.ord_date >= TO_DATE('22-02-2022') AND o.ord_date <= TO_DATE('08-03-2022'))
AND film_id IN (SELECT f.film_id
                FROM film_mng f
                JOIN translated_to t_t ON (f.film_id = t_t.film_id)
                JOIN language_mng l ON (t_t.language_id = l.language_id)
                WHERE UPPER(language_name) = 'FRANCEZA');


- CERINȚA 14 -

CREATE VIEW customer_view_mng AS
SELECT cust_last NUME, cust_first PRENUME, cust_email EMAIL
FROM customer_mng c
JOIN order_mng o ON (c.cust_id = o.cust_id)
JOIN order_consists_of o_c ON (o.ord_id = o_c.ord_id)
JOIN film_mng f ON (o_c.film_id = f.film_id)
JOIN director_mng d ON (f.director_id = d.director_id)
WHERE c.cust_email IS NOT NULL AND UPPER(director_last) = 'WHEDON' AND UPPER(director_first) = 'JOSH'
WITH CHECK OPTION;

INSERT INTO customer_view_mng 
VALUES ('Neagu', 'Mara', NULL);

DELETE FROM customer_view_mng
WHERE LENGTH(EMAIL) > 22;


- CERINȚA 15 -

- division -

SELECT cust_last || ' ' || cust_first NUME_CLIENT, DATA_COMANDA, ANGAJAT_COMANDA, DATA_INCHIRIERE, ANGAJAT_INCHIRIERE
FROM customer_mng c,
    (SELECT c_m.cust_id ID, ord_date DATA_COMANDA, rental_date DATA_INCHIRIERE, e_o.emp_first || ' ' || e_o.emp_last ANGAJAT_COMANDA, e_r.emp_first || ' ' || e_r.emp_last ANGAJAT_INCHIRIERE
     FROM customer_mng c_m
     JOIN order_mng o ON (c_m.cust_id = o.cust_id)
     JOIN employee_mng e_o ON (o.emp_id = e_o.emp_id)
     JOIN rental_mng r ON (c_m.cust_id = r.cust_id)
     JOIN employee_mng e_r ON (r.emp_id = e_r.emp_id)
     WHERE ord_date = rental_date) C
WHERE c.cust_id = C.ID 
AND NOT EXISTS ((SELECT c.cust_id
                 FROM customer_mng c
                 JOIN order_mng o ON (c.cust_id = o.cust_id)
                 JOIN rental_mng r ON (c.cust_id = r.cust_id)
                 WHERE ord_date = rental_date)
                MINUS
                (SELECT c.cust_id
                 FROM customer_mng c));


- outerjoin -

SELECT cust_last || ' ' || cust_first NUME_CLIENT, SUM(CASE WHEN UPPER(language_name) = 'SPANIOLA' THEN 1 ELSE 0 END) NUMAR_INCHIRIERI
FROM customer_mng c
LEFT OUTER JOIN rental_mng r ON (c.cust_id = r.cust_id)
LEFT OUTER JOIN rental_consists_of r_c ON (r.rental_id = r_c.rental_id)
LEFT OUTER JOIN film_mng f_r ON (r_c.film_id = f_r.film_id)
LEFT OUTER JOIN translated_to t_t ON (f_r.film_id = t_t.film_id)
LEFT OUTER JOIN language_mng l ON (t_t.language_id = l.language_id)
GROUP BY cust_last, cust_first
ORDER BY NUMAR_INCHIRIERI;


- top-n -

SELECT store_name,
      (SELECT 'NUME CLIENT: ' || NUME_CLIENT || ' - NUMAR VANZARI: ' || NUMAR_COMENZI
       FROM (SELECT w_i.store_id ID_MAGAZIN, c.cust_first || ' ' || c.cust_last NUME_CLIENT, COUNT(o.cust_id) NUMAR_COMENZI
             FROM customer_mng c
             JOIN order_mng o ON (c.cust_id = o.cust_id)
             JOIN employee_mng e ON (o.emp_id = e.emp_id)
             JOIN works_in w_i ON (e.emp_id = w_i.emp_id)
             GROUP BY w_i.store_id, c.cust_first, c.cust_last 
             ORDER BY ID_MAGAZIN, NUMAR_COMENZI DESC, NUME_CLIENT),
             store_mng s_m
       WHERE s_m.store_id = ID_MAGAZIN AND s_m.store_id = s.store_id AND ROWNUM = 1) TOP_CLIENT
FROM store_mng s; 


- CERINȚA 16 -

COD NEOPTIMIZAT:
WITH
    M AS (SELECT f.film_id, film_title
          FROM film_mng f
          JOIN store_inventory s_i ON (f.film_id = s_i.film_id)
          JOIN store_mng s ON (s_i.store_id = s.store_id)
          WHERE UPPER(store_name) = 'THE VELVET STAGE'),
    C AS (SELECT film_id, film_title
          FROM film_mng f
          JOIN category_mng c ON (f.category_id = c.category_id)
          WHERE UPPER(category_name) = 'COMEDIE')
SELECT M.film_title TITLU_FILM
FROM M JOIN C ON (M.film_id = C.film_id);

RELATIA ALGEBRICA NEOPTIMIZATA:
R1 = SELECT(STORE_MNG, store_name = 'THE VELVET STAGE')
R2 = SEMIJOIN(STORE_INVENTORY, R1)
R3 = SEMIJOIN(FILM_MNG, R2)
R4 = PROJECT(R3, film_id, film_title)
R5 = SELECT(CATEGORY_MNG, category_name = 'COMEDIE')
R6 = SEMIJOIN(FILM_MNG, R5)
R7 = PROJECT(R6, film_id, film_title)
R8 = INTERSECT(R4, R7)
REZULTAT = R9 = PROJECT(R8, film_title)

COD OPTIMIZAT:
SELECT film_title
FROM film_mng
WHERE film_id IN (SELECT s_i.film_id
                  FROM store_inventory s_i
                  JOIN store_mng s ON (s_i.store_id = s.store_id)
                  WHERE UPPER(store_name) = 'THE VELVET STAGE')
AND category_id IN (SELECT c.category_id
                    FROM category_mng c 
                    WHERE UPPER(category_name) = 'COMEDIE');

RELATIA ALGEBRICA OPTIMIZATA:
R1 = SELECT(STORE_MNG, store_name = 'THE VELVET STAGE')
R2 = SEMIJOIN(STORE_INVENTORY, R1)
R3 = SEMIJOIN(FILM_MNG, R2)
R4 = PROJECT(R3, film_id, film_title, category_id)
R5 = SELECT(CATEGORY_MNG, category_name = 'COMEDIE')
R6 = PROJECT(R5, category_id)
R7 = SEMIJOIN(R4, R6)
REZULTAT = R8 = PROJECT(R7, film_title)