# FLISOL-2017

This is a basic Qt app. which can show the very basic concept:

to run this:
git clone https://github.com/bedi1982/FLISOL-2017

Open qtcreator, in Qtcreator: File -> 'Open File or Project', browse to the cloned folder and select FLISOL.pro
Click the green 'Play' icon on qtcreator and it will run.

Don't forget to create a Database named Teste if you want to use the save feature:

On mysql:

CREATE DATABASE Teste;
use Teste;

CREATE TABLE `Clientes` (
  `cliente_id` int(11) NOT NULL AUTO_INCREMENT,
  `nome` varchar(40) DEFAULT NULL,
  `endereco` varchar(40) DEFAULT NULL,
  `phone` varchar(50) DEFAULT NULL,
  `sexo` varchar(30) DEFAULT NULL,
  `cidade` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`cliente_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
