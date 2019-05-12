<?php
require_once 'connection.php';

if(isset($_POST['submit'])) {

	//comprobar datos

	$name = isset($_POST['name']) ? $_POST['name'] : null;
	$password = isset($_POST['password']) ? $_POST['password'] : null;


	//validar datos

	$check_data = true;
	if(empty($name) || ! preg_match("/^[a-zA-Z\s]+$/", $name)) {
		$check_data = false;
		echo '<div style="position: relative;background-color: red; width: 400px; height: 20px;">
    <h3>>Por favor completa el campo del nombre correctamente<h3></div>';
	}
	if(empty($password)) {
		$check_data = false;
		echo '<div style="position: relative;background-color: red; width: 400px; height: 20px;">
    <h3>>La contraseña no puede estar vacía<h3></div>';
	}
	if ($check_data == true) {

		//Comprobar si el usuario existe
		$sql = "SELECT * FROM usuarios WHERE name = '$name'";
		$login = mysqli_query($connection, $sql);

		if($login && mysqli_num_rows($login) == 1) {

			$usuario = mysqli_fetch_assoc($login);

			$verify = password_verify($password, $usuario["password"]);

			if ($verify) {
				session_start();
				$_SESSION['name'] = $name;
				header("Location: ../logged.html");
			}else {
				echo '<div style="position: relative;background-color: red; width: 450px; height: 20px;">
			<h3>>Contraseña incorrecta<h3></div>';
			}
		}else {
			echo '<div style="position: relative;background-color: red; width: 450px; height: 20px;">
			<h3>>El usuario introducido no está registrado<h3></div>';
		}
	}
}

?>
