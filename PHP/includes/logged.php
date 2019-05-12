<?php
require_once 'connection.php';

if(isset($_POST['submit'])) {

	//comprobar datos

	$password = isset($_POST['password']) ? $_POST['password'] : null;
	$password2 = isset($_POST['password2']) ? $_POST['password'] : null;


	//validar datos

	$check_data = true;
	if(empty($password) || empty($password2)) {
		$check_data = false;
		echo '<div style="position: relative;background-color: red; width: 400px; height: 20px;">
    <h3>>La contraseña no puede estar vacía<h3></div>';
	}
	if(strcmp($password, $password2) != 0) {
		$check_data = false;
		echo '<div style="position: relative;background-color: red; width: 400px; height: 20px;">
    <h3>>Las contraseñas no coinciden<h3></div>';
	}
	if ($check_data == true) {
		session_start();
		$name = $_SESSION['name'];
		$enc_password = password_hash($password, PASSWORD_BCRYPT);

		$sql = "UPDATE usuarios SET password = '$enc_password' WHERE name = '$name'";
		$change_pwd = mysqli_query($connection, $sql);

		if($change_pwd) {
			echo '<div style="position: relative;background-color: green; width: 400px; height: 20px;">
			<h3>>La contraseña ha sido modificada correctamente<h3></div>';
		}
	}
}

?>
