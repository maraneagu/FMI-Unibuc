store_mng:
CREATE TABLE store_mng(
    store_id        NUMBER(5)       PRIMARY KEY,
    store_name      VARCHAR2(50)    NOT NULL,
    manager_id      NUMBER(5)       NOT NULL UNIQUE,
    adress          VARCHAR2(30)    NOT NULL,
    city            VARCHAR2(15)    NOT NULL,
    state           VARCHAR2(15),
    zip             VARCHAR2(6)     NOT NULL,
    phone           VARCHAR2(10)    NOT NULL UNIQUE,
    email           VARCHAR2(20)    NOT NULL UNIQUE
);

employee_mng:
CREATE TABLE employee_mng(
    emp_id          NUMBER(5)       PRIMARY KEY,
    emp_last        VARCHAR2(25)    NOT NULL,
    emp_first       VARCHAR2(25)    NOT NULL,
    emp_phone       VARCHAR2(10)    NOT NULL UNIQUE,
    emp_email       VARCHAR2(10)    NOT NULL UNIQUE,
    emp_hire_date   DATE,
    emp_salary      NUMBER(4,2)     NOT NULL
);

works_in:
CREATE TABLE works_in(
    store_id        NUMBER(5)       REFERENCES store_mng(store_id) ON DELETE CASCADE,
    emp_id          NUMBER(5)       REFERENCES employee_mng(emp_id) ON DELETE CASCADE,
    CONSTRAINT pk_works_in PRIMARY KEY(store_id, emp_id)
);

category_mng:
CREATE TABLE category_mng(
    category_id         NUMBER(5)       PRIMARY KEY,
    category_name       VARCHAR2(20)    NOT NULL UNIQUE
);

director_mng:
CREATE TABLE director_mng(
    director_id         NUMBER(5)       PRIMARY KEY,
    director_last       VARCHAR2(20)    NOT NULL,
    director_first      VARCHAR2(20)    NOT NULL
);

film_mng:
CREATE TABLE film_mng(
    film_id                 NUMBER(5)       PRIMARY KEY,
    film_title              VARCHAR2(30)    NOT NULL,
    film_description        VARCHAR2(150),
    film_release            DATE,
    film_original_language  VARCHAR2(15)    NOT NULL,
    film_length             NUMBER(3)       NOT NULL,
    film_rental_price       NUMBER(2)       NOT NULL,
    film_order_price        NUMBER(2)       NOT NULL,
    film_rating             NUMBER(2),
    director_id             NUMBER(5)       REFERENCES director_mng(director_id) ON DELETE CASCADE,
    category_id             NUMBER(5)       REFERENCES category_mng(category_id) ON DELETE CASCADE
);

store_inventory:
CREATE TABLE store_inventory(
    store_id        NUMBER(5)       REFERENCES store_mng(store_id) ON DELETE CASCADE,
    film_id         NUMBER(5)       REFERENCES film_mng(film_id) ON DELETE CASCADE,
    CONSTRAINT pk_store_inventory PRIMARY KEY(store_id, film_id)
);

actor_mng:
CREATE TABLE actor_mng(
    actor_id        NUMBER(5)       PRIMARY KEY,
    actor_last      VARCHAR2(20)    NOT NULL,
    actor_first     VARCHAR2(20)    NOT NULL
);

acts_in:
CREATE TABLE acts_in(
    film_id     NUMBER(5)       REFERENCES film_mng(film_id) ON DELETE CASCADE,
    actor_id    NUMBER(5)       REFERENCES actor_mng(actor_id) ON DELETE CASCADE,
    CONSTRAINT pk_acts_in PRIMARY KEY(film_id, actor_id)
);

language_id:
CREATE TABLE language_mng(
    language_id     NUMBER(5)       PRIMARY KEY,
    language_name   VARCHAR2(15)    NOT NULL UNIQUE
);

translated_to:
CREATE TABLE translated_to(
    film_id     NUMBER(5)       REFERENCES film_mng(film_id) ON DELETE CASCADE,
    language_id NUMBER(5)       REFERENCES language_mng(language_id) ON DELETE CASCADE,
    CONSTRAINT pk_translated_to PRIMARY KEY(film_id, language_id)
);

customer_mng:
CREATE TABLE customer_mng(
    cust_id         NUMBER(5)       PRIMARY KEY,
    cust_last       VARCHAR2(20)    NOT NULL,
    cust_first      VARCHAR2(20)    NOT NULL,
    cust_phone      VARCHAR2(10)    UNIQUE,
    cust_email      VARCHAR2(20)    UNIQUE
);

rental_mng:
CREATE TABLE rental_mng(
    rental_id           NUMBER(5)       PRIMARY KEY,
    rental_date         DATE            NOT NULL,
    rental_return_date  DATE,
    rental_price        NUMBER(6),
    emp_id              NUMBER(5)       REFERENCES employee_mng(emp_id) ON DELETE CASCADE,
    cust_id             NUMBER(5)       REFERENCES customer_mng(cust_id) ON DELETE CASCADE
);

rental_consists_of:
CREATE TABLE rental_consists_of(
    rental_id       NUMBER(5)       REFERENCES rental_mng(rental_id) ON DELETE CASCADE,
    film_id         NUMBER(5)       REFERENCES film_mng(film_id) ON DELETE CASCADE,
    CONSTRAINT pk_rental_consists_of PRIMARY KEY(rental_id, film_id)
);

order_mng:
CREATE TABLE order_mng(
    ord_id      NUMBER(5)       PRIMARY KEY,
    ord_date    DATE            NOT NULL,
    ord_price   NUMBER(6),
    emp_id      NUMBER(5)       REFERENCES employee_mng(emp_id) ON DELETE CASCADE,
    cust_id     NUMBER(5)       REFERENCES customer_mng(cust_id) ON DELETE CASCADE
);

order_consists_of:
CREATE TABLE order_consists_of(
    ord_id              NUMBER(5)       REFERENCES order_mng(ord_id) ON DELETE CASCADE,
    film_id             NUMBER(5)       REFERENCES film_mng(film_id) ON DELETE CASCADE,
    number_of_films     NUMBER(5)       NOT NULL,
    CONSTRAINT pk_order_consists_of PRIMARY KEY(ord_id, film_id)
);           

