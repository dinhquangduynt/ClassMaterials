<?php 
	$maphong=$_REQUEST['ID'];
	$link=mysqli_connect("localhost","root","") or die("khong the ket noi den CSDL MYSQL");
	mysqli_set_charset($link,"UTF8");
	mysqli_select_db($link,"DULIEU");
	////
	if (isset($maphong)) {
		$rs=mysqli_query($link,"DELETE from THONGTINPHONG WHERE maphong ='$maphong'");
	}
	if (isset($_REQUEST['ID2'])) {
		$rs=mysqli_query($link,"DELETE from THONGTINPHONG");
	}
	//$add="update loaiphong set soluongphong = soluongphong - 1 where maloaiphong ='$loaiphong'";
	//$rs1=mysqli_query($link,$add);
	header("Location: deletephong.php");

 ?>