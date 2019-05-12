<?php

$server = 'localhost';
$user = 'root';
$password = 'root';
$database = 'data';


$connection = mysqli_connect($server, $user, $password, $database);

if(mysqli_connect_errno()) {
	echo '<div style="position: relative;background-color: red; width: 400px; height: 20px;">
    <h3>>Failed to connect to database<h3></div>';
}

?>
