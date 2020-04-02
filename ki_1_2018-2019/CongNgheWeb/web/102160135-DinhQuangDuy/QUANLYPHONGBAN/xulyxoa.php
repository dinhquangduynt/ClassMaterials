<?php 
	$mapb=$_REQUEST['IDPB'];
	$link=mysqli_connect("localhost","root","") or die("khong the ket noi den CSDL MYSQL");
	mysqli_select_db($link,"DULIEU");
	if (isset($mapb)) {
		$rs=mysqli_query($link,"DELETE from PHONGBAN WHERE IDPB ='$mapb'");
	}
	else 
		$rs=mysqli_query($link,"DELETE from PHONGBAN");
	header("Location:xoa.php");

 ?>