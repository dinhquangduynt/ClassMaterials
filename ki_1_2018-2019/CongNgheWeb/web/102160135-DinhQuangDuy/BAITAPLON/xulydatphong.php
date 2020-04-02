<?php 
	$maphong=$_REQUEST['ID'];
	$ten=$_POST['txtten'];
	$socm=$_POST['sochungminh'];
	$ngaynhan=$_POST['ngaynhan'];
	$ngaytra=$_POST['ngaytra'];

	$link= mysqli_connect("localhost", "root", "") or die("khong the ket noi den CSDL MySQL");
	$db_selected=mysqli_select_db($link, "DULIEU");
	mysqli_set_charset($link,"UTF8");
	
	$rs=mysqli_query($link, "update thongtinphong set tinhtrang='Đã đặt', tennguoidat='$ten', ngaydatphong='$ngaynhan', ngaytraphong='$ngaytra' where maphong='$maphong' ");
		header("Location: display_roomcus.php");

	mysqli_free_result($rs);
	mysqli_close($link);

 ?>