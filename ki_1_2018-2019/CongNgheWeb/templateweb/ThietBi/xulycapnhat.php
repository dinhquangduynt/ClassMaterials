<?php
	$tenpb=$_REQUEST['txtTenPB'];
	$moTa=$_REQUEST['txtMoTa'];
	$myID=$_REQUEST['IDPB'];
	$bienketnoi=mysqli_connect("127.0.0.1", "root", "") or die('Could not connect: '.mysqli_error());
	$db_selected=mysqli_select_db($bienketnoi, "DULIEU");
	$rs=mysqli_query($bienketnoi, "update phongban set TenPB='$tenpb', MoTa='$moTa' where IDPB='$myID'");
	header("Location:capnhat.php");
?>