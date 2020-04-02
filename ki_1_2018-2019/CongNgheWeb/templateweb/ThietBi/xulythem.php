<?php
	$mapb=$_REQUEST['txtMaPB'];
	$tenpb=$_REQUEST['txtTenPB'];
	$moTa=$_REQUEST['txtMoTa'];
	//$myID=$_REQUEST['IDPB'];
	$bienketnoi=mysqli_connect("127.0.0.1", "root", "") or die('Could not connect: '.mysqli_error());
	$db_selected=mysqli_select_db($bienketnoi, "DULIEU");
	$rs=mysqli_query($bienketnoi, "select IDPB from phongban where IDPB = '$mapb'");
		//kiem tra co ban ghi tra ve khong
		if(mysqli_num_rows($rs)==0) {
			$rs=mysqli_query($bienketnoi, "insert into phongban (IDPB, TenPB, MoTa) values ('$mapb', '$tenpb', '$moTa')");
			header("Location:xemthongtinpb.php");
		}
		else {
			echo "<script type='text/javascript'>
				alert('IDPB da ton tai');
				window.location.href = 'them.php';
			</script>";
		}
?>