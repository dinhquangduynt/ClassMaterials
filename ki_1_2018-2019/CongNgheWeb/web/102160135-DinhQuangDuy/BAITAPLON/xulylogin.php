<?php 
// lay user pass
	$user=$_POST['t1'];
	$pass=$_POST['p1'];
//khai bao ket noi
    $link= mysqli_connect("localhost", "root", "") or die("khong the ket noi den CSDL MySQL");
	mysqli_select_db($link,"DULIEU");
	$sql = "select *from ADMIN where Username = '$user' and password = '$pass'";
	$result= mysqli_query($link,$sql);

	
	if (mysqli_num_rows($result) == 0)
	{
		echo '<script language="javascript">alert("sai thông tin đăng nhập"); 
            window.location="login.php";</script>';
	}
	else
		header("location: index2.php");
	
 ?>
