.<?php
	$user=$_REQUEST['t1'];
	$pass=$_REQUEST['p1'];
	if($user=="" || $pass=="") {
		header("Location:index1.php");
	}
	else {
		$bienketnoi=mysqli_connect("127.0.0.1", "root", "") or die('Could not connect: '.mysqli_error());
		//Chon CSDL de lam viec
		$db_selected=mysqli_select_db($bienketnoi, "DULIEU");
		//Lay tat ca cac ban ghi
		$rs=mysqli_query($bienketnoi, "select * from admin where username='$user' and password='$pass'");
		//kiem tra co ban ghi tra ve khong
		if(mysqli_num_rows($rs)==0)
			header("Location:index1.php");
		else
			header("Location:index2.php");
		//giai phong tap cac ban ghi trong $rs
		mysqli_free_result($rs);
	}
?>