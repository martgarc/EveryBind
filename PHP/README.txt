CREATE TABLE usuarios(
id           int(255) PRIMARY KEY auto_increment,
nombre       varchar(50) not null,
apellidos    varchar(100) not null,
nick         varchar(50) not null,
pais         varchar(50),
telefono     int(9),
password     varchar(50) not null,
CONSTRAINT uq_nombre UNIQUE(nombre)
);
