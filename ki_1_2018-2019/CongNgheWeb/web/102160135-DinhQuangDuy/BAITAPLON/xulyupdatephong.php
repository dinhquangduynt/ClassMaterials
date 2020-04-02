<?php 
	$maphong=$_REQUEST['ID'];
	$songuoi=$_POST['txtsonguoi'];
	$tinhtrang=$_POST['txttt'];
	$ten=$_POST['txtten'];
	$ngaynhan=$_POST['ngaynhan'];
	$ngaytra=$_POST['ngaytra'];

	$link= mysqli_connect("localhost", "root", "") or die("khong the ket noi den CSDL MySQL");
	$db_selected=mysqli_select_db($link, "DULIEU");
	mysqli_set_charset($link,"UTF8");
	
		$rs=mysqli_query($link, "update thongtinphong set songuoitoida='$songuoi', tinhtrang='$tinhtrang', tennguoidat='$ten', ngaydatphong='$ngaynhan', ngaytraphong='$ngaytra' where maphong='$maphong' ");
			header("Location: updatephong.php");

	mysqli_free_result($rs);
	mysqli_close($link);

 ?>