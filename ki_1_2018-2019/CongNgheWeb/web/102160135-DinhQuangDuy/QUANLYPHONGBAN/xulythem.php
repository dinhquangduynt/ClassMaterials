<?php 
	$IDPB=$_REQUEST['txtMapb'];
	$mota=$_REQUEST['txtMoTa'];
	$thoigian=$_REQUEST['thoigian'];
	$link = mysqli_connect("localhost", "root", "") or die("khong the ket noi den CSDL MYSQL");
	mysqli_select_db($link,"DULIEU");
	$rs1=mysqli_query($link, "select IDPB from PHONGBAN where IDPB= '$IDPB'");
	if (mysql_num_rows(rs1)==0) {
		$sql = "insert into PHONGBAN (IDPB,mota,thoigian) values ('$IDPB','$mota','$thoigian')";
	$rs=mysqli_query($link,$sql);
	}
	else {
		echo '<script language="javascript">alert("Phòng ban đã tồn tại"); 
            window.location="form_them.php";</script>';
	}

	header("Location:them.php");
 ?>