<?php 
	$ten=$_POST['txtten'];
	$user=$_POST['txtuser'];
	$pass=$_POST['txtpass'];
	$sdt=$_POST['txtsdt'];
	$link = mysqli_connect("localhost", "root", "") or die("khong the ket noi den CSDL MYSQL");
	mysqli_set_charset($link,"UTF8");
	mysqli_select_db($link,"DULIEU");
	$rs=mysqli_query($link, "select User from customer where User = '$user'");
	if ($ten!="" && $user!=""&& $pass!="" && $sdt!="" &&is_numeric($sdt) && mysqli_num_rows($rs)==0 ) {
		$sql ="insert into customer(User,Password,Hoten,SDT) 
		values ('$user','$pass','$ten','$sdt')";
		$rs=mysqli_query($link,$sql);
		echo '<script language="javascript">alert("Đăng ký thành công, đăng nhập để tiếp tục"); 
            window.location="logincus.php";</script>';
	}

	else
		echo '<script language="javascript">alert("Đăng ký thất bại, vui lòng thử lại"); 
            window.location="register.php";</script>';


	

 ?>