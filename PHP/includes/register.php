<?php
require_once 'connection.php';


if(isset($_POST['submit'])) {

	//comprobar datos

	$name = isset($_POST['name']) ? $_POST['name'] : null;
	$surname = isset($_POST['surname']) ? $_POST['surname'] : null;
	$gender = isset($_POST['gender']) ? $_POST['gender'] : null;
	$password = isset($_POST['password']) ? $_POST['password'] : null;
	$password2 = isset($_POST['password2']) ? $_POST['password2'] : null;



	//validar datos

	$check_data = true;
	if(empty($name) || ! preg_match("/^[a-zA-Z\s]+$/", $name)) {
		$check_data = false;
		echo '<div style="position: relative;background-color: red; width: 400px; height: 20px;">
    <h3>>Por favor completa el campo del nombre correctamente<h3></div>';
	}
	if(!preg_match("/^[a-zA-Z\s]+$/", $surname) && !empty($surname)) {
		$check_data = false;
		echo '<div style="position: relative;background-color: red; width: 400px; height: 20px;">
    <h3>>Por favor completa el campo de los apellidos correctamente<h3></div>';
	}
	if(empty($gender)) {
		$check_data = false;
		echo '<div style="position: relative;background-color: red; width: 400px; height: 20px;">
    <h3>>El campo del género no puede estar vacío<h3></div>';
	}
	if(empty($password) || empty($password2)) {
		$check_data = false;
		echo '<div style="position: relative;background-color: red; width: 400px; height: 20px;">
    <h3>>La contraseña no puede estar vacía<h3></div>';
	}
	else if(strcmp($password, $password2) != 0) {
		$check_data = false;
		echo '<div style="position: relative;background-color: red; width: 450px; height: 20px;">
    <h3>>Las contraseñas no coinciden<h3></div>';
	}
	if ($check_data == true) {

		//cifrado contrasena
		$enc_password = password_hash($password, PASSWORD_BCRYPT);

		//introducir usuarios en la BBDD
		$sql = "INSERT INTO usuarios VALUES (null, '$name', '$surname', '$gender', '$enc_password')";
		$save_data = mysqli_query($connection, $sql);

		if($save_data) {
			echo '<div style="position: relative;background-color: green; width: 450px; height: 20px;">
			<h3>>Tu cuenta ha sido creada con éxito<h3></div>';
			}else {
			echo '<div style="position: relative;background-color: red; width: 450px; height: 20px;">
			<h3>>Tus datos no han llegado a la base de datos<h3></div>';
			}
	}
}
?>
