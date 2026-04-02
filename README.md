# hello-world repository
# fixing an immaginary branch and showing how merging works.

Hello World repository for Git tutorial
This is an example repository for the Git tutoial on  https://www.w3schools.com

This repository is built step by step in the tutorial.
I am going to be using this file to edit lines of code
It mow includes steps for GitHub
I will be using some of my personal C projects.




Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
Sakila Sample Database
The sakila.mwb file is a MySQL Workbench data model that you can open within MySQL Workbench
to examine the database structure. For more information, see MySQL Workbench.
To install the Sakila sample database, follow these steps:
1. Extract the installation archive to a temporary location such as C:\temp\ or /tmp/. When
you unpack the archive, it creates a directory named sakila-db that contains the sakila-
schema.sql and sakila-data.sql files.
2. Connect to the MySQL server using the mysql command-line client with the following command:
$> mysql -u root -p
Enter your password when prompted. A non-root account can be used, provided that the account
has privileges to create new databases.
3. Execute the sakila-schema.sql script to create the database structure, and execute the
sakila-data.sql script to populate the database structure, by using the following commands:
mysql> SOURCE C:/temp/sakila-db/sakila-schema.sql;
mysql> SOURCE C:/temp/sakila-db/sakila-data.sql;
Replace the paths to the sakila-schema.sql and sakila-data.sql files with the actual paths
on your system.
Note
On Windows, use slashes rather than backslashes when executing the
SOURCE command.
4. Confirm that the sample database is installed correctly. Execute the following statements. You
should see output similar to that shown here.
mysql> USE sakila;
Database changed
mysql> SHOW FULL TABLES;
+----------------------------+------------+
| Tables_in_sakila | Table_type |
+----------------------------+------------+
| actor | BASE TABLE |
| actor_info | VIEW |
| address | BASE TABLE |
| category | BASE TABLE |
| city | BASE TABLE |
| country | BASE TABLE |
| customer | BASE TABLE |
| customer_list | VIEW |
| film | BASE TABLE |
| film_actor | BASE TABLE |
| film_category | BASE TABLE |
| film_list | VIEW |
| film_text | BASE TABLE |
| inventory | BASE TABLE |
| language | BASE TABLE |
| nicer_but_slower_film_list | VIEW |
| payment | BASE TABLE |
| rental | BASE TABLE |
| sales_by_film_category | VIEW |
| sales_by_store | VIEW |
| staff | BASE TABLE |
| staff_list | VIEW |
| store | BASE TABLE |
+----------------------------+------------+
23 rows in set (0.01 sec)
mysql> SELECT COUNT(*) FROM film;
+----------+
4
Sakila Sample Database
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
mysql> SELECT COUNT(*) FROM film_text;
+----------+
| COUNT(*) |
+----------+
| 1000 |
+----------+
1 row in set (0.00 sec)
5 Structure
The following diagram provides an overview of Sakila sample database structure. The diagram source
file (for use with MySQL Workbench) is included in the Sakila distribution and is named sakila.mwb.
Figure 1 The Sakila Schema
5.1 Tables
The following sections describe the tables that make up the Sakila sample database, in alphabetic
order.
5.1.1 The actor Table
The actor table lists information for all actors.
5
Sakila Sample Database
The actor table is joined to the film table by means of the film_actor table.
Columns
• actor_id: A surrogate primary key used to uniquely identify each actor in the table.
• first_name: The actor first name.
• last_name: The actor last name.
• last_update: When the row was created or most recently updated.
5.1.2 The address Table
The address table contains address information for customers, staff, and stores.
The address table primary key appears as a foreign key in the customer, staff, and store tables.
Columns
• address_id: A surrogate primary key used to uniquely identify each address in the table.
• address: The first line of an address.
• address2: An optional second line of an address.
• district: The region of an address, this may be a state, province, prefecture, etc.
• city_id: A foreign key pointing to the city table.
• postal_code: The postal code or ZIP code of the address (where applicable).
• phone: The telephone number for the address.
• last_update: When the row was created or most recently updated.
• location: A Geometry column with a spatial index on it.
Note
The spatial location column is supported as of MySQL 5.7.5. This column
is added only when executing the Sakila SQL files against MySQL server
5.7.5 and higher. Additionally, SPATIAL KEY idx_location is also added.
5.1.3 The category Table
The category table lists the categories that can be assigned to a film.
The category table is joined to the film table by means of the film_category table.
Columns
• category_id: A surrogate primary key used to uniquely identify each category in the table.
• name: The name of the category.
• last_update: When the row was created or most recently updated.
5.1.4 The city Table
The city table contains a list of cities.
6
Sakila Sample Database
The city table is referred to by a foreign key in the address table and refers to the country table
using a foreign key.
Columns
• city_id: A surrogate primary key used to uniquely identify each city in the table.
• city: The name of the city.
• country_id: A foreign key identifying the country that the city belongs to.
• last_update: When the row was created or most recently updated.
5.1.5 The country Table
The country table contains a list of countries.
The country table is referred to by a foreign key in the city table.
Columns
• country_id: A surrogate primary key used to uniquely identify each country in the table.
• country: The name of the country.
• last_update: When the row was created or most recently updated.
5.1.6 The customer Table
The customer table contains a list of all customers.
The customer table is referred to in the payment and rental tables and refers to the address and
store tables using foreign keys.
Columns
• customer_id: A surrogate primary key used to uniquely identify each customer in the table.
• store_id: A foreign key identifying the customer “home store.” Customers are not limited to renting
only from this store, but this is the store at which they generally shop.
• first_name: The customer first name.
• last_name: The customer last name.
• email: The customer email address.
• address_id: A foreign key identifying the customer address in the address table.
• active: Indicates whether the customer is an active customer. Setting this to FALSE serves as an
alternative to deleting a customer outright. Most queries should have a WHERE active = TRUE
clause.
• create_date: The date the customer was added to the system. This date is automatically set using
a trigger during an INSERT.
• last_update: When the row was created or most recently updated.
5.1.7 The film Table
The film table is a list of all films potentially in stock in the stores. The actual in-stock copies of each
film are represented in the inventory table.
7
Sakila Sample Database
The film table refers to the language table and is referred to by the film_category,
film_actor, and inventory tables.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
• release_year: The year in which the movie was released.
• language_id: A foreign key pointing at the language table; identifies the language of the film.
• original_language_id: A foreign key pointing at the language table; identifies the original
language of the film. Used when a film has been dubbed into a new language.
• rental_duration: The length of the rental period, in days.
• rental_rate: The cost to rent the film for the period specified in the rental_duration column.
• length: The duration of the film, in minutes.
• replacement_cost: The amount charged to the customer if the film is not returned or is returned in
a damaged state.
• rating: The rating assigned to the film. Can be one of: G, PG, PG-13, R, or NC-17.
• special_features: Lists which common special features are included on the DVD. Can be zero
or more of: Trailers, Commentaries, Deleted Scenes, Behind the Scenes.
• last_update: When the row was created or most recently updated.
5.1.8 The film_actor Table
The film_actor table is used to support a many-to-many relationship between films and actors. For
each actor in a given film, there will be one row in the film_actor table listing the actor and film.
The film_actor table refers to the film and actor tables using foreign keys.
Columns:
• actor_id: A foreign key identifying the actor.
• film_id: A foreign key identifying the film.
• last_update: When the row was created or most recently updated.
5.1.9 The film_category Table
The film_category table is used to support a many-to-many relationship between films and
categories. For each category applied to a film, there will be one row in the film_category table
listing the category and film.
The film_category table refers to the film and category tables using foreign keys.
Columns:
• film_id: A foreign key identifying the film.
• category_id: A foreign key identifying the category.
8
Sakila Sample Database
• last_update: When the row was created or most recently updated.
5.1.10 The film_text Table
The film_text table contains the film_id, title and description columns of the film table,
with the contents of the table kept in synchrony with the film table by means of triggers on film table
INSERT, UPDATE and DELETE operations (see Section 5.5, “Triggers”).
Before MySQL server 5.6.10, the film_text table was the only table in the Sakila sample database
that used the MyISAM storage engine. This is because full-text search is used for titles and descriptions
of films listed in the film table. MyISAM was used because full-text search support with InnoDB was not
available until MySQL server 5.6.10.
Columns
• film_id: A surrogate primary key used to uniquely identify each film in the table.
• title: The title of the film.
• description: A short description or plot summary of the film.
The contents of the film_text table should never be modified directly. All changes should be made
to the film table instead.
5.1.11 The inventory Table
The inventory table contains one row for each copy of a given film in a given store.
The inventory table refers to the film and store tables using foreign keys and is referred to by the
rental table.
Columns
• inventory_id: A surrogate primary key used to uniquely identify each item in inventory.
• film_id: A foreign key pointing to the film this item represents.
• store_id: A foreign key pointing to the store stocking this item.
• last_update: When the row was created or most recently updated.
5.1.12 The language Table
The language table is a lookup table listing the possible languages that films can have for their
language and original language values.
The language table is referred to by the film table.
Columns
• language_id: A surrogate primary key used to uniquely identify each language.
• name: The English name of the language.
• last_update: When the row was created or most recently updated.
5.1.13 The payment Table
The payment table records each payment made by a customer, with information such as the amount
and the rental being paid for (when applicable).
The payment table refers to the customer, rental, and staff tables.
9
