<?php 
	$mapb=$_REQUEST['IDPB'];
	$mota=$_POST['txtMoTa'];
	$thoigian=$_POST['thoigian'];

	$link= mysqli_connect("localhost", "root", "") or die("khong the ket noi den CSDL MySQL");
	$db_selected=mysqli_select_db($link, "DULIEU");//
	$rs=mysqli_query($link, "update PHONGBAN set mota='$mota', thoigian ='$thoigian' where IDPB='$mapb'");
	header("Location: capnhat.php");
	mysqli_free_result($rs);
	mysqli_close($link);

 ?>